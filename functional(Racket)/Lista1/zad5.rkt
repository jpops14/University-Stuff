#lang racket

; forma specjalna or po napotkaniu argumentu true nie oblicza pozostałych argumentów
; w przeciwnym wypadko napotkanu by błąd w postaci niezgodności argumentów dodawania

(or true (> (+ 5 "text") 0))

; analogicznie:
; forma specjalna and po napotkaniu argumentu false nie oblicza pozostałych argumentów
; w przeciwnym wypadko napotkanu by błąd w postaci niezgodności argumentów dodawania

(and false (> (+ 5 "text") 0))