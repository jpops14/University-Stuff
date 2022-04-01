#lang racket


(define (swap p)
  (cons (cdr p) (car p)))

(define (fun-product f g)
  (lambda (x) (cons (f (car x))
                    (g (cdr x)))))

(define (inc x) (+ 1 x))
(define (square x) (* x x))

