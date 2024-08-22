## Meine kalibrierung
1. Bett aufheizen mit [`M140 S60`](https://marlinfw.org/docs/gcode/M140.html) wobei S60 für 60°C steht.
2. [`G28`](https://marlinfw.org/docs/gcode/G028.html) (Auf Home Position fahren + Endschalter einmessen)
3. [`G90`](https://marlinfw.org/docs/gcode/G090.html) (Absolute Positionierung einschalten)
4. [`G1 Z10`](https://marlinfw.org/docs/gcode/G000-G001.html) (Z Achse anheben)
5. [`G1 X40 Y40 F4000`](https://marlinfw.org/docs/gcode/G000-G001.html) (Mit der Düse auf X40 Y40 fahren)
6. [`M280 P0 S10`](https://marlinfw.org/docs/gcode/M280.html) (BL Touch Stift ausfahren)
7. [`G91`](https://marlinfw.org/docs/gcode/G091.html) (Relative Positionierung aktivieren)
8. Mit [`G1 Z-1`](https://marlinfw.org/docs/gcode/G000-G001.html) bzw. [`G1 Z-0.1`](https://marlinfw.org/docs/gcode/G000-G001.html) oder [`G1 Z-0.02`](https://marlinfw.org/docs/gcode/G000-G001.html) die Düse langsam absenken, bis der Sensor auslöst. NICHT WEITER!
9. Wenn der Sensor ausgelöst hat und blinkt: [`M280 P0 S160`](https://marlinfw.org/docs/gcode/M280.html) (Position vom BLTouch zurücksetzen)
10. [`M114`](https://marlinfw.org/docs/gcode/M114.html) = Aktuelle Position der Düse ermitteln und merken! (z.B. Recv: X:40.00 Y:40.00 Z:1.30 E:0.00 Count X:3200 Y:3200 Z:520)
12. [`G1 X-74 Y-1 F4000`](https://marlinfw.org/docs/gcode/G000-G001.html) (Düse an die selbe Position bringen wo der BLtouch gerade war)
14. [`M211 S0`](https://marlinfw.org/docs/gcode/M211.html) (Software-Endstops ausschalten)
15. Ein Blatt Papier unter die Düse legen
16. Mit [`G1 Z-1`](https://marlinfw.org/docs/gcode/G000-G001.html) bzw. [`G1 Z-0.1`](https://marlinfw.org/docs/gcode/G000-G001.html) oder [`G1 Z-0.02`](https://marlinfw.org/docs/gcode/G000-G001.html) die Düse langsam absenken, bis sich das Papier nur noch schwer bewegen lässt.
17. [`M114`](https://marlinfw.org/docs/gcode/M114.html) = Aktuelle Position der Düse ermitteln und merken! (z.B. Recv: X:38.00 Y:38.00 Z:0.70 E:0.00 Count X:3200 Y:3200 Z:520)
18. Punkt an dem der Sensor auslöste (10)von dem Punkt, an dem Düse das Bett berührte (17) subtrahieren -> 0,7 - 1,30 = **-0,6 mm** -> Das ist unser Z-Offset.
19. [`M851 Z-0.6`](https://marlinfw.org/docs/gcode/M851.html) (Z-Offset speichern. Achtung! Vorzeichen beachten!)
20. [`M211 S1`](https://marlinfw.org/docs/gcode/M211.html) (Software-Endstops einschalten)
21. [`M500`](https://marlinfw.org/docs/gcode/M500.html) (Einstellungen im EEPROM sichern)
22. [`G28`](https://marlinfw.org/docs/gcode/G028.html) (Auf Home Position fahren)
23. [`G29`](https://marlinfw.org/docs/gcode/G029-abl-bilinear.html) (Das erste Mal das AutoLeveling ausführen. Sicherheitshalber mit Software-Endstops um die Düse im Fehlerfall aufzuhalten)
24. Nach Abschluss entweder mit [`M500`](https://marlinfw.org/docs/gcode/M500.html) das Mesh sichern, oder von nun an über das Special Menu sowohl Z-Offset einstellen als auch jederzeit ein neues AutoLeveling starten.

## Ermittlung und Konfiguration des Z-Offsets - Original

Für die nächsten Schritte brauchen wir den Drucker, einen PC und Pronterface


1. Bett aufheizen mit [`M140 S60`](https://marlinfw.org/docs/gcode/M140.html) wobei S60 für 60°C steht.
2. [`G28`](https://marlinfw.org/docs/gcode/G028.html) (Auf Home Position fahren + Endschalter einmessen)
3. [`G90`](https://marlinfw.org/docs/gcode/G090.html) (Absolute Positionierung einschalten)
4. [`G1 Z10`](https://marlinfw.org/docs/gcode/G000-G001.html) (Z Achse anheben)
5. [`G1 X40 Y40 F4000`](https://marlinfw.org/docs/gcode/G000-G001.html) (Mit der Düse auf X40 Y40 fahren)
6. [`M280 P0 S10`](https://marlinfw.org/docs/gcode/M280.html) (BL Touch Stift ausfahren)
7. [`G91`](https://marlinfw.org/docs/gcode/G091.html) (Relative Positionierung aktivieren)
8. Mit [`G1 Z-1`](https://marlinfw.org/docs/gcode/G000-G001.html) bzw. [`G1 Z-0.1`](https://marlinfw.org/docs/gcode/G000-G001.html) oder [`G1 Z-0.02`](https://marlinfw.org/docs/gcode/G000-G001.html) die Düse langsam absenken, bis der Sensor auslöst. NICHT WEITER!
9. Wenn der Sensor ausgelöst hat und blinkt: [`M280 P0 S160`](https://marlinfw.org/docs/gcode/M280.html) (Position vom BLTouch zurücksetzen)
10. [`M114`](https://marlinfw.org/docs/gcode/M114.html) = Aktuelle Position der Düse ermitteln und merken! (z.B. Recv: X:40.00 Y:40.00 Z:1.30 E:0.00 Count X:3200 Y:3200 Z:520)
11. [`G90`](https://marlinfw.org/docs/gcode/G090.html) (Absolute Positionierung einschalten)
12. [`G1 X38 Y15 F4000`](https://marlinfw.org/docs/gcode/G000-G001.html) (BL Touch Sensor an genau dieselbe Position fahren, an der die Düse eben war)
13. [`G91`](https://marlinfw.org/docs/gcode/G091.html) (Relative Positionierung aktivieren)
14. [`M211 S0`](https://marlinfw.org/docs/gcode/M211.html) (Software-Endstops ausschalten)
15. Ein Blatt Papier unter die Düse legen
16. Mit [`G1 Z-1`](https://marlinfw.org/docs/gcode/G000-G001.html) bzw. [`G1 Z-0.1`](https://marlinfw.org/docs/gcode/G000-G001.html) oder [`G1 Z-0.02`](https://marlinfw.org/docs/gcode/G000-G001.html) die Düse langsam absenken, bis sich das Papier nur noch schwer bewegen lässt.
17. [`M114`](https://marlinfw.org/docs/gcode/M114.html) = Aktuelle Position der Düse ermitteln und merken! (z.B. Recv: X:38.00 Y:38.00 Z:0.70 E:0.00 Count X:3200 Y:3200 Z:520)
18. Punkt an dem der Sensor auslöste (10)von dem Punkt, an dem Düse das Bett berührte (17) subtrahieren -> 0,7 - 1,30 = **-0,6 mm** -> Das ist unser Z-Offset.
19. [`M851 Z-0.6`](https://marlinfw.org/docs/gcode/M851.html) (Z-Offset speichern. Achtung! Vorzeichen beachten!)
20. [`M500`](https://marlinfw.org/docs/gcode/M500.html) (Einstellungen im EEPROM sichern)
21. [`G28`](https://marlinfw.org/docs/gcode/G028.html) (Auf Home Position fahren)
22. [`M211 S1`](https://marlinfw.org/docs/gcode/M211.html) (Software-Endstops einschalten)
23. [`G29`](https://marlinfw.org/docs/gcode/G029-abl-bilinear.html) (Das erste Mal das AutoLeveling ausführen. Sicherheitshalber mit Software-Endstops um die Düse im Fehlerfall aufzuhalten)
24. Nach Abschluss entweder mit [`M500`](https://marlinfw.org/docs/gcode/M500.html) das Mesh sichern, oder von nun an über das Special Menu sowohl Z-Offset einstellen als auch jederzeit ein neues AutoLeveling starten.