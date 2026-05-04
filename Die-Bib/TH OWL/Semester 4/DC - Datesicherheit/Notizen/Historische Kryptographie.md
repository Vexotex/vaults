> Referenz: [[DC-01.pdf#page=7|DC-01, Seite 7–19]] (Kapitel 1)

# Kryptographie und Kryptoanalyse

**Kryptographie** (griech. *kryptos* = verborgen, *graphein* = schreiben): Lehre der Geheimschrift.
Bis in die 1970er Jahre fast ausschließlich im militärischen und diplomatischen Bereich genutzt.

**Kryptoanalyse**: Methoden zum Angriff auf kryptographische Verfahren (Schwachstellensuche).

---

# Klassische Verschlüsselungsverfahren

> [[DC-01.pdf#page=9|DC-01, Seite 9–13]]

Alle klassischen Verfahren: Verschlüsselung von Klartext → Geheimtext.
Ziel: Dritte können aus Geheimtext keine Rückschlüsse auf Klartext ziehen.

## Caesar-Verfahren
- Jeder Buchstabe wird um einen festen Betrag (Schlüssel) verschoben
- Schlüsselraum: 25 mögliche Schlüssel → sehr unsicher (Brute Force trivial)
- Sicherheit basiert auf Geheimhaltung des Algorithmus → schlechte Eigenschaft

## Monoalphabetische Substitution

> [[DC-01.pdf#page=11|DC-01, Seite 11]]

- Schlüssel $k: \mathbb{Z} \to \mathbb{Z}$ ist eine beliebige Permutation (bijektive Abbildung)
- Schlüsselraum: $K = \Sigma_Z$ (alle bijektiven Selbstabbildungen), $|K| = 26!$
- Verschlüsselung: $E_k(z) := k(z)$
- Angriff: **Häufigkeitsanalyse** von Buchstaben

## Vigenère-Verfahren (Polyalphabetische Substitution)

> [[DC-01.pdf#page=13|DC-01, Seite 13]]

- Schlüssel ist ein Schlüsselwort, das periodisch wiederholt wird
- Jeder Buchstabe wird mit einem anderen Teilschlüssel verschlüsselt
- Entwickelt 1585 von B. de Vigenère
- Schutz gegen einfache Häufigkeitsanalyse, aber angreifbar über Schlüsselwortlänge

---

# One-Time-Pad

> [[DC-01.pdf#page=15|DC-01, Seite 15–17]]

- Jedes Klartextzeichen wird mit einem **zufällig gewählten, einmalig genutzten** Schlüsselzeichen verschlüsselt
- Schlüssel $k = (k_1, k_2, \ldots, k_l) \in \mathbb{Z}_n^l$ zufällig gewählt
- Verschlüsselung: $E_k(m) := m + k = (m_1 + k_1, \ldots, m_l + k_l)$ (mod $n$)
- **Perfekte Sicherheit**: Geheimtext gibt keinerlei Information über Klartext
- **Problem**: Schlüssel muss mindestens so lang sein wie die Nachricht → unpraktisch

---

# Hill-Verschlüsselungsverfahren

> [[DC-01.pdf#page=18|DC-01, Seite 18]]

- Eingeführt 1929 von L. Hill
- Blöcke der Länge $k$ aus $\mathbb{Z}_n$, Schlüssel ist eine invertierbare $(k \times k)$-Matrix $K$
- Verschlüsselung: $E_K(b) := K \cdot b$
- Entschlüsselung: $D_K(c) := K^{-1} \cdot c$
- Erste algebraische Methode in der Kryptographie

---

# Elektromechanische Verschlüsselungsmaschinen

> [[DC-01.pdf#page=19|DC-01, Seite 19]]

- Beispiel: Enigma (2. Weltkrieg)
- Mechanische Umsetzung polyalphabetischer Substitution

---

# Moderne Verschlüsselungsverfahren

> [[DC-01.pdf#page=19|DC-01, Seite 19]]

- 1976: **DES** (Data Encryption Standard) – erster standardisierter Algorithmus für kommerzielle Nutzung
- Weiterentwicklung: **Triple-DES**
- Heute: **AES** (Advanced Encryption Standard), **RSA**, elliptische Kurven, ...
- Treiber: Übertragung sensibler Daten über das Internet
