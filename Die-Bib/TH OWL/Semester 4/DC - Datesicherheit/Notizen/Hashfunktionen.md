> Referenz: [[DC-02.pdf#page=59|DC-02, Seite 59–70]] (Kapitel 4)

# Definition

Eine **Hashfunktion** $H : M \to \{0,1\}^l$ bildet beliebig lange Eingaben auf einen **Hashwert** fester Länge $l$ (in Bit) ab.

Hashfunktionen sind **nicht injektiv** (Kollisionen sind unvermeidbar, da $|M| > 2^l$).

---

# Sicherheitseigenschaften

| Eigenschaft | Beschreibung | Angriff |
|---|---|---|
| **Einwegfunktion** (Preimage Resistance) | Aus Hashwert $y$ ist Urbild $m$ nicht berechenbar | Preimage-Angriff |
| **Schwache Kollisionsresistenz** (2nd Preimage Resistance) | Zu gegebenem $m$ ist kein $m' \neq m$ mit $H(m') = H(m)$ findbar | 2nd-Preimage-Angriff |
| **Starke Kollisionsresistenz** (Collision Resistance) | Keine zwei verschiedenen $m_1 \neq m_2$ mit $H(m_1) = H(m_2)$ findbar | Kollisionsangriff |

---

# SHA-256

- Ausgabelänge: **256 Bit**
- Familie: SHA-2 (Secure Hash Algorithm 2)
- Verbreitet in digitalen Signaturen, Passworthashing, Blockchains

---

# Anwendungsbeispiele

## Passwortdateien

> [[DC-02.pdf#page=63|DC-02, Seite 63]]

Statt Klartext-Passwörter werden **Hashwerte** gespeichert:
$$\text{Datei: } (u_i,\ H(p_i))$$

Bei Anmeldung: $H(p_{\text{eingabe}}) \stackrel{?}{=} H(p_i)$

**Problem**: Wörterbuchangriffe mit vorausberechneten Hashwerten.

**Schutz**: **Salt-Wert** $s_i$ (zufällig, pro Nutzer verschieden):
$$\text{Datei: } (u_i,\ s_i,\ H(p_i \| s_i))$$

Zusätzlich: **Iteration Count** → Hashfunktion wird $c$-mal angewendet → Brute-Force-Aufwand erhöhen.

---

# Brute-Force-Angriffe auf Hashfunktionen

> [[DC-02.pdf#page=65|DC-02, Seite 65]]

## Preimage-Angriff (Urbild finden)
- Ziel: Finde $m$ mit $H(m) = y$
- Erwartete Anzahl Versuche: $2^l$
- Mit $p = 0.5$: ca. $\ln(2) \cdot 2^l \approx 0{,}693 \cdot 2^l$ Versuche

## Kollisionssuche (Geburtstagsangriff)

> [[DC-02.pdf#page=66|DC-02, Seite 66]]

- Ziel: Finde $m_1 \neq m_2$ mit $H(m_1) = H(m_2)$
- **Geburtstagsparadoxon**: Mit ca. $\sqrt{2^l} = 2^{l/2}$ zufälligen Nachrichten findet man mit Wahrscheinlichkeit $> 0.5$ eine Kollision
- Wahrscheinlichkeit: $p(n, r) = \prod_{i=1}^{r-1}\left(1 - \frac{i}{n}\right) \leq e^{-\frac{r(r-1)}{2n}}$

**Konsequenz**: Bei $l = 128$ Bit ist Kollisionssuche mit $2^{64}$ Versuchen möglich → mindestens **256 Bit** für Kollisionsresistenz empfohlen.
