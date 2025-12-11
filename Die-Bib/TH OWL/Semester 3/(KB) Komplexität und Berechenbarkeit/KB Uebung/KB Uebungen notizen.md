

## [Aufgabe 19](KuB-Uebungen-gesamt.pdf#page=6&selection=23,0,24,1|KuB-Uebungen-gesamt, page 6)

Alles sketschy nicht berrücksichtigen

|           | Uniforme Kosten | Logarithmische Kosten |
| --------- | --------------- | --------------------- |
| LOAD #28  | 1               | 28 =                  |
| STORE *17 | 1               |                       |
| MULT 8    | 1               |                       |
| SUB *4    | 1               |                       |
| DIV 17    | 1               |                       |
| GOTO 45   | 1               |                       |
| JZERO 28  | 1               |                       |

|         | Uniforme Kosten | Logarithmische Kosten |
| ------- | --------------- | --------------------- |
| LOAD x  | 1               | c(x)                  |
| STORE x | 1               | L(c(0)) + L(c(x))     |
| MULT x  | 1               | L(c(0))               |
| SUB x   | 1               | c(0)-1                |
| DIV x   | 1               |                       |
| GOTO x  | 1               | x                     |
| JZERO x | 1               |                       |


a)

|       |       |       |                            |
| ----- | ----- | ----- | -------------------------- |
| Loop: | LOAD  | 1     | lade Wert aus c(1) in c(0) |
|       | MUL   | #2    | Multipliziere c(0) mit 2   |
|       | ADD   | #1    | Addiere c(0) mit 1         |
|       | STORE | 1     | Speichere c(0) in c(1)     |
|       | LOAD  | 2     |                            |
|       | SUB   | #1    |                            |
|       | STORE | 2     |                            |
|       | ADD   | #1    |                            |
|       | SUB   | 3     | subtrahiere c(3) von c(0)  |
|       | JZERO | Done: |                            |
|       | GOTO  | Loop: |                            |
|       |       |       |                            |

| c(0) | c(1) | c(2) | c(3) |        |
| ---- | ---- | ---- | ---- | ------ |
|      | 5    | 6    | 4    |        |
| 5    |      |      |      |        |
| 10   |      |      |      |        |
| 11   |      |      |      |        |
|      | 11   |      |      |        |
| 6    |      |      |      |        |
| 5    |      |      |      |        |
|      |      | 5    |      |        |
| 6    |      |      |      |        |
| 2    |      |      |      | ->Loop |
| 11   |      |      |      |        |
| 22   |      |      |      |        |
| 23   |      |      |      |        |
|      | 23   |      |      |        |
| 5    |      |      |      |        |
| 4    |      |      |      |        |
|      |      | 4    |      |        |
| 5    |      |      |      |        |
| 1    |      |      |      | ->Loop |
| 23   |      |      |      |        |
| 46   |      |      |      |        |
| 47   |      |      |      |        |
|      | 47   |      |      |        |
| 4    |      |      |      |        |
| 3    |      |      |      |        |
|      |      | 3    |      |        |
| 4    |      |      |      |        |
| 0    |      |      |      | ->Done |
|      |      |      |      |        |
b)
$$
A_{ij} = K + (i-1)n + (j-1)
\quad \text{,mit } 1 \leq i < m \quad , \text{und } 1\leq j < n
$$

# [Aufgabe 20](KuB-Uebungen-gesamt.pdf#page=7&selection=14,0,14,10|KuB-Uebungen-gesamt, page 7)

L = {abc, aabbcc, aaabbbccc, ... }
DTM ist ein 7-Tupel
$$
\begin{array} \\
TM = (Q, \Sigma, \Gamma, B, q_{0}, \delta, F) \\
Q = & \{q_{0}, q_{1}, q_{2}, q_{3}, q_{4}, q_{5}, q_{6}, q_{7},q_{8}\} \\
\Sigma= & \{a, b, c\} \\
\Gamma= & \{a, b, c, B\} \\
F =  & \{q_{8}\} \\
\delta= & \text{ gemäß Tabelle}
\end{array}
$$


|     | a          | b          | c          | B          |
| --- | ---------- | ---------- | ---------- | ---------- |
| q0  | (q1, B, R) | -          | -          | (q0, B, R) |
| q1  | (q1, a, R) | (q1, b, R) | (q1, c, R) | (q2, B, L) |
| q2  | -          | -          | (q3, B, L) | -          |
| q3  | -          | (q6, B, L) | (q4, B, L) | -          |
| q4  | -          | (q5, c, L) | (q4, c, L) | -          |
| q5  | (q5, a, L) | (q5, b, L) | -          | (q0, B, R) |
| q6  | (q7, B, L) | -          | -          | -          |
| q7  | -          | -          | -          | (q8, B, N) |
| q8  | -          | -          | -          | -          |

# [Aufgabe 21](KuB-Uebungen-gesamt.pdf#page=7&selection=45,0,45,11|KuB-Uebungen-gesamt, page 7)

a)
!!! Annahme: Wir stehen irgendwo links von der Binärzahl

|     | 0          | 1          | B          |
| --- | ---------- | ---------- | ---------- |
| q0  | (q1, 0, R) | (q1, 1, R) | (q0, B, R) |
| q1  | (q1, 0, R) | (q2, 1, R) | (q4, B, L) |
| q2  | (q2, 0, R) | (q2, 1, R) | (q3, B, L) |
| q3  | (q3, 1, L) | (q4, 0, L) | -          |
| q4  | (q4, 0, L) | (q4, 1, L) | (q5, B, R) |
| q5  | (q5, 0, N) | (q5, 1, N) | -          |

b)
Rechenzeit: 
	Anzahl Schritte die vom Programm in a) durchlaufen werden müssen, das Wort abzuarbeiten

Speicherplatzbedarf: 
	Anzahl Speicherstellen die im Durchlauf verwendet werden. 
	(die "Überschritt" in die "Blank"-Zeichen zählt mit)

|           |     Wort     | Rechenzeit | Speicherplatzbedarf |
| --------- | :----------: | ---------- | ------------------- |
| $$w_{1}$$ |     101      | 8          | 5                   |
| $$w_{2}$$ |     1000     | 10         | 6                   |
| $$w_{3}$$ |      0       | 4          | 3                   |
| $$w_{4}$$ | $$\epsilon$$ | $$\infty$$ | 1                   |


# [Aufgabe 22](KuB-Uebungen-gesamt.pdf#page=7&selection=152,0,152,11|KuB-Uebungen-gesamt, page 7)


$$
\lceil \log_{2}|\Gamma alt|\rceil
$$



# [Aufgabe 23](KuB-Uebungen-gesamt.pdf#page=8&selection=22,0,22,11|KuB-Uebungen-gesamt, page 8)

keine Ahnung


# [Aufgabe 24](KuB-Uebungen-gesamt.pdf#page=8&selection=69,0,69,10|KuB-Uebungen-gesamt, page 8)


| ... | -3  | -2  | -1  | 0   | 1   | 2   | 3   | ... |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |

 |
\\/

| 0   | 1   | 2   | 3   | 4   | 5   | 6   | ... |
| --- | --- | --- | --- | --- | --- | --- | --- |

||

| #   | 0   | -1  | 1   | -2  | 2   | -3  | 3   | ... |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |

"#" ist ein symolischer vorzeichenwechsel
daher ist der wechsel von positiv von negativ von n auf n+1 verändert 
Also in O()notation kein Zeitverlust

# [Aufgabe 25](KuB-Uebungen-gesamt.pdf#page=8&selection=90,0,90,10|KuB-Uebungen-gesamt, page 8)

ja, alles bleibt gleich, weil wir von den alten Endzuständen dann nur auf den einen Verweisen. 
An der Funktionsweise ändert sich nichts


# [Aufgabe 26](KuB-Uebungen-gesamt.pdf#page=8&selection=123,0,123,10|KuB-Uebungen-gesamt, page 8)

(wechsel zu Zustand, (Band 1), (Band 2))

|     | 0, 0 | 0, 1 | 0, B                 | 1, 0 | 1, 1 | 1, B                 | B, B                 |
| --- | ---- | ---- | -------------------- | ---- | ---- | -------------------- | -------------------- |
| q0  |      |      | (q0, (0, R), (0, R)) |      |      | (q0, (1, R), (1, R)) | (q1, (B, L), (B, N)) |
| q1  |      |      | (q1, (0, L), (B, N)) |      |      | (q1, (1, L), (B, N)) | (q2, (B, R), (B, N)) |
| q2  |      |      | (q2, (0, R), (0, R)) |      |      | (q2, (1, R), (1, R)) | (q3, (B, L), (B, N)) |
| q3  |      |      |                      |      |      |                      | (q3, (B, N), (B, N)) |

# Übung 7
## [Aufgabe 28](KuB-Uebungen-gesamt.pdf#page=9&selection=28,0,28,10|KuB-Uebungen-gesamt, page 9)
{0,1}* = {e, 0, 10, 00, 01, 10, 11, 000, 001, 010, 011, 100, 101, 110, 111, ...}
Länge   0, 1,           2                 ,                          3    

$$
f: \{0,1\}^k \rightarrow \mathbb{N}
$$
$$
f(\epsilon) = 0, f(0) = 1, f(1) = 2, f(00) = 3, f(01) = 4, \quad \dots
$$


## [Aufgabe 29](KuB-Uebungen-gesamt.pdf#page=9&selection=50,0,50,10|KuB-Uebungen-gesamt, page 9)
Es gibt unendlich viele Turingmaschinen, da unendlich viele Kombinationen von befehlen möglich sind.



## Aufgabe 30
Jede Turingmaschine kann durch {1,0}° Dargestellt werden. und diese Menge ist lauf Aufgabe 28 abzählbar.


## [Aufgabe 31](KuB-Uebungen-gesamt.pdf#page=9&selection=74,0,74,10|KuB-Uebungen-gesamt, page 9)


| ... | B   | B   | $$a_{1}$$ | $$a_{2}$$ | $$a_{1}$$ | B   | B   | ... |
| --- | --- | --- | --------- | --------- | --------- | --- | --- | --- |

|           | $$t_{0}$$ | $$t_{1}$$ | $$t_{2}$$ | $$t_{3}$$ | $$t_{4}$$ | $$t_{5}$$ | $$t_{6}$$ | $$t_{7}$$ |
| --------- | --------- | --------- | --------- | --------- | --------- | --------- | --------- | --------- |
| $$R_{1}$$ | 0         | 1         | 2         | 3         | 3         | 3         |           |           |
| $$R_{1}$$ | 0         | 0         | 0         | 0         | 1         | 1         |           |           |
| $$R_{1}$$ | 1         | 1         | 1         | 1         | 1         | 1         |           |           |
| $$R_{1}$$ | 2         | 2         | 1         | 1         | 1         | 1         |           |           |
| $$R_{1}$$ | 1         | 1         | 1         | 1         | 1         | 1         |           |           |
| $$R_{1}$$ | 3         | 3         | 3         | 3         | 1         | 1         |           |           |
| $$R_{1}$$ | 3         | 3         | 3         | 3         | 3         | 3         |           |           |



## [Aufgabe 32](KuB-Uebungen-gesamt.pdf#page=9&selection=219,0,219,10|KuB-Uebungen-gesamt, page 9)
Es existiert ein Zustand in dem Spieler x durch perfektes Spielen auf jeden Fall gewinnt.
(am einfachsten der Zustand wo noch ein Plättchen für eine volle reihe fehlt)





## [Aufgabe 33](KuB-Uebungen-gesamt.pdf#page=10&selection=14,0,14,10|KuB-Uebungen-gesamt, page 10)
Weil beim prüfen müssten wir alle stellen von Pi prüfen. Aber Pi hat unendlich viele Nachkommastellen. Somit würde die Bestätigung "Nein, existiert nicht" niemals erreich werden. 
Somit, wenn wir was finden bekommen wir eine Antwort. Bei nein würden wir nie ein Ergebnis bekommen.

machmal gibt es ein Ergebnis, manchmal nicht -> Semi-Entscheidbar


# Übung 8

## [Aufgabe 34](KuB-Uebungen-gesamt.pdf#page=11&selection=18,0,18,10|KuB-Uebungen-gesamt, page 11)

DTM = linkestes Zeichen einlesen -> rechtestes Zeichen vergleichen -> loop
"von außen nach innen"

NTM = Mitte raten und bis dahin alle Werte auf zweites Band kopieren -> beim weiterlaufen 2. Band rückwärts laufen lassen und vergleichen.

Überführungsfunktion:
$$
\begin{array} \\
\delta(q_{0}, B, B) = & \{ (q_{3}, (B, N), (B, N)) \} \\
\delta(q_{0}, 0, B) = & \{ (q_{1}, (0, N), (B, N)) \} \\
\delta(q_{0}, 1, B) = & \{ (q_{1}, (1, N), (B, N)) \} \\
  \\
\delta(q_{1}, 0, B) = & \{ (q_{1}, (0, R), (0, R)) \space , \space (q_{2}, (0, N), (B, L)) \} \\
\delta(q_{1}, 1, B) = & \{ (q_{1}, (1, R), (1, R) \space , \space (q_{2}, (1, N), (B, L)) \} \\
\\
\delta(q_{2}, 0, 0) = & \{ (q_{2}, (0, R), (0, L)) \} \\
\delta(q_{2}, 1, 1) = & \{ (q_{2}, (1, R), (1, L)) \} \\
\delta(q_{2}, B, B) = & \{ (q_{3}, (B, R), (B, L)) \}
\end{array}
$$


## [Aufgabe 35](KuB-Uebungen-gesamt.pdf#page=11&selection=61,0,61,10|KuB-Uebungen-gesamt, page 11)




## [Aufgabe 36](KuB-Uebungen-gesamt.pdf#page=11&selection=110,0,110,10|KuB-Uebungen-gesamt, page 11)

### a)
Wir gehen über jeden Knoten und raten die Farbe -> überprüfen, ob geratene Farben stimmt

### b)
Wir raten 2 Zahlen zwischen 1 und n -> multipilzieren diese und schauen dann

### c)
Wir raten, bei welchem Knoten wir anfangen -> Raten wir wo wir weitergehen -> unterbrechen, wenn bereits besucht / terminieren, wenn wir n knoten besucht haben

alt:
Wir raten die Reihenfolge -> schauen dann ob es die gibt

### d)
µ raten und schauen ob alpha richtig ist



## [Aufgabe 37](KuB-Uebungen-gesamt.pdf#page=11&selection=203,0,203,10|KuB-Uebungen-gesamt, page 11)

c und d folgen aus a und b

???



# [Übung 9 Berechenbarkeit](KuB-Uebungen-gesamt.pdf#page=13&selection=14,0,15,1|KuB-Uebungen-gesamt, page 13)


## [Aufgabe 38](KuB-Uebungen-gesamt.pdf#page=13&selection=147,0,147,11|KuB-Uebungen-gesamt, page 13)

Lösungsidee:
$$
\begin{array} \\
H = & \{ \langle M \rangle w|M \text{ hält auf } w \} \\
H = & \{ w\#x|T_{w} \text{hält auf x} \}  ,w=\text{code}(T_{w})
\end{array}
$$






# [Übung 10: Komplexitätstheorie (1)](KuB-Uebungen-gesamt.pdf#page=14&selection=16,0,16,19|KuB-Uebungen-gesamt, page 14)


## [Aufgabe 40](KuB-Uebungen-gesamt.pdf#page=14&selection=18,0,18,11|KuB-Uebungen-gesamt, page 14)

L(T) ist entscheidbar, weil wir nach jedem Wort irgendwann aufhören



## [Aufgabe 41](KuB-Uebungen-gesamt.pdf#page=14&selection=73,0,73,10|KuB-Uebungen-gesamt, page 14)

- Wenn wir die kürzeste Rundreise kennen kennen wir auch die Kosten dieser Reise
- Wenn wir alle Kanten k einzeln weglöschen und dann den Algorithmus A für die kürzeste Rundreise laufenlassen haben wir k*o(A) immer noch polynomiellen Aufwand
- Nehme die Kosten aller Kanten als MAX-Wert an und suche dann binärbaum-artig nach den Kosten der kürzesten Rundreisen


## [Aufgabe 42](KuB-Uebungen-gesamt.pdf#page=14&selection=171,0,171,10|KuB-Uebungen-gesamt, page 14)

a)
$$
\{ \langle T \rangle w \space | \space w \in L(T) \text{ und } t_{T(w)} \leq|w| \}
$$
b)
Ist in P weil durch die Zeitschranke $$t_{T(w)}$$ beenden wir auch, wenn wir normal nicht anhalten würde





# [Übung 11: Komplexitätstheorie (2)](KuB-Uebungen-gesamt.pdf#page=15&selection=16,0,16,19|KuB-Uebungen-gesamt, page 15)


## [Aufgabe 43](KuB-Uebungen-gesamt.pdf#page=15&selection=18,0,18,10|KuB-Uebungen-gesamt, page 15)

