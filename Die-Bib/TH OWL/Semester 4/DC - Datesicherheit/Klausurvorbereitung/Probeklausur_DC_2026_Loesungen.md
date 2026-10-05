# Lösungen zur Probeklausur Datensicherheit (DC) – SoSe 2026

Alle Zahlenergebnisse wurden per Skript (Python) nachgerechnet. Quellenangaben beziehen sich auf die Studienhefte DC-01, DC-02, DC-03 (Ordner `/Skript`) und die Folien in `/Vorlesungen 26`. Inhalte, die nicht in diesen Unterlagen stehen, sind mit **[EXTERN]** markiert.

## Ergebnisübersicht (zum schnellen Abgleich)

| Aufgabe | Ergebnis                                                                                             |
| ------- | ---------------------------------------------------------------------------------------------------- |
| 1 (a)   | det(M₁₂) = 274 ≡ 14, ggT(14, 26) = 2 → nicht invertierbar                                            |
| 1 (b)   | K = ((5, 17), (8, 3))                                                                                |
| 1 (c)   | K⁻¹ = ((9, 1), (2, 15)), Klartext **TRESOR CODE ACHT**                                               |
| 1 (d)   | mindestens 9 Buchstaben (3 Blöcke)                                                                   |
| 2 (a)   | m₂ = `46 72 20 31 37 3A 33 30` = **"Fr 17:30"**                                                      |
| 2 (b)   | Byte 4: `D0` → `D1`; bei CBC: Byte 4 des IV ⊕ `01`, keine Nebenwirkung                               |
| 2 (c)   | m₁, m₄…m₉ fehlerfrei; m₂ zerstört; m₃ genau ein Bit falsch                                           |
| 2 (d)   | 63 Blöcke, 8 Byte vom letzten; Zähler `…FE`, `…FF`, `00…00`, `00…01`                                 |
| 2 (e)   | ≤ 2⁻³³ ≈ 1,2 · 10⁻¹⁰; max. 2³⁸ Byte = 256 GiB                                                        |
| 3 (a)   | T(62,8) ≈ 4,9 · 10⁷ s ≈ 1,6 a; T(95,10) ≈ 1,4 · 10¹³ s ≈ 4,3 · 10⁵ a; mit c = 600 000: ≈ 9,4 · 10⁵ a |
| 3 (b)   | r(0,5) ≈ 8,5 · 10¹⁶; r(0,99) ≈ 2,2 · 10¹⁷; ≈ 2,7 a; ≈ 1,9 · 10¹⁸ Byte; Urbild ≈ 3,6 · 10³³           |
| 3 (c)   | 59 Personen genügen (exakt minimal: 57)                                                              |
| 4 (a)   | max ≈ 7,2 · 10⁷ s ≈ 834 d ≈ 2,3 a; Mittel ≈ 1,1 a                                                    |
| 4 (b)   | ≈ 2⁵⁷ Operationen (≈ 4,6 a); 2⁶⁰ Byte ≈ 1,15 · 10¹⁸ Byte; naiv ≈ 1,6 · 10¹⁷ a                        |
| 4 (c)   | r=1: 2⁴⁸; r=2: 2⁻¹⁶ ≈ 1,5 · 10⁻⁵; r=3: 2⁻⁸⁰; P ≈ 1,5 · 10⁻⁵                                          |
| 4 (d)   | 3 Paare; bei 2 Paaren P ≈ 1 − e⁻¹ ≈ 0,63                                                             |
| 5       | n = 7313, φ = 7140, μₙ = 3570, e = 11, d = 2921, d′ = 6491, d₁ = 51, d₂ = 65, q\* = 20, **m = 4242** |
| 6       | v = 25344 = 99 · 2⁸, 2⁹⁹ = 7477 → 6854 → 5163 → **6498** → 1; **p, q = 89, 97**                      |
| 7       | e_A = **157**, s = **189**                                                                           |
| 8 (b)   | k₁ = `34 78 E2 0B D0 85 AD 79`, k₂ = `68 F1 C4 17 A1 0B 5A F2`                                       |
| 8 (c)   | 373 / 342 / 318 Byte                                                                                 |
| 8 (d)   | `82 04 A6`; 1194 Byte; 1592 Zeichen                                                                  |

---

## Aufgabe 1 – Hill-Verfahren (12 P)

Buchstaben → Zahlen: T=19, R=17, E=4, S=18, O=14, R=17. Geheimtextblöcke: UV = (20, 21), OI = (14, 8), VH = (21, 7), OG = (14, 6), FK = (5, 10), IG = (8, 6), UJ = (20, 9).

Ansatz: Werden die Klartextblöcke als Spalten in eine Matrix M und die zugehörigen Geheimtextblöcke als Spalten in C geschrieben, gilt **K · M = C**. Ist M über ℤ₂₆ invertierbar, folgt **K = C · M⁻¹**.

### (a) (2 P)

Blöcke 1 und 2: TR = (19, 17), ES = (4, 18):

M₁₂ = ((19, 4), (17, 18)),  det(M₁₂) = 19·18 − 4·17 = 342 − 68 = 274 ≡ **14** (mod 26).

