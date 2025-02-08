//
// Created by axelo on 03/02/2025.
//

#ifndef BATTLE_H
#define BATTLE_H

#include "choicesupemon.h"

// Prototypes des fonctions
void afficherPokemon(Pokemon p);
void attack(Pokemon *enemy, Pokemon *monPokemon);
void item(void);
void run(Pokemon enemy, Pokemon monPokemon);
int battle(Joueur *joueur);

#endif //BATTLE_H
