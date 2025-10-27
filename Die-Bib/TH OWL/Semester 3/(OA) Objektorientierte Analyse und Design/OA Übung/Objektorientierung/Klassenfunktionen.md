- Klassenfunktionen nutzen keine Referenz auf das Objekt selbst
- Man kann sie direkt auf der Klasse aufrufen, aber auch auf Objekten
- kann auf Daten in der Klasse zugreifen

Beispiel in Python:

@classmethod
def reden(cls):
	return "Hallo"
	return cls.gruss
