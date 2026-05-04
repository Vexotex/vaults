> Referenz: [[DC-01.pdf#page=47|DC-01, Seite 47–58]] (Kapitel 3)

# Überblick der Schutzziele

| Schutzziel | Englisch | Bedrohung | Maßnahme |
|---|---|---|---|
| Vertraulichkeit | Confidentiality / Privacy | Abhören, Mitlesen | Verschlüsselung |
| Integrität | Integrity | Manipulation von Daten | MAC, Signatur, Hashfunktion |
| Nachrichtenauthentizität | Message Authenticity | Fälschung, MITM | MAC, digitale Signatur |
| Nutzerauthentizität | User Authenticity | Identitätsbetrug | Passwort, Token, Biometrie |
| Zugriffskontrolle | Access Control | Unberechtigter Zugriff | ACL, RBAC |
| Nichtabstreitbarkeit | Non-Repudiation | Abstreiten von Aktionen | Digitale Signatur + PKI |
| Verfügbarkeit | Availability | DoS/DDoS, Ausfall | Redundanz, Backup |
| Anonymität | Anonymity | Rückverfolgung | Anonymisierungsverfahren |

---

# Vertraulichkeit (Confidentiality)

> [[DC-01.pdf#page=48|DC-01, Seite 48]]

**Gefährdung**: Unbefugtes Mitlesen von Daten bei Übertragung oder Speicherung.

**Beispiele**: E-Mail-Mitlesen, Homebanking-Abhören

**Schutzmaßnahme**: Symmetrische oder asymmetrische **Verschlüsselung**

---

# Integrität (Integrity)

> [[DC-01.pdf#page=49|DC-01, Seite 49]]

**Gefährdung**: Daten werden absichtlich verändert (Malware, MITM-Angriff).

**Unterschied zu Kommunikationstechnik**: CRC-Codes schützen nicht vor gezielten Angriffen, da ein Angreifer den Prüfwert einfach neu berechnen kann.

**Schutzmaßnahme**: **Hashfunktionen**, MACs, Signaturen

---

# Authentizität von Nachrichten (Message Authenticity)

> [[DC-01.pdf#page=51|DC-01, Seite 51]]

**Gefährdung**: Aktiver Angreifer (Charly) kann Nachrichten fälschen oder austauschen.
- **MITM-Angriff**: Charly schaltet sich zwischen Alice und Bob, liest alle Nachrichten und sendet beliebige Nachrichten weiter.

**Schutzmaßnahmen**:

## Digitale Signatur
- Alice hat privaten Schlüssel $sk_A$ (geheim) und öffentlichen Schlüssel $pk_A$ (öffentlich bekannt)
- Alice signiert Nachricht $m$: $\sigma = \text{Sign}_{sk_A}(m)$
- Bob verifiziert: $\text{Verify}_{pk_A}(m, \sigma) \in \{\text{TRUE}, \text{FALSE}\}$

## MAC-Verfahren (Message Authentication Code)
- Alice und Bob teilen geheimen Schlüssel $k_{A,B}$
- MAC-Wert: $h_{A,B}(m) := M_{k_{A,B}}(m)$
- Bob berechnet MAC selbst und vergleicht → nur Alice als Schlüsselbesitzerin kann authentischen MAC erzeugen

---

# Authentizität von Nutzern (User Authenticity)

> [[DC-01.pdf#page=53|DC-01, Seite 53]]

**Gefährdung**: Angreifer gibt sich als anderer Nutzer aus. Gefahr von **Replay-Angriffen**.

**Authentifizierungsmittel**:
- **Wissen** (z.B. Passwort, PIN)
- **Besitz** (Hardware-Token, Smartcard, Software-Token)
  - Software-Token: Schlüssel als Datei, verschlüsselt mit passwortbasiertem Schlüssel
- **Biometrie** (Fingerabdruck, Iris, Gesicht)

---

# Zugriffskontrolle (Access Control)

> [[DC-01.pdf#page=55|DC-01, Seite 55]]

**Komponenten**:
- Nutzerauthentifikation (Voraussetzung)
- **Access Control System** mit nutzer- oder rollenspezifischen Zugriffsregeln
- **Access Control Lists (ACL)**: Konfiguration der Zugriffsrechte

**RBAC** (Role Based Access Control): Rollen werden definiert, Rechte werden Rollen zugeordnet.

---

# Nichtabstreitbarkeit (Non-Repudiation)

> [[DC-01.pdf#page=56|DC-01, Seite 56]]

**Gefährdung**: Alice bestreitet, eine Nachricht gesendet zu haben.

**Schutzmaßnahme**: **Digitale Signatur + PKI**
- Zertifikat = signierte Daten (öffentlicher Schlüssel + Besitzerinformationen) von einer **Certification Authority (CA)**
- **PKI** (Public Key Infrastructure): Infrastruktur zur Verwaltung von Zertifikaten

---

# Verfügbarkeit (Availability)

> [[DC-01.pdf#page=57|DC-01, Seite 57]]

**Gefährdungen**:
- Netzwerkausfall von Infrastrukturkomponenten
- **(D)DoS-Angriffe** (Distributed Denial of Service) gegen Webdienste

**Schutzmaßnahmen**:
- Redundante, örtlich verteilte Datenspeicherung
- Regelmäßige Backups auf externen Medien

---

# Anonymität (Anonymity)

> [[DC-01.pdf#page=57|DC-01, Seite 57]]

**Gefährdung**: Rückverfolgung von Nutzeraktionen auf eine Person.

**Schutzmaßnahmen**: Anonymisierungsverfahren (z.B. Tor, Mix-Netzwerke)
