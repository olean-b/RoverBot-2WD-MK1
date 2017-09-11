# Installasjon og oppsett 

## Laste ned og installere mBlock
[mBlock v3.4.10 for Windows7 og nyere](http://gofile.me/3eDDn/P6di7iRDC)

mBlock har støtte for norsk. For å endre, gå til [Language] menyen og velg Norsk. Denne veiledningen forutsetter at norsk er valg.

## Koble til Arduino med USB
Først må vi fortelle mBlock at vi skal jobbe med Arduino. I menyen __[Styrekort]__ velg __«Arduino Nano (mega328)__.
Før du kobler til enheten er det lurt å ta en titt på hvilke serieporter som allerede finnes. Gå til menyen __[Koble til]__ og velg __[Serieport]__. Noter hvilke porter som vises her. F.eks. COM11, COM4.

Koble USB kabel til Arduino og PC. Vent til Windows har installert nødvendige USB drivere. Hvis du nå går inn på __[Koble til]__ og velger __[Serieport]__, skal det dukke opp en ny COM- port her. Velg denne.

Dersom det øverst i programmet står «Serieport Tilkoblet» betyr det at du er klar til å programmere Arduino enheten.
![](/software/images/mBlock_Tilkoblet.jpg)

## Mitt første Arduino program
Nå skal vi forsøke å laste opp et enkelt program.

I mBlock velg skript gruppen _«Roboter»_ og trekk inn hovedblokken _«Arduinoprogram»_.
På enheten finnes det en liten LED som vi kan slå av og på – Denne kan vi kontrollere ved å sette «Digital pinne 13» til enten høy(på) eller lav(av).

__Lag et skript tilsvarende dette__

![](/software/images/simpleBlink.jpg)

For å overføre koden til Arduino, høyreklikk blokken «Arduinoprogram» og velg «last opp til Arduino». 
Et nytt bilde vises nå på høyresiden. Dobbeltsjekk at du fremdeles er tilkoblet og trykk «Laste opp til Arduino».
![](/software/images/mBlockArduinoUpload.jpg)

Programmet er overført og starter automatisk når dialogboksen viser __"Opplasting fullført"__. 

På enheten ser du nå en LED som vekselsvis er tent/slukket i nøyaktig 1 sekund.
![](/software/images/arduinoNanoTilkoblet.jpg)

## Programmere motor driver (PWM kontroller)
Før vi kan programmere motorene må vi laste ned og installere en tilleggsfunksjon i mBlock.
1.	Laste ned utvidelsen fra [denne siden.](/Software/Robbie_Robot/Robot/RoverBotMotorExtension.zip) Velg Download.
2.	Start mBlock og velg __[Tilleggsfunksjoner]__ --> __[Håndtere tilleggsfunksjoner]__ fra menyen. I dialogen klikker du på Knappen nederst til høyre og velger filen du lastet ned i forrige steg. 

_Ps. Husk å velge filtype .zip i fildialogen._

![](/software/images/TilleggsfunksjonRobbieRobot.jpg)

Du skal nå finne tillegget "Robbie Robot" i listen.
