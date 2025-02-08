//
// Created by axelo on 03/02/2025.
//
#include <stdio.h>
#include <stdlib.h>
#include "shop.h"
#include "inventory.h"
#include "out-of-combat.h"
#include "save.h"

int shop(Joueur *joueur, const char *playerName) {
    while (1) {
        printf("Welcome to the shop !\n");
        printf("What do you want to do ?\n");
        printf("1. Buy an object\n");
        printf("2. Sell an object\n");
        printf("3. Exit shop\n");
        
        int choicebs;
        if (scanf("%d", &choicebs) != 1) {  // Vérification de la saisie
            while (getchar() != '\n');  // Vider le buffer
            printf("Invalid input. Please enter a number.\n");
            continue;
        }
        
        switch (choicebs) {  // Utilisation de switch pour plus de clarté
        case 1:
            printf("What do you want to buy ?\n");
            printf("You have %d Supcoins left\n", supcoins);
            printf("1. Potion (100 Supcoins), It gives +5PV to your Supemon \n");
            printf("2. Super Potion (300 Supcoins), It gives +10PV to your Supemon \n");
            printf("3. Rare Candy (700 Supcoins), It gives +1 level to your Supemon \n");
            printf("4. Back to the shop menu\n");
            
            int choicebuy;
            if (scanf("%d", &choicebuy) != 1) {
                while (getchar() != '\n');
                printf("Invalid input. Please enter a number.\n");
                continue;
            }
            
            switch (choicebuy) {
            case 1:
                if (supcoins >= 100) {
                    supcoins -= 100;
                    potion_count++;
                    printf("You bought a potion ! You have %d potions\n", potion_count);
                    printf("You have %d Supcoins left\n", supcoins);
                    saveGame(joueur, playerName);
                } else {
                    printf("You don't have enough Supcoins !\n");
                }
                break;
            case 2:
                if (supcoins >= 300) {
                    supcoins -= 300;
                    super_potion_count++;
                    printf("You bought a super potion ! You have %d super potions\n", super_potion_count);
                    printf("You have %d Supcoins left\n", supcoins);
                    saveGame(joueur, playerName);
                } else {
                    printf("You don't have enough Supcoins !\n");
                }
                break;
            case 3:
                if (supcoins >= 700) {
                    supcoins -= 700;
                    rare_candy_count++;
                    printf("You bought a rare candy ! You have %d rare candy\n ", rare_candy_count);
                    printf("You have %d Supcoins left\n", supcoins);
                    saveGame(joueur, playerName);
                } else {
                    printf("You don't have enough Supcoins !\n");
                }
                break;
            case 4:
                break;
            default:
                printf("Invalid choice.\n");
            }
            break;

        case 2:
            printf("What do you want to sell ?\n");
            printf("1. Potion (50 Supcoins)\n");
            printf("2. Super Potion (150 Supcoins)\n");
            printf("3. Rare Candy (350 Supcoins)\n");
            printf("4. Back to the shop menu\n");
            
            int choicesell;
            if (scanf("%d", &choicesell) != 1) {
                while (getchar() != '\n');
                printf("Invalid input. Please enter a number.\n");
                continue;
            }
            
            switch (choicesell) {
            case 1:
                if (potion_count > 0) {
                    potion_count--;
                    supcoins += 50;
                    printf("You sold a potion !\n");
                    printf("You have %d Supcoins left\n", supcoins);
                } else {
                    printf("You don't have any potions to sell !\n");
                }
                break;
            case 2:
                if (super_potion_count > 0) {
                    super_potion_count--;
                    supcoins += 150;
                    printf("You sold a super potion !\n");
                    printf("You have %d Supcoins left\n", supcoins);
                } else {
                    printf("You don't have any super potions to sell !\n");
                }
                break;
            case 3:
                if (rare_candy_count > 0) {
                    rare_candy_count--;
                    supcoins += 350;
                    printf("You sold a rare candy !\n");
                    printf("You have %d Supcoins left\n", supcoins);
                    printf("You get", supcoins, "Supcoins left");
                } else {
                    printf("You don't have any rare candies to sell !\n");
                }
                break;
            case 4:
                break;
            default:
                printf("Invalid choice.\n");
            }
            break;

        case 3:
            outofcombat(joueur, playerName);
            break;

        default:
            printf("Invalid choice. Please select 1, 2 or 3.\n");
        }
    }
    return 0;
}