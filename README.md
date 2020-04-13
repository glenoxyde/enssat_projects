# Projet Microcontrôleur
## ENSSAT 2020

### Présentation : 

L'objectif du projet est de développer une application sur microcontrôleur (modèle LPC1768 Cortex M3). 
Dans notre cas, il s'agit du fameux jeu de PONG des années 80. 

Fonctionnalités implémentées : 
   
   * Menus 
        * Navigations dans les menus avec l'écran tactile
    * Réglages 
        * Couper/Activer le son 
        * Désactiver/Activer le mode démo (deux AI)
    * Lancer le jeu depuis le menu
    * Reprendre une partie précédente avec "Resume"
    * Contrôler le joueur avec les touches **a** et **d** (bluetooth)
    * Mettre le jeu en pause avec la touche **espace**
       * Mettre en pause a pour effet de sauvegarder automatiquement l'état de la partie en mémoire (expérimental)
       * Depuis le menu pause : 
            * Reprendre la partie
            * Aller dans les réglages
            * Retour menu principal 
    * Lorsqu'un joueur gagne la partie  :
        * Proposition de recommencer
            * Si on ne souhaite par recommencer, le jeu se termine. 
            * Quoi qu'il arrive, le dernier joueur à avoir gagné aura la main lors d'une nouvelle partie (sauvegardé en mémoire)
            
Ont été réalisés les modules suivants : 

    * Bluetooth
        * Transmission 
        * Réception
    * Mémoire I2C
        * Lecture
        * Ecriture
    * Sons avec haut parleur


