#lang racket

(require "sudoku-spec.rkt")

(provide
 rows->board board-rows board-columns board-boxes ; Zad A
 partial-solution-ok? solutions )                 ; Zad B                                              ; Zad B

;; =========
;; Zadanie A
;; =========

;; Tworzy planszę z wierszy (listy list znaków z alfabetu)
(define (rows->board xss)
  xss)

;; Ujawnia listę wierszy (każdy wiersz to lista znaków z alfabetu)
(define (board-rows board)
  board)

;; Ujawnia listę kolumn (każda kolumna to lista znaków z alfabetu)
(define (board-columns board)

  (define (makelist n)
    (define (addlength x acc)
      (if (equal? x 0) acc
          (addlength (- x 1)
                     (cons null acc))))
    (addlength n null))  

  (define (zip xs ys)
    (define (reduce x y acc) (cons (cons x y) acc))
    (foldr reduce null xs ys))
  (foldr zip (makelist  (length board)) board))

;; Ujawnia listę pudełek (każde pudełko to lista znaków z alfabetu)
(define (board-boxes board)
  (define n2 (length (board-rows board)))
  (define n (sqrt n2))

  (define (getboxes nr boxlist)
    (if (equal? nr n2)
        boxlist
        (getboxes (+ nr 1) (cons (getbox
                                  (board-rows board)
                                  null
                                  1
                                  (* (floor (/ nr n)) n)
                                  (+(* (floor (/ nr n)) n) n)
                                  ( *(modulo nr n) n)
                                  (+ ( *(modulo nr n) n) n) 
                                  )
                                 boxlist))))

  (define (getbox rows box cur a b c d)
    (cond [(> cur b) box]
          [(> cur a) (getbox (cdr rows)
                             (boxrow (car rows) box 1 c d)
                             (+ cur 1)
                             a
                             b
                             c
                             d)]
          [else (getbox (cdr rows) box (+ cur 1) a b c d)]))
  
  (define (boxrow row box cur c d)
    (cond [(> cur d) box]
          [(> cur c) (boxrow (cdr row)
                             (cons  (car row) box)
                             (+ cur 1)
                             c
                             d)]
          [else (boxrow
                 (cdr row)
                 box
                 (+ cur 1)
                 c
                 d)]))
  (getboxes 0 null))
;; przykład
;(define plansza (rows->board '((1 2 3 4)(1 2 3 4)(1 2 3 4)(1 2 3 4))))
;(board-columns plansza)
;(board-boxes plansza)
;; =========
;; Zadanie B
;; =========


(define (partial-solution-ok? initial-board elems rows)
  (define (czyok? brd sol)
    (define (correct-single a xs)
      (cond [(eq? a '_) true]
            [(null? xs) true]
            [(ch-eq? a (car xs)) false]
            [else (correct-single a (cdr xs))]))

    (define (checkset xs)
      (define (incheck ys dict)
        (cond [(null? ys) true]
              [(eq? (car ys) '_) (incheck (cdr ys)  dict)]
              [(correct-single (car ys) dict) (incheck (cdr ys) (cons (car ys) dict))]
              [else false]))
      (incheck xs null))

    (define (checkboard xs)
      (cond [(null? xs) true]
            [(checkset (car xs)) (checkboard (cdr xs))]
            [else false]))

    (define (compareboards board sol)
      (cond [(null? board) true]
            [(comparerows (car board) (car sol)) (compareboards (cdr board) (cdr sol))]
            [else false]))

    (define (comparerows xs ys)
      (cond [(null? xs) true]
            [(equal? (car xs) '_) (comparerows (cdr xs) (cdr ys))]
            [(equal? (car xs) (car ys)) (comparerows (cdr xs) (cdr ys))]
            [else false]))
    (and (compareboards (board-rows brd) (board-rows sol))
         (checkboard (board-rows sol))
         (checkboard (board-columns sol))
         (checkboard (board-boxes sol))))
  (define (fillelems xs elem n)
    (cond [(equal? elem null) xs]
          [(equal? n 0)  elem]
          [else (cons (car xs) (fillelems (cdr xs) elem (- n 1)))]))
  (define (stitchwithoutelem board rows n)
    (if (eq? n 0) rows
        (cons (car board) (stitchwithoutelem (cdr board) rows (- n 1)))))

  (define (stitchwithelem board rows  elem n)
    (if (eq? n 1) (cons
                   (fillelems
                    (car board)
                    elem
                    (-(length (car board))(length elem)))
                   rows)
        (cons (car board)
              (stitchwithelem (cdr board) rows elem (- n 1)))))
  (define partsol
    (if (null? elems) (stitchwithoutelem initial-board
                                         rows
                                         (-(length (board-rows initial-board))
                                           (length rows)))
        (stitchwithelem initial-board
                        rows
                        elems
                        (-(length (board-rows initial-board))
                          (length rows)))))
;  (czyok? initial-board partsol))
 (czyok? initial-board partsol))
  


;reszta B

;; Lista poprawnych częściowych wierszy po dodaniu
;; nowego znaku do jakiegoś częściowego rozwiązania
;; (elems, rows)
(define (new-elems initial-board elems rows)
  (filter
   (λ(es) (partial-solution-ok? initial-board es rows))
   (map (λ(c) (cons c elems)) alphabet)))

;; Lista poprawnych wierszy możliwych do dodania do
;; częściowego rozwiązania zawierającego tylko pełne
;; wiersze (rows)
(define (new-rows initial-board rows)
  (map (λ(r) (cons r rows))
       (foldr (λ(_ ess)
                (append-map
                 (λ(es) (new-elems initial-board es rows))
                 ess))
              (list null)
              alphabet)))

;; Lista poprawnych pełnych rozwiązań
(define (solutions initial-board)
  (map (λ(s) (rows->board s))
       (foldr (λ(_ rss)
                (append-map
                 (λ(rs) (new-rows initial-board rs))
                 rss))
              (list null)
              alphabet)))

;test B
;( partial-solution-ok?
;  (rows->board '(( _ _ 4 _ ) ( _ 3 _ _ ) (1 2 _ 4) ( _ 4 _ _ )))
;  '(2 1)
 ; '((1 2 3 4) (3 4 1 2) ))
                                  
  
                   

        
         






             
          
  