ggT(14, 26) = 2 ≠ 1, also ist det(M₁₂) ∉ ℤ₂₆\* und M₁₂ nicht invertierbar. Die Gleichung K · M₁₂ = C₁₂ bestimmt K deshalb nicht eindeutig. Es reicht nicht, dass det ≠ 0 ist – über ℤ₂₆ muss die Determinante **teilerfremd zu 26** sein.

*Bewertung:* 1 P Determinante, 1 P korrekte Begründung über ggT/ℤ₂₆\*.

### (b) (5 P)

Blöcke 1 und 3: TR = (19, 17), OR = (14, 17), zugehörig UV = (20, 21), VH = (21, 7):

M = ((19, 14), (17, 17)),  C = ((20, 21), (21, 7))

det(M) = 19·17 − 14·17 = 17·5 = 85 ≡ **7** (mod 26), ggT(7, 26) = 1 ✓

7⁻¹ in ℤ₂₆ mit erweitertem Euklid:

| 26 | 7 | …, a, b | q |
|---|---|---|---|
| 1 | 0 | 26 | |
| 0 | 1 | 7 | 3 |
| 1 | −3 | 5 | 1 |
| −1 | 4 | 2 | 2 |
| 3 | −11 | 1 | |

3·26 + (−11)·7 = 1 → 7⁻¹ = −11 ≡ **15**. (Probe: 7·15 = 105 = 4·26 + 1 ✓)

M⁻¹ = det(M)⁻¹ · adj(M) = 15 · ((17, −14), (−17, 19)) = ((255, −210), (−255, 285)) ≡ **((21, 24), (5, 25))**

K = C · M⁻¹ = ((20·21 + 21·5, 20·24 + 21·25), (21·21 + 7·5, 21·24 + 7·25)) = ((525, 1005), (476, 679)) ≡ **((5, 17), (8, 3))**

Probe mit Block 2: K · (4, 18)ᵀ = (5·4 + 17·18, 8·4 + 3·18) = (326, 86) ≡ (14, 8) = **OI** ✓

*Bewertung:* 1 P richtige Blockwahl, 1 P det/Inverses, 1 P M⁻¹, 1 P K, 1 P Probe.

### (c) (4 P)

det(K) = 5·3 − 17·8 = −121 ≡ **9**, 9⁻¹ ≡ **3** (9·3 = 27 ≡ 1)

K⁻¹ = 3 · ((3, −17), (−8, 5)) = ((9, −51), (−24, 15)) ≡ **((9, 1), (2, 15))**

| Geheimtext | Vektor | K⁻¹ · c | mod 26 | Klartext |
|---|---|---|---|---|
| OG | (14, 6) | (132, 118) | (2, 14) | CO |
| FK | (5, 10) | (55, 160) | (3, 4) | DE |
| IG | (8, 6) | (78, 106) | (0, 2) | AC |
| UJ | (20, 9) | (189, 175) | (7, 19) | HT |

Klartext: **TRESORCODEACHT** („Tresorcode acht“).

*Bewertung:* 1 P K⁻¹, 3 P Entschlüsselung (je Block 0,75 P).

### (d) (1 P)

Für eine (3,3)-Matrix werden mindestens **3 Blöcke = 9 Klartextbuchstaben** benötigt (9 Unbekannte). Mehr sind nötig, wenn die aus den bekannten Blöcken gebildete Matrix M keine zu 26 teilerfremde Determinante hat – wie in (a) gesehen.

**Quellen:** DC-01, Abschn. 1.4, Beispiel 1.6 (Hill-Verfahren), Frage 7; Abschn. 2.3, Gleichung (2.11) (A⁻¹ = det(A)⁻¹ · adj(A)), Frage 12, Frage 13 (Known-Plaintext-Angriff); Abschn. 2.4, Beispiel 2.6 (EEA-Tabelle).
**Bezug Altklausur:** 2021, Aufgabe 1 (Hill-Verschlüsselung mit (3,3)-Matrix) – hier umgekehrt als Angriff.

---

## Aufgabe 2 – Betriebsmodi und Stromverschlüsselung (14 P)

### (a) (4 P)

Im CTR-Modus gilt cᵢ = mᵢ ⊕ zᵢ mit zᵢ = E_k(Ctr ⊞ (i−1)). Bei gleichem k und gleichem Ctr ist der Schlüsselstrom z identisch:

c₁ ⊕ c₂ = (m₁ ⊕ z) ⊕ (m₂ ⊕ z) = m₁ ⊕ m₂  ⇒  **m₂ = c₁ ⊕ c₂ ⊕ m₁**

|         | Byte 1 | 2      | 3      | 4      | 5      | 6      | 7      | 8      |
| ------- | ------ | ------ | ------ | ------ | ------ | ------ | ------ | ------ |
| c₁      | 77     | F3     | 71     | D0     | 8E     | 1E     | BD     | 5F     |
| c₂      | 7C     | EE     | 71     | D1     | 80     | 1E     | BE     | 5F     |
| c₁ ⊕ c₂ | 0B     | 1D     | 00     | 01     | 0E     | 00     | 03     | 00     |
| m₁      | 4D     | 6F     | 20     | 30     | 39     | 3A     | 30     | 30     |
| **m₂**  | **46** | **72** | **20** | **31** | **37** | **3A** | **33** | **30** |

m₂ = **"Fr 17:30"** (0x46 = 'F', 0x72 = 'r', 0x20 = ' ', 0x31 = '1', 0x37 = '7', 0x3A = ':', 0x33 = '3', 0x30 = '0').

