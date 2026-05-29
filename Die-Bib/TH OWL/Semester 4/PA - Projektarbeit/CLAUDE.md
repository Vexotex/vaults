# Projektarbeit: OPC UA ↔ AAS Integration Layer

## Kontext

Projektarbeit an der TH OWL (inIT - Institute Industrial IT, AG Vernetzte Automatisierungssysteme).
Ziel: Eine Festo-Produktionsanlage (Labormaßstab) über OPC UA und AAS (Asset Administration Shell / Verwaltungsschale) ansteuerbar machen.

## Aufgabe

1. OPC UA Informationsmodell (NodeSet XML) in AAS-Submodels konvertieren ✅
2. AAS-Struktur per Python in BaSyx laden ✅
3. Integration Layer implementieren:
   - OPC UA → AAS (Monitoring: Sensorwerte live in AAS schreiben)
   - AAS → OPC UA (Steuerung: Skill-Aufrufe aus AAS als OPC UA Methoden weiterleiten)

## Architekturentscheidung

**Eine AAS pro Band** (Band1, Band2, Band3) — nicht eine große AAS für das gesamte ProductionModule.
Begründung: modulare Bauweise der Anlage, einfache Erweiterbarkeit um Band4.

## Anlagenstruktur (aus NodeSet)

```
ProductionModule
├── Band1
│   ├── Transferband       (Sensors: LightBarrierLeft/Right | Commands: RunLeft/Right/SlowMode/Stop | Skills: StartConveyorLeft/Right, StopConveyor)
│   ├── StackMagazine      (Sensors: MagazineRetracted/Extended/Empty | Commands: ExtendCylinder/RetractCylinder | Skills: DispenseWorkpiece)
│   ├── HeightMeasurement  (Sensors: WorkpiecePresent | Measurements: HeightValue | Skills: ReadHeight)
│   └── SignalTower        (Commands: Red/Yellow/Green | Skills: SetSignalState)
├── Band2
│   ├── Transferband
│   ├── TurningUnit        (Sensors: WorkpiecePresent/CylinderUp/Down/GripperAt0/180 | Commands: MoveCylinder/Rotate | Skills: LiftWorkpiece/LowerWorkpiece/RotateTo0/180)
│   ├── GripperUnit        (Sensors: GripperOpen/Closed | Commands: OpenGripper/CloseGripper | Skills: OpenGripperSkill/CloseGripperSkill)
│   └── SignalTower
└── Band3
    ├── Transferband
    ├── SwitchUnit         (Sensors: SwitchOpen/OpticalWorkpieceDetected/WorkpiecePresentAtSwitch | Commands: CloseSwitch | Skills: CloseSwitchSkill/SortWorkpieceToSlide)
    ├── PneumaticUnit      (Sensors: AirActivationPosition/DeactivationPosition | Commands: Activate/DeactivateCompressedAir | Skills: ActivateCompressedAirSkill/DeactivateCompressedAirSkill/MoveWorkpieceByAir)
    ├── TiltingUnit        (Sensors: WorkpieceAtTiltingPosition | Commands: TiltWorkpiece | Skills: TiltWorkpieceSkill)
    ├── ReturnUnit         (Sensors: SlideFull | Skills: CheckReturnSlide)
    └── SignalTower
```

Jedes Modul folgt exakt diesem Muster:
- `Sensors/`      → read-only Variablen (Boolean/Double)
- `Commands/`     → write Variablen (Boolean)
- `Measurements/` → read-only Messwerte (Double)
- `Skills/`       → aufrufbare Methoden (UAMethod)

## NodeSet → AAS Mapping

| OPC UA | AAS |
|---|---|
| UAObject (BandX) | AssetAdministrationShell |
| UAObject (Modul, z.B. Transferband) | Submodel |
| UAObject (Sensors/Commands/Skills/Measurements) | SubmodelElementCollection |
| UAVariable Boolean | Property, valueType: xs:boolean |
| UAVariable Double  | Property, valueType: xs:double  |
| UAMethod           | Operation |

Detaillierte Mapping-Dokumentation: `mapping.md`

## Tech Stack

| Komponente | Tool |
|---|---|
| OPC UA Server (simuliert) | CODESYS Soft PLC (Windows 11 VM) |
| OPC UA Client (Test) | UaExpert |
| OPC UA Informationsmodell | UaModeler (NodeSet2 XML) |
| AAS Environment | BaSyx `eclipsebasyx/aas-environment:2.0.0-SNAPSHOT` |
| AAS Registry | BaSyx `eclipsebasyx/aas-registry-log-mem:2.0.0-SNAPSHOT` |
| Submodel Registry | BaSyx `eclipsebasyx/submodel-registry-log-mem:2.0.0-SNAPSHOT` |
| AAS GUI | BaSyx `eclipsebasyx/aas-gui` |
| XML parsen | Python `xml.etree.ElementTree` (stdlib) |
| AAS bauen | Python `basyx-python-sdk` (Fraunhofer) |
| OPC UA Client (Python) | `asyncua` |
| HTTP zu BaSyx | `requests` |

## BaSyx Docker Setup

### Projektstruktur
```
~/basyx/
├── docker-compose.yml
├── basyx-infra.yml          ← GUI-Endpunkt-Konfiguration (wird in aas-gui gemountet)
├── aas-data/                ← optionaler Persistenz-Ordner
└── basyx/
    └── aas-env.properties   ← Spring Boot Properties für aas-env
```

### docker-compose.yml (aktueller Stand)
```yaml
services:
  aas-env:
    image: eclipsebasyx/aas-environment:2.0.0-SNAPSHOT
    container_name: aas-env
    ports:
      - "8081:8081"
    environment:
      - BASYX_CORS_ALLOWED-ORIGINS=*
      - BASYX_CORS_ALLOWED-METHODS=GET,POST,PATCH,PUT,DELETE,OPTIONS,HEAD
    volumes:
      - ./aas-data:/application/aas
      - ./basyx/aas-env.properties:/application/application.properties
    restart: unless-stopped

  aas-registry:
    image: eclipsebasyx/aas-registry-log-mem:2.0.0-SNAPSHOT
    container_name: aas-registry
    ports:
      - "8082:8080"
    environment:
      - SERVER_PORT=8080
      - BASYX_CORS_ALLOWED-ORIGINS=*
      - BASYX_CORS_ALLOWED-METHODS=GET,POST,PATCH,PUT,DELETE,OPTIONS,HEAD
    restart: unless-stopped

  submodel-registry:
    image: eclipsebasyx/submodel-registry-log-mem:2.0.0-SNAPSHOT
    container_name: submodel-registry
    ports:
      - "8083:8080"
    environment:
      - SERVER_PORT=8080
      - BASYX_CORS_ALLOWED-ORIGINS=*
      - BASYX_CORS_ALLOWED-METHODS=GET,POST,PATCH,PUT,DELETE,OPTIONS,HEAD
    restart: unless-stopped

  aas-gui:
    image: eclipsebasyx/aas-gui
    container_name: aas-gui
    ports:
      - "3000:3000"
    volumes:
      - ./basyx-infra.yml:/basyx-infra.yml
    environment:
      ALLOW_EDITING: "true"
      ALLOW_UPLOADING: "true"
      AAS_REPO_PATH: "http://localhost:8081"
      SUBMODEL_REPO_PATH: "http://localhost:8081"
      CD_REPO_PATH: "http://localhost:8081"
      AAS_REGISTRY_PATH: "http://localhost:8082"
      SUBMODEL_REGISTRY_PATH: "http://localhost:8083"
    restart: unless-stopped
```

### basyx/aas-env.properties
```properties
basyx.cors.allowed-origins=*
basyx.cors.allowed-methods=GET,POST,PATCH,PUT,DELETE,OPTIONS,HEAD
```

### basyx-infra.yml
```yaml
infrastructures:
  default: local

  local:
    name: Local BaSyx
    components:
      aasRegistry:
        baseUrl: "http://localhost:8082"
        hasDiscoveryIntegration: false
      submodelRegistry:
        baseUrl: "http://localhost:8083"
      aasRepository:
        baseUrl: "http://localhost:8081"
      submodelRepository:
        baseUrl: "http://localhost:8081"
      conceptDescriptionRepository:
        baseUrl: "http://localhost:8081"
    security:
      type: none
```

**Wichtig:** `default: local` ist ein Key-Verweis auf den Block darunter, keine verschachtelte Map.
Die Registry-Registrierung erfolgt manuell durch `nodeset_to_aas.py`, nicht automatisch durch den Server.

## BaSyx REST API Endpunkte

- AAS Environment:    `http://localhost:8081`
- AAS Registry:       `http://localhost:8082`
- Submodel Registry:  `http://localhost:8083`
- Web UI:             `http://localhost:3000`

```
# AAS Environment (8081)
POST   /shells                                                  → AAS anlegen
POST   /submodels                                               → Submodel anlegen
GET    /submodels/{base64id}/submodel-elements/{idShort}        → Wert lesen
PATCH  /submodels/{base64id}/submodel-elements/{idShort}        → Wert schreiben
POST   /submodels/{base64id}/submodel-elements/{idShort}/invoke → Operation aufrufen

# AAS Registry (8082)
POST   /shell-descriptors                                       → AAS registrieren
GET    /shell-descriptors                                       → alle AAS auflisten

# Submodel Registry (8083)
POST   /submodel-descriptors                                    → Submodel registrieren
GET    /submodel-descriptors                                    → alle Submodels auflisten
```

Hinweis: IDs sind base64url-enkodiert in den URL-Pfaden.

## Status

### ✅ Erledigt
- `nodeset_to_aas.py` läuft, alle 3 AAS korrekt in BaSyx geladen und registriert
- BaSyx GUI zeigt alle 3 Bänder mit Submodels korrekt an
- CORS konfiguriert und verifiziert
- Voller BaSyx V2 Stack (Environment + AAS Registry + Submodel Registry + GUI) läuft

### 🔲 Offen: Integration Layer (`integration_layer.py`)
- OPC UA → AAS (Monitoring: Sensorwerte live in AAS schreiben)
- AAS → OPC UA (Steuerung: Skill-Aufrufe aus AAS als OPC UA Methoden weiterleiten)

## Nützliche Debug-Befehle

```bash
# Stack starten / stoppen
cd ~/basyx && sudo docker compose up -d
cd ~/basyx && sudo docker compose down

# Container-Status
sudo docker ps --format "table {{.Names}}\t{{.Status}}\t{{.Ports}}"

# AAS-Inhalt prüfen (Repository)
curl -s http://localhost:8081/shells | python3 -m json.tool | grep '"id"'

# Registry prüfen
curl -s http://localhost:8082/shell-descriptors | python3 -m json.tool | grep '"id"'
curl -s http://localhost:8083/submodel-descriptors | python3 -m json.tool | grep '"id"'

# Logs
cd ~/basyx && sudo docker compose logs aas-env --tail=50
cd ~/basyx && sudo docker compose logs aas-registry --tail=50

# Neustart (Daten gehen verloren → danach nodeset_to_aas.py neu ausführen)
cd ~/basyx && sudo docker compose down && sudo docker compose up -d
cd ~/code/PA-AAS && python nodeset_to_aas.py
```

## Skripte

```
NodeSetXML_Ablage/Nodesetv2.xml   → aktuelles NodeSet2 XML
nodeset_to_aas.py                 → NodeSet parsen + AAS in BaSyx laden + in Registry registrieren ✅
integration_layer.py              → Live-Sync OPC UA ↔ AAS (noch nicht implementiert)
mapping.md                        → detailliertes NodeSet→AAS Mapping
```

### integration_layer.py (geplante Struktur)
```python
# OPC UA → AAS (Monitoring)
poll_opcua_sensors()    # asyncua: Variablen periodisch lesen
push_to_basyx()         # requests: PATCH Submodel-Element

# AAS → OPC UA (Steuerung)
watch_aas_operations()  # requests: auf Operation-Aufrufe warten
call_opcua_method()     # asyncua: Methode auf OPC UA Server weiterleiten
```

## Entwicklungsumgebung

- OS: NixOS
- IDE: VSCode mit Claude Code Extension
- Python: via `uv` (virtuelle Umgebung)
- Docker: läuft nativ auf NixOS
- Windows 11 VM: nur für CODESYS + UaExpert + UaModeler

## Prüfungsform

- Abschlusspräsentation: 10 Minuten pro Person + Fragen
- Schriftlicher Bericht: ~5 Seiten pro Person
- Struktur: Abstract, Einleitung, Grundlagen, Konzept, Implementierung, Ergebnisse, Fazit
- Abgabe Bericht: 2 Wochen vor Präsentation
- Code einreichen (nicht bewertet, aber abgeben)
