#lang racket

(provide integral)

(define (sum val next a b)
  (if (> a b)
      0
      (+ (val a) (sum val next (next a) b))))

(define (integral f prec)
  (lambda (x y)
    (let ([section (/ (- y x) prec)])
      (sum (lambda (x) (* (f x) section))
           (lambda (x) (+ section x))
           x
           (- y section))))) 
    
     
    
  
     
          
         
  
  
    
         
; przykładowe testy
  
( ( integral ( lambda ( x ) 10) 1000)  0 10)
( ( integral ( lambda ( x ) x ) 1000) 9 10 )
( ( integral ( lambda ( x ) x ) 1000) 0 10 )
(( integral sin 1000) 0 (* pi 2 ))
(( integral sin 1000) 0 (/ pi 2 ))         
(( integral tan 1000) (/ pi -2) (/ pi 2) )

; przybliżenie jest niezadowalające w przypadku całkowania szybko zmieniających
; (szybko rosnących lub szybko malejących) przy pomocy małej liczby prostokątów
( ( integral ( lambda ( x ) (* x x x x)) 5)  0 10)
; wynik przybliżenia to 11328, poprawny wynik to 20 000
( ( integral ( lambda ( x ) (/ 1 (* x x x x))) 5)  10 20)
; wynik przybliżenia to 0.0003980818101763585, poprawny wynik to 0,00029167
( ( integral ( lambda ( x ) (* 10 x)) 5)  0 10)
; wynik przybliżenia to 400, poprawny wynik to 500
( ( integral ( lambda ( x ) (* x x x x x x)) 10)  0 20)
; wynik przybliżenia to 125235840, poprawny wynik to ok 182860000