*Bewertung:* 1 P Begründung c₁ ⊕ c₂ = m₁ ⊕ m₂, 2 P Hex-Rechnung, 1 P ASCII.

### (b) (3 P)

(i) Nur das 4. Zeichen ändert sich: '0' (0x30) → '1' (0x31), Δ = 0x01. Da mᵢ = cᵢ ⊕ zᵢ, wirkt eine XOR-Änderung von c direkt bitgenau auf m: Byte 4 von c₁: `D0` ⊕ `01` = **`D1`**, also c₁′ = `77 F3 71 D1 8E 1E BD 5F`.

(ii) Im CBC-Modus gilt m₁ = D_k(c₁) ⊕ IV. Der Angreifer muss **Byte 4 des IV mit 0x01 XOR-verknüpfen**. Der IV geht nur in m₁ ein, daher gibt es **keine Nebenwirkungen**. (Würde er einen späteren Block mᵢ angreifen, müsste er cᵢ₋₁ manipulieren – dann wäre mᵢ₋₁ komplett zerstört.) Deshalb muss auch der IV integritätsgeschützt sein; Verschlüsselung allein schützt nicht vor gezielter Manipulation.

*Bewertung:* 1 P (i), 1 P IV, 1 P Nebenwirkung/Begründung.

### (c) (2 P)

CBC-Entschlüsselung: mᵢ = D_k(cᵢ) ⊕ cᵢ₋₁. Ein Bitfehler in c₂ wirkt auf:
- **m₂** = D_k(c₂′) ⊕ c₁: vollständig zerstört (Blockchiffre, Diffusion)
- **m₃** = D_k(c₃) ⊕ c₂′: genau das entsprechende Bit ist gekippt, sonst korrekt

Fehlerfrei lesbar: **m₁, m₄, …, m₉** (und m₃ bis auf ein Bit).

### (d) (3 P)

(i) r = ⌈l / n⌉ = ⌈1000 / 16⌉ = **63** Blöcke; vom letzten Block werden ((l−1) mod n) + 1 = (999 mod 16) + 1 = 7 + 1 = **8** Byte verwendet.

(ii) Ctr ⊞ i ist die Addition modulo 2¹²⁸:
- Block 1: `FFFFFFFF FFFFFFFF FFFFFFFF FFFFFFFE`
- Block 2: `FFFFFFFF FFFFFFFF FFFFFFFF FFFFFFFF`
- Block 3: `00000000 00000000 00000000 00000000`
- Block 4: `00000000 00000000 00000000 00000001`

(iii) Laut Skript müssen **alle** Werte Ctr, Ctr ⊞ 1, …, Ctr ⊞ (r−1) Nonce-Werte sein. Überlappen die Zählerbereiche zweier Nachrichten (z. B. Nachricht A mit Ctr = 5 und 10 Blöcken, Nachricht B mit Ctr = 8), werden Schlüsselstromblöcke wiederverwendet – mit denselben Folgen wie in (a).

### (e) (2 P)

Satz 4.3 (i) mit n = 2⁹⁶ möglichen Nonces und r = 2³² Nachrichten:

c(n, r) ≤ r(r−1) / (2n) < 2⁶⁴ / 2⁹⁷ = 2⁻³³ ≈ **1,16 · 10⁻¹⁰**

Der ChaCha20-Schlüsselstrom ist auf **2³⁸ Byte = 256 GiB** begrenzt (32-Bit-Blockzähler, 64 Byte pro Block).

**Quellen:** DC-02, Abschn. 1.3 (Nonces), Abschn. 1.4 (ChaCha20, Länge ≤ 2³⁸ Byte); Abschn. 2.3 (CBC S. 27, Frage 6, CTR mit Warnung zu Ctr ⊞ i, Frage 10, Abb. 2.9 mit Ctr = FF…FE); Abschn. 4.4.2, Satz 4.3.
**Bezug Altklausur:** 2008, Aufgabe 3 (gezielte Bitmanipulation) und Aufgabe 5 (Zweck des IV bei CBC).

---

## Aufgabe 3 – Brute-Force (12 P)

### (a) (5 P)

Die maximale Zeit skaliert mit der Größe des Passwortraums: T(z, l) = T(26, 6) · zˡ / 26⁶, mit 26⁶ = 308 915 776.

(i)
- T(62, 8) = 70 s · 62⁸ / 26⁶ = 70 s · 2,183 · 10¹⁴ / 3,089 · 10⁸ ≈ 70 s · 7,07 · 10⁵ ≈ **4,95 · 10⁷ s ≈ 573 Tage ≈ 1,6 Jahre**
- T(95, 10) = 70 s · 95¹⁰ / 26⁶ = 70 s · 5,99 · 10¹⁹ / 3,089 · 10⁸ ≈ **1,36 · 10¹³ s ≈ 4,3 · 10⁵ Jahre**

(ii) Jeder Test braucht jetzt c = 600 000 Hashberechnungen: 4,95 · 10⁷ s · 6 · 10⁵ ≈ **2,97 · 10¹³ s ≈ 9,4 · 10⁵ Jahre**.

