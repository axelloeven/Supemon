//
// Created by axelo on 04/02/2025.
//


// this file is using for the information of the supemon. Informations are the HP, the attack, defense, evasion, accuracy speeds and moves.
#include "supemon.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "choicesupemon.h"
#include <math.h>
#include <save.h>

void afficherPokemon(Pokemon p) {
    printf("Nom : %s\n", p.nom);
    printf("Level: %d\n", p.lvl);
    printf("XP: %d\n", p.xp);
    printf("HP : %d\n", p.hp);
    printf("Attaque : %d\n", p.attaque);
    printf("Defense : %d\n", p.defense);
    printf("Evasion : %d\n", p.evasion);
    printf("Precision : %.2f\n", p.precision);
    printf("Vitesse : %.2f\n", p.vitesse);
    printf("Moves : %s, %s\n", p.moves[0], p.moves[1]);
}

int VérifierSelectibilité(int stats[], Pokemon *p) {
    // Vérifier si les statuts du joueur sont compatibles avec le supémon
    return (stats[0] >= p->hp) && (stats[1] >= p->attaque) && (stats[2] >= p->defense);
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
        1,
        0,
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
        1,      // niveau initial
        0,      // XP initial
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
        1,      // niveau initial
        0,      // XP initial
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

int getMaxHP(Pokemon p) {
    if (strcmp(p.nom, "Supmander") == 0) {
        return 10;
    } else if (strcmp(p.nom, "Supasaur") == 0) {
        return 9;
    } else if (strcmp(p.nom, "Supirtle") == 0) {
        return 11;
    }
    return 10;  // Valeur par défaut
}

int lvlupstat(Pokemon *p) {
    float newHp = p->hp * 1.3;
    float newPrecision = p->precision * 1.3;
    float newVitesse = p->vitesse * 1.3;
    float newAttaque = p->attaque * 1.3;
    float newDefense = p->defense * 1.3;
    float newEvasion = p->evasion * 1.3;

    

    p->hp = (newHp - (int)newHp > 0) ? 
            ((rand() % 2) ? ceil(newHp) : floor(newHp)) : 
            newHp;
    
    p->attaque = (newAttaque - (int)newAttaque > 0) ?
                 ((rand() % 2) ? ceil(newAttaque) : floor(newAttaque)) :
                 newAttaque;

    p->defense = (newDefense - (int)newDefense > 0) ?
                 ((rand() % 2) ? ceil(newDefense) : floor(newDefense)) :
                 newDefense;

    p->evasion = (newEvasion - (int)newEvasion > 0) ?
                 ((rand() % 2) ? ceil(newEvasion) : floor(newEvasion)) :
                 newEvasion;
    

    p->precision = (newPrecision - (int)newPrecision > 0) ? 
                  ((rand() % 2) ? ceil(newPrecision) : floor(newPrecision)) : 
                  newPrecision;


    p->vitesse = (newVitesse - (int)newVitesse > 0) ? 
                 ((rand() % 2) ? ceil(newVitesse) : floor(newVitesse)) : 
                 newVitesse;
    
    return 1;
}
int xpRequis(int level) {
    if (level == 1) {
        return 500;
    } else {
        return level * 1000;
    }
}


int lvlup(Pokemon *p, Joueur *joueur, const char *playerName) {
    if (p->xp >= xpRequis(p->lvl)) {
        p->lvl++;
        p->xp = 0;
        lvlupstat(p);
        saveGame(joueur, playerName);
        return 1;
    }
    return 0;  // Ajout d'un return pour tous les cas
}

