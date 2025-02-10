//
// Created by axelo on 03/02/2025.
//

#include "center.h"
#include <stdio.h>
#include <stdlib.h>
#include <supemon.h>

#include "choicesupemon.h"
#include "out-of-combat.h"
#include "save.h"

void center(Joueur *joueur, const char *playerName)
{
    printf("Welcome to the Sup%cmon Center !\n", 130);
    printf("What do you want to do ?\n");
    printf("1. Watch your team\n");
    printf("2. Heal your Sup%cmon\n", 130);
    printf("3. Leave the Sup%cmon Center\n", 130);
    int choice;
    scanf("%d", &choice);
    if (choice == 1)
    {
        printf("Here your team: \n");
        for (int i = 0; i < joueur->nb_supemon; i++)
        {
            printf("Sup%cmon %d : %s\n", 130, i + 1, joueur->equipe[i].nom);
            afficherPokemon(joueur->equipe[i]);
        }
        center(joueur, playerName);
    }
    if (choice == 2)
    {
        printf("Your Sup%cmon are now healed !\n", 130);
        for (int i = 0; i < joueur->nb_supemon; i++)
        {
            joueur->equipe[i].hp = getMaxHP(joueur->equipe[i]);
            saveGame(joueur, playerName);
        }
        center(joueur, playerName);
    }
    if (choice == 3)
    {
        outofcombat(joueur, playerName);
    }
}