# init
```
auto_ampel_state := 2;
fuss_ampel_state := 1;
max_warten := 1;
autos := 0;

tor_state := 0;

blink := false;
warnlicht := false;
```

# Aufgabe 6 - ampel_state
```
CASE auto_ampel_state OF
	0:
		led0 := true;
		led1 := false;
		led2 := false;
		
		if schalter0 = true THEN
			IF counter >= max_warten THEN
				counter := 1;
				auto_ampel_state := 1;
			ELSE
				counter := counter + 1;
			END_IF;
		END_IF;
	
	1:
		led0 := false;
		led1 := true;
		led2 := false;
		
		auto_ampel_state := 2;
	
	2:
		led0 := false;
		led1 := false;
		led2 := true;
		
		fuss_gruen := true;
	
END_CASE

CASE fuss_ampel_gruen OF
	0: 
		led3 := true;
		led4 := false;
		
		IF schalter0 = false THEN
			fuss_gruen := false;
			fuss_ampel_state := 1;
			auto_ampel_state := 0;
		END_IF;
	
	1: 
		led3 := false;
		led4 := true;
		
		IF fuss_gruen = true THEN
			fuss_ampel_state := 0;
		END_IF;
	
END_CASE;
```

# Aufgabe 6 - switch
```
IF schalter2 THEN
	max_warten := 3;
ELSE
	max_warten := 1;
END_IF
```

# Aufgabe 7 - ampel_state
```
CASE auto_ampel_state OF
	0:
		led0 := true;
		led1 := false;
		led2 := false;
		
		if schalter0 = true THEN
			IF counter >= max_warten THEN
				counter := 1;
				auto_ampel_state := 1;
			ELSE
				counter := counter + 1;
			END_IF;
		END_IF;
	
	1:
		led0 := false;
		led1 := true;
		led2 := false;
		
		auto_ampel_state := 2;
	
	2:
		led0 := false;
		led1 := false;
		led2 := true;
		
		fuss_gruen := true;
	
END_CASE

CASE fuss_ampel_gruen OF
	0: 
		led3 := true;
		led4 := false;
		
		IF schalter0 = false THEN
			fuss_gruen := false;
			fuss_ampel_state := 1;
			auto_ampel_state := 0;
			autos := 0;
		END_IF;
	
	1: 
		led3 := false;
		led4 := true;
		
		IF fuss_gruen = true THEN
			fuss_ampel_state := 0;
		END_IF;
	
END_CASE;
```

# Aufgabe 7 - switch
```
IF autos = 0 THEN
	max_warten := 0;
END_IF

IF prev <> schalter2 THEN
	prev := schalter2;
	autos := autos + 1;
	max_warten := autos / 2;
	max_warten := max_warten + 1;
END_IF 
```


# Aufgabe 8 - torState
```
CASE tor_state OF
	0:
		IF position < schritt THEN
			position := WORD#16#0000
		ELSE
			position := position - schritt;
		END_IF;
		
		IF schalter2 = true THEN
			tor_state := 2;
		END_IF;
		
		IF schalter1 = false THEN
			tor_state := 1;
		END_IF;
	
	1:
		IF (WORD#16#FFFF - position) < schritt THEN
			position := WORD#16#FFFF;
		ELSE
			position := position + schritt;
		END_IF;
		
		IF schalter2 = true THEN
			tor_state := 2;
		END_IF;
		
		IF schalter1 = true THEN
			tor_state := 0;
		END_IF;
	
	2:
		warnlicht := true;
		IF schalter2 = false THEN
			IF schalter3 = true THEN
				tor_state := 1;
				warnlicht := false;
				led1 := false;
			END_IF;
		END_IF;
	
END_CASE;
```

# Aufgabe 8 - speed
```
schritt := analog_in / WORD#16#0008;

IF (position < WORD#16#3000) or (position > WORD#16#CFFF) THEN
	schritt := WORD#16#0400;
END_IF;
```

# Aufgabe 8 - blinkendes warnlicht
```
IF warnlicht = true THEN
	blick := not blick;
	led1 := blink;
END_IF;
```

