


# AccessAspect
## Arbeitsanweisung

Designe und implementiere einen AccessAspect. Der AccessAspect kann überprüfen, ob Lese- oder Schreibberechtigungen vorliegen.

## Versuch



---
# Komposition von Klassen
## Arbeitsanweisung

Erstelle eine Klassenstruktur für ein Flugzeug mithilfe von Komposition. Das Flugzeug soll aus mehreren Komponenten bestehen, darunter Triebwerke, Flügel und Fahrwerk. Jede dieser Komponenten sollte eine eigene Klasse sein. 

1. Erstelle eine Klasse Triebwerk, die die Methoden start und stop enthält. Die Methode start soll "Triebwerk gestartet" ausgeben, und die Methode stop soll "Triebwerk gestoppt" ausgeben.
2. Erstelle eine Klasse Flügel, die die Methode hebe_ab enthält. Diese Methode soll "Flugzeug hebt ab" ausgeben.
3. Erstelle eine Klasse Fahrwerk, die die Methode lande enthält. Diese Methode soll "Flugzeug landet" ausgeben.
4. Erstelle schließlich eine Klasse Flugzeug, die die oben genannten Komponenten als Attribute verwendet, indem Sie Instanzen dieser Klassen in ihrer __init__-Methode erstellen.

## Versuch

```python
class Triebwerk:
    """Klasse für das Triebwerk des Flugzeugs"""
    
    def __init__(self, name):
        self.name = name
        self.ist_gestartet = False
    
    def start(self):
        """Startet das Triebwerk"""
        if not self.ist_gestartet:
            self.ist_gestartet = True
            print(f"{self.name}: Triebwerk gestartet")
        else:
            print(f"{self.name}: Triebwerk läuft bereits")
    
    def stop(self):
        """Stoppt das Triebwerk"""
        if self.ist_gestartet:
            self.ist_gestartet = False
            print(f"{self.name}: Triebwerk gestoppt")
        else:
            print(f"{self.name}: Triebwerk ist bereits gestoppt")
    
    def __str__(self):
        return f"Triebwerk '{self.name}' - Status: {'gestartet' if self.ist_gestartet else 'gestoppt'}"

class Flügel:
    """Klasse für die Flügel des Flugzeugs"""
    
    def __init__(self, spannweite):
        self.spannweite = spannweite
        self.klappen_ausgefahren = False
    
    def hebe_ab(self):
        """Lässt das Flugzeug abheben"""
        print("Flugzeug hebt ab")
        self.klappen_ausgefahren = True
        print("Landeklappen ausgefahren")
    
    def klappen_einfahren(self):
        """Fährt die Landeklappen ein"""
        if self.klappen_ausgefahren:
            self.klappen_ausgefahren = False
            print("Landeklappen eingefahren")
        else:
            print("Landeklappen sind bereits eingefahren")
    
    def __str__(self):
        return f"Flügel mit {self.spannweite}m Spannweite - Klappen: {'ausgefahren' if self.klappen_ausgefahren else 'eingefahren'}"

class Fahrwerk:
    """Klasse für das Fahrwerk des Flugzeugs"""
    
    def __init__(self, anzahl_räder):
        self.anzahl_räder = anzahl_räder
        self.ist_ausgefahren = True
        self.ist_verriegelt = True
    
    def lande(self):
        """Lässt das Flugzeug landen"""
        if not self.ist_ausgefahren:
            self.ausfahren()
        print("Flugzeug landet")
        self.ist_verriegelt = True
    
    def ausfahren(self):
        """Fährt das Fahrwerk aus"""
        if not self.ist_ausgefahren:
            self.ist_ausgefahren = True
            self.ist_verriegelt = True
            print("Fahrwerk ausgefahren und verriegelt")
        else:
            print("Fahrwerk ist bereits ausgefahren")
    
    def einfahren(self):
        """Fährt das Fahrwerk ein"""
        if self.ist_ausgefahren:
            self.ist_ausgefahren = False
            self.ist_verriegelt = False
            print("Fahrwerk eingefahren")
        else:
            print("Fahrwerk ist bereits eingefahren")
    
    def __str__(self):
        status = "ausgefahren" if self.ist_ausgefahren else "eingefahren"
        verriegelung = "verriegelt" if self.ist_verriegelt else "nicht verriegelt"
        return f"Fahrwerk mit {self.anzahl_räder} Rädern - Status: {status}, {verriegelung}"

class Flugzeug:
    """Hauptklasse für das Flugzeug, das Komposition verwendet"""
    
    def __init__(self, name, anzahl_triebwerke=2, flügel_spannweite=30, anzahl_räder=3):
        self.name = name
        self.ist_in_der_luft = False
        
        # Komposition: Erstellen der Komponenten
        self.triebwerke = [Triebwerk(f"Triebwerk {i+1}") for i in range(anzahl_triebwerke)]
        self.flügel = Flügel(flügel_spannweite)
        self.fahrwerk = Fahrwerk(anzahl_räder)
    
    def startvorbereitung(self):
        """Bereitet das Flugzeug für den Start vor"""
        print(f"\n=== {self.name} Startvorbereitung ===")
        
        # Triebwerke starten
        for triebwerk in self.triebwerke:
            triebwerk.start()
        
        # Fahrwerk verriegeln
        self.fahrwerk.ausfahren()
    
    def abheben(self):
        """Lässt das Flugzeug abheben"""
        print(f"\n=== {self.name} Abheben ===")
        
        # Prüfen ob Triebwerke laufen
        if all(triebwerk.ist_gestartet for triebwerk in self.triebwerke):
            self.flügel.hebe_ab()
            self.fahrwerk.einfahren()
            self.ist_in_der_luft = True
            print(f"{self.name} ist in der Luft!")
        else:
            print("Fehler: Nicht alle Triebwerke sind gestartet!")
    
    def landen(self):
        """Lässt das Flugzeug landen"""
        print(f"\n=== {self.name} Landen ===")
        
        if self.ist_in_der_luft:
            self.fahrwerk.lande()
            self.flügel.klappen_einfahren()
            self.ist_in_der_luft = False
            print(f"{self.name} ist sicher gelandet!")
        else:
            print("Flugzeug ist bereits am Boden")
    
    def parken(self):
        """Bereitet das Flugzeug für das Parken vor"""
        print(f"\n=== {self.name} Parken ===")
        
        # Triebwerke stoppen
        for triebwerk in self.triebwerke:
            triebwerk.stop()
        
        print(f"{self.name} ist parkbereit")
    
    def vollständiger_flug(self):
        """Führt einen kompletten Flug durch"""
        self.startvorbereitung()
        self.abheben()
        self.landen()
        self.parken()
    
    def status(self):
        """Zeigt den aktuellen Status des Flugzeugs"""
        print(f"\n=== {self.name} Status ===")
        print(f"Flugzustand: {'In der Luft' if self.ist_in_der_luft else 'Am Boden'}")
        print(f"Anzahl Triebwerke: {len(self.triebwerke)}")
        
        for triebwerk in self.triebwerke:
            print(f"  - {triebwerk}")
        
        print(f"  - {self.flügel}")
        print(f"  - {self.fahrwerk}")
    
    def __str__(self):
        return f"Flugzeug '{self.name}' - {'In der Luft' if self.ist_in_der_luft else 'Am Boden'}"
```


---
# Lösung
