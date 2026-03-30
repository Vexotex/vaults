# Ablauf vom Lösen einer DGL 1. Ordnung
1. DGL in Normalform umwandeln
2. Allgemeine Homogene Lösung aus Formelsammlung bestimmen

Falls es eine Anregung gibt:
 3. Ansatz der partikulären Lösung auswählen 
 4. Ansatz als unbekannte Funktion und Anregung als Anregung in die DGL einsetzen
 5. Konstanten der partikulären Lösung bestimmen und einsetzen

Danach:
6. homogene und partikuläre Lösung addieren
   $y = y_{h} + y_{p}$
   $y_{p} = 0$ wenn es keine Anregung gibt
7. Durch einsetzten der Anfangswerte die Konstanten bestimmen
8. Gesamtlösung nochmal schön aufschreiben

## Beispiel

Wir benötigen eine homogene DGL 1. oder 2. Ordnung mit Konstanten Koeffizienten

$$
\begin{array} \\
\text{ausgangsformel} & &  2 \dot{y} + 6 y = 0 \\
\text{1. Normalform}  & \Leftrightarrow &  \dot{y} + 3y = 0
\end{array}
$$

# Ablauf vom Lösen einer DGL 2. Ordnung
1. DGL in Normalform umwandeln
2. charakteristische Polynom Aufstellen
3. Nullstellen des ch. Polynom bestimmen (Eigenwerte)
4. Anhand der Eigenwerte Ansatz für die homogene Lösung auswählen

Falls es eine Anregung gibt:
 5. Ansatz der partikulären Lösung auswählen 
 6. Ansatz als unbekannte Funktion und Anregung als Anregung in die DGL einsetzen
 7. Konstanten der partikulären Lösung bestimmen und einsetzen

Danach:
8. homogene und partikuläre Lösung addieren
   $y = y_{h} + y_{p}$
   $y_{p} = 0$ wenn es keine Anregung gibt
9. Durch einsetzten der Anfangswerte die Konstanten bestimmen
10. Gesamtlösung nochmal schön aufschreiben

## Beispiel

$$
\begin{array} \\
  & & 2 \ddot{y} + 6 \dot{y} = 0 \\
1. & \Leftrightarrow &  \ddot{y} + 3 \dot{y} = 0 \\
2. &  &  \ddot{y} \to \lambda^{2} \\
 &  & \dot{y} \to \lambda \\
 &  & y \to 1 \\
 & \Rightarrow  & \lambda^{2} + 3 \lambda = 0 \\
3. & \Leftrightarrow & \lambda(\lambda+3) = 0 \\
 & \Rightarrow & \lambda_{1} = 0 \quad \lambda_{2}=-3 \\
4. & 
\end{array}
$$
