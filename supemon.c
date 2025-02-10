//
// Created by axelo on 04/02/2025.
//



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

Pokemon Supmander(void) {
    Pokemon supmander = {
        "Supmander",
        1,
        0,
        10,
        10,
        1,
        1,
        1,
        2.0,
        2.0,
        {"Scratch", "Growl"}
    };
    return supmander;
}

Pokemon Supasaur(void) {
    Pokemon supasaur = {
        "Supasaur",
        1,
        0,
        9,
        1,
        1,
        3,
        1,
        2,
        2,
        {"Pound", "Foliage"}
    };
    return supasaur;
}

Pokemon Supirtle(void) {
    Pokemon supirtle = {
        "Supirtle",
        1,
        0,
        11,
        1,
        2,
        2,
        1,
        1,
        2,
        {"Pound", "Shell"}
    };
    return supirtle;
}

int getMaxHP(Pokemon p) {
    return p.max_hp;
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
    }
    return 500 + (level - 1) * 1000;
}

int lvlup(Pokemon *p, Joueur *joueur, const char *playerName) {
    int xpRequired = xpRequis(p->lvl);
    
    if (p->xp >= xpRequired) {
        p->lvl++;
        p->xp = p->xp - xpRequired;
        p->max_hp = (int)(p->max_hp * 1.3);
        p->hp = p->max_hp;
        p->attaque = (int)(p->attaque * 1.3);
        p->defense = (int)(p->defense * 1.3);
        p->evasion = (int)(p->evasion * 1.3);
        p->precision = (int)(p->precision * 1.3);
        p->vitesse = (int)(p->vitesse * 1.3);
        saveGame(joueur, playerName);
        return 1;
    }
    return 0;
}

void resetStats(Pokemon *p) {
    int baseHP, baseAttack, baseDefense, baseEvasion;
    double basePrecision, baseSpeed;
    if (strcmp(p->nom, "Supmander") == 0) {
        baseHP = 10;
        baseAttack = 1;
        baseDefense = 1;
        baseEvasion = 1;
        basePrecision = 2.0;
        baseSpeed = 2.0;
    } else if (strcmp(p->nom, "Supasaur") == 0) {
        baseHP = 9;
        baseAttack = 1;
        baseDefense = 1;
        baseEvasion = 3;
        basePrecision = 2.0;
        baseSpeed = 2.0;
    } else {
        baseHP = 11;
        baseAttack = 1;
        baseDefense = 2;
        baseEvasion = 2;
        basePrecision = 1.0;
        baseSpeed = 2.0;
    }
    for(int i = 1; i < p->lvl; i++) {
        baseHP = (int)(baseHP * 1.3);
        baseAttack = (int)(baseAttack * 1.3);
        baseDefense = (int)(baseDefense * 1.3);
        baseEvasion = (int)(baseEvasion * 1.3);
        basePrecision = (int)(basePrecision * 1.3);
        baseSpeed = (int)(baseSpeed * 1.3);
    }

    p->max_hp = baseHP;
    p->hp = baseHP;
    p->attaque = baseAttack;
    p->defense = baseDefense;
    p->evasion = baseEvasion;
    p->precision = basePrecision;
    p->vitesse = baseSpeed;
}

