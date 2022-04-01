# Gra w statki

## Autor
Jakub Popiel (nr indeksu: 323236) \
323236@uwr.edu.pl\
Data: 27/06/2021

## Opis

W ramach projektu zaimplementowałem prostą grę w statki w oparciu o standardowe zasady gry planszowej. Funkcjonalność rozszerzyłem o możliwość zapisu i wczytywania stanu gry.

### Implementacja

Projekt został napisany w javie przy użyciu elementów interfejsu graficznego z biblioteki Swing; do zapisywania i odczytywania stanu gry z plików wykorzystywany jest interfejs Serializable.

### Uruchamianie

W głównym katalogu znajduje się makefile obsługujący komendy make compile/run/clean umożliwające odpowiednio kompilację programu, uruchomienie programu i usunięcie plików binarnych.

### Interfejs użytkownika
#### Faza przygotowań
Po uruchomieniu gry pojawia się okno przygotowań, w którym pierwszy gracz  przy użyciu rozwijanych menu wybiera dla każdego z siedmiu swoich statków parametry rozstawienia: rząd, kolumnę oraz orientację, po czym potwierdza wybór odpowiednim przyciskiem. Następnie działania te powtarza drugi gracz, po czym rozpoczyna się właściwa faza gry wyświetlana przez drugie okno interfejsu.
W dowolnym momencie przygotowań można również wczytać zapisany stan gry wpisując nazwę pliku w którym jest przechowywany oraz potwierdzając przyciskiem. Udane wczytanie gry powoduje zakończenie przygotowań i uruchomienie drugiej fazy rozgrywki.
#### Faza rozgrywki
Gracze na zmianę wybierają przy pomocy rozwijanych menu koordynaty pola na planszy przeciwnika, które chcą zaatakować, potwierdzając atak odpowiednim przyciskiem. W dowolnym momencie można zapisać stan gry wpisując nazwę pliku, w którym zostanie umieszczony zapis, i potwierdzając odpowiednim przyciskiem.
Gra kończy się w momencie, gdy któryś z graczy straci wszystkie statki.


### Diagram klas UML

W pliku diagram.uxf/diagram.png.

### Dokumentacja

Do wygenerowania dokumentacji został wykorzystany program Doxygen.
Opis klas znajduje się w pliku documentation.pdf.

### Dodatkowe uwagi techniczne

Program był pisany i testowany na Ubuntu 20.04 LTS, ale ponieważ nie korzysta z żadnych rozwiązań zależnych od platformy, jegon działanie nie powinno być zależne od systemu.

