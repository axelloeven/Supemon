//
// Created by axelo on 04/02/2025.
//
// this file is using for the information of the supemon. Informations are the HP, the attack, defense, evasion, accuracy speeds and moves.
#include "supemon.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This structure is used to store the information of the supemon.


typedef struct {
    char nom[50];
    int hp;
    int attaque;
    int défense;
    int évadation;
    double précision;
    double vitesse;
} pokemon;

// This function is used to display the information of the supemon.
void afficherPokemon(pokemon p) {
    printf("Nom : %s\n", p.nom);
    printf("HP : %d\n", p.hp);
    printf("Attaque : %d\n", p.attaque);
    printf("Défense : %d\n", p.defense);
    printf("Évasion : %d\n", p évadation);
    printf("Précision : %.2f\n", p.precision);
    printf("Vitesse : %.2f\n", p.vitesse);
}