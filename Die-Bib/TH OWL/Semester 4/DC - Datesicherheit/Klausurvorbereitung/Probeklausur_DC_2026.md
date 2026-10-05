# Probeklausur Datensicherheit (DC)

**TH OWL · Prof. Dr. S. Heiss · SoSe 2026 · Probeklausur (inoffiziell)**

| | |
|---|---|
| **Bearbeitungszeit** | 90 Minuten |
| **Hilfsmittel** | nicht programmierbarer Taschenrechner, sonst keine |
| **Gesamtpunktzahl** | 100 Punkte |
| **Schwierigkeitsgrad** | hoch |

Die Wertung erfolgt aufgrund richtiger und **nachvollziehbar begründeter** Antworten. Rechenwege (Tabellen des erweiterten Euklid'schen Algorithmus, Quadratfolgen bei modularen Potenzen, Zwischenergebnisse) müssen erkennbar sein – ein reines Endergebnis ohne Weg gibt höchstens die Hälfte der Punkte. Ergebnisse in ℤₙ sind immer als Repräsentant aus {0, 1, …, n−1} anzugeben.

Richtwert: 1 Punkt ≈ 0,9 Minuten.

| Aufgabe | Thema | Punkte |
|---|---|---|
| 1 | Hill-Verfahren: Known-Plaintext-Angriff | 12 |
| 2 | Betriebsmodi und Stromverschlüsselung | 14 |
| 3 | Brute-Force auf Passwörter und Hashfunktionen | 12 |
| 4 | DES, 2DES, Meet-in-the-Middle, AES | 10 |
| 5 | RSA mit CRT-Schlüssel | 16 |
| 6 | Faktorisierung von n bei bekanntem d | 8 |
| 7 | Diffie-Hellman und Pohlig-Hellman-Reduktion | 14 |
| 8 | MACs, RSA-Padding, X.509, HTTPS | 14 |
| **Σ** | | **100** |

**Hilfstabellen**

Buchstaben ↔ ℤ₂₆:

| A   | B   | C   | D   | E   | F   | G   | H   | I   | J   | K   | L   | M   | N   | O   | P   | Q   | R   | S   | T   | U   | V   | W   | X   | Y   | Z   |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| 0   | 1   | 2   | 3   | 4   | 5   | 6   | 7   | 8   | 9   | 10  | 11  | 12  | 13  | 14  | 15  | 16  | 17  | 18  | 19  | 20  | 21  | 22  | 23  | 24  | 25  |

ASCII (Ausschnitt): `0x20` = Leerzeichen, `0x30`–`0x39` = `'0'`–`'9'`, `0x3A` = `':'`, `0x41`–`0x5A` = `'A'`–`'Z'`, `0x61`–`0x7A` = `'a'`–`'z'`.

---

## Aufgabe 1 – Hill-Verfahren: Known-Plaintext-Angriff (12 Punkte)

Eine Nachricht wurde mit dem Hill-Verfahren mit einer unbekannten invertierbaren (2,2)-Matrix K über ℤ₂₆ verschlüsselt. Klartextblöcke b = (b₁, b₂)ᵀ (Spaltenvektoren aus je zwei aufeinanderfolgenden Buchstaben) werden dabei zu

  E_K(b) = K · b

verschlüsselt. Der abgefangene Geheimtext lautet:

  **UV OI VH OG FK IG UJ**

Aus einer anderen Quelle ist bekannt, dass der Klartext mit **TRESOR** beginnt.

**(a)** (2 P) Eine naheliegende Idee ist, K aus den ersten beiden Klartext-/Geheimtextblöcken zu bestimmen. Zeigen Sie, dass das hier nicht funktioniert, und begründen Sie genau, woran es scheitert.

**(b)** (5 P) Bestimmen Sie die Schlüsselmatrix K. Prüfen Sie Ihr Ergebnis mit dem nicht verwendeten bekannten Block.

**(c)** (4 P) Berechnen Sie K⁻¹ und entschlüsseln Sie den Rest der Nachricht.

**(d)** (1 P) Wie viele Klartextbuchstaben müssen bei einer (3,3)-Hill-Matrix über ℤ₂₆ *mindestens* bekannt sein, damit ein solcher Angriff überhaupt möglich ist? Warum können auch mehr nötig sein?

---

## Aufgabe 2 – Betriebsmodi und Stromverschlüsselung (14 Punkte)

**(a)** (4 P) Ein Terminserver verschlüsselt kurze Nachrichten mit AES im CTR-Modus. Durch einen Implementierungsfehler werden zwei Nachrichten mit **demselben Schlüssel k und demselben Ctr-Wert** verschlüsselt. Ein Angreifer beobachtet die beiden Geheimtexte

  c₁ = `77 F3 71 D0 8E 1E BD 5F`
  c₂ = `7C EE 71 D1 80 1E BE 5F`

und weiß, dass der erste Klartext m₁ = `"Mo 09:00"` (= `4D 6F 20 30 39 3A 30 30`) ist. Bestimmen Sie m₂ ohne Kenntnis von k (hexadezimal und als Text). Begründen Sie formal, warum das möglich ist.

**(b)** (3 P) Ein aktiver Angreifer (Man-in-the-Middle) möchte, dass der Empfänger von c₁ statt `"Mo 09:00"` den Klartext `"Mo 19:00"` erhält.
  (i) Welches Byte von c₁ muss er wie verändern (neuer Hexwert)?
  (ii) Angenommen, m₁ wäre stattdessen der erste Block einer Nachricht, die im **CBC-Modus** mit übertragenem IV verschlüsselt wurde. Welchen Wert muss der Angreifer dann manipulieren, damit genau diese Änderung eintritt, und hat die Manipulation Nebenwirkungen auf andere Klartextblöcke?

**(c)** (2 P) Alice überträgt IV und (c₁, …, c₉) einer CBC-verschlüsselten Nachricht an Bob. Ein Bit von c₂ wird fehlerhaft empfangen. Welche Klartextblöcke kann Bob fehlerfrei lesen, welche nicht, und wie genau sind die fehlerhaften Blöcke gestört?

**(d)** (3 P) Eine Nachricht der Länge l = 1000 Byte wird mit AES-CTR verschlüsselt.
  (i) Wie viele Schlüsselstromblöcke werden benötigt, und wie viele Bytes des letzten Blocks werden verwendet?
  (ii) Der Ctr-Wert sei `FFFFFFFF FFFFFFFF FFFFFFFF FFFFFFFE`. Geben Sie die Zählerwerte an, die für die ersten vier Schlüsselstromblöcke verschlüsselt werden.
  (iii) Warum reicht es nicht, darauf zu achten, dass nur die Ctr-Startwerte verschiedener Nachrichten verschieden sind?

**(e)** (2 P) Ein Server verwendet ChaCha20 (96-Bit-Nonce) und wählt für jede Nachricht den Nonce-Wert zufällig. Unter einem Schlüssel werden 2³² Nachrichten verschlüsselt. Schätzen Sie die Wahrscheinlichkeit, dass dabei ein Nonce-Wert doppelt vorkommt, nach oben ab. Wie lang darf eine einzelne mit ChaCha20 verschlüsselte Nachricht höchstens sein?

---

## Aufgabe 3 – Brute-Force auf Passwörter und Hashfunktionen (12 Punkte)

**(a)** (5 P) Ein Angreifer kennt den SHA-256-Hashwert eines Passworts. Für ein Passwort aus sechs Kleinbuchstaben (ohne Umlaute) benötigt ein Brute-Force-Angriff maximal T(26, 6) = 70 s.
  (i) Bestimmen Sie T(62, 8) (Groß-, Kleinbuchstaben, Ziffern) und T(95, 10) (95 druckbare ASCII-Zeichen) in einer sinnvollen Einheit.
  (ii) Statt eines einfachen Hashwerts wird der Eintrag mit einem Salt und einem Iteration Count c = 600 000 berechnet. Wie lange dauert der Angriff für T(62, 8) jetzt?
  (iii) Gegen welche Angriffsart hilft der Salt, und warum verlängert er den Brute-Force-Angriff auf *ein einzelnes* Passwort nicht?

**(b)** (5 P) Gegeben sei eine Hashfunktion H: 𝓜 → ℤ₂¹¹².
  (i) Wie oft muss H ungefähr ausgeführt werden, um mit Wahrscheinlichkeit p = 0,5 bzw. p = 0,99 eine Kollision zu finden? (Zwei signifikante Stellen)
  (ii) Wie lange dauert das für p = 0,5 bei 10⁹ Hashberechnungen pro Sekunde?
  (iii) Jeder Tabelleneintrag der Kollisionssuche benötigt 22 Byte (14 Byte Hashwert, 8 Byte Nachrichtenzähler). Wie viel Speicher wird für p = 0,5 benötigt?
  (iv) Wie viele Hashberechnungen benötigt dagegen eine Urbildsuche mit Erfolgswahrscheinlichkeit p = 0,5?

**(c)** (2 P) Wie viele Personen müssen mindestens auf einer Party sein, damit mit Wahrscheinlichkeit p ≥ 0,99 zwei Gäste am gleichen Tag Geburtstag haben? Bestimmen Sie eine hinreichende Anzahl mit einer Abschätzung aus der Vorlesung und weisen Sie nach, dass Ihre Zahl tatsächlich genügt.

---

## Aufgabe 4 – DES, 2DES, Meet-in-the-Middle, AES (10 Punkte)

Rechnen Sie mit 10⁹ DES-Operationen pro Sekunde.

**(a)** (2 P) Warum hat der DES-Schlüsselraum trotz 8-Byte-Schlüsseln nur die Größe 2⁵⁶? Wie lange dauert ein Brute-Force-Angriff auf DES maximal und im Mittel?

**(b)** (3 P) Für 2DES mit E_(k₁,k₂)(m) = E_k₂(E_k₁(m)) liegt ein bekanntes Klartext-/Geheimtextpaar (m₁, c₁) vor. Beschreiben Sie knapp den Meet-in-the-Middle-Angriff. Schätzen Sie Rechenaufwand (Anzahl DES-Operationen) und Speicherbedarf in Byte ab, wenn pro Tabelleneintrag 16 Byte benötigt werden. Wie lange würde der Angriff dauern, und wie lange ein naiver Brute-Force-Angriff auf 2DES?

**(c)** (3 P) Wie viele *falsche* Schlüsselpaare (k̃₁, k̃₂) ≠ (k₁, k₂) sind im Mittel mit r = 1, 2 bzw. 3 bekannten Klartext-/Geheimtextpaaren verträglich? Mit welcher Wahrscheinlichkeit gibt es für r = 2 noch mindestens ein falsches Paar?

**(d)** (2 P) Bei AES-256 ist |𝒦| = 2²⁵⁶ und |𝓜| = 2¹²⁸. Wie viele bekannte Klartext-/Geheimtextpaare braucht ein (hypothetischer) Brute-Force-Angriff mindestens, damit der Schlüssel mit hoher Wahrscheinlichkeit eindeutig bestimmt ist? Mit welcher Wahrscheinlichkeit gibt es bei einem Paar *weniger* noch einen weiteren passenden Schlüssel?

---

## Aufgabe 5 – RSA mit CRT-Schlüssel (16 Punkte)

Alice erzeugt ein RSA-Schlüsselpaar mit den Primzahlen **p = 71** und **q = 103**. Dabei wählt sie v = kgV(p−1, q−1) und den öffentlichen Exponenten e so klein wie möglich.

**(a)** (2 P) Bestimmen Sie |ℤₙ*| und μₙ.

**(b)** (2 P) Geben Sie k_A,pub = (n, e) an und begründen Sie die Wahl von e.

**(c)** (3 P) Berechnen Sie den privaten Exponenten d mit dem erweiterten Euklid'schen Algorithmus (Tabelle!).

**(d)** (1 P) Welchen privaten Exponenten d′ hätte Alice erhalten, wenn sie v = (p−1)(q−1) verwendet hätte? In welcher Beziehung stehen d und d′, und warum funktionieren beide?

**(e)** (3 P) Alice speichert ihren privaten Schlüssel im CRT-Format k_A,priv = (p, q, d₁, d₂, q\*). Berechnen Sie d₁, d₂ und q\*.

**(f)** (5 P) Bob schickt Alice den Geheimtext **c = 1890**. Entschlüsseln Sie c ausschließlich mit dem CRT-Schlüssel aus (e). Geben Sie für beide modularen Potenzen die Folge der Quadrate an.

---

## Aufgabe 6 – Faktorisierung von n bei bekanntem d (8 Punkte)

Bob besitzt das RSA-Schlüsselpaar mit

  k_B,pub = (n, e) = (8633, 5)  und  k_B,priv = (n, d) = (8633, 5069).

Durch ein Datenleck wird d öffentlich.

**(a)** (6 P) Bestimmen Sie die Primfaktoren von n mit dem Verfahren aus der Vorlesung (Bestimmung von p, q bei Kenntnis eines Vielfachen von kgV(p−1, q−1)). Verwenden Sie a = 2. Geben Sie alle Zwischenschritte an und begründen Sie, warum der Algorithmus mit diesem a erfolgreich endet.

**(b)** (2 P) Bob schlägt vor, einfach ein neues Paar (e′, d′) zum *selben* Modul n zu erzeugen. Beurteilen Sie diesen Vorschlag.

---

## Aufgabe 7 – Diffie-Hellman und Pohlig-Hellman-Reduktion (14 Punkte)

Alice und Bob verwenden die DH-Parameter (n, g) = (211, 2). Es ist n − 1 = 210 = 2 · 3 · 5 · 7.

*Hinweis:* In ℤ₂₁₁ gilt 2¹⁰⁵ = 210, 2⁷⁰ = 196, 2⁴² = 107, 2³⁰ = 171.

**(a)** (1 P) Zeigen Sie mit dem Hinweis, dass g = 2 ein primitives Element von ℤ₂₁₁* ist.

**(b)** (7 P) Charlie liest Alices öffentlichen Schlüssel **k_A,pub = 152** mit. Bestimmen Sie Alices privaten Schlüssel e_A mit der Pohlig-Hellman-Reduktion. Geben Sie für jeden Primteiler pᵢ von n − 1 die Werte mᵢ, gᵢ, aᵢ, xᵢ und vᵢ an.

**(c)** (4 P) Bobs öffentlicher Schlüssel ist **k_B,pub = 194**. Berechnen Sie das gemeinsame Geheimnis s mit dem Algorithmus „Quadrieren und Multiplizieren“ (Folge der Quadrate angeben).

**(d)** (2 P) Warum sind die in RFC 7919 spezifizierten DH-Parameter (sichere Primzahlen n mit (n−1)/2 prim) optimal gegen die Pohlig-Hellman-Reduktion? Wie viele Tabelleneinträge müsste Charlie beim BSGS-Verfahren für die Gruppe aus dieser Aufgabe mindestens speichern?

---

## Aufgabe 8 – MACs, RSA-Padding, X.509, HTTPS (14 Punkte)

**(a)** (3 P) Ein Server verwendet CBC-MAC (IV = 0, kein Padding) mit AES für Nachrichten **beliebiger** Blockanzahl. Charlie kennt zu einem einzelnen Block m den MAC-Wert t = M_k(m). Konstruieren Sie ohne Kenntnis von k eine zweiblöckige Nachricht mit gültigem MAC und weisen Sie die Gültigkeit nach. Welche Voraussetzung des CBC-MAC-Verfahrens wird verletzt?

**(b)** (3 P) CMAC wird mit einem 64-Bit-Blockverfahren (n = 8 Byte) eingesetzt. Es gilt k₀ = E_k(0) = `9A 3C 71 05 E8 42 D6 B1`. Berechnen Sie die abgeleiteten Schlüssel k₁ und k₂. Für welche Nachrichten wird k₁ bzw. k₂ verwendet?

**(c)** (3 P) Ein RSA-Modul hat 3072 Bit. Wie viele Byte darf eine Nachricht M höchstens haben bei
  (i) EME-PKCS1-v1_5-Kodierung,
  (ii) EME-OAEP-Kodierung mit Default-Parametern,
  (iii) EME-OAEP-Kodierung mit SHA-256 als h und h̃?
  Warum wurde OAEP als Nachfolger von PKCS1-v1_5 empfohlen?

**(d)** (3 P) Ein X.509-Zertifikat ist eine DER-kodierte `SEQUENCE` (Tag-Byte `30`) mit 1190 Contents-Octets.
  (i) Geben Sie die Length-Octets hexadezimal an.
  (ii) Wie viele Byte umfasst die gesamte DER-Kodierung?
  (iii) Wie viele Base64-Zeichen (ohne Zeilenumbrüche, Header und Footer) enthält die PEM-Datei?

**(e)** (2 P) Nennen Sie vier verschiedene Situationen, in denen ein Webbrowser beim Aufruf einer Seite über `https://…` eine Warnung ausgeben sollte.
