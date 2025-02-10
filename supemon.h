//
// Created by axelo on 04/02/2025.
//

#ifndef SUPEMON_H
#define SUPEMON_H

#include "choicesupemon.h"  // Ajout de l'include pour la définition de Pokemon

// Prototypes des fonctions
void afficherPokemon(Pokemon p);  // Déclaration unique du prototype
Pokemon Supmander(void);  // Changé de void à Pokemon
Pokemon Supasaur(void);   // Changé de void à Pokemon
Pokemon Supirtle(void);   // Changé de void à Pokemon
int getMaxHP(Pokemon p);  // Nouvelle fonction
int lvlup(Pokemon *p, Joueur *joueur, const char *playerName);  // Modification de la signature
void resetStats(Pokemon *p);  // Nouvelle fonction

#endif //SUPEMON_H
