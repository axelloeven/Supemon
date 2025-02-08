//
// Created by axelo on 03/02/2025.
//

#include "out-of-combat.h"
#include "battle.h"
#include "shop.h"
#include "center.h"
#include "intro.h"
#include "main.h"
#include <stdio.h>
#include <stdlib.h>

int outofcombat(Joueur *joueur, const char *playerName)
{
    printf("You are now out of combat.\n");
    printf("You can now explore the world and catch Sup%cmon.\n", 130);
    printf("Press any key to continue...\n");
    char c;
    scanf("%c", &c);
    printf("Where do you want to go ?\n");
    printf("1. Into the wild\n");
    printf("2. In the shop\n");
    printf("3. In the Supémon Center\n");
    printf("4. Leave the game\n");
    printf("What do you want to do ?\n");
    int choice;
    scanf("%d", &choice);
    printf("You chose %s !\n", choice == 1 ? "Into the wild" : choice == 2 ? "In the shop" : choice == 3 ? "In the Supémon Center" : "Leave the game");
    
    switch (choice) {
        case 1:
            battle(joueur, playerName);
            break;
        case 2:
            shop(joueur, playerName);
            break;
        case 3:
            center(joueur, playerName);
            break;
        case 4:
            printf("Goodbye !\n");
            exit(0);
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            return outofcombat(joueur, playerName);
    }
    return 0;
}
