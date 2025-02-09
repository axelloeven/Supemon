//
// Created by axelo on 03/02/2025.
//

#ifndef BATTLE_H
#define BATTLE_H

#include "choicesupemon.h"


void dodge(Pokemon *monPokemon, Pokemon *enemy);
void afficherPokemon(Pokemon p);
void attack(Pokemon *enemy, Pokemon *monPokemon);
void item(void);
void change(Pokemon *monPokemon, Joueur *joueur);
void run(Pokemon enemy, Pokemon monPokemon, Joueur *joueur, const char *playerName);
int battle(Joueur *joueur, const char *playerName);

#endif //BATTLE_H
