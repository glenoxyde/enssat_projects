# Projet Microcontrôleur

## ENSSAT 2020

## Présentation

L'objectif du projet est de développer une application sur microcontrôleur (modèle LPC1768 Cortex M3).
Dans notre cas, il s'agit du fameux jeu PONG des années 80.

## Fonctionnalités implémentées

* Menus
  * Navigations dans les menus avec l'écran tactile
* Réglages
  * Couper/Activer le son
  * Désactiver/Activer le mode démo (deux IA)
* Lancer le jeu depuis le menu
* Reprendre une partie précédente avec *Resume* (*cf* Problèmes connus)
* Contrôler **un** joueur avec les touches **a** et **d** (bluetooth)
* Mettre le jeu en pause avec la touche **espace**
  * Mettre en pause a pour effet de sauvegarder automatiquement l'état de la partie en mémoire (comme une sauvegarde du contexte)
  * Depuis le menu pause :
    * Reprendre la partie
    * Aller dans les réglages
    * Retour menu principal
* Lorsqu'un joueur gagne la partie  :
  * Proposition de recommencer
  * Si on ne souhaite par recommencer, le jeu se termine.
  * Quoi qu'il arrive, le dernier joueur à avoir gagné aura la main lors d'une nouvelle partie (sauvegardé en mémoire)

## Foncitonnalités à implémenter

* Réglages :
  * Changer de contôles : utiliser l'écran tactile pour contrôler les joueurs
  * Multijoueur via bluetooth possible sur deux terminaux différents
* Développer un jingle/mélodie pour rendre la chose moins monotone
* Vitesse de la balle dynamique
* Améliorations de la mécanique de rebond
* Implémenter des niveaux : développer une IA dont la vitesse est limitée
* Donner aux joueur le choix des couleurs (étant donné la simplicité d'utilisation de l'écran tactile, le développelent d'options de personnalisation est facile)

## Problèmes connus

* La sauvegarde (lors de la pause) fonctionne, mais la restitution du contexte pose souvent problème. On a alors un plantage du comportement de la balle.
* La générations de sons fonctionne, mais si deux sons sont trop rapprochés dans le temps et se chevauchent, le timer s'éteint, et le son s'arrête de fonctionner

Je n'ai pas eu le temps de débugger ces problèmes.

## Modules

* Bluetooth
  * Transmission
  * Réception
* Mémoire I2C
  * Lecture
  * Ecriture
* Sons avec haut parleur

Chaque module a été développé et testé séparément, puis assemblé à la fin, lors du développement du moteur du jeu.

## Contrôles

Ne possédant pas de terminal android, j'ai installé l'application Bluetooth Serial Terminal, disponible sur le Windows Store.
L'envoi de caractères ASCII vers la carte ne pose pas de problèmes, et sert à contrôler le joueur. (Il faut au préalable désactiver le mode démo depuis les réglages, dans le menu principal ou le menu pause).

* Navigation tactile dans les menus.

* Déplacer le joueur à droite : touche **d**.

* Déplacer le joueur à droite : touche **a**.

* Mettre le jeu en pause : touche **espace**.
