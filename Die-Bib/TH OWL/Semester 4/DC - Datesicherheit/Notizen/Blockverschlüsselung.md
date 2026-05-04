> Referenz: [[DC-02.pdf#page=27|DC-02, Seite 27–50]] (Kapitel 2)

# Grundlagen

> [[DC-02.pdf#page=28|DC-02, Seite 28]]

Ein **Blockverschlüsselungsverfahren** verschlüsselt Nachrichten in Blöcken fixer Länge $n$ (in Bytes):
$$E : K \times (\mathbb{Z}_{2^8})^n \to (\mathbb{Z}_{2^8})^n$$

Anforderung: Für jeden Schlüssel $k$ soll die Abbildung $k \mapsto E_k$ **nicht von einer zufälligen Permutation** unterscheidbar sein.

Konsequenz: Ändert sich **ein Bit** in $m$ oder $k$, ändern sich im Durchschnitt $4n$ Bitstellen im Geheimtextblock.

---

# Padding-Verfahren

> [[DC-02.pdf#page=29|DC-02, Seite 29]]

Notwendig bei ECB/CBC, wenn Nachrichtenlänge kein Vielfaches der Blocklänge ist.

- **PKCS5PADDING**: Füllt mit Bytes, deren Wert der Anzahl der Padding-Bytes entspricht
- **ISO10126PADDING**: Zufällige Bytes, letztes Byte = Anzahl der Padding-Bytes

---

# Betriebsmodi

> [[DC-02.pdf#page=30|DC-02, Seite 30]]

| Modus | Voll | Parallelisierbar | Padding |
|---|---|---|---|
| ECB | Electronic Code Book | Ja | Ja |
| CBC | Cipher Block Chaining | Nur Entschlüsselung | Ja |
| CTS | Ciphertext Stealing | – | Nein (ab $n$ Bytes) |
| CTR | Counter | Ja | Nein |
| OFB | Output Feedback | Vorausberechenbar | Nein |
| CFB | Cipher Feedback | Nur Entschlüsselung | Nein |

## ECB (Electronic Code Book)
- Jeder Block wird **unabhängig** mit demselben Schlüssel verschlüsselt
- **Problem**: Gleiche Klartextblöcke → gleiche Geheimtextblöcke → Muster erkennbar
- **Nicht sicher** für semantische Sicherheit

## CBC (Cipher Block Chaining)

> [[DC-02.pdf#page=33|DC-02, Seite 33]]

Verschlüsselung (rekursiv):
$$c_0 := IV, \quad c_i := E_k(m_i \oplus c_{i-1})$$

Entschlüsselung:
$$m_i := D_k(c_i) \oplus c_{i-1}$$

- Benötigt **Nonce** = **IV** (Initialization Vector)
- Gleiche Klartextblöcke → verschiedene Geheimtextblöcke (abhängig von IV)

## CTS (Ciphertext Stealing)
- Erweiterung von CBC für Nachrichten beliebiger Länge $\geq n$ (kein Padding nötig)
- Geheimtextlänge = Klartextlänge

## CTR, OFB, CFB
- Verwenden Blockverschlüsselung zur **Konstruktion eines Schlüsselstromgenerators**
- CTR: Counter-Werte werden verschlüsselt → Schlüsselstrom

---

# Konstruktionsprinzipien

> [[DC-02.pdf#page=41|DC-02, Seite 41]]

Blockverschlüsselungsverfahren basieren auf Wiederholung elementarer Operationen (**Runden**):
- **Transposition**: Permutation von Bitpositionen innerhalb des Blocks
- **Substitution**: Austausch von Teilblock-Werten (S-Boxen)
- **Schlüsseleinmischung** (Key Mixing): XOR mit Rundenschlüssel

---

# DES (Data Encryption Standard)

> [[DC-02.pdf#page=42|DC-02, Seite 42]]

- Standardisiert 1976
- Blocklänge: **64 Bit** (8 Byte)
- Schlüssellänge: **56 Bit** → zu klein (heute durch Brute Force brechbar)
- Struktur: **Feistel-Netzwerk** (16 Runden)

**Triple-DES (3DES)**:
- Dreifache Anwendung: $E_{k_1}(D_{k_2}(E_{k_3}(m)))$
- Effektive Schlüssellänge: 112 Bit (durch Meet-in-the-Middle-Angriff auf 2DES)

## Meet-in-the-Middle-Angriff

> [[DC-02.pdf#page=44|DC-02, Seite 44]]

Angriff auf **Double-DES** ($E_{k_2}(E_{k_1}(m))$):
- Für alle $k_1$: $c_1 = E_{k_1}(m)$ berechnen und speichern
- Für alle $k_2$: $c_1' = D_{k_2}(c)$ berechnen und mit Tabelle vergleichen
- Aufwand: $2^{57}$ statt $2^{112}$ → Double-DES bietet kaum mehr Sicherheit als einfaches DES

---

# AES (Advanced Encryption Standard)

> [[DC-02.pdf#page=47|DC-02, Seite 47]]

- Standardisiert 2001 (Rijndael-Algorithmus)
- Blocklänge: **128 Bit** (16 Byte = $4 \times 4$ Byte-Matrix = **State**)
- Schlüssellänge: **128, 192 oder 256 Bit**
- Runden: 10 / 12 / 14 (je nach Schlüssellänge)

**Operationen pro Runde**:
1. **SubBytes**: Nicht-lineare Substitution (S-Box über $\mathbb{F}_{256}$)
2. **ShiftRows**: Zyklische Verschiebung der Zeilen des State-Arrays
3. **MixColumns**: Matrixmultiplikation in $\mathbb{F}_{256}$ (Diffusion)
4. **AddRoundKey**: XOR mit Rundenschlüssel

Die Operationen werden in $\mathbb{F}_{2^8}$ (Körper mit 256 Elementen) berechnet → [[Endliche Körper]].

In Java: `Cipher.getInstance("AES/CBC/PKCS5PADDING")`
