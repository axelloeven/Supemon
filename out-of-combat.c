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

int outofcombat()
{
    printf("You are now out of combat.\n");
    printf("You can now explore the world and catch Supémon.\n");
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
    if (choice == 1)
    {

        battle();

        }
    if (choice == 2)
    {
            shop();
        }
    if (choice ==3)
    {
            center();
        }
    if (choice == 4)
    {
            printf("Goodbye !\n");
            exit(0);
        }
    return 0;
}
