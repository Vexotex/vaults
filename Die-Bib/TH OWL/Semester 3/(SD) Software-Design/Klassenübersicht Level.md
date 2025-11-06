
```
@startuml
class Level{
    + Kamele: List<Kamel>
    + Bahnhof: List<Platz>
    + Personen: List<Person>
    + Highscroe: Levelstate
    + Lowscore: Levelstate
    + Score: int
    - Bedürfnis_anzeigen(Person): str
    - Person_umsetzten(Person, Kamel, int Zielplatz): void
    - Person_an_Bahnhof_stellen(Person, int Zielplatz): void
    - Caravanen_abfahrt(): void
    - Person_inspizieren(): str
    - Score_berechnen(): void
    - Person_zurückgeben(int Aufentahlsort, int, int): Person
}
class Kamel{
    + Plätze: List<Platz>
}
class Platz{
    + Besetzer: Person
    + Bedürfnisse: List<str>
}
class DB{
    + HighDict: [int], Levelstate
    + LowDict: [int], Levelstate
}
class Levelstate{
    + Kamele: List<Kamel>
    + Score: int
    + Plaetze: List<Platz>
    + Personen: List<Person>
}
class Person{
    + Name
    + Zufriedenheit: int
    + Bedürfnisse: Hashmap<Bedürfnis>
    + Platz: int, int
    + Aufenthaltsort: int
    - get_Zufriedenheit(): int
    - get_Bedürfnisse(): Hashmap<Bedürfnis>
    - Zufriedenheit_berechnen(): void
}
class Bedürfnis{
    + Beschreibung: <str>
    + Befriedigung: int
    - getBefriedigung(void): int
    - Befriedigung_berechnen(): void
}

Level o-- Levelstate
Level o-- Person
DB o-- Levelstate
Kamel o-- Platz
Level o-- Kamel
Level o-- Platz
Person o--Bedürfnis


@enduml
```