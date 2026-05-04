> Referenz: [[DC-01.pdf#page=21|DC-01, Seite 21–39]] (Kapitel 2) | [[DC-03.pdf#page=7|DC-03, Seite 7–28]] (Kapitel 1)

# Der Ring $\mathbb{Z}_n$

> [[DC-01.pdf#page=22|DC-01, Seite 22]]

Für $n \in \mathbb{N}, n \geq 2$: $\mathbb{Z}_n := \{0, 1, \ldots, n-1\}$

**Division mit Rest**: Für $a, b \in \mathbb{Z}, b \neq 0$ gibt es eindeutig $q, r \in \mathbb{Z}$ mit $0 \leq r < |b|$:
$$a = b \cdot q + r \quad \Rightarrow \quad r = a \bmod b$$

**Addition und Multiplikation in $\mathbb{Z}_n$**:
$$a +_{\mathbb{Z}_n} b := (a+b) \bmod n$$
$$a \cdot_{\mathbb{Z}_n} b := (a \cdot b) \bmod n$$

**Additives Inverses**: 
$$a + (-a) = 0$$
$$-a := \begin{cases} 0 & a = 0 \\ n - a & \text{sonst} \end{cases}$$

## Kongruenzen

$a \equiv b \pmod{n}$ genau dann, wenn $n \mid (a - b)$

Wichtige Rechenregeln: Kongruenz ist verträglich mit $+$ und $\cdot$:
$$(a+b) \bmod n = ((a \bmod n) + (b \bmod n)) \bmod n$$

---

# Inverse Elemente in $\mathbb{Z}_n$ (multiplikativ)

> [[DC-01.pdf#page=28|DC-01, Seite 28]]

$a \in \mathbb{Z}_n$ heißt **invertierbar**, falls es $b \in \mathbb{Z}_n$ gibt mit $a \cdot b = 1$ in $\mathbb{Z}_n$.
Die Menge der invertierbaren Elemente: $\mathbb{Z}_n^* = \{a \in \mathbb{Z}_n \mid \text{ggT}(a, n) = 1\}$

**Satz**: $a \in \mathbb{Z}_n^* \iff \text{ggT}(a, n) = 1$

Beispiel: $\mathbb{Z}_{10}^* = \{1, 3, 7, 9\}$

---

# Matrizen über $\mathbb{Z}_n$

> [[DC-01.pdf#page=30|DC-01, Seite 30]]

Determinanten von Matrizen mit Koeffizienten aus $\mathbb{Z}_n$ können in $\mathbb{Z}_n$ berechnet werden.
Eine Matrix $A$ über $\mathbb{Z}_n$ ist invertierbar $\iff$ $\det(A) \in \mathbb{Z}_n^*$.

Inverse: $A^{-1} = (\det(A))^{-1} \cdot \text{adj}(A)$

---

# Euklidischer Algorithmus

> [[DC-01.pdf#page=32|DC-01, Seite 32]]

Berechnung von $\text{ggT}(a_0, b_0)$ iterativ:
1. $a := a_0,\ b := b_0$
2. Wenn $b = 0$: $\text{ggT} = |a|$, Ende
3. $r := a \bmod b$; dann $a := b$, $b := r$; zurück zu 2.

## [[Erweiterter Euklidischer Algorithmus]]

> [[DC-01.pdf#page=36|DC-01, Seite 36–33]]

Liefert zusätzlich $\alpha, \beta \in \mathbb{Z}$ mit: $\alpha \cdot a_0 + \beta \cdot b_0 = \text{ggT}(a_0, b_0)$

Anwendung: Berechnung des multiplikativen Inversen von $a$ in $\mathbb{Z}_n$:
- Falls $\text{ggT}(a, n) = 1$: finde $\beta$ mit $\beta \cdot a \equiv 1 \pmod{n}$
- Dann: $a^{-1} = \beta \bmod n$

---

# Eulersche $\varphi$-Funktion

> [[DC-01.pdf#page=42|DC-01, Seite 42]]

$\varphi(n) := |\mathbb{Z}_n^*|$ (Anzahl der zu $n$ teilerfremden Zahlen in $\mathbb{Z}_n$)

- $\varphi(p) = p - 1$ für Primzahl $p$
- $\varphi(p^e) = p^{e-1}(p-1)$ für Primzahlpotenz $p^e$
- Für $n = p_1^{e_1} \cdots p_r^{e_r}$: $\displaystyle\varphi(n) = n \cdot \prod_{i=1}^r \left(1 - \frac{1}{p_i}\right)$

---

# Modulare Arithmetik – Teil 2 (DC-03)

> [[DC-03.pdf#page=7|DC-03, Seite 7–28]]

## Potenzen in $\mathbb{Z}_n^*$

Für $a \in \mathbb{Z}_n^*$ und $i \in \mathbb{Z}$: $a^i$ wie üblich definiert.

**Ordnung** von $a$: $o_n(a) := |\langle a \rangle|$ (Anzahl verschiedener Potenzen von $a$)
$$\langle a \rangle = \{1, a, a^2, \ldots, a^{o(a)-1}\}$$

**Satz**: $a^i = 1 \iff o(a) \mid i$

**Erzeuger** (primitives Element): $a$ heißt Erzeuger von $\mathbb{Z}_n^*$, falls $\langle a \rangle = \mathbb{Z}_n^*$.

## Chinesischer Restsatz

> [[DC-03.pdf#page=17|DC-03, Seite 17]]

Seien $n_1, \ldots, n_k \in \mathbb{N}$ paarweise teilerfremd, $n = n_1 \cdots n_k$.
Dann ist die Abbildung $\mathbb{Z}_n \to \mathbb{Z}_{n_1} \times \cdots \times \mathbb{Z}_{n_k}$, $a \mapsto (a \bmod n_1, \ldots, a \bmod n_k)$ ein Ringisomorphismus.

Anwendung in RSA: Berechnungen können aufgeteilt werden.
