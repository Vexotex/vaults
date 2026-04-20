Quelle: Teil 3 – Einschleifiger Regelkreis

## Struktur
$$w \rightarrow [+] \rightarrow G_R(s) \rightarrow G_A(s) \rightarrow G_P(s) \rightarrow y$$
$$y_m \leftarrow G_M(s) \leftarrow y$$

**Streckenübertragungsfunktion**: $G_S(s) = G_A(s) \cdot G_P(s) \cdot G_M(s)$

## Wichtige Übertragungsfunktionen
- **Offener Kreis**: $G_o(s) = G_R(s) \cdot G_S(s)$
- **Führungsübertragungsfunktion**: $G_w(s) = \dfrac{G_o(s)}{1 + G_o(s)}$
- **Störübertragungsfunktion**: $G_z(s) = \dfrac{G_S(s)}{1 + G_o(s)}$

## Reglerentwurfsziel
$G_R(s)$ so wählen, dass: Stabilität + gutes Führungsverhalten + gutes Störverhalten
