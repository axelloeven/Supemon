//
// Created by axelo on 04/02/2025.
//

```

<!-- replace lines 35 to 35 -->
// this file is using for the information of the supemon. Informations are the HP, the attack, defense, evasion, accuracy speeds and moves.
#include "supemon.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nom[50];          // Name of the Pokémon
    int hp;               // Hit Points (HP)
    int attaque;         // Attack Power
    int defense;          // Defense Value
    int evasion;          // Evasion Rate
    double precision;     // Accuracy
    double vitesse;       // Speed
    char moves[];         // List of moves (can be represented as an array or a string with semicolons)
} pokemon;


void afficherPokemon(pokemon p) {
    printf("Nom : %s\n", p.nom);
    printf("HP : %d - Vitesse : %.2f\n", p.hp, p.vitesse);
    printf("Attaque : %d - Defense : %d - Evasion : %d\n", p.attaque, p.defense, p.evasion);
    printf("Précision : %.2f\n", p.precision);
    // Afficher la liste des coups
    printf("Liste de coups :\n");
    for(int i = 0; i < strlen(p.moves); i++) {
        if(i > 0 && p.moves[i] == ';') break;
        printf("» ", p.moves[i]);
    }

int VérifierSelectibilité(int stats[], pokemon *p) {
    // Vérifier si les statuts du joueur sont compatibles avec le supémon
    return (stats[0] >= p->hp) && (stats[1] >= p->attaque) && (stats[2] >= p->defense);
}

void listeDesCoup(pokemon p, int stat[]){
    printf("Coups disponibles :\n");
    for(int i = 0; i < strlen(p.moves); i++) {
        if(i > 0 && p.moves[i] == ';') break;
        printf("» ", p.moves[i]);
        printf(" Effectivité : %.2f\n", stat[stats[3 + i]]);
    }
}

}
int main() {
    pokemon supmander = {
        "Supmander",
        10,
        1,
        1,
        1,
        2,
        2,
        "Scratch; Grawl",
        -3,
      p.attack + 1
    };

    pokemon supasaur = {
        "Supasaur",
        9,
        1,
        1,
        3,
        1,
        2,
        "Poundl; Foliage",
        -2,
        p.evasion + 1
    };

    pokemon supirtle = {
        "Porygon2",
        50,
        40,
        30,
        25,
        80.0,
        60,
        "Pound; Shell",
        -2,
        p.defense + 1
    };