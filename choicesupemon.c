//
// Created by axelo on 06/02/2025.
//

#include "choicesupemon.h"
#include "intro.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "supemon.h"
#define MAX 6

typedef struct {
    char name[20];
    int level;
    int hp;
    int attack;
    int defense;
    int speed;
    int xp;
    int xp_max;
} Supemon;

typedef struct {
  Supemon equipe[MAX];
    int nb_supemon;
} Joueur;