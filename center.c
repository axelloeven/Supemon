//
// Created by axelo on 03/02/2025.
//

#include "center.h"
#include <stdio.h>
#include <stdlib.h>
#include "choicesupemon.h"
#include "out-of-combat.h"

void center(Joueur joueur)
    {
        printf("Welcome to the Supémon Center !\n");
        printf("What do you want to do ?\n");
        printf("1. Watch your team\n");
        printf("1. Heal your Supémon\n");
        printf("2. Leave the Supémon Center\n");
        int choice;
        scanf("%d", &choice);
        if (choice == 1)
        {
            printf("Here your team: \n", joueur.nb_supemon, MAX);
            for (int i = 0; i < joueur.nb_supemon; i++)
            {
                printf("Supémon %d : %s\n", i + 1, joueur.equipe[i].nom);
            }
            return;
        }
        if (choice == 2)
        {
            outofcombat();
        }


    }