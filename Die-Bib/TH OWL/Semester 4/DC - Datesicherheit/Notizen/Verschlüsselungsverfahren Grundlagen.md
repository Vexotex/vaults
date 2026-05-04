> Referenz: [[DC-01.pdf#page=59|DC-01, Seite 59–64]] (Kapitel 4)

# Kerckhoffs'sches Prinzip

> [[DC-01.pdf#page=60|DC-01, Seite 60]]

Die Sicherheit eines Verschlüsselungsverfahrens darf **nicht** auf der Geheimhaltung des Algorithmus beruhen, sondern **nur auf der Geheimhaltung des Schlüssels**.

Begründung: Ein geheimer Algorithmus kann nicht in großem Maßstab eingesetzt werden, und Geheimnis gelangt früher oder später an die Öffentlichkeit.

---

# Mathematische Modellierung

> [[DC-01.pdf#page=61|DC-01, Seite 61]]

Ein **Verschlüsselungsverfahren** (Cipher) besteht aus einem Paar von Funktionen $(E, D)$:
$$E : K \times M \to M \quad \text{(Verschlüsselung)}$$
$$D : K \times M \to M \quad \text{(Entschlüsselung)}$$

- $M$: Menge der Klar- und Geheimtextnachrichten
- $K$: Schlüsselraum
- Für jeden Schlüssel $k$: $E_k : M \to M$ ist bijektiv, $D_k = E_k^{-1}$

**Blockverschlüsselung**: $M = (\mathbb{Z}_{2^8})^n$ (Blöcke fixer Länge $n$)

**Stromverschlüsselung**: $M = (\mathbb{Z}_{2^8})^{>0}$ (Nachrichten beliebiger Länge)

---

# Schlüsselaustausch

> [[DC-01.pdf#page=64|DC-01, Seite 64]]

**Problem**: Bei symmetrischen Verfahren müssen Alice und Bob vorab einen gemeinsamen Schlüssel auf sicherem Weg austauschen.

**Lösungsansätze**:
- Persönlicher Austausch (unpraktisch für Internet)
- **Asymmetrische Verfahren / Key Agreement** (z.B. Diffie-Hellman) → DC-03

---

# Angriffsszenarien

> [[DC-01.pdf#page=65|DC-01, Seite 65]]

| Angriffsszenario | Englisch | Angreiferin hat Zugang zu |
|---|---|---|
| Nur-Geheimtext | Ciphertext-only | Nur Geheimtexten |
| Bekannter Klartext | Known-plaintext | Klartext-Geheimtext-Paaren |
| Gewählter Klartext | Chosen-plaintext | Selbst gewählten Klartexten + Geheimtexten |
| Gewählter Geheimtext | Chosen-ciphertext | Selbst gewählten Geheimtexten + Klartexten |

Stärkstes Szenario: **Chosen-plaintext** – ein sicheres Verfahren muss auch dagegen sicher sein.

---

# Brute-Force-Angriffe

> [[DC-01.pdf#page=66|DC-01, Seite 66]]

Systematisches Durchsuchen aller möglichen Schlüssel oder Nachrichten.

**Grundanforderung an Verschlüsselungsverfahren** (Version 3):
1. Kein Schlüsselangriff mit weniger als $\frac{|K|}{2}$ Operationen im Durchschnitt
2. Kein Nachrichtenangriff mit weniger als $\frac{|M|}{2}$ Operationen im Durchschnitt
3. Chosen-plaintext-Angriff soll nicht effizient möglich sein

---

# Wörterbuchangriffe (Dictionary Attacks)

> [[DC-01.pdf#page=69|DC-01, Seite 69]]

**Angriff**: Vorabberechnung von Hashwerten/Geheimtexten für eine Menge schwacher Schlüssel (z.B. Wörter aus dem Wörterbuch).

**Schutzmaßnahme**: **Nonce** (Number used Once)
- Nonce-Werte werden einmalig verwendet und schließen Vorausberechnungen aus
- Arten von Nonce-Werten:
  - **Counter** (Zähler)
  - **Zeitstempel** (Time Stamp)
  - **Zufallszahlen** aus hinreichend großem Zahlenraum
