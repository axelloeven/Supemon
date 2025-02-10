//
// Created by axelo on 05/02/2025.
//
#include <stdio.h>
#include <stdlib.h>
#include "inventory.h"


int potion_count = 1;
int super_potion_count = 0;
int rare_candy_count = 0;
int supcoins = 1000;

void inventory(void) {
    printf("You are in your Inventory :\n");
    printf("Potions : %d\n", potion_count);
    printf("Super Potions : %d\n", super_potion_count);
    printf("Rare Candy : %d\n", rare_candy_count);
    printf("Supcoins : %d\n", supcoins);
    
    while (1) {
        printf("What do you want to do ?\n");
        printf("1. Use an object\n");
        printf("2. Leave the inventory\n");
        
        int choice;
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            printf("Invalid input. Please enter a number.\n");
            continue;
        }
        if (choice == 2) {
            break;
        }
        if (choice == 1) {
            printf("What do you want to use ?\n");
            printf("1. Potion\n");
            printf("2. Super Potion\n");
            printf("3. Rare Candy\n");
            printf("4. Back\n");
            int choiceuse;
            if (scanf("%d", &choiceuse) != 1) {
                while (getchar() != '\n');
                printf("Invalid input. Please enter a number.\n");
                continue;
            }
            if (choiceuse == 4) {
                continue;
            }
            switch (choiceuse) {
            case 1:
                if (potion_count > 0) {
                    printf("On which Supemon do you want to use the potion ?\n");
                    int choicesupemon;
                    scanf("%d", &choicesupemon);
                    potion_count--;
                    printf("You used a potion !\n");
                } else {
                    printf("You don't have any potions !\n");
                }
                break;
            case 2:
                if (super_potion_count > 0) {
                    printf("On which Supemon do you want to use the super potion ?\n");
                    int choicesupemon;
                    scanf("%d", &choicesupemon);
                    super_potion_count--;
                    printf("You used a super potion !\n");
                } else {
                    printf("You don't have any super potions !\n");
                }
                break;
            case 3:
                if (rare_candy_count > 0) {
                    printf("On which Supemon do you want to use the rare candy ?\n");
                    int choicesupemon;
                    scanf("%d", &choicesupemon);
                    rare_candy_count--;
                    printf("You used a rare candy !\n");
                } else {
                    printf("You don't have any rare candies !\n");
                }
                break;
            default:
                printf("Invalid choice.\n");
            }
        } else {
            printf("Invalid choice. Please select 1 or 2.\n");
        }
    }
}