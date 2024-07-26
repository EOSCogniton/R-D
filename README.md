# R-D Repository

Ce repository a été créé à l'occasion des stages d'applications de la Saison 2024, afin de permettre une conservation des connaissances acquises lors de ceux-ci. Il contient à ce jour les connaissances acquises sur la réalisation d'un VCU home-made.
Il est actuellement en cours de construction.


## Table of contents
1. VCU


## VCU
La partie VCU du repository contient le travail réalisé sur le VCU lors du stage FS@ECL de la Saison 2024. Lors de ce stage, un cahier des charges a été du VCU a été effectué ce qui a mené à un choix de micro-contrôleur sur lequel a été basé un banc de test.
Le cahier des charges est disponible directement dans le dossier "VCU", et les informations pertinentes par rapport au banc de test sont dans le dossier "VCU/Banc de test/"


### Banc de test du VCU basé sur le MCU ATSAMC21J18A-ANT
Description des différents documents présents dans le dossier "VCU/Banc de test/". Le travail a principalement été réalisé pour fournir des outils par rapport au test du code du VCU, en réalisant un banc de test à brancher à la carte de développement.

#### Dev_board_connector.png
Schéma des pins de la carte de développement ATSAMC21-XPro pour le MCU ATSAMC21J18.

#### Interface_Pins_Devboard.xlsx
Ce tableur est décomposé en deux feuilles : "PINS correspondance" et "références composants".*

Dans la feuille PINS correspondance, l'utilisation des différents pins utilisable par la carte de développement est détaillé.
Pour chaque pins de la carte, il est indiqué lesquels sont utilisés, à quelle pin du MCU ils sont reliés et à la fonctionnalité choisie pour le pin. Une description plus factuelle est aussi fournie avec des précisions sur l'utilisation du pin.

Dans la feuille "références composants", l'ensemble des composants utilisés pour la réalisation du pcb sont présents (hors résistances, condensateurs et connecteurs qui sont couramment utilisés dans l'écurie. Si besoin il est possible de retrouver les références sur le schematics KiCad). il sera notamment possible de trouver les références des régulateurs de tension linéaires, des LEDs, des potentiomètres, des switchs, des transceiver CAN et de la carte de développement ATSAMC21-XPro.

#### Schematics-banc
Schematics du pcb.

#### Code 
Exemple de code effectué sur MPLab X IDE pour mesurer un ADC.