(iii) Der Salt verhindert **Wörterbuchangriffe mit vorberechneten Listen** (Hashwerte schwacher Passwörter einmal berechnen und für alle Nutzer nachschlagen) und dass gleiche Passwörter verschiedener Nutzer gleiche Einträge erzeugen (vgl. Frage 28). Der Salt steht im Klartext in der Passwortdatei; beim Angriff auf **ein** Passwort wird er einfach mitgehasht – der Suchraum bleibt gleich groß. Den Einzelangriff verlangsamt nur der Iteration Count.

*Bewertung:* (i) 2 P, (ii) 1 P, (iii) 2 P.

### (b) (5 P)

n = 2¹¹² ≈ 5,19 · 10³³.

(i) Satz 4.3 (iv): c(n, r) ≥ p₀, falls r ≥ √(−2 · ln(1 − p₀) · n + 1/4) + 1/2

- p = 0,5: −2 ln 0,5 = ln 4 ≈ 1,386; r ≥ √(1,386 · 5,19 · 10³³) ≈ **8,5 · 10¹⁶** (≈ 1,18 · 2⁵⁶)
- p = 0,99: −2 ln 0,01 ≈ 9,210; r ≥ √(9,210 · 5,19 · 10³³) ≈ **2,2 · 10¹⁷**

(Der Summand 1/4 bzw. 1/2 ist bei dieser Größenordnung vernachlässigbar; Satz 4.3 (iii) liefert dieselben Werte.)

(ii) 8,48 · 10¹⁶ / 10⁹ s⁻¹ ≈ 8,5 · 10⁷ s ≈ **2,7 Jahre** (für p = 0,99 etwa 6,9 Jahre).

(iii) 8,48 · 10¹⁶ · 22 Byte ≈ **1,9 · 10¹⁸ Byte** (≈ 1,9 Exabyte). Genau dieser Speicherbedarf ist die technische Voraussetzung, damit die Kollisionssuche mit nur ≈ √n Berechnungen gelingt (vgl. 2021, Aufgabe 3 (2)).

(iv) Satz 4.1 (iv): p ≥ 1/2, falls r ≥ ln(2) · n ≈ 0,693 · 5,19 · 10³³ ≈ **3,6 · 10³³** – also um den Faktor ≈ 4 · 10¹⁶ mehr als bei der Kollisionssuche.

*Bewertung:* (i) 2 P, (ii) 1 P, (iii) 1 P, (iv) 1 P.

### (c) (2 P)

Satz 4.3 (iv) mit n = 365, p₀ = 0,99:

r ≥ √(9,210 · 365 + 0,25) + 0,5 = √3361,8 + 0,5 ≈ 57,98 + 0,5 ≈ 58,48  ⇒  **r = 59 genügt**.

Nachweis mit der unteren Schranke aus Satz 4.3 (i):

c(365, 59) ≥ 1 − e^(−59·58 / 730) = 1 − e^(−4,688) ≈ 1 − 0,0092 = **0,9908 ≥ 0,99** ✓

(Zusatzinfo: Die exakte Formel aus Satz 4.2 liefert c(365, 57) ≈ 0,9901 und c(365, 56) ≈ 0,9883, das exakte Minimum ist also 57. Die Abschätzungen sind hinreichende Bedingungen.)

**Quellen:** DC-02, Abschn. 4.3, Frage 27 (T(26,6) = 70 s), Frage 28, Frage 29 (Salt, Iteration Count); Abschn. 4.4.1, Satz 4.1; Abschn. 4.4.2, Satz 4.2, Satz 4.3, Beispiel 4.8, Frage 31, Frage 32.
**Bezug Altklausur:** 2021, Aufgabe 3 (Kollisionssuche für ℤ₂¹³⁴, gleiche Formel).

---

## Aufgabe 4 – DES, 2DES, Meet-in-the-Middle, AES (10 P)

### (a) (2 P)

Jedes der 8 Schlüsselbytes muss ungerade Parität haben: 7 Bits frei wählbar, das 8. Bit ist festgelegt → 8 · 7 = **56 Bit**.

- maximal: 2⁵⁶ / 10⁹ s⁻¹ ≈ 7,21 · 10⁷ s ≈ **834 Tage ≈ 2,3 Jahre**
- im Mittel (Erwartungswert |𝒦|/2): ≈ **1,1 Jahre**

### (b) (3 P)

Angriff: Für alle k̃₁ ∈ 𝒦 wird E_k̃₁(m₁) berechnet und zusammen mit k̃₁ in einer nach dem Blockwert sortierten Tabelle abgelegt. Dann wird für alle k̃₂ der Wert D_k̃₂(c₁) berechnet und in der Tabelle nachgeschlagen („Treffen in der Mitte“, D_k̃₂(c₁) = E_k̃₁(m₁)). Jeder Treffer (k̃₁, k̃₂) ist ein Kandidat, der mit weiteren Paaren (mᵢ, cᵢ) geprüft wird.

- Aufwand: ≈ 2 · 2⁵⁶ = **2⁵⁷ ≈ 1,44 · 10¹⁷** DES-Operationen (+ Sortieren) → ≈ 1,44 · 10⁸ s ≈ **4,6 Jahre**
- Speicher: 2⁵⁶ · 16 Byte = **2⁶⁰ Byte ≈ 1,15 · 10¹⁸ Byte**
- Naiver Brute-Force auf 2DES: 2¹¹² ≈ 5,2 · 10³³ Operationen ≈ **1,6 · 10¹⁷ Jahre**

