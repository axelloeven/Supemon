//
// Created by axelo on 03/02/2025.
//

#include "intro.h"
#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <unistd.h>
#include "supemons.h"


int intro()
{
    printf("Welcome to Supémon !\n");
    sleep(1);
    printf("You are about to enter a world full of Supémon, creatures that you can catch and train.\n");
    sleep(1);
    printf("You will have to explore the world to find them and catch them.\n");
    sleep(1);
    printf("You will also have to train them to become the best Supémon trainer in the world.\n");
    sleep(1);
    printf("Are you ready to start your adventure ?\n");
    printf("Press any key to continue...\n");
    char c;
    scanf("%c", &c);
    printf("First, how do you want me to call you ?\n");
    char name[20];
    scanf("%s", name);
    printf("Nice to meet you, %s !\n", name);
    sleep(1);
    printf("Now, choose your first Supémon !\n");
    sleep(1);
    printf("Here are three Supémon you can choose from :\n");
    sleep(1);
    printf("1. Supmander\n");
    printf("2. Supasaur\n");
    printf("3. Supirtle\n");
    sleep(1);
    printf("Which one do you want to choose ?\n");
    int choicesup;
    scanf("%d", &choicesup);
    printf("Wow ! You chose %s !\n", choicesup == 1 ? "Supmander" : choicesup == 2 ? "Supasaur" : "Supirtle");

    sleep(1);
    printf("What a great choice !\n");
    sleep(1);
    printf("Now, let's start your adventure !\n");
    sleep(1);
    printf("Press any key to continue...\n");
    scanf("%c", &c);

    return 0;

}