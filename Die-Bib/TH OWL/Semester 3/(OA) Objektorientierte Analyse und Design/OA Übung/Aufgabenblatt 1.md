[[Objektorientierung 2025.pdf]]

# Klassen und Instanzen

## Arbeitsanweisung
Erzeuge Klassendiagramme für Klassen, die in der folgenden Problembeschreibung benötigt werden: Es soll eine Parkhausverwaltung implementiert werden. Ein Parkhaus enthält Parkplätze. Diese können leer sein oder nicht. Ein Parkplatz soll angeben können, ob er leer ist oder nicht. Die Parkverwaltung soll einem Auto einen Parkplatz zuweisen können, und soll angeben können, wie viele Parkplätze frei sind. Implementiere die Klassen in einer Sprache deiner Wahl.

## Versuch

![[KlassenUndInstanzen.png]]

### in Python

```python
class Auto
	def __init__(self, kennzeichen) -> None:
		self.kennzeichen = kennzeichen

class Parkplatz:
	def __init__(self) -> None:
		self.besetzt = False
		self.auto = None
	
	def istBesetzt(self):
		return self.besetzt
	
	def besetzte(self, auto):
		if self.besetzt:
			raise ValueError("Parkplatz besetzt")
		self.auto = auto
		self.besetzt = True
	
	def auto_auf_parkplatz(self):
		if not self.besetzt:
			raise ValueError("Parkplatz nicht besetzt")
		return self.auto
	
	def leere(self):
		self.auto = None
		self.besetzt = False

class Parkhaus:
	def __init__(self, parkplaetze) -> None:
		self.parkplaetze = [Parkplatz() for _ in range (parkplaetze)]
	
	def weise_zu(self, auto):
		for parkplatz in self.parkplaetze:
			if not parkplatz.ist_besetzt():
				parkplatz.besetze(auto)
				return
		raise ValueError("Kein leerer Parkplatz")
	
	def freie_plaetze(self)
		i = 0
		for parkplatz in self.parkplätze:
			if parkplatz.ist_besetzt():
				i = i+1
		return i
	
	def entferne_auto(self, auto):
		for parkplatz in self.parkplaetze:
			if parkplatz.auto_auf_parkplatz() == auto
				parkplatz.leere()

```



---
# Vererbung
## Arbeitsanweisung
Erzeuge vererbte Klassen für folgende Dinge: Tier, Hund, Katze, Labrador, Fisch, Goldfisch, Spinne, Lurch, Schlumpf. Gebe hierfür Klassendiagramme an, und markiere die Beziehungen.

## Versuch
[[zu AB1]]


--- 

# Lösung
[[Blatt 1.pdf]]