2DES ist also nur etwa doppelt so aufwendig wie DES, aber nicht 2⁵⁶-mal – deshalb Triple-DES.

### (c) (3 P)

Die 2E_(k̃₁,k̃₂) werden als zufällige Permutationen auf 𝓜 betrachtet. Erwartete Anzahl falscher Schlüsselpaare, die alle r Paare erfüllen: (K² − 1) / Mʳ mit K = 2⁵⁶, M = 2⁶⁴:

| r | (K² − 1) / Mʳ |
|---|---|
| 1 | 2¹¹² / 2⁶⁴ = **2⁴⁸ ≈ 2,8 · 10¹⁴** |
| 2 | 2¹¹² / 2¹²⁸ = **2⁻¹⁶ ≈ 1,5 · 10⁻⁵** |
| 3 | 2¹¹² / 2¹⁹² = **2⁻⁸⁰ ≈ 8,3 · 10⁻²⁵** |

Für r = 2: P(mindestens ein falsches Paar) ≈ 1 − e^(−2⁻¹⁶) ≈ **1,5 · 10⁻⁵** (≈ 2⁻¹⁶, da klein). Zwei Paare reichen also praktisch aus, drei ganz sicher.

### (d) (2 P)

Erwartete Zahl weiterer Schlüssel bei t Paaren: (2²⁵⁶ − 1) / 2¹²⁸ᵗ.
- t = 1: ≈ 2¹²⁸
- t = 2: ≈ **1** → Wahrscheinlichkeit für mindestens einen weiteren Schlüssel ≈ 1 − (1 − 2⁻²⁵⁶)^(2²⁵⁶) ≈ **1 − e⁻¹ ≈ 0,632** (Fall K = M aus Frage 22 (iii))
- t = 3: ≈ 2⁻¹²⁸ → **3 Paare** nötig

**Quellen:** DC-02, Abschn. 2.5 (DES, Paritätsbedingung, 3DES), Abschn. 2.6 (Meet-in-the-Middle, Abb. 2.16, Kommentar mit K²/Mʳ, Frage 14); DC-01, Abschn. 4.5, Frage 22.
**Bezug Altklausur:** 2008, Aufgabe 4 (Brute-Force auf DES).

---

## Aufgabe 5 – RSA mit CRT-Schlüssel (16 P)

### (a) (2 P)

n = 71 · 103 = **7313**

|ℤₙ\*| = φ(n) = (p−1)(q−1) = 70 · 102 = **7140**

μₙ = kgV(70, 102) = 70 · 102 / ggT(70, 102) = 7140 / 2 = **3570** (70 = 2·5·7, 102 = 2·3·17)

### (b) (2 P)

e muss in ℤᵥ\* liegen, also ggT(e, 3570) = 1 mit 3570 = 2 · 3 · 5 · 7 · 17. Alle Zahlen 2, …, 10 haben einen Primteiler aus {2, 3, 5, 7}. e = 1 ist trivial (c = m). Also **e = 11**, k_A,pub = **(7313, 11)**.

### (c) (3 P)

| 3570 | 11 | …, a, b | q |
|---|---|---|---|
| 1 | 0 | 3570 | |
| 0 | 1 | 11 | 324 |
| 1 | −324 | 6 | 1 |
| −1 | 325 | 5 | 1 |
| 2 | −649 | 1 | 5 |
| | | 0 | |

2 · 3570 + (−649) · 11 = 1 → d = −649 mod 3570 = **2921**

Probe: 11 · 2921 = 32 131 = 9 · 3570 + 1 ✓

### (d) (1 P)

d′ = 11⁻¹ mod 7140 = **6491** = 2921 + 3570, also **d′ ≡ d (mod μₙ)**. Beide funktionieren, weil e·d ≡ e·d′ ≡ 1 (mod kgV(p−1, q−1)) gilt, damit erfüllt r = e·d die Bedingungen (3.1) und (3.2) aus Satz 3.1, also z^(ed) = z für alle z ∈ ℤₙ.

### (e) (3 P)

- d₁ = d mod (p−1) = 2921 mod 70 = 2921 − 41·70 = **51**
- d₂ = d mod (q−1) = 2921 mod 102 = 2921 − 28·102 = **65**
- q\* = q⁻¹ mod p: 103 mod 71 = 32, EEA:

| 71 | 32 | …, a, b | q |
|---|---|---|---|
| 1 | 0 | 71 | |
| 0 | 1 | 32 | 2 |
| 1 | −2 | 7 | 4 |
| −4 | 9 | 4 | 1 |
| 5 | −11 | 3 | 1 |
| −9 | 20 | 1 | |

→ q\* = **20** (Probe: 32 · 20 = 640 = 9·71 + 1 ✓)

k_A,priv = (p, q, d₁, d₂, q\*) = **(71, 103, 51, 65, 20)**

### (f) (5 P)

Reduktion: c mod p = 1890 − 26·71 = **44**, c mod q = 1890 − 18·103 = **36**

**a₁ = 44⁵¹ mod 71**, 51 = 110011₂:

| i | 0 | 1 | 2 | 3 | 4 | 5 |
|---|---|---|---|---|---|---|
| 44^(2ⁱ) mod 71 | 44 | 19 | 6 | 36 | 18 | 40 |
| Bit eᵢ | 1 | 1 | 0 | 0 | 1 | 1 |

