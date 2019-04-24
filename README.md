# Wyniki testów

![alt text](https://raw.githubusercontent.com/sebastianrziolkowski/Punkty/master/Punkty.bmp)

# Punkty

<p>
Zadanie dotyczy punktów na płaszczyźnie. Każdy punkt jest zdefiniowany
przez

dwie współrzędne (x,y), KTÓRE SĄ CAŁKOWITE! </p> <p> Użytkownik
najpierw pobiera pewien zbiór punktów S. Następnie odpowiada na

m pytań czy punkt (x,y) leży wewnątrz otoczki wypukłej zbioru S, czy na
zewnątrz

tej otoczki, czy na jej brzegu? </p> <h2>Bardziej szczegółowo</h2>
<ul> <li>Najpierw pobieramy ilość n punktów zbioru S (n<10000).</p>
<li>Nastepnie pobieramy 2n współrzędnych tych punktów. Kolejno
najpierw

współrzędna x, potem y, itd. </p> <li>Następnie pobieramy ilość
zapytań m (m<1000000).</p> <li>Następnie pobieramy m zapytań. Są one
postaci x y. Gdzie x, y są

całkowite. Zapytanie rozumiemy następująco: Czy punkt (x,y) leży
wewnątrz

otoczki wypukłej zbioru S, czy na zewnątrz, czy w na brzegu?</p>
<li>Odpowiadamy zwracając jedną z liczb -1,0,1. W znaczeniu
następującym: -1

punkt leży na zewnątrz otoczki wypukłej zbioru S, 0 - punkt leży na
brzegu

otoczki wypukłej zbioru S, 1 punkt leży wewnątrz otoczki.</p> </ul>
<h2>Przykład:</h2> 
<h2>Wejście</h2>
 <pre>
7
1 2
-1 2
2 3
3 2
3 3
1 4
1 1
6
0 3
1 3
1 0
2 2
4 3
3 2
</pre> <h2>Wyjście</h2> 
<pre>
0
1
-1
1
-1
0
</pre> <p>Wyjaśnienie: Otrzymujemy zbiór punktów

{(1,2),(-1,2),(2,3),(3,2),(3,3),(1,4),(1,1)}. Jego otoczka wypukła
jest

wyznaczona przez wielokąt o wierzchołkach
{(1,1),(3,2),(3,3),(1,4),(-1,2)}. Następnie otrzymujemy 6 pytań:</p>
<ul>
    <li> Czy punkt (0,3) leży na zewnątrz/na brzegu/wewnątrz otoczki

wypukłej? Odpowiedź: Na brzegu(0)
    <li> Czy punkt (1,3) leży na zewnątrz/na brzegu/wewnątrz otoczki

wypukłej? Odpowiedź: Wewnątrz(1)
    <li> Czy punkt (1,0) leży na zewnątrz/na brzegu/wewnątrz otoczki

wypukłej? Odpowiedź: Na zewnątrz(-1)
    <li> Czy punkt (2,2) leży na zewnątrz/na brzegu/wewnątrz otoczki

wypukłej? Odpowiedź: Wewnątrz(1)
    <li> Czy punkt (4,3) leży na zewnątrz/na brzegu/wewnątrz otoczki

wypukłej? Odpowiedź: Na zewnątrz(-1)
    <li> Czy punkt (3,2) leży na zewnątrz/na brzegu/wewnątrz otoczki

wypukłej? Odpowiedź: Na brzegu(0) </ul> <p> Następnie wyświetlane
jest 6 odpowiedzi w znaczeniu następującym: -1 na

zewnątrz, 0 na brzegu, 1 wewnątrz.</p>

<h2>UWAGA. ZABRANIA SIĘ STOSOWANIA OBLICZEŃ ZMIENNOPRZECINKOWYCH.
WSZYSTKIE

WSPÓŁRZĘDNE SĄ CAŁKOWITE. NALEŻY KORZYSTAĆ Z ILOCZYNU
WEKTOROWEGO.</h2>


Zadanie pochodzi z kursu uczelni UMCS
tichy.umcs.lublin.pl
