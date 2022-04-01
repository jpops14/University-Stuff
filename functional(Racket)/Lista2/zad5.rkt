#lang racket

; accumulate w wersji rekurencyjnej

;(define (accumulate combiner null-value term a next b )
;  (if (> a b)
;      null-value
;      (combiner (term a) (accumulate combiner null-value term (next a) next b))))


; accumulate w wersji iteracyjnej:

(define (accumulate combiner null-value term a next b )
  (if (> a b)
      null-value
      (accumulate combiner (combiner null-value (term a)) term (next a) next b)))
            

(define (sum val next a b)
  (accumulate + 0 val a next b))

(define (product val next a b)
  (accumulate * 1 val a next b))


(define (identity x) x)
(define (inc x) (+ x 1))

(product identity inc 1 4)
(sum identity inc 1 4)