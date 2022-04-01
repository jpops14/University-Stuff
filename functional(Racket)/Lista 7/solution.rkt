#lang racket

(provide (struct-out const)
         (struct-out binop)
         (struct-out var-expr)
         (struct-out var-free)
         (struct-out var-bound)
         (struct-out let-expr)
         (struct-out pos)
         (struct-out environ)
         annotate-expression)

;; ---------------
;; Jezyk wejsciowy
;; ---------------

(struct pos (file line col)     #:transparent)
  
(struct const    (val)          #:transparent)
(struct binop    (op l r)       #:transparent)
(struct var-expr (id)           #:transparent)
(struct let-expr (loc id e1 e2) #:transparent)

(define (expr? e)
  (match e
    [(const n)      (number? n)]
    [(binop op l r) (and (symbol? op) (expr? l) (expr? r))]
    [(var-expr x)   (symbol? x)]
    [(let-expr loc x e1 e2)
     (and (pos? loc) (symbol? x) (expr? e1) (expr? e2))]
    [_ false]))

(define (make-pos s)
  (pos (syntax-source s)
       (syntax-line   s)
       (syntax-column s)))

(define (parse e)
  (let ([r (syntax-e e)])
    (cond
      [(number? r) (const r)]
      [(symbol? r) (var-expr r)]
      [(and (list? r) (= 3 (length r)))
       (match (syntax-e (car r))
         ['let (let* ([e-def (syntax-e (second r))]
                      [x     (syntax-e (first e-def))])
                 (let-expr (make-pos (first e-def))
                           (if (symbol? x) x (error "parse error!"))
                           (parse (second e-def))
                           (parse (third r))))]
         [op   (binop op (parse (second r)) (parse (third r)))])]
      [else (error "parse error!")])))

; ---------------------------------- ;
; Środowisko                         ;
; ---------------------------------- ;

(struct environ (xs))
(define env-empty (environ null))
(define (env-add x v env)
  (environ (cons (cons x v) (environ-xs env))))
(define (env-lookup x env)
  (define (assoc-lookup xs)
    (cond [(null? xs) null]
          [(eq? x (car (car xs))) (cdr (car xs))]
          [else (assoc-lookup (cdr xs))]))
  (assoc-lookup (environ-xs env)))


;; ---------------
;; Jezyk wyjsciowy
;; ---------------

(struct var-free  (id)     #:transparent)
(struct var-bound (pos id) #:transparent)

(define (expr-annot? e)
  (match e
    [(const n)         (number? n)]
    [(binop op l r)    (and (symbol? op) (expr-annot? l) (expr-annot? r))]
    [(var-free x)      (symbol? x)]
    [(var-bound loc x) (and (pos? loc) (symbol? x))]
    [(let-expr loc x e1 e2)
     (and (pos? loc) (symbol? x) (expr-annot? e1) (expr-annot? e2))]
    [_ false]))

; rozwiazanie

(define (annotate-expression e)
 
(define (antexp e env)
    (match e
    [(const n) e]
    [(binop op l r)   (binop op (antexp l env) (antexp r env))] 
    [(var-expr x) (let ([pos (env-lookup x env)]) (if (null? pos) (var-free x)
                                                                    (var-bound pos x))) ]
    [(let-expr loc x e1 e2) (let-expr loc x (antexp e1 env)
                                            (antexp e2 (env-add x loc env)))] 
    [_ false]))
  (antexp e env-empty))


;przyklad z tresci zadania
(annotate-expression (parse #'(let [ x 5] (* y x))))
;wynik:
;(let-expr
; (pos #<path:/home/jakub/Letni 2021/MP/Lista 7/solution.rkt> 86 37)
; 'x
; (const 5)
; (binop
;  '*
;  (var-free 'y)
;  (var-bound (pos #<path:/home/jakub/Letni 2021/MP/Lista 7/solution.rkt> 86 37) 'x)))