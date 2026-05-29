# Projektarbeit: OPC UA ↔ AAS Integration Layer

  

## Kontext

  

Projektarbeit an der TH OWL (inIT - Institute Industrial IT, AG Vernetzte Automatisierungssysteme).

Ziel: Eine Festo-Produktionsanlage (Labormaßstab) über OPC UA und AAS (Asset Administration Shell / Verwaltungsschale) ansteuerbar machen.

  

## Aufgabe

1. OPC UA Informationsmodell (NodeSet XML) in AAS-Submodels konvertieren
2. AAS-Struktur per Python in BaSyx laden
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

│ ├── Transferband (Sensors: LightBarrierLeft/Right | Commands: RunLeft/Right/SlowMode/Stop | Skills: StartConveyorLeft/Right, StopConveyor)

│ ├── StackMagazine (Sensors: MagazineRetracted/Extended/Empty | Commands: ExtendCylinder/RetractCylinder | Skills: DispenseWorkpiece)

│ ├── HeightMeasurement (Sensors: WorkpiecePresent | Measurements: HeightValue | Skills: ReadHeight)

│ └── SignalTower (Commands: Red/Yellow/Green | Skills: SetSignalState)

├── Band2

│ ├── Transferband

│ ├── TurningUnit (Sensors: WorkpiecePresent/CylinderUp/Down/GripperAt0/180 | Commands: MoveCylinder/Rotate | Skills: LiftWorkpiece/LowerWorkpiece/RotateTo0/180)

│ ├── GripperUnit (Sensors: GripperOpen/Closed | Commands: OpenGripper/CloseGripper | Skills: OpenGripperSkill/CloseGripperSkill)

│ └── SignalTower

└── Band3

├── Transferband

├── SwitchUnit (Sensors: SwitchOpen/OpticalWorkpieceDetected/WorkpiecePresentAtSwitch | Commands: CloseSwitch | Skills: CloseSwitchSkill/SortWorkpieceToSlide)

├── PneumaticUnit (Sensors: AirActivationPosition/DeactivationPosition | Commands: Activate/DeactivateCompressedAir | Skills: ActivateCompressedAirSkill/DeactivateCompressedAirSkill/MoveWorkpieceByAir)

├── TiltingUnit (Sensors: WorkpieceAtTiltingPosition | Commands: TiltWorkpiece | Skills: TiltWorkpieceSkill)

├── ReturnUnit (Sensors: SlideFull | Skills: CheckReturnSlide)

└── SignalTower

```

  

Jedes Modul folgt exakt diesem Muster:

- `Sensors/` → read-only Variablen (Boolean/Double)

- `Commands/` → write Variablen (Boolean)

- `Measurements/`→ read-only Messwerte (Double)

- `Skills/` → aufrufbare Methoden (UAMethod)

  

## NodeSet → AAS Mapping

  

| OPC UA                             | AAS                             |
| ---------------------------------- | ------------------------------- |
| UAObject (BandX)                   | AssetAdministrationShell        |
| UAObject (Sensors/Commands/Skills) | Submodel                        |
| UAVariable Boolean                 | Property, valueType: xs:boolean |
| UAVariable Double                  | Property, valueType: xs:double  |
| UAMethod                           | Operation                       |

  

## Tech Stack

  

| Komponente                | Tool                                                           |
| ------------------------- | -------------------------------------------------------------- |
| OPC UA Server (simuliert) | CODESYS Soft PLC (Windows 11 VM)                               |
| OPC UA Client (Test)      | UaExpert                                                       |
| OPC UA Informationsmodell | UaModeler (NodeSet2 XML)                                       |
| AAS Server                | BaSyx (eclipsebasyx/aas-environment:2.0.0-SNAPSHOT via Docker) |
| AAS GUI                   | BaSyx Web UI (eclipsebasyx/aas-gui via Docker)                 |
| XML parsen                | Python `xml.etree.ElementTree` (stdlib)                        |
| AAS bauen                 | Python `basyx-python-sdk` (Fraunhofer)                         |
| OPC UA Client (Python)    | `asyncua`                                                      |
| HTTP zu BaSyx             | `requests`                                                     |

  

## BaSyx Endpunkte (lokal)

  

- REST API: `http://localhost:8081`

- Web UI: `http://localhost:3000`

  

Wichtige API-Routen:

```

POST /shells → AAS anlegen

POST /submodels → Submodel anlegen

GET /submodels/{submodelId}/submodel-elements/{idShort} → Wert lesen

PATCH /submodels/{submodelId}/submodel-elements/{idShort} → Wert schreiben

POST /submodels/{submodelId}/submodel-elements/{idShort}/invoke → Operation aufrufen

```

  

IDs sind base64url-enkodiert in den URL-Pfaden.

  

## Geplante Skripte

  

```

nodeset_to_aas.py → NodeSet XML parsen + AAS in BaSyx laden (Einmaliger Setup)

integration_layer.py → Live-Sync OPC UA ↔ AAS (dauerhaft laufend)

```

  

### nodeset_to_aas.py Struktur

```python

parse_nodeset(xml_path) # XML einlesen → dict {band: {sensors: [], commands: [], skills: []}}

build_aas(band_data) # basyx-sdk: AAS + Submodels bauen

upload_to_basyx(aas) # per requests an localhost:8081 schicken

```

  

### integration_layer.py Struktur

```python

# OPC UA → AAS (Monitoring)

poll_opcua_sensors() # asyncua: Variablen lesen

push_to_basyx() # requests: PATCH Submodel-Element

  

# AAS → OPC UA (Steuerung)

watch_aas_operations() # requests: auf Operation-Aufrufe warten

call_opcua_method() # asyncua: Methode auf OPC UA Server aufrufen

```

  

## Entwicklungsumgebung

  

- OS: NixOS

- IDE: VSCode mit Claude Code Extension

- Python: via `uv` (virtuelle Umgebung)

- Docker: läuft nativ auf NixOS (BaSyx-Stack)

- Windows 11 VM: nur für CODESYS + UaExpert + UaModeler

  

## NodeSet Datei

  

`Nodeset_vollständig.xml` — liegt im Projektordner.

Namespace: `http://th-owl.de/project/vws/festo-productionmodule/`

Erstellt mit: Siemens SiOME 3.2.0

  

## Prüfungsform

  

- Abschlusspräsentation: 10 Minuten pro Person + Fragen

- Schriftlicher Bericht: ~5 Seiten pro Person

- Struktur: Abstract, Einleitung, Grundlagen, Konzept, Implementierung, Ergebnisse, Fazit

- Abgabe Bericht: 2 Wochen vor Präsentation

- Code einreichen (nicht bewertet, aber abgeben)