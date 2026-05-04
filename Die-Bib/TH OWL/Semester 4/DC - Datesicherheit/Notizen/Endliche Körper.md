> Referenz: [[DC-02.pdf#page=44|DC-02, Seite 44–56]] (Kapitel 3, Mathematischer Exkurs)

Benötigt für [[Blockverschlüsselung]] (AES).

# Grundbegriff: Körper

Ein **Körper** $\mathbb{F}$ ist eine Menge mit zwei Operationen $(+, \cdot)$, bei der:
- $(\mathbb{F}, +)$ eine abelsche Gruppe ist
- $(\mathbb{F} \setminus \{0\}, \cdot)$ eine abelsche Gruppe ist
- Distributivgesetze gelten

---

# Endliche Körper $\mathbb{F}_{p^n}$

> [[DC-02.pdf#page=48|DC-02, Seite 48]]

Es gibt genau einen (bis auf Isomorphie) endlichen Körper mit $q$ Elementen, wenn $q = p^n$ für eine Primzahl $p$ und $n \in \mathbb{N}$.

- $\mathbb{F}_p = \mathbb{Z}_p$ für Primzahlen $p$
- $\mathbb{F}_{p^n}$ für $n > 1$: Konstruktion über Polynome mod einem irreduziblen Polynom

---

# $\mathbb{F}_{2^8} = \mathbb{F}_{256}$ (für AES)

> [[DC-02.pdf#page=53|DC-02, Seite 53]]

Elemente: Polynome $a_7 x^7 + a_6 x^6 + \cdots + a_0$ mit Koeffizienten in $\mathbb{F}_2$ → dargestellt als Byte $(a_7, \ldots, a_0)$

**Addition**: Bitweise XOR der Byte-Darstellungen
$$0xB5 \oplus 0x2A = \ldots$$

**Multiplikation**: Polynommultiplikation mod einem irreduziblen Polynom:
$$m(x) = x^8 + x^4 + x^3 + x + 1 \quad \text{(für AES)}$$

Entspricht dem hex-Wert `0x11B`.

## Relevanz für AES
- **SubBytes**: Berechnung des multiplikativen Inversen in $\mathbb{F}_{256}$, danach affine Abbildung
- **MixColumns**: Matrixmultiplikation in $\mathbb{F}_{256}$

MixColumns-Matrix:
$$M = \begin{pmatrix} 02 & 03 & 01 & 01 \\ 01 & 02 & 03 & 01 \\ 01 & 01 & 02 & 03 \\ 03 & 01 & 01 & 02 \end{pmatrix}$$

(Einträge in hex, Multiplikation in $\mathbb{F}_{256}$)
