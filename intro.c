//
// Created by axelo on 03/02/2025.
//

#include "intro.h"
#include "main.h"
#include <stdio.h>
#include <stdlib.h>

int intro()
{
    printf("Welcome to Supémon !\n");
    printf("You are about to enter a world full of Supémon, creatures that you can catch and train.\n");
    printf("You will have to explore the world to find them and catch them.\n");
    printf("You will also have to train them to become the best Supémon trainer in the world.\n");
    printf("Are you ready to start your adventure ?\n");
    printf("Press any key to continue...\n");
    char c;
    scanf("%c", &c);
    printf("First, how do you want me to call you ?\n");
    char name[20];
    scanf("%s", name);
    printf("Nice to meet you, %s !\n", name);
    printf("Now, choose your first Supémon !\n");
    printf("Here are three Supémon you can choose from :\n");
    printf("1. Supmander\n");
    printf("2. Supasaur\n");
    printf("3. Supirtle\n");
    printf("Which one do you want to choose ?\n");
    int choice;
    scanf("%d", &choice);
    printf("Wow ! You chose %s !\n", choice == 1 ? "Supmander" : choice == 2 ? "Supasaur" : "Supirtle");
    printf("What a great choice !\n");
    printf("Now, let's start your adventure !\n");
    printf("Press any key to continue...\n");
    scanf("%c", &c);
    return 0;

}