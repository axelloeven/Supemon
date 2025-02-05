//
// Created by axelo on 05/02/2025.
//
#include <stdio.h>
#include <stdlib.h>
#include "inventory.h"


int inventory()
{
  int potion_count = 1;
    int super_potion_count = 0;
    int rare_candy_count = 0;
    int supcoins = 1000;
    printf("Welcome to your inventory !\n");
    printf("You have %d potions, %d super potions, %d rare candies and %d Supcoins.\n", potion_count, super_potion_count, rare_candy_count, supcoins);
    printf("What do you want to do ?\n");
    printf("1. Use an object\n");
    printf("2. Leave the inventory\n");
    int choice;
    scanf("%d", &choice);
    if (choice == 1)
    {
        printf("What do you want to use ?\n");
        printf("1. Potion\n");
        printf("2. Super Potion\n");
        printf("3. Rare Candy\n");
        int choiceuse;
        scanf("%d", &choiceuse);
        if (choiceuse == 1)
        {
            if (potion_count > 0)
            {
                printf("On which Supemon do you want to use the potion ?\n");
                //printf("1. %s\n", supemons[0].name);
                //printf("2. %s\n", supemons[1].name);
                //printf("3. %s\n", supemons[2].name);
                int choicesupemon;
                scanf("%d", &choicesupemon);
                potion_count -= 1;
                printf("You used a potion !\n");
                //choicesupemon += 5;
                inventory();
            }
            else
            {
                printf("You don't have any potions !\n");
                inventory();
            }
        }
        if (choiceuse == 2)
        {
            if (super_potion_count > 0)
            {
                printf("On which Supemon do you want to use the super potion ?\n");
                //printf("1. %s\n", supemons[0].name);
                //printf("2. %s\n", supemons[1].name);
                //printf("3. %s\n", supemons[2].name);
                int choicesupemon;
                scanf("%d", &choicesupemon);
                super_potion_count -= 1;
                printf("You used a super potion !\n");
                //choicesupemon += 10;
                inventory();
            }
            else
            {
                printf("You don't have any super potions !\n");
                inventory();
            }
        }
        if (choiceuse == 3)
        {
            if (rare_candy_count > 0)
            {
                printf("On which Supemon do you want to use the rare candy ?\n");
                //printf("1. %s\n", supemons[0].name);
                //printf("2. %s\n", supemons[1].name);
                //printf("3. %s\n", supemons[2].name);
                int choicesupemon;
                scanf("%d", &choicesupemon);
                rare_candy_count -= 1;
                printf("You used a rare candy !\n");
                //choicesupemon += 1;
                inventory();
            }
            else
            {
                printf("You don't have any rare candies !\n");
                inventory();
            }
        }
    }
}