a₁ = 44 · 19 · 18 · 40: 44·19 = 836 ≡ 55; 55·18 = 990 ≡ 67; 67·40 = 2680 ≡ **53**

**a₂ = 36⁶⁵ mod 103**, 65 = 1000001₂:

| i | 0 | 1 | 2 | 3 | 4 | 5 | 6 |
|---|---|---|---|---|---|---|---|
| 36^(2ⁱ) mod 103 | 36 | 60 | 98 | 25 | 7 | 49 | 32 |
| Bit eᵢ | 1 | 0 | 0 | 0 | 0 | 0 | 1 |

a₂ = 36 · 32 = 1152 ≡ **19**

**Zusammensetzen** (Folie „RSA CRT private key“): m = ((a₁ − a₂) · q\* mod p) · q + a₂

(53 − 19) · 20 = 680 ≡ 680 − 9·71 = 41 (mod 71)  ⇒  m = 41 · 103 + 19 = 4223 + 19 = **4242**

Probe: 4242¹¹ mod 7313 = 1890 ✓ (4242² ≡ 4584, 4242⁴ ≡ 2807, 4242⁸ ≡ 3148; 4242 · 4584 · 3148 ≡ 1890)

*Bewertung:* 1 P Reduktionen, je 1,5 P a₁ und a₂ (mit Quadratfolge), 1 P Zusammensetzen.

**Quellen:** DC-03, Abschn. 1.1, Satz 1.3 (μₙ); Abschn. 1.3, Satz 1.9 (CRT), Frage 11 (μₙ = kgV); Abschn. 2.1 (Quadrieren und Multiplizieren, Beispiel 2.4); Kap. 3, Satz 3.1; Abschn. 3.1 (RSA-Schlüsselpaar, Beispiel 3.2 mit EEA-Tabelle); Folien `260716_dc_03_26.pdf`, Folie 415–418 (RSA-CRT-Schlüssel (p, q, d₁, d₂, q\*)).
**Bezug Altklausur:** 2021, Aufgabe 4 (|ℤₙ\*|, μₙ, Inverse, CRT) und Aufgabe 5 (RSA, kleinstes e, Quadratfolge); 2008, Aufgabe 7 und 8.

---

## Aufgabe 6 – Faktorisierung bei bekanntem d (8 P)

### (a) (6 P)

v := e · d − 1 = 5 · 5069 − 1 = **25 344**. Wegen e·d ≡ 1 (mod kgV(p−1, q−1)) ist v ein Vielfaches von kgV(p−1, q−1) – die Voraussetzung (1.12) von Satz 1.13.

(1) Größter ungerader Teiler: 25 344 = 12 672 · 2 = … = **99 · 2⁸** → u = 99, i = 8

(2)/(3) a = 2, ggT(8633, 2) = 1 → weiter

(4) aᵘ = 2⁹⁹ mod 8633, 99 = 1100011₂:

| j | 0 | 1 | 2 | 3 | 4 | 5 | 6 |
|---|---|---|---|---|---|---|---|
| 2^(2ʲ) mod 8633 | 2 | 4 | 16 | 256 | 5105 | 6631 | 2292 |
| Bit | 1 | 1 | 0 | 0 | 0 | 1 | 1 |

2 · 4 = 8; 8 · 6631 = 53 048 ≡ 1250; 1250 · 2292 = 2 865 000 ≡ **7477** ≠ 1 → weiter

(5) Fortgesetztes Quadrieren:

| | Wert mod 8633 |
|---|---|
| a^u | 7477 |
| a^(2u) | 6854 |
| a^(4u) | 5163 |
| a^(8u) | **6498** |
| a^(16u) | 1 |

(6) a^(8u) = 6498 ≠ −1 = 8632 → Erfolg: 6498 ist eine Involution ≠ ±1 (Satz 1.11)

(7) ggT(8633, 6498 + 1) = ggT(8633, 6499) = **97** (6499 = 97 · 67)
  ggT(8633, 6498 − 1) = ggT(8633, 6497) = **89** (6497 = 89 · 73)

Probe: 89 · 97 = 8633 ✓

*Bewertung:* 1 P v, u, i; 2 P 2⁹⁹; 1 P Quadratfolge; 1 P Begründung (≠ −1, Satz 1.11); 1 P ggT-Rechnungen.

### (b) (2 P)

Schlechter Vorschlag. Mit dem bekannten d kann **jeder** n wie in (a) faktorisieren. Kennt man p und q, berechnet man zu jedem neuen öffentlichen Exponenten e′ sofort d′ = e′⁻¹ mod kgV(p−1, q−1). Bob muss **neue Primzahlen p, q** (also einen neuen Modul n) erzeugen.

**Quellen:** DC-03, Abschn. 1.4, Satz 1.11, Satz 1.12, Satz 1.13 (Algorithmus, S. 20–22); Abschn. 3.1 (Kommentar: aus d lässt sich v = d·e − 1 berechnen, dann Satz 1.13).
**Bezug Altklausur:** keine direkte Entsprechung – bewusst ergänzt, weil Satz 1.13 der „Rückweg“ zum RSA-Schlüssel ist.

---

## Aufgabe 7 – Diffie-Hellman und Pohlig-Hellman (14 P)

### (a) (1 P)

o(2) teilt |ℤ₂₁₁\*| = 210 (Satz 1.2 (i)). Wäre o(2) < 210, so wäre o(2) ein Teiler von 210/pᵢ für ein pᵢ ∈ {2, 3, 5, 7}, also 2^(210/pᵢ) = 1. Laut Hinweis sind 2¹⁰⁵, 2⁷⁰, 2⁴², 2³⁰ alle ≠ 1 ⇒ **o(2) = 210**, g = 2 ist primitiv.

### (b) (7 P)

Gesucht: x mit 2ˣ = A = 152. Für jeden Primteiler pᵢ: mᵢ = 210/pᵢ, gᵢ = g^(mᵢ), aᵢ = A^(mᵢ), xᵢ mit gᵢ^(xᵢ) = aᵢ, vᵢ = mᵢ⁻¹ mod pᵢ.

Quadratfolge von 152 in ℤ₂₁₁ (einmal berechnen, für alle aᵢ nutzen):

| k | 0 | 1 | 2 | 3 | 4 | 5 | 6 |
|---|---|---|---|---|---|---|---|
| 152^(2ᵏ) mod 211 | 152 | 105 | 53 | 66 | 136 | 139 | 120 |

- a₁ = 152¹⁰⁵, 105 = 1101001₂: 152 · 66 · 139 · 120 → 115 → 160 → **210**
- a₂ = 152⁷⁰, 70 = 1000110₂: 105 · 53 · 120 → 79 → **196**
- a₃ = 152⁴², 42 = 101010₂: 105 · 66 · 139 → 178 → **55**
- a₄ = 152³⁰, 30 = 11110₂: 105 · 53 · 66 · 136 → 79 → 150 → **144**

| pᵢ | mᵢ | gᵢ | aᵢ | Potenzen von gᵢ | xᵢ | mᵢ mod pᵢ | vᵢ |
|---|---|---|---|---|---|---|---|
| 2 | 105 | 210 | 210 | 1, 210 | **1** | 1 | 1 |
| 3 | 70 | 196 | 196 | 1, 196, 14 | **1** | 1 | 1 |
| 5 | 42 | 107 | 55 | 1, 107, **55**, 188, 71 | **2** | 2 | 3 |
| 7 | 30 | 171 | 144 | 1, 171, 123, **144**, … | **3** | 2 | 4 |

(z. B. 107² = 11 449 = 54 · 211 + 55; 171² ≡ 123, 123 · 171 ≡ 144)

x = Σ vᵢ · mᵢ · xᵢ mod 210 = (1·105·1 + 1·70·1 + 3·42·2 + 4·30·3) mod 210 = (105 + 70 + 252 + 360) mod 210 = 787 mod 210 = **157**

Probe: 2¹⁵⁷ mod 211 = 152 ✓ → **e_A = 157**

*Bewertung:* 2 P aᵢ (Quadratfolge), 2 P xᵢ, 1 P vᵢ, 2 P Zusammensetzen.

### (c) (4 P)

s = B^(e_A) = 194¹⁵⁷ mod 211, 157 = 10011101₂:

| k | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |
|---|---|---|---|---|---|---|---|---|
| 194^(2ᵏ) mod 211 | 194 | 78 | 176 | 170 | 204 | 49 | 80 | 70 |
| Bit | 1 | 0 | 1 | 1 | 1 | 0 | 0 | 1 |

194 · 176 ≡ 173; 173 · 170 ≡ 81; 81 · 204 ≡ 66; 66 · 70 ≡ **189**

**s = 189**

### (d) (2 P)

Bei einer sicheren Primzahl ist n − 1 = 2 · q mit einer großen Primzahl q. Die Pohlig-Hellman-Reduktion zerlegt das DL-Problem nur in Teilprobleme der Ordnung 2 und q – das Teilproblem der Ordnung q ist praktisch genauso schwer wie das ursprüngliche. Hier war n − 1 = 2·3·5·7 „glatt“, deshalb waren nur Teilprobleme mit höchstens 7 Möglichkeiten zu lösen.

BSGS: m̃ = ⌈√210⌉ = **15** Tabelleneinträge, höchstens 2 · 15 = 30 Potenzberechnungen.

**Quellen:** DC-03, Kap. 2 (DH-Verfahren, DL- und DH-Problem, Beispiel 2.1 sichere Primzahlen); Abschn. 2.1 (Algorithmus auf Grundlage von (2.2), Beispiel 2.4); Abschn. 2.2.1 (Pohlig-Hellman-Reduktion, S. 34–35); Abschn. 2.2.2 (BSGS); Abschn. 1.1, Satz 1.2.
**Bezug Altklausur:** 2021, Aufgabe 5 (3) (Folge der Quadrate); 2008, Aufgabe 8 (modulares Inverses).

---

## Aufgabe 8 – MACs, RSA-Padding, X.509, HTTPS (14 P)

### (a) (3 P)

Charlie wählt die Nachricht **(m, m ⊕ t)**. CBC-Berechnung mit IV = 0:
- c₁ = E_k(m ⊕ 0) = E_k(m) = t
- c₂ = E_k((m ⊕ t) ⊕ c₁) = E_k(m ⊕ t ⊕ t) = E_k(m) = t

