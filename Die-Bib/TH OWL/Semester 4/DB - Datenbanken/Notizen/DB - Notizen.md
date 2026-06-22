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

[[4.canvas]]





# 6 [[2026-06-01 - DB - 07 - P - SQL-DDL.pdf]]



# 8 [[2026-06-08 - DB - 08 - P - SQL 2.pdf]]

---
Mengenoperationen
## 8.1
``` sql
select Name from professoren  
union  
select Name from assistenten;
```

## 8.2
``` sql 
select p.*  
from professoren p  
where not exists(  
    select *  
    from vorlesungen v  
    where v.gelesenVon = p.PersNr  
);
```
## 8.3
```sql
select p.*  
from professoren p  
where not exists(  
    select *  
    from assistenten a  
    where a.boss = p.PersNr  
);
```

*ODER*

``` sql 
SELECT Name  
FROM professoren  
WHERE PersNr NOT IN (  
    SELECT gelesenVon  
    FROM vorlesungen  
);
```

## 8.4
``` sql 
SELECT Name  
FROM studenten  
where Semester >= all (  
    select Semester  
    from studenten  
);
```

--- 
Aggregat und Gruppierung
## 8.5
``` sql 
SELECT avg(Note)  
from pruefen;
```
# 8.6
``` sql 
SELECT min(Note)  
from pruefen;
```
## 8.7
``` sql 
select sum(Semester)  
from studenten;
```
## 8.8
``` sql 
select count(Note)  
from pruefen  
where Note = 1;
```
## 8.9
``` sql 
select professoren.Name, sum(vorlesungen.SWS)  
from professoren, vorlesungen  
where vorlesungen.gelesenVon = professoren.PersNr  
group by professoren.Name;
```
---
Outer Joins
## 8.10
``` sql 
select s.name, p.Note
from studenten s left outer join pruefen p on s.MatrNr = p.MatrNr;
```
## 8.11
``` sql 
select *  
FROM assistenten  
RIGHT OUTER JOIN professoren ON professoren.PersNr = assistenten.Boss
```
## 8.12
``` sql 
select s.MatrNr, s.Name, h.VorlNr  
FROM studenten s  
LEFT OUTER JOIN hoeren h ON s.MatrNr = h.MatrNr
```
--- 
Abfragen über eine Relation
## 8.13
``` sql 

```
## 8.14
``` sql 

```
## 8.15
``` sql 

```
## 8.16
``` sql 

```
## 8.17
``` sql 

```
## 8.18
``` sql 

```
## 8.19
``` sql 

```
## 8.20
``` sql 

```
## 8.21 
``` sql 

```
## 8.22
``` sql 

```
---
Abfragen über mehrere Relationen
## 8.23
``` sql 

```
## 8.24
``` sql 

```
## 8.25
``` sql 

```
## 8.26
``` sql 

```
## 8.27
``` sql 

```
## 8.28
``` sql 

```


# 10 [[2026-06-22 - DB - 10 - P - SQL - Optimierung - Anwendungsentwicklung.pdf]]

## 10.1 
**Führen Sie die SQL-Anweisung auf Seite 11 aus der aktuellen Vorlesung aus und schauen Sie sich den Ausführungsplan an.**
``` sql
SELECT stud.Name , stud.MatrNr FROM studenten stud, hoeren ho, vorlesungen vl, professoren prof   
WHERE stud.MatrNr = ho.MatrNr AND ho.VorlNr = vl.VorlNr AND vl.gelesenVon = prof.PersNr AND prof.Name = 'Kant';
```
Durch welche Optimierungsmaßnahmen lässt sich die Abfrage beschleunigen? Führen Sie diese aus und betrachten Sie den schrittweisen Zeitgewinn.
- indices setzten -> B-Tree wird erzeugt -> $\log_{2}(n)$ Suchzeit aber mehr speicherverbrauch für den B-Tree
- Datenbak-aufbau für lesen oder schreiben obtimieren
	- viele Table wenig Spalten -> hohe Schreibgeschwindigkeit
	- wenig Table viele Spalten -> hohe Lesegeschwindigkeit


**Was ist der Unterschied zwischen einem Full Table Scan und einer Index-Suche?**
