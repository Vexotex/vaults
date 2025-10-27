- Eine Klasse beschreibt einen Bauplan für ein Objekt
- Sie legt fest, welche Daten und Funktionen Objekte haben
- Ein Objekt ist eine konkrete Instanz einer Klasse

Beispiel: Ein Mensch besitzt ein Alter, eine Größe, und eine E-mail-Adresse. Ein Mensch kann sein Alter und seine Größe nennen. Sebastian ist 37, 185cm groß, und wenn er gefragt wird, nennt er sein Alter und seine Größe.

# Beispiel in PlantUML:

@startuml
	class Mensch {
	- alter: int
	- groesse: int
	- emailAdresse: String
	+ alterNennen(): int
	+ groesseNennen(): int
}
@enduml


werden zu [[Instanz]] wenn initiiert