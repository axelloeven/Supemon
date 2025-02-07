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

void capture(Pokemon p, Joueur *joueur)
{   if (joueur -> nb_supemon < MAX)
    {
    printf("You throw a Pokéball!");
    int capture = rand() % 2;
    if (capture == 1)
    {
        printf("You captured the enemy!");
        printf("You can now use it in battle!");
        joueur -> equipe[joueur -> nb_supemon] = p;
        joueur -> nb_supemon++;

    }
    else
    {
        printf("The enemy broke free!");
    }
}
}

void team(Joueur *joueur)
    {
  printf("Here your team: \n", joueur->nb_supemon, MAX);
            for (int i = 0; i < joueur->nb_supemon; i++)
            {
                printf("Supémon %d : %s\n", i + 1, joueur->equipe[i].nom);
            }
            center();
      }