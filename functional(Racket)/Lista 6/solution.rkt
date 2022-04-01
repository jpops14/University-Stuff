#lang racket

(provide (struct-out const) (struct-out binop) rpn->arith)

;; -------------------------------
;; Wyrazenia w odwr. not. polskiej
;; -------------------------------

(define (rpn-expr? e)
  (and (list? e)
       (pair? e)
       (andmap (lambda (x) (or (number? x) (member x '(+ - * /))))
               e)))

;; ----------------------
;; Wyrazenia arytmetyczne
;; ----------------------

(struct const (val)    #:transparent)
(struct binop (op l r) #:transparent)

(define (arith-expr? e)
  (match e
    [(const n) (number? n)]
    [(binop op l r)
     (and (symbol? op) (arith-expr? l) (arith-expr? r))]
    [_ false]))

;; ----------
;; Kompilacja
;; ----------
(define (rpn->arith e)
  (define (operator? op)
    (member op '(+ - * /)))
  (define (convert e s)
    (cond
      [(and (null? e)
            (cons? s)
            (null? (cdr s)))
       (car s)]
      [(number? (car e))
       (convert (cdr e) (cons (const (car e)) s))]
      [(operator? (car e))
       (let* ((x (cadr s))
              (y (car s))
              (s (cddr s))
              (s (cons (binop (car e) x y) s)))
         (convert (cdr e) s))]))
  (convert e null))



; Testy:
(rpn->arith '( 2 3 + 5 *))
;wynik (binop '* (binop '+ (const 2) (const 3)) (const 5))
(rpn->arith '(2 7 + 3 / 14 3 - 4 * + 2 /))
;wynik:
; (binop
;  '/
;  (binop
;   '+
;   (binop '/ (binop '+ (const 2) (const 7)) (const 3))
;   (binop '* (binop '- (const 14) (const 3)) (const 4)))
;  (const 2))
