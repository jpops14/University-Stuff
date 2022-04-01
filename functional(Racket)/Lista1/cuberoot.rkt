#lang racket
(provide cube-root)

; za wzór do rozwiązania posłużył kod z wykładu



(define (cube-root x)

  (define (neg x) (- x))


  (define (abs x)
    (cond [(> x 0) x]
          [(= x 0) x]
          [else (- x)]))

  (define (average a b)
    (/ (+ a b) 2))
  
  (define (improve guess)
    (/ ( + (/ x (* guess guess))
           (* 2 guess))
       3))

  (define (cbrt-iter guess)
    (if (good-enough? guess)
        guess
        (cbrt-iter (improve guess))))

  (define (good-enough? guess)
    (< (abs (- (* guess guess guess)
               x))
       0.001))
  
  (cbrt-iter 1.0))

; przykladowe wyrazenia

(cube-root 125)
(cube-root 64)
(cube-root -125)
(cube-root 27)