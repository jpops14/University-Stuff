#lang racket

(struct bdlist (v [prev #:mutable] [next #:mutable]))

(define (list->bdlist xs)
  (define (makenode bdstart bdprev cur)
    (if (null? cur) bdstart
        (let ([x (bdlist (car cur) bdprev null)])
          (begin (set-bdlist-next! bdprev x)
                 (makenode bdstart x (cdr cur))))))
  (if (null? xs) null
      (let ([x (bdlist (car xs) null (cdr xs))])
        (makenode x x (cdr xs)))))
                          

;test









    
         

;filtr
(define (bdfilter p xs)
  (define (bdfiltr p xs)
    (cond [(null? xs) null]
          [(p (bdlist-v xs))
           (cond [(null? (bdlist-next xs)) xs]
                 [(p (bdlist-v (bdlist-next xs)))
                  (bdfiltr p (bdlist-next xs))]
                 [else (begin (set-bdlist-next!
                               xs
                               (bdlist-next (bdlist-next xs)))
                              (bdfiltr p xs))])]
          [else
           (cond [(null? (bdlist-next xs)) null]
                 [else (bdfiltr p (bdlist-next xs))])]))
  (define (bdfiltrev p xs)
    (cond [(null? xs) null]
          [(p (bdlist-v xs))
           (cond [(null? (bdlist-prev xs)) xs]
                 [(p (bdlist-v (bdlist-prev xs)))
                  (bdfiltrev p (bdlist-prev xs))]
                 [else (begin (set-bdlist-prev!
                               xs
                               (bdlist-prev (bdlist-prev xs)))
                              (bdfiltrev p xs))])]
          [else
           (cond [(null? (bdlist-prev xs)) null]
                 [else (bdfiltrev p (bdlist-prev xs))])]))
  (bdfiltrev p (bdfiltr p xs)))

;test filtra
(define (bdprint xs)
  (if (null? xs) null
      (cons (bdlist-v xs) (bdprint (bdlist-next xs)))))

(define (bdrevprint xs)
  (define (revprint xs prev)
    (define (supp xs)
      (if (null? xs) null
          (cons (bdlist-v xs) (supp (bdlist-prev xs)))))
    (if (null? xs) (supp prev) (revprint (bdlist-next xs) xs)))
  (revprint xs null))

(define test1 (list->bdlist (list 1 2 3 4 5 6)))
(bdprint test1)
(bdrevprint test1)
(define test2 (bdfilter even? test1))
(bdprint test2)
(bdrevprint test2)



                                             
                                                          
                                 

       
    
    
  
