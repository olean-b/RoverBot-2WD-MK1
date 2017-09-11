# Koblingsoversikt

Fra komponent            | Til hovedkort | Beskrivelse
:------------------------|------------:|:------------------------
__Motor driver (pwm)__
Gul A1 (4 pin kontakt)    | D6         |
Hvit A2 (4 pin kontakt)   | D5         |
Rød B1 (4 pin kontakt)    | D9         |
Svart B2 (4 pin kontakt)  | D10        |
Rød +                     | VIN        |
Sort -                    | GND        | Bruk en av de to GND kontaktene
2xPin                     | Motor A    | Kinesisk tekst... A
2xPin                     | Motor B    | Kinesisk tekst... B
__Avstandsensor__                        
GND                      |  GND        | Bruk en av de to GND kontaktene
Echo                     |  D12        | 
Trig                     |  D13        | 
VCC                      |  5V         | 
__Batteri__                        
Sort                      |  GND       | Bruk en av de to GND kontaktene
Rød                       |  VIN       | 


### Bilde nedenfor viser hvordan man kan plassere ledningene slik at det ikke blir for mye spagetti.
![](/design/WiringSketch/KoblingerFoto.jpg)

### Dette er et litt mer teknisk koblingsskjema som viser akkurat det samme som tabellen øverst på siden.
![](/design/WiringSketch/KoblingerSkjema.png)
