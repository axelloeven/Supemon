//
// Created by axelo on 03/02/2025.
//

#ifndef BATTLE_H
#define BATTLE_H

#include "choicesupemon.h"

// Prototypes des fonctions
void afficherPokemon(Pokemon p);
void attack(Pokemon *p);  // Utilisation d'un pointeur pour modifier le Pokemon
void change(Joueur *joueur);  // Mise à jour du prototype
void item(void);
void run(void);
int battle(void);

#endif //BATTLE_H
