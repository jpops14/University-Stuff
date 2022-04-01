#lang racket

(define (nullist n)
  (define (addlength x acc)
    (if (equal? x 0) acc
        (addlength (- x 1)
                   (cons null acc))))
  (addlength n null))
    
    
  

(define (zip xs ys)
    (define (reduce x y acc) (cons (cons x y) acc))
    (foldr reduce null xs ys))