//
// Created by axelo on 06/02/2025.
//

#ifndef CHOICESUPEMON_H
#define CHOICESUPEMON_H

#define MAX 6

typedef struct {
    char nom[50];
    int hp;
    int attaque;
    int defense;
    int evasion;
    double precision;
    double vitesse;
    char moves[2][50];
} Pokemon;

typedef struct {
    Pokemon equipe[MAX];
    int nb_supemon;
    char playerName[20];
} Joueur;

void capture(Pokemon enemy, int maxhp, Joueur *joueur, const char *playerName);
void change(Pokemon *monPokemon, Joueur *joueur);

#endif //CHOICESUPEMON_H
