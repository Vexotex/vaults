> Referenz: [[DC-02.pdf#page=7|DC-02, Seite 7–26]] (Kapitel 1)

# Grundprinzip

> [[DC-02.pdf#page=8|DC-02, Seite 8]]

Bei **symmetrischen Verschlüsselungsverfahren** wird zur Ver- und Entschlüsselung derselbe Schlüssel $k$ (**Secret Key**) genutzt.

Zwei Klassen:
- **Stromverschlüsselung** (Stream Cipher): Zeichen für Zeichen
- **Blockverschlüsselung** (Block Cipher): Block für Block → [[Blockverschlüsselung]]

---

# Synchrone Stromverschlüsselung

> [[DC-02.pdf#page=9|DC-02, Seite 9]]

Die Verschlüsselung des $i$-ten Zeichens hängt **nur vom Schlüssel** ab (nicht von vorherigen Zeichen):
$$c_i = E^{(i)}(k, m_i)$$

Vorteil: Zeichen können **parallel** berechnet werden.

Beispiele: Monoalphabetisches Verfahren, Vigenère-Verfahren

---

# Synchrones Additives Stromverschlüsselungsverfahren

> [[DC-02.pdf#page=13|DC-02, Seite 13]]

Schlüsselstromgenerator erzeugt aus Schlüssel $k$ einen **Schlüsselstrom** $(z_1, z_2, \ldots)$.
Verschlüsselung durch Addition (XOR bei Bytes):
$$c_i = m_i + z_i$$

Entschlüsselung analog: $m_i = c_i - z_i = c_i + z_i$ (da $-z_i = z_i$ in $\mathbb{Z}_2$)

**Sicherheitsanforderung**: Kenntnis von $z_1, \ldots, z_i$ darf keinen Aufschluss über $z_{i+1}$ geben.

---

# Schlüsselstrom vs. One-Time-Pad

> [[DC-02.pdf#page=15|DC-02, Seite 15]]

Das **One-Time-Pad** ist ein spezielles synchrones additives Stromverschlüsselungsverfahren, bei dem der Schlüsselstrom aus echten Zufallszahlen besteht.

Ein **Schlüsselstromgenerator** ersetzt den physikalischen Zufallsprozess durch einen deterministischen Algorithmus. Dieser muss aber:
1. Statistisch gleichverteilte und unkorrelierte Schlüsselstromzeichen erzeugen
2. Für jeden Schlüssel $k$ einen anderen, unvorhersehbaren Strom produzieren

---

# Nonces zur Initialisierung

> [[DC-02.pdf#page=16|DC-02, Seite 16]]

Problem: Derselbe Schlüssel $k_{AB}$ darf **nie zweimal** zur Initialisierung verwendet werden.

Lösung: Gemeinsamer Schlüssel $k_{AB}$ wird um einen **Nonce-Wert** $\eta_m$ erweitert:
$$k = k_{AB} \| \eta_m$$

Der Nonce wird zusammen mit dem Geheimtext übertragen.

---

# ChaCha20

> [[DC-02.pdf#page=17|DC-02, Seite 17]]

In **TLS 1.3** (RFC 8446) standardisiertes Stromverschlüsselungsverfahren.
Spezifikation: RFC 8439 (*ChaCha20 and Poly1305 for IETF Protocols*)

**Schlüssellänge**: 256 Bit (32 Byte)
**Nonce**: 96 Bit (12 Byte)
**Maximale Schlüsselstromlänge**: $2^{38}$ Bytes

**Funktionsweise**:
- Interner Zustand: $4 \times 4$-Matrix aus 32-Bit-Wörtern
- Update-Funktion: **Quarter-Round** ($q$), bestehend aus Addition, XOR und Rotation
- 10 × 2 Quarter-Rounds pro Block (20 Runden insgesamt)
- Verwendung in HTTPS (zusammen mit AES als Alternative)

**Quarter-Round** (Kernoperation):
```
a += b; d ^= a; d = rot16(d)
c += d; b ^= c; b = rot12(b)
a += b; d ^= a; d = rot8(d)
c += d; b ^= c; b = rot7(b)
```

---

# Cipher-Instanzen in Java

> [[DC-02.pdf#page=25|DC-02, Seite 25]]

Nutzung kryptographischer Algorithmen in Java über `javax.crypto.Cipher`:
```java
Cipher cipher = Cipher.getInstance("ChaCha20");
cipher.init(Cipher.ENCRYPT_MODE, key, params);
byte[] ciphertext = cipher.doFinal(plaintext);
```
