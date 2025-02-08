//
// Created by axelo on 03/02/2025.
//

#include "intro.h"
#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <unistd.h>
#include "supemon.h"
#include "save.h"
#include <string.h>

void intro(Joueur *joueur)
{
    printf("Welcome to Sup%cmon !\n", 130);
    sleep(1);
    printf("You are about to enter a world full of Sup%cmon, creatures that you can catch and train.\n", 130);
    sleep(1);
    printf("You will have to explore the world to find them and catch them.\n");
    sleep(1);
    printf("You will also have to train them to become the best Sup%cmon trainer in the world.\n", 130);
    sleep(1);
    printf("Are you ready to start your adventure ?\n");
    printf("Press any key to continue...\n");
    char c;
    scanf("%c", &c);
    printf("First, how do you want me to call you ?\n");
    char playerName[20];
    scanf("%s", playerName);
    strcpy(joueur->playerName, playerName);  // Sauvegarder le nom dans la structure
    
    // Essayer de charger une sauvegarde existante
    if (loadGame(joueur, playerName)) {
        printf("Sauvegarde trouvée ! Bienvenue à nouveau, %s !\n", playerName);
        outofcombat(joueur, joueur->playerName);
        return;
    }
    
    printf("Nice to meet you, %s !\n", playerName);
    sleep(1);
    printf("Now, choose your first Sup%cmon !\n", 130);
    sleep(1);
    printf("Here are three Sup%cmon you can choose from :\n", 130);
    sleep(1);
    printf("1. Supmander\n");
    printf("2. Supasaur\n");
    printf("3. Supirtle\n");
    
    int choice;
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            joueur->equipe[0] = Supmander();  // Utilisation de la fonction qui retourne un Pokemon
            joueur->nb_supemon = 1;
            printf("You chose Supmander !\n");
            break;
        case 2:
            joueur->equipe[0] = Supasaur();
            joueur->nb_supemon = 1;
            printf("You chose Supasaur !\n");
            break;
        case 3:
            joueur->equipe[0] = Supirtle();
            joueur->nb_supemon = 1;
            printf("You chose Supirtle !\n");
            break;
        default:
            printf("Invalid choice. You get Supmander by default.\n");
            joueur->equipe[0] = Supmander();
            joueur->nb_supemon = 1;
    }
    
    printf("Here's your starter Sup%cmon:\n", 130);
    afficherPokemon(joueur->equipe[0]);
    
    // Sauvegarder après avoir choisi le premier Pokémon
    saveGame(joueur, joueur->playerName);
    outofcombat(joueur, joueur->playerName);
}