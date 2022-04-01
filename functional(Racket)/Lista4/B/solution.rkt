#lang racket

(provide crack-caesar)

(define (crack-caesar alphabet c xs)

  ;procedura zip z listy ćwiczeniowej
  (define (zip xs ys)
    (define (reduce x y acc) (cons (cons x y) acc))
    (foldr reduce null xs ys))

  ;dictionary
  (define (newdict cs)
    (define (zeroes cs)
      (if (equal? cs null)
          null
          (cons 0 (zeroes (cdr cs)))))
    (zip alphabet (zeroes alphabet)))
  
  (define empty-dictionary (newdict alphabet))


  (define (dictcreate tekst dicti)
    (define (dictinc x ls)
      (if (equal? (car(car ls)) x)
          (cons (cons (car (car ls)) (+ (cdr (car ls)) +1)) (cdr ls))
          (cons (car ls) (dictinc x (cdr ls)))))

    (define (through g result)
      (if (equal? g null)
          result
          (through (cdr g) (dictinc (car g) result))))

    (through tekst dicti))   
  
  (define (maks-dict a x dict)
    (cond [(equal? dict null) a]
          [(> (cdr (car dict)) x) (maks-dict
                                   (car (car dict))
                                   (cdr (car dict))
                                   (cdr dict))]
          [else (maks-dict a x (cdr dict))]))


;key
  (define (findkey c a alphabet)
    (define (calculate-key a alph cur key)
      (cond [(equal? cur null) (calculate-key c a alph alph key)]
            [(equal? (car cur) a) key]
            [else (calculate-key a alph (cdr cur) (+ key 1 ))]))
    (define (startkey c a alphabet cur)
      (if (equal? c (car cur))
          (calculate-key a alphabet (cdr cur) 1)
          (startkey c a alphabet (cdr cur))))
    (startkey c a alphabet alphabet))
           
          
  (define key (findkey
               c
               (maks-dict "z" 0 (dictcreate xs empty-dictionary))
               alphabet))
               
;decode
;procedura rotate-left z listy ćwiczeniowej
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
 
 

  (define slownik (zip
                   (rotate-left key alphabet)
                   alphabet))


  (define (decode s)
    (define (lookup a xs)
      (if (equal? a (car (car xs)))
          (cdr (car xs))
          (lookup a (cdr xs))))
    (lookup s slownik))

  (map decode xs))



;testy
(define alphabet
   ( let ([ az ( string->list "aąbcćdeęfghijklłmnńoópqrsśtuvwxyzźż")])
      ( list* #\space #\. #\, #\! #\- #\: #\newline
              ( append az ( map char-upcase az ) ) ) ) )
( define ( crack-string xs )
   ( list->string ( crack-caesar alphabet #\space ( string->list xs ) ) ) )
( define text
   "ŃukeĘsńwkeBvkĘGfeĘeqĄźłesńleśkteĘevźJtzfjKłGeĘGĘkumHGnexstmHowxleżsóńIeHsowsfjXketĆźĄośexsoewkeńzCnewsośBmkeńzeĘkutsjKxseńzCneńkĄxsfełGeBtĄGvkewzqsvGj-GmrfemzeżzuoqxlęeŁlńIezńĆlńeHkJkĄĆlfjZeĘzuzewzśkfekułzeĘHqkĄńGeĘkĄĆlg")
( display ( crack-string text ))

 
  

  
  
