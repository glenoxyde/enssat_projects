#include "constantes.h" // fichier contenant toutes les constantes du projet
#include <stdint.h>


// mettez ici toutes les "extern" correspondant aux déclarations contenues dans globadec.h


/**
* J'ai découvert trop tard ce fichier, et je ne l'ai donc pas utilisé
* En cherchant un peu, j'ai trouve comment contourner le probleme de redefinition de symboles
* J'ai ainsi compris la nécéssité d'utiliser "extern" pour déclarer les variables globales
* J'ai crée le fichier globaldec.c, qui est un direct équivalent
*/

extern char chaine[30]; // buffer pour l'affichage sur le LCD
extern uint16_t touch_x, touch_y ;


