//
// Created by axelo on 06/02/2025.
//

#ifndef CHOICESUPEMON_H
#define CHOICESUPEMON_H
#define MAX 6
#include <stdio.h>

typedef struct {
    char nom[50];
    int xp;
    int lvl;
    int hp;
    int attaque;
    int défense;
    int évasion;
    double précision;
    double vitesse;
    char moves[2][50];
} Pokemon;

typedef struct {
    Pokemon equipe[MAX];
    int nb_supemon;
} Joueur;

void capture(Pokemon p, Joueur *joueur);
void change(Joueur *joueur);


#endif //CHOICESUPEMON_H
