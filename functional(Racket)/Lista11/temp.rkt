
#lang racket
(require racket/contract)

(define/contract (with-labels f xs)
  (parametric->/c [a b] (-> (-> a b) (listof a) (listof (list/c b a))))
  
  (if (null? xs) null
      (cons (list (f (car xs)) (car xs))
            (with-labels f (cdr xs)))))

(with-labels number->string (list 1 2 3))


;analogicznie do foldl z ćwiczenia (również iteracyjnie)
(define/contract (foldr-map f acc xs)
  (parametric->/c [a b c](-> (-> a b (cons/c c b))
                             b
                             (listof a)
                             (cons/c (listof c) b)))
  (define (it acc xs ys)
    (if (null? xs)
        (cons ys acc)
        (let[(p (f (car xs) acc))]
          (it (cdr p)
              (cdr xs)
              (cons (car p) ys)))))
  (it acc (reverse xs) null))

(foldr-map (lambda (x a) (cons a (+ a x))) 0 '(1 2 3))

(define/contract (pair-from f g)
  (parametric->/c [a b c] (-> (-> a b) (-> a c) (-> a (cons/c b c))))
  (lambda (x) (cons (f x) (g x))))

((pair-from (lambda (x) (+ x 1)) (lambda (x) (* x 2))) 2)

