#lang racket



(provide null null? cons pair? car cdr)



  
(define (cons x y)
  (lambda (z) (cond
                [(= z 0) x]
                [(= z 1) y]
                )))

(define null 'mynull)

(define (null? x)
  (if (eq? x null) #t #f))

(define (pair? x)
  (if (null? x) #f #t))

(define (car x)
  (x 0))

(define (cdr x)
  (x 1))


(define ( list-sum xs )
  (if (null?  xs)
      0
      (+ (car xs)
         (list-sum (cdr xs)))))

(define (list-mult xs)
  (define (mult-iter xs acc)
    (if (null?  xs)
        acc
        (mult-iter (cdr xs) (* acc (car xs)))))
  (mult-iter xs 1))
          


(list-sum (cons 1 (cons 2 (cons 3 (cons 4 null)))))
;wynik: 10
(list-mult (cons 1 (cons 2 (cons 3 (cons 4 null)))))
;wynik 24
(pair? null)
;zwraca #f
(pair? (cons 3 5))
;zwraca #t
(pair? (cons "slowo" "wyraz"))
;zwraca #t
(null? null)
;zwraca #t
(null? (cons 3 5))
;zwraca #f
(null? (cons "slowo" "wyraz"))
;zwraca #f

