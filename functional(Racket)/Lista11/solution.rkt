#lang racket
(require racket/contract)

(provide ( contract-out
            [ with-labels with-labels/c ]
            [ foldr-map foldr-map/c ]
            [ pair-from pair-from/c ]) )
(provide with-labels/c foldr-map/c pair-from/c )




(define (with-labels f xs)
  (if (null? xs) null
      (cons (list (f (car xs)) (car xs))
            (with-labels f (cdr xs)))))

(define with-labels/c  (parametric->/c [a b] (-> (-> a b) (listof a) (listof (list/c b a)))))

;przyklad z treści zadania
(with-labels number->string (list 1 2 3))


;analogicznie do foldl z ćwiczenia (również iteracyjnie)
(define (foldr-map f acc xs)
  (define (it acc xs ys)
    (if (null? xs)
        (cons ys acc)
        (let[(p (f (car xs) acc))]
          (it (cdr p)
              (cdr xs)
              (cons (car p) ys)))))
  (it acc (reverse xs) null))

(define foldr-map/c (parametric->/c [a b c](-> (-> a b (cons/c c b))
                             b
                             (listof a)
                             (cons/c (listof c) b))))

;przyklad z treści zadania
(foldr-map (lambda (x a) (cons a (+ a x))) 0 '(1 2 3))

(define (pair-from f g)
  (lambda (x) (cons (f x) (g x))))

(define pair-from/c  (parametric->/c [a b c] (-> (-> a b) (-> a c) (-> a (cons/c b c)))))

;przyklad z treści zadania
((pair-from (lambda (x) (+ x 1)) (lambda (x) (* x 2))) 2)

