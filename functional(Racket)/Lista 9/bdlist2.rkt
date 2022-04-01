#lang racket

(struct bdlist (v [prev #:mutable] [next #:mutable]))

(define (list->bdlist xs)
  (define (makenode bdprev xs)
    (if (null? cur) null
         (let ([x (bdlist (car cur) bdprev null)])
           


(define test (list->bdlist (list 1 2 3 4 5 5 6)))

(bdlist-v (bdlist-prev  (bdlist-next (bdlist-next test))))
