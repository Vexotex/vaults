> Referenz: [[DC-02.pdf#page=76|DC-02, Seite 76–80]] (Kapitel 5)

Schutzziel: [[IT-Sicherheit Schutzziele#Authentizität von Nachrichten (Message Authenticity)|Nachrichtenauthentizität]]

# Grundprinzip

Ein **MAC** (Message Authentication Code) sichert die Authentizität einer Nachricht bei **gemeinsamem geheimen Schlüssel**.

Alice und Bob teilen Schlüssel $k_{A,B}$:
- Alice berechnet $h = M_{k_{A,B}}(m)$ und sendet $(m, h)$
- Bob berechnet $M_{k_{A,B}}(m)$ selbst und vergleicht mit $h$

→ Nur Alice (als Schlüsselbesitzerin) kann den korrekten MAC erzeugen.

**Unterschied zur Signatur**: MAC erfordert gemeinsamen geheimen Schlüssel → keine Nichtabstreitbarkeit.

---

# HMAC (Hash-based MAC)

> [[DC-02.pdf#page=77|DC-02, Seite 77]]

Konstruktion eines MACs aus einer **Hashfunktion** $H$ und Schlüssel $k$:
$$\text{HMAC}_k(m) = H\bigl((k \oplus \text{opad}) \| H((k \oplus \text{ipad}) \| m)\bigr)$$

- `ipad` = `0x36` × Blocklänge
- `opad` = `0x5C` × Blocklänge
- Zwei Durchläufe durch die Hashfunktion schützen gegen Längen-Erweiterungsangriffe

Standardisiert in **RFC 2104**.

Beispiel: `HMAC-SHA-256` → 256-Bit-Authentifizierungstag

In Java: `Mac.getInstance("HmacSHA256")`

---

# CMAC und CBC-MAC

> [[DC-02.pdf#page=79|DC-02, Seite 79]]

Konstruktion eines MACs aus einem **Blockverschlüsselungsverfahren** $E$:

## CBC-MAC (Cipher Block Chaining MAC)
$$c_0 = 0, \quad c_i = E_k(m_i \oplus c_{i-1}), \quad \text{MAC} = c_r$$

**Problem**: Unsicher für **variable Nachrichtenlängen** → CBC-MAC nur für feste Längen verwenden.

## CMAC (Cipher-based MAC)
- Erweiterung von CBC-MAC
- Verwendet zwei zusätzliche abgeleitete Schlüssel $K_1, K_2$ für den letzten Block
- Sicher für **variable Längen**
- Standardisiert in NIST SP 800-38B

In Java: `Mac.getInstance("AESCMAC")`
