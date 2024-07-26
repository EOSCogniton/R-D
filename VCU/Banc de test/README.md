#Banc de test du VCU basé ATSAMC21J18A-ANT
Derscription des différents documents dans le dossier. Le travail a principalement été réalisé pour fournir des outils par rapport au test du code du VCU, en réalisant un banc de test à brancher à la carte de développement.

##Dev_board_connector.png
Schéma des pins de la carte de développement ATSAMC21-XPro pour le MCU ATSAMC21J18.

##Interface_Pins_Devboard.xlsx
Ce tableur est décomposé en deux feuilles : "PINS correspondance" et "références composants".*

Dans la feuille PINS correspondance, l'utilisation des différents pins utilisable par la carte de développement est détaillé.
Pour chaque pins de la carte, il est indiqué lesquels sont utilisés, à quelle pin du MCU ils sont reliés et à la fonctionnalité choisie pour le pin. Une description plus factuelle est aussi fournie avec des précisions sur l'utilisation du pin.

Dans la feuille "références composants", l'ensemble des composants utilisés pour la réalisation du pcb sont présents (hors résistances, condensateurs et connecteurs qui sont couramment utilisés dans l'écurie. Si besoin il est possible de retrouver les références sur le schematics KiCad). il sera notamment possible de trouver les références des régulateurs de tension linéaires, des LEDs, des potentiomètres, des switchs, des transceiver CAN et de la carte de développement ATSAMC21-XPro.

##Schematics-banc
Schematics du pcb de test du code.