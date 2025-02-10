//
// Created by axelo on 04/02/2025.
//

#ifndef SUPEMON_H
#define SUPEMON_H

#include "choicesupemon.h"


void afficherPokemon(Pokemon p);
Pokemon Supmander(void);
Pokemon Supasaur(void);
Pokemon Supirtle(void);
int getMaxHP(Pokemon p);
int lvlup(Pokemon *p, Joueur *joueur, const char *playerName);
void resetStats(Pokemon *p);

#endif //SUPEMON_H
