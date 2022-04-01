#lang plait



; wyrażenia

(define-type ArithExpr
  (const [val : Number])
  (binop [op : Symbol] [l : ArithExpr] [r : ArithExpr])
  (var-expr [id : Symbol])
  (let-expr [id : Symbol] [e1 : ArithExpr] [e2 : ArithExpr])
  (if-expr [eb : ArithExpr] [et : ArithExpr] [ef : ArithExpr]))

(define (binary-operator? op)
  (member op '(+ - * / = < and or)))

(define (parse q)
  (cond
    [(s-exp-number? q) (const (s-exp->number q))]
    [(s-exp-symbol? q) (var-expr (s-exp->symbol q))]
    [(s-exp-list? q)
     (let ([ql (s-exp->list q)])
       (cond
         [(and (= (length ql) 3)
               (equal? (first ql) `let))
          (let ([ll (s-exp->list (second ql))])
            (let-expr (s-exp->symbol (first ll))
                      (parse (second ll))
                      (parse (third ql))))]
         [(and (= (length ql) 4)
               (equal? (first ql) `if))
          (if-expr (parse (second ql))
                   (parse (third ql))
                   (parse (fourth ql)))]
         [(and (= (length ql) 3)
               (binary-operator? (s-exp->symbol (first ql))))
          (binop (s-exp->symbol (first ql))
                 (parse (second ql))
                 (parse (third ql)))]))]))

; środowiska

(define-type-alias (Env 'a) (Listof (Symbol * 'a)))

(env-empty : (Env 'a))
(define env-empty empty)

(define (env-add x v env) (cons (pair x v) env))

(define (env-lookup x env)
  (type-case (Env 'a) env
    [empty (error 'env-lookup (string-append "Unknown identifier "
                                             (to-string x)))]
    [(cons p ps)
     (if (eq? (fst p) x)
         (snd p)
         (env-lookup x (rest env)))]))

; ewaluacja

(define-type Value
  (number-val [v : Number])
  (boolean-val [v : Boolean]))

(define (arith-op f)
  (lambda (x y)
    (number-val (f (number-val-v x) (number-val-v y)))))

(define (comp-op f)
  (lambda (x y)
    (boolean-val (f (number-val-v x) (number-val-v y)))))

(define (bool-op f)
  (lambda (x y)
    (boolean-val (f (boolean-val-v x) (boolean-val-v y)))))

(define (op->proc op)
  (case op
    ['+ (arith-op +)]
    ['- (arith-op -)]
    ['* (arith-op *)]
    ['/ (arith-op /)]
    ['= (comp-op =)]
    ['< (comp-op <)]
    ['and (bool-op (lambda (x y) (and x y)))]
    ['or (bool-op (lambda (x y) (or x y)))]))

(define (eval-env e env)
  (type-case ArithExpr e
    [(const n) (number-val n)]
    [(binop op l r) ((op->proc op) (eval-env l env) (eval-env r env))]
    [(var-expr x) (env-lookup x env)]
    [(let-expr x e1 e2) (eval-env e2 (env-add x (eval-env e1 env) env))]
    [(if-expr eb et ef)
     (if (boolean-val-v (eval-env eb env))
         (eval-env et env)
         (eval-env ef env))]))

(define (eval e) (eval-env e env-empty))



;   Rozwiązanie zadania
;typy
(define-type Type
(number-type)
(boolean-type))


;procedura
(define (logical-operator? op)
       (member op '(and or)))
(define (compare-operator? op)
       (member op '(= <)))
(define (arith-operator? op)
  (member op '(+ - * /)))


(define (type-check e env)
  (type-case ArithExpr e
    [(const n) (some (number-type))]
    [(binop op l r) (let ([l-type (type-check l env)]
                          [r-type (type-check r env)])
                         (cond [(or (none? l-type) (none? r-type)) (none)]
                               [(and (logical-operator? op)
                                     (boolean-type? (some-v l-type))
                                     (boolean-type? (some-v r-type)))
                                (some (boolean-type))]
                               [(and (compare-operator? op)
                                     (number-type? (some-v l-type))
                                     (number-type? (some-v r-type)))
                                (some (boolean-type))]
                               [(and (arith-operator? op)
                                     (number-type? (some-v l-type))
                                     (number-type? (some-v r-type)))
                                (some (number-type))]
                               [else (none)]))]
    [(var-expr x) (env-lookup x env)]
    [(if-expr eb et ef) (let ([eb-type (type-check eb env)]
                              [et-type (type-check et env)]
                              [ef-type (type-check ef env)])
                         (if (and (boolean-type? (some-v eb-type))
                                  (equal? et-type ef-type))
                             et-type
                             (none)))]
    [(let-expr x e1 e2) (let* ([e1-type (type-check e1 env)]
                               [new-env  (env-add x e1-type env)])
                               (if (none? e1-type) (none)
                               (type-check e2 new-env)))]))

(define (typecheck e) (type-check e empty))


         
                              
;testowanie ifa
(typecheck (parse `(if (< 5 4) (+ 7 3) (* 3 4))))
(typecheck (parse `(if (+ 2 3) (+ 2 3) (+ 2 3))))
;testowanie binopa
(typecheck (parse `(+ 2 3)))
(typecheck (parse `(< 2 3)))
;testowanie leta
(typecheck (parse `(let (a (+ 2 3)) (* a 3))))
(typecheck (parse `(let (a (< 2 3)) (and a a))))






