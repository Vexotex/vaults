> Referenz: [[DC-03.pdf#page=45|DC-03, Seite 45–63]] (Kapitel 3)

# Grundidee

**RSA** (Rivest, Shamir, Adleman, 1977) ist ein asymmetrisches Verfahren für:
- **Verschlüsselung** (ohne vorherigen Schlüsselaustausch)
- **Digitale Signaturen** (Nichtabstreitbarkeit)

Sicherheit basiert auf der Schwierigkeit der **Primfaktorzerlegung** großer Zahlen.

---

# RSA-Schlüsselerzeugung

> [[DC-03.pdf#page=47|DC-03, Seite 47]]

1. Wähle zwei große verschiedene Primzahlen $p, q$ (je ca. 1024–2048 Bit)
2. Berechne $n = p \cdot q$ (**RSA-Modul**)
3. Berechne $\varphi(n) = (p-1)(q-1)$ (Euler'sche $\varphi$-Funktion)
4. Wähle $e$ mit $1 < e < \varphi(n)$ und $\text{ggT}(e, \varphi(n)) = 1$ (**öffentlicher Exponent**, typisch $e = 65537$)
5. Berechne $d = e^{-1} \bmod \varphi(n)$ (**privater Exponent**, mit erweitertem Euklid)

| Schlüssel | Inhalt | Verwendung |
|---|---|---|
| Öffentlich | $(n, e)$ | Verschlüsseln / Verifizieren |
| Privat | $(n, d)$ (+ $p$, $q$, CRT-Werte) | Entschlüsseln / Signieren |

**Euler'scher Satz**: Für $m$ mit $\text{ggT}(m, n) = 1$ gilt: $m^{\varphi(n)} \equiv 1 \pmod{n}$
Daher: $m^{ed} \equiv m \pmod{n}$, da $ed \equiv 1 \pmod{\varphi(n)}$

---

# RSA-Verschlüsselung

> [[DC-03.pdf#page=51|DC-03, Seite 51]]

**Verschlüsselung** (Alice → Bob, mit Bobs öffentlichem Schlüssel $(n, e)$):
$$c = m^e \bmod n$$

**Entschlüsselung** (Bob mit privatem Schlüssel $d$):
$$m = c^d \bmod n = (m^e)^d \bmod n = m^{ed} \bmod n = m$$

**Einschränkungen**:
- Nachricht muss in $\mathbb{Z}_n$ liegen ($m < n$)
- **Textbuch-RSA** ist deterministisch → gleicher Klartext → gleicher Geheimtext → unsicher
- Praxis: **OAEP-Padding** (Optimal Asymmetric Encryption Padding) für semantische Sicherheit

---

# RSA-Signaturverfahren

> [[DC-03.pdf#page=57|DC-03, Seite 57]]

**Signieren** (Alice mit privatem Schlüssel $d$):
$$\sigma = H(m)^d \bmod n$$

**Verifizieren** (Bob mit Alices öffentlichem Schlüssel $(n, e)$):
$$\sigma^e \bmod n \stackrel{?}{=} H(m)$$

- Hashfunktion $H$ wird benötigt, da RSA nur auf $\mathbb{Z}_n$ operiert
- Padding: **PSS** (Probabilistic Signature Scheme) für Sicherheitsnachweise

---

# Sicherheit von RSA

**Voraussetzung**: Primfaktorzerlegung von $n = p \cdot q$ ist nicht praktikabel.

- Mindestschlüssellänge: **2048 Bit** für $n$ (heute empfohlen)
- 4096 Bit für langfristige Sicherheit

**Angriffe**:
- Faktorisierung von $n$ → Berechnung von $\varphi(n)$ → privater Schlüssel bekannt
- Algorithmen: Quadratisches Sieb, Zahlkörpersieb

**Effizienzoptimierung** mit CRT (Chinesischer Restsatz):
- Entschlüsselung in $\mathbb{Z}_p$ und $\mathbb{Z}_q$ getrennt → ca. 4× schneller
