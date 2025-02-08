//
// Created by axelo on 06/02/2025.
//

#include "choicesupemon.h"
#include "intro.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "supemon.h"
#include "center.h"

void team(Joueur *joueur)
{
    printf("Here your team: \n");
    for (int i = 0; i < joueur->nb_supemon; i++)
    {
        printf("Supémon %d : %s\n", i + 1, joueur->equipe[i].nom);
    }
    center(joueur);
}