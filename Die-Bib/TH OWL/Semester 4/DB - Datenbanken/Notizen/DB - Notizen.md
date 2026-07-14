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
SELECT * FROM professoren
```
## 8.14
``` sql 
SELECT PersNr, Name FROM professoren
```
## 8.15
``` sql 
SELECT p.PersNr, p.Name  
FROM professoren p  
WHERE p. Rang = 'C4'
```
## 8.16
``` sql 
SELECT p.PersNr, p.Name  
FROM professoren p  
ORDER BY p.Rang
```
## 8.17
``` sql 
SELECT p.Rang  
FROM professoren p
```
## 8.18
``` sql 
SELECT DISTINCT p.Rang  
FROM professoren p
```
## 8.19
``` sql 
SELECT DISTINCT s.Name, s.Semester  
FROM studenten s
```
## 8.20
``` sql 
SELECT DISTINCT s.Name, s.Semester  
FROM studenten s  
WHERE s.Semester >= 5
```
## 8.21 
``` sql 
SELECT DISTINCT s.Name, s.Semester  
FROM studenten s  
WHERE s.Semester >= 5  
GROUP BY s.Semester ASC
```
## 8.22
``` sql 
SELECT * FROM hoeren
```
---
Abfragen über mehrere  Relationen 
## 8.23
``` sql 
SELECT p.Name  
FROM professoren p  
WHERE p.PersNr = (  
    SELECT v.gelesenVon  
    FROM vorlesungen v  
    WHERE v.Titel = 'Logik'
    )
```
## 8.24
``` sql 
SELECT s.Name, s.MatrNr  
FROM studenten s  
WHERE s.MatrNr IN (  
    SELECT h.MatrNr  
    From hoeren h  
    WHERE h.VorlNr = (  
        SELECT v.VorlNr  
        FROM vorlesungen v  
        WHERE v.Titel = 'Glaube und Wissen'  
        )  
    )
```
## 8.25
``` sql 
SELECT s.Name, s.MatrNr, v.Titel  
FROM studenten s  
JOIN hoeren h ON s.MatrNr = h.MatrNr  
JOIN vorlesungen v ON h.VorlNr = v.VorlNr  
WHERE v.gelesenVon = (  
    SELECT PersNr  
    FROM professoren  
    WHERE Name = 'Kant'  
);
```
oder
```SQL
SELECT s.Name, s.MatrNr, v.Titel
FROM studenten s, hoeren h, vorlesungen v
WHERE s.MatrNr = h.MatrNr
  AND h.VorlNr = v.VorlNr
  AND v.gelesenVon = (
      SELECT PersNr
      FROM professoren
      WHERE Name = 'Kant'
  );
```
## 8.26
``` sql 
SELECT p.Name  
FROM professoren p  
  
UNION  
  
SELECT a.Name  
FROM assistenten a
```

## 8.27
``` sql 
SELECT Name  
FROM professoren  
  
UNION  
  
SELECT Name  
FROM assistenten  
  
GROUP BY Name
```
## 8.28
``` sql 
SELECT Name, Position  
FROM (  
    SELECT Name, 'Professor' AS Position FROM professoren  
    UNION  
    SELECT Name, 'Assistent' FROM assistenten  
) AS Angestellte  
  
GROUP BY Name
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


# 11 [[2026-06-29 - DB - 11 - P - XML-Einstieg.pdf]]

## 11.1
```xPath
/Name
```

## 11.2
```xPath
avg(//@Note)
```

## 11.3
```xPath
//Professor[@Rang="C4"]/concat(@PersNr , " " , Name/text())
```

## 11.4
```xPath
//Student[@Semester > 5]/concat(Name/text() , " ", @Semester)
```

## 11.5

Geht nicht in XPath




# 12 [[2026-07-06 - DB - 12 - P - XML - XSLT-XQuery .pdf]]
## 12.1



## 12.2
### 12.2.1
```Xquery
xquery version "3.1";

for $x in (//Name)
return $x

```

### 12.2.2
```Xquery
xquery version "3.1";

for $rang in distinct-values(//Professor/@Rang)
order by $rang
return $rang

```

### 12.2.3
```Xquery
xquery version "3.1";

for $stud in //Student
where some $h in //hoert satisfies $h/@MatrNr = $stud/@MatrNr
return $stud/Name
```


### 12.2.4
```Xquery
xquery version "3.1";

let $Anzahl := count(//Vorlesung)
return $Anzahl
```

### 12.2.5
```Xquery
xquery version "3.1";

count(distinct-values(//Student/@Semester))
```

### 12.2.6
```Xquery
xquery version "3.1";

for $prof in (//Professor)
where some $v in (//Vorlesung) satisfies $prof/@PersNr = $v/@gelesenVon 
return $prof/Name
```


### 12.2.7
```Xquery
xquery version "3.1";

max(distinct-values(//Student/@Semester))
```

### 12.2.8
```Xquery
for $p in //Professor
let $sws := sum(//Vorlesung[@gelesenVon = $p/@PersNr]/@SWS)
return 
<Professor>{$p/Name} {$sws}</Professor>
```

### 12.2.9
```Xquery
for $s in //Student
where every $p in //pruef[@MatrNr = $s/@MatrNr] 
satisfies $p/@Note >= 3.0
return $s/Name
```
