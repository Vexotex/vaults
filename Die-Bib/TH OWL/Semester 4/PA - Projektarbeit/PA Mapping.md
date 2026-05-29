# NodeSet XML → AAS JSON Mapping

  

Beschreibt wie `nodeset_to_aas.py` das OPC UA NodeSet in die AAS-JSON-Struktur überführt.

---

## Hierarchie-Übersicht

```
OPC UA NodeSet                          AAS JSON
──────────────────────────────────────  ──────────────────────────────────────
ProductionModule                        (ignoriert)
└── Band1 UAObject                      AssetAdministrationShell "Band1"
└── Transferband UAObject               └── Submodel "Transferband"
├── Sensors UAObject                    ├── SubmodelElementCollection "Sensors"
│ ├── LightBarrierLeft UAVar            │ ├── Property "LightBarrierLeft" xs:boolean
│ └── LightBarrierRight UAVar           │ └── Property "LightBarrierRight" xs:boolean
├── Commands UAObject                   ├── SubmodelElementCollection "Commands"
│ ├── RunLeft UAVar                     │ ├── Property "RunLeft" xs:boolean
│ └── Stop UAVar                        │ └── Property "Stop" xs:boolean
├── Skills UAObject                     ├── SubmodelElementCollection "Skills"
│ ├── StartConveyorLeft UAMethod        │ ├── Operation "StartConveyorLeft"
│ └── StopConveyor UAMethod             │ └── Operation "StopConveyor"
└── Measurements UAObject               └── SubmodelElementCollection "Measurements"
└── HeightValue UAVar                   └── Property "HeightValue" xs:double
```


---

## Node-Typ-Mapping

| OPC UA Node-Typ                                                         | Attribut                          | AAS JSON                                                 |
| ----------------------------------------------------------------------- | --------------------------------- | -------------------------------------------------------- |
| `UAObject` unter ProductionModule                                       | `DisplayName` z.B. `Band1`        | `AssetAdministrationShell`, `"idShort": "Band1"`         |
| `UAObject` unter BandX                                                  | `DisplayName` z.B. `Transferband` | `Submodel`, `"idShort": "Transferband"`                  |
| `UAObject` mit Name `Sensors` / `Commands` / `Skills` / `Measurements`  | Name direkt                       | `SubmodelElementCollection`, `"idShort": "Sensors"` etc. |
| `UAVariable` mit `DataType="Boolean"`                                   | `DisplayName`                     | `Property`, `"valueType": "xs:boolean"`                  |
| `UAVariable` mit `DataType="Double"`                                    | `DisplayName`                     | `Property`, `"valueType": "xs:double"`                   |
| `UAMethod`                                                              | `DisplayName`                     | `Operation`                                              |
| `UAVariable` mit `BrowseName="InputArguments"` oder `"OutputArguments"` | —                                 | **ignoriert**                                            |
| `UAObjectType` (Typdefinitionen)                                        | —                                 | **ignoriert**                                            |
| `UAObject` unter `UAObjectType` (Typ-Instanzen)                         | —                                 | **ignoriert**                                            |


---

## ID-Schema

```
AAS: urn:th-owl:festo-productionmodule:aas:{band}
Asset: urn:th-owl:festo-productionmodule:{band}
Submodel: urn:th-owl:festo-productionmodule:sm:{band}:{modul}
```

Alles lowercase und ohne Sonderzeichen. Beispiele:

| Objekt                        | ID                                                        |
| ----------------------------- | --------------------------------------------------------- |
| AAS Band1                     | `urn:th-owl:festo-productionmodule:aas:band1`             |
| AAS Band2                     | `urn:th-owl:festo-productionmodule:aas:band2`             |
| Submodel Transferband (Band1) | `urn:th-owl:festo-productionmodule:sm:band1:transferband` |
| Submodel TurningUnit (Band2)  | `urn:th-owl:festo-productionmodule:sm:band2:turningunit`  |

---

## JSON-Beispiele

### AssetAdministrationShell


```json

{

"idShort": "Band1",

"modelType": "AssetAdministrationShell",

"id": "urn:th-owl:festo-productionmodule:aas:band1",

"assetInformation": {

"assetKind": "Instance",

"globalAssetId": "urn:th-owl:festo-productionmodule:band1"

},

"submodels": [

{ "type": "ModelReference", "keys": [{ "type": "Submodel", "value": "urn:...:sm:band1:transferband" }] }

]

}

```


### Submodel mit SubmodelElementCollections

```json

{

"idShort": "Transferband",

"modelType": "Submodel",

"id": "urn:th-owl:festo-productionmodule:sm:band1:transferband",

"submodelElements": [

{

"idShort": "Sensors",

"modelType": "SubmodelElementCollection",

"value": [

{ "idShort": "LightBarrierLeft", "modelType": "Property", "valueType": "xs:boolean" },

{ "idShort": "LightBarrierRight", "modelType": "Property", "valueType": "xs:boolean" }

]

},

{

"idShort": "Commands",

"modelType": "SubmodelElementCollection",

"value": [

{ "idShort": "RunLeft", "modelType": "Property", "valueType": "xs:boolean" },

{ "idShort": "RunRight", "modelType": "Property", "valueType": "xs:boolean" },

{ "idShort": "SlowMode", "modelType": "Property", "valueType": "xs:boolean" },

{ "idShort": "Stop", "modelType": "Property", "valueType": "xs:boolean" }

]

},

{

"idShort": "Skills",

"modelType": "SubmodelElementCollection",

"value": [

{ "idShort": "StartConveyorLeft", "modelType": "Operation" },

{ "idShort": "StartConveyorRight", "modelType": "Operation" },

{ "idShort": "StopConveyor", "modelType": "Operation" }

]

}

]

}

```

### Property xs:double (Measurements)

```json

{

"idShort": "HeightValue",

"modelType": "Property",

"valueType": "xs:double"

}

```
