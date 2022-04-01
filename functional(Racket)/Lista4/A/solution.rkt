#lang racket

(provide caesar)

(define (caesar alphabet key)
  ;procedura rotate-left z ćwiczeń  
  (define (rotate-left k l)
    (define (length xs)
      (if (null? xs)
          0
          (+ 1 (length (cdr xs)))))
    (define (left l  k)
      (cond [(= k 0) l] 
            [(null? l) null]
            [else (left
                   (append (cdr l) (cons (car l) null))
                   (- k 1))]))
    (left l (modulo k (length l))))
 
  (define (zip xs ys)
    (define (reduce x y acc) (cons (cons x y) acc))
    (foldr reduce null xs ys))

  (define slownik (zip
                   (rotate-left key alphabet)
                   alphabet))

  (define (encode s)
    (define (lookup a xs)
      (if (equal? a (cdr (car xs)))
          (car (car xs))
          (lookup a (cdr xs))))
    (lookup s slownik))
  
  (define (decode s)
    (define (lookup a xs)
      (if (equal? a (car (car xs)))
          (cdr (car xs))
          (lookup a (cdr xs))))
    (lookup s slownik))

  
  (cons encode decode))

;alfabety:
(define chars
  (let ([az (string->list "aąbcćdeęfghijklłmnńoópqrsśtuvwxyzźż")])
    (list* #\space #\. #\, #\! #\- #\: #\newline
           (append az (map char-upcase az)))))
( define a-z (string->list "abcdefghijklmnopqrstuvwxyz") )

;testy:

(define ring (caesar a-z 1))
(list->string ( map ( car ring ) ( string->list "abcxyz")))
;wynik: "bcdyza"
(list->string ( map ( cdr ring ) ( string->list "bcdyza")))
;wynik: "abcxyz"
(map ( car ( caesar ( list 0 1 2 'a 'b 'c ) 2))
     ( list 0 2 'c 'c 1 2 'b 'a ) )
;wynik: (2 b 1 1 a b 0 c)

(define code (caesar chars 3))
(list->string ( map ( car code ) ( string->list "aBc xyz")))
;wynik: "cDe!źżA"


(list->string (map (cdr code)
     ( map ( car code ) ( string->list "aBc xyz"))))
;wynik: "aBc xyz"


    
          



  

  
      
    

  

  
  
