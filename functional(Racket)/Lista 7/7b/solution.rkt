#lang racket

(provide (struct-out const) (struct-out binop) (struct-out var-expr) (struct-out let-expr) (struct-out var-dead) find-dead-vars)

; --------- ;
; Wyrazenia ;
; --------- ;

(struct const    (val)      #:transparent)
(struct binop    (op l r)   #:transparent)
(struct var-expr (id)       #:transparent)
(struct var-dead (id)       #:transparent)
(struct let-expr (id e1 e2) #:transparent)

(define (expr? e)
  (match e
    [(const n) (number? n)]
    [(binop op l r) (and (symbol? op) (expr? l) (expr? r))]
    [(var-expr x) (symbol? x)]
    [(var-dead x) (symbol? x)]
    [(let-expr x e1 e2) (and (symbol? x) (expr? e1) (expr? e2))]
    [_ false]))

(define (parse q)
  (cond
    [(number? q) (const q)]
    [(symbol? q) (var-expr q)]
    [(and (list? q) (eq? (length q) 3) (eq? (first q) 'let))
     (let-expr (first (second q))
               (parse (second (second q)))
               (parse (third q)))]
    [(and (list? q) (eq? (length q) 3) (symbol? (first q)))
     (binop (first q)
            (parse (second q))
            (parse (third q)))]))

; ---------------------------------- ;
; Wyszukaj ostatnie uzycie zmiennych ;
; ---------------------------------- ;

(define (find-dead-vars e)
  (define (fdv e deadvars)
   (match e
    [(const n) (cons (const n) deadvars)]
    [(binop op l r) (let* ([R (fdv r deadvars)]
                           [L (fdv l (cdr R))])
                      (cons (binop op (car L) (car R)) (cdr L)))]
    [(var-expr x) (if (set-member? deadvars x)
                      (cons (var-expr x) deadvars)
                      (cons (var-dead x) (set-add deadvars x)))]
    [(let-expr x e1 e2) (let* ([R  (fdv e2 (set-remove deadvars x))]
                               [ndv (cdr R)]
                               [L  (fdv e1 (set-union deadvars (set-remove ndv x)))])
                          (cons (let-expr x (car L) (car R)) (cdr L)))]
    [_ false]))
    (car (fdv e (set))))

;test
(find-dead-vars ( let-expr 'x (const 3)
( binop '+ ( var-expr 'x ) ( var-expr 'x ) ) ) )