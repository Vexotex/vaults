# 3 [[2026-04-27 - DB - 03 - P - Datenbankentwurf.pdf]]

## 3.1.1 Welche Ziele verfolgt diese Datenbank? 
Ziel dieser Datenbank ist es, vorhandene Informationen zu alten Obstsorten zur Verfügung zu stellen, damit man:
- Entscheidungshilfen hat für die Auswahl und Anpflanzung alter Obstsorten
- unbekannte Sorten leichter bestimmen kann und
- Hintergrundinformationen über die Herkunft und Entstehung zur Verfügung hat.

## 3.1.2 Welche Informationen sind hier niedergeschrieben und in welcher Beziehung stehen diese zueinander?
eine Auflistung aller Sorten von Obst und deren Synonyme. Die zuordnung der Baüme, Blüten und Früchte mit den jeweiligen Bildern zur Identifizierung.

## ![[3.2 Muster]]


# 4 [[2026-05-04 - DB - 04 - P - Das relationale Modell.pdf]]

- [[Obstsorte]]
	- O_ID (P)
	- Name
	- Allergieverträglichkeit
	- Obstart (F)
- [[Obstart]]
	- Name (P)
- [[Region - Gebiet]]
	- R_ID (P)
	- Bezeichnung
- [[wächst in]]
	- R_ID (F)
	- O_ID (F)
- [[Bezugsquellen]]
	- B_ID (P)
	- Addresse
	- Name
- [[erhältlich in]]
	- B_ID (F)
	- O_ID (F)
- [[dargestellt]]
	- D_ID (P)
	- Link
	- O_ID (F)
- [[Literatur]]
	- L_ID (P)
	- Author
	- Titel
	- Datum
- [[referenz in]]
	- L_ID (F)
	- O_ID (F)
- [[Synonym]]
	- S_ID (P)
	- S_Name
	- O_ID (F)