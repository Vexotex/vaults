> Referenz: [[DC-03.pdf#page=29|DC-03, Seite 29–43]] (Kapitel 2)

# Motivation

**Problem**: Wie können Alice und Bob über einen öffentlichen, abhörbaren Kanal einen gemeinsamen geheimen Schlüssel vereinbaren?

→ Lösung: **Diffie-Hellman-Schlüsselaustauschverfahren** (1976, Diffie und Hellman)

Grundlage: Schwierigkeit des **Diskreten Logarithmusproblems** (DLP)

---

# Diskretes Logarithmusproblem (DLP)

Gegeben: Gruppe $\mathbb{Z}_p^*$ mit Primzahl $p$, Erzeuger $g$ und Element $y$.

**DLP**: Finde $x \in \mathbb{Z}$ mit $g^x \equiv y \pmod{p}$.

Notation: $x = \log_g(y)$ (diskreter Logarithmus von $y$ zur Basis $g$)

**Sicherheitsannahme**: Für große $p$ (mind. 2048 Bit) ist das DLP praktisch unlösbar.

---

# Diffie-Hellman-Protokoll

> [[DC-03.pdf#page=29|DC-03, Seite 29]]

**Öffentliche Parameter**: Primzahl $p$, Erzeuger $g$ von $\mathbb{Z}_p^*$

| Schritt | Alice | Bob |
|---|---|---|
| 1 | wählt zufällig $a \in \{1,\ldots,p-2\}$ | wählt zufällig $b \in \{1,\ldots,p-2\}$ |
| 2 | berechnet $A = g^a \bmod p$ | berechnet $B = g^b \bmod p$ |
| 3 | sendet $A$ an Bob | sendet $B$ an Alice |
| 4 | berechnet $K = B^a \bmod p$ | berechnet $K = A^b \bmod p$ |

**Gemeinsamer Schlüssel**: $K = g^{ab} \bmod p$ (beide erhalten denselben Wert)

Angreifer Charly kennt $p$, $g$, $A$, $B$ – muss aber $K = g^{ab}$ ohne $a$ oder $b$ berechnen → **DH-Problem**

---

# Berechnung modularer Potenzen

> [[DC-03.pdf#page=36|DC-03, Seite 36]]

**Square-and-Multiply** (effiziente Potenzierung):
- Binärdarstellung des Exponenten $a = (a_{l-1}, \ldots, a_1, a_0)_2$
- Schrittweise Quadrieren und bedingte Multiplikation mit $g$
- Laufzeit: $O(\log a)$ Multiplikationen statt $O(a)$

```
result = 1
for bit in bits(a):
    result = result² mod p
    if bit == 1:
        result = result · g mod p
```

---

# Angriffe auf das DH-Verfahren

> [[DC-03.pdf#page=40|DC-03, Seite 40]]

## Pohlig-Hellman-Reduktion
- Reduziert DLP in $\mathbb{Z}_p^*$ auf DLPs in kleinen Untergruppen
- Effizient wenn $p-1$ nur kleine Primfaktoren hat
- **Gegenmaßnahme**: $p$ so wählen, dass $p-1$ einen großen Primfaktor $q$ hat (**Safe Prime**: $p = 2q+1$)

## Baby-Steps-Giant-Steps (BSGS, Shanks)

> [[DC-03.pdf#page=41|DC-03, Seite 41]]

- Zeit- und Speicheraufwand: $O(\sqrt{|G|})$
- Idee: Zerlegung $x = i \cdot m + j$ mit $m = \lceil\sqrt{p}\rceil$
- Speichere $g^j$ für alle $j$ → suche Kollision mit $y \cdot g^{-im}$

## Pollard's Rho-Methode

> [[DC-03.pdf#page=41|DC-03, Seite 41]]

- Zeitaufwand $O(\sqrt{|G|})$, aber **ohne** großen Speicherbedarf
- Zufallswanderung in der Gruppe bis Kollision

## Zahlkörpersieb (Number Field Sieve)

> [[DC-03.pdf#page=43|DC-03, Seite 43]]

- Subexponentieller Aufwand: $O(e^{c \cdot (\log p)^{1/3} (\log \log p)^{2/3}})$
- Effizientester bekannter Algorithmus für DLP in $\mathbb{Z}_p^*$
- **Begründet Mindestschlüssellänge von 2048 Bit für $p$**
