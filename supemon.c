//
// Created by axelo on 04/02/2025.
//


// this file is using for the information of the supemon. Informations are the HP, the attack, defense, evasion, accuracy speeds and moves.
#include "supemon.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "choicesupemon.h"

void afficherPokemon(Pokemon p) {
    printf("Nom : %s\n", p.nom);
    printf("HP : %d - Vitesse : %.2f\n", p.hp, p.vitesse);
    printf("Attaque : %d - Defense : %d - Evasion : %d\n", p.attaque, p.défense, p.évasion);
    printf("Précision : %.2f\n", p.précision);
    // Afficher la liste des coups
    printf("Liste de coups :\n");
    for(int i = 0; i < strlen(p.moves[0]); i++) {
        if(i > 0 && p.moves[0][i] == ';') break;
        printf("» %c", p.moves[0][i]);
    }
    printf("\n");
}

int VérifierSelectibilité(int stats[], Pokemon *p) {
    // Vérifier si les statuts du joueur sont compatibles avec le supémon
    return (stats[0] >= p->hp) && (stats[1] >= p->attaque) && (stats[2] >= p->défense);
}

void listeDesCoup(Pokemon p, int stat[]) {
    printf("Coups disponibles :\n");
    for(int i = 0; i < strlen(p.moves[0]); i++) {
        if(i > 0 && p.moves[0][i] == ';') break;
        printf("» %c", p.moves[0][i]);
        printf(" Effectivité : %.2f\n", stat[3 + i]);
    }
}

// Les fonctions suivantes doivent retourner un Pokemon
Pokemon Supmander(void) {
    Pokemon supmander = {
        "Supmander",
        10,
        1,
        1,
        1,
        2,
        2,
        {"Scratch", "Growl"}
    };
    return supmander;
}

Pokemon Supasaur(void) {
    Pokemon supasaur = {
        "Supasaur",
        9,
        1,
        1,
        3,
        1,
        2,
        {"Pound", "Foliage"}
    };
    return supasaur;
}

Pokemon Supirtle(void) {
    Pokemon supirtle = {
        "Supirtle",
        11,
        1,
        2,
        2,
        1,
        1,
        {"Pound", "Shell"}
    };
    return supirtle;
}