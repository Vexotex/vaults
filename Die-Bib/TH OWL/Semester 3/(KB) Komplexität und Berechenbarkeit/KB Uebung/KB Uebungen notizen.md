

## [Aufgabe 19](KuB Uebungen gesamt.pdf#page=6&selection=23,0,24,1|KuB Uebungen gesamt, page 6)

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

# [Aufgabe 20](KuB Uebungen gesamt.pdf#page=7&selection=14,0,14,10|KuB Uebungen gesamt, page 7)

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

# [Aufgabe 21](KuB Uebungen gesamt.pdf#page=7&selection=45,0,45,11|KuB Uebungen gesamt, page 7)

|     | 0          | 1          | B          |
| --- | ---------- | ---------- | ---------- |
| q0  | (q1, 0, R) | (q1, 1, R) | (q0, B, L) |
| q1  | (q1, 0, R) | (q1, 1, R) | (q2, B, L) |
| q2  | (q2, 1, L) | (q3, 0, L) | -          |
| q3  | (q3, 0, L) | (q3, 1, L) | (q4, B, R) |
| q4  | (q4, 0, N) | (q4, 1, N) | -          |