⇒ M_k(m, m ⊕ t) = **t** – ein gültiger MAC ohne Kenntnis von k.

Verletzt ist die Voraussetzung, dass **alle Nachrichten dieselbe feste Länge** (Vielfaches der Blocklänge) haben. CMAC verhindert das, weil der letzte Block zusätzlich mit k₁ bzw. k₂ verknüpft wird.

### (b) (3 P)

Für n = 8 ist R_b = `1B`. Regel (Abb. 5.2): Linksshift um 1 Bit; war das herausgeschobene Bit 1, wird das letzte Byte mit `1B` XOR-verknüpft.

- k₀ = `9A 3C 71 05 E8 42 D6 B1`, MSB = 1 (0x9A = 1001 1010₂)
- k₀ ≪ 1 = `34 78 E2 0B D0 85 AD 62` → k₁ = … ⊕ `1B` = **`34 78 E2 0B D0 85 AD 79`**
- MSB(k₁) = 0 (0x34 = 0011 0100₂) → k₂ = k₁ ≪ 1 = **`68 F1 C4 17 A1 0B 5A F2`**

k₁: Nachricht nicht leer und Länge ein Vielfaches von n (kein Padding). k₂: sonst (Padding mit `80 00 … 00`).

### (c) (3 P)

k = ⌊log₂(n) / 8⌋ + 1 = 384 Byte (3071 ≤ log₂ n < 3072)

- (i) PKCS1-v1_5: mLen ≤ k − 11 = **373 Byte**
- (ii) OAEP Default (SHA-1, hLen = 20): mLen ≤ k − 2·hLen − 2 = 384 − 40 − 2 = **342 Byte**
- (iii) OAEP mit SHA-256 (hLen = 32): 384 − 64 − 2 = **318 Byte**

PKCS1-v1_5 ist durch den **Bleichenbacher-Angriff** gefährdet: ein adaptiver Chosen-Ciphertext-Angriff, der ein Orakel ausnutzt, das verrät, ob c̃ᵈ mod n korrekt PKCS1-v1_5-formatiert ist (z. B. durch spezifische Fehlermeldungen oder Laufzeitunterschiede eines Servers). OAEP wurde als Schutz dagegen vorgeschlagen.

### (d) (3 P)

(i) 1190 > 127 → lange Form: m = ⌊log₂₅₆(1190)⌋ + 1 = 2 (256 ≤ 1190 < 65 536); erstes Byte 128 + 2 = 0x82, dann 1190 = 0x04A6 → **`82 04 A6`**

(ii) 1 (Tag `30`) + 3 (Length) + 1190 (Contents) = **1194 Byte**

(iii) Je 3 Byte → 4 Zeichen: 1194 / 3 = 398 → 398 · 4 = **1592 Base64-Zeichen**

### (e) (2 P) – je 0,5 P, vier davon:

- Zertifikat abgelaufen oder noch nicht gültig (Feld `validity`)
- Hostname der aufgerufenen URL passt nicht zum Zertifikat (`subject` bzw. Subject Alternative Name)
- Zertifikatskette endet nicht bei einer vertrauenswürdigen Wurzel-CA (z. B. selbstsigniertes Zertifikat, unbekannter Aussteller)
- Signatur des Zertifikats ungültig (Zertifikat verändert)
- Zertifikat wurde widerrufen (CRL / OCSP) **[EXTERN: RFC 5280 wird auf den Folien nur genannt]**
- Veraltete, unsichere Protokollversion oder Algorithmen (z. B. SHA-1-Signatur, SSL 3.0) **[EXTERN]**
- Gemischte Inhalte: Teile der HTTPS-Seite werden per HTTP nachgeladen **[EXTERN]**

**Quellen:** DC-02, Abschn. 5.2 (CMAC, Abb. 5.2 mit R_b = 0x1B/0x87, CBC-MAC mit Warnung, S. 74–76); DC-03, Abschn. 3.2, Beispiel 3.4 (PKCS1-v1_5, mLen ≤ k − 11), Beispiel 3.5 (Bleichenbacher), Beispiel 3.6 (OAEP, mLen ≤ k − 2hLen − 2); Folien `260716_dc_tls_x509_jsse_keytool.pdf` (X.509, ASN.1 DER Length Octets, PEM/Base64).
**Bezug Altklausur:** 2008, Aufgabe 2 (HTTPS-Warnungen); 2021, Aufgabe 2 (MAC-Verfahren und Authentizität).

---

## Hinweise zur Klausur

- **JavaCard/APDUs** (2021, Aufgabe 6) sind bewusst nicht enthalten: Das Thema kommt weder in den Skripten noch in den Folien 2026 vor.
- Die Probeklausur ist mit ~100 Punkten in 90 Minuten bewusst an der oberen Grenze. Wer unter Zeitdruck gerät: Aufgaben 1, 5 und 7 sind die rechenintensivsten, Aufgaben 3 und 4 bringen mit sauberer Formelkenntnis (Satz 4.1, 4.3, K²/Mʳ) schnelle Punkte.
- Rechenkontrolle mit dem Taschenrechner: Bei Produkten mod n zuerst das Produkt bilden, dann ⌊Produkt / n⌋ bestimmen und abziehen. Alle Zwischenprodukte in dieser Klausur bleiben unter 10⁸ und damit im genauen Bereich eines normalen Taschenrechners.
