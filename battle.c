//
// Created by axelo on 03/02/2025.

#include "battle.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "choicesupemon.h"
#include "supemon.h"
#include "out-of-combat.h"








void attack(Pokemon *p)
{
    if (p->hp <= 0)
    {
        printf("You can't attack, your Supémon is KO!\n");
        return;
    }

    printf("Which move do you want to use ?\n");
    printf("1. %s\n", p->moves[0]);
    printf("2. %s\n", p->moves[1]);
    
    int choice;
    if (scanf("%d", &choice) != 1) {
        while (getchar() != '\n');
        printf("Invalid input!\n");
        return;
    }

    switch (choice) {
        case 1:
            printf("You used Scratch!\n");
            printf("The enemy lost 3 HP!\n");
            p->hp -= 3;
            break;
        case 2:
            printf("You used Growl!\n");
            printf("Your attack increased by 1!\n");
            p->attaque += 1;
            break;
        default:
            printf("Invalid choice!\n");
    }
}



void change(Joueur *joueur)
{
    // À implémenter
    (void)joueur;  // Pour éviter l'avertissement de paramètre non utilisé
}

void item()
{
    // À implémenter
}

void run()
{
    // À implémenter
}




int battle()
{
    printf("You are walking...\n");
    printf("A wild enemy appears!\n");
    
    int pokemonrandom = rand() % 3 + 1;  // 1, 2, ou 3
    Pokemon p;
    
    switch (pokemonrandom) {
        case 1:
            strcpy(p.nom, "Supmander");
            p.hp = 10;
            p.attaque = 1;
            p.défense = 1;
            p.évasion = 1;
            p.précision = 2;
            p.vitesse = 2;
            strcpy(p.moves[0], "Scratch deals 3 damages");
            strcpy(p.moves[1], "Growl gives 1 attack");
            break;
            
        case 2:
            strcpy(p.nom, "Supasaur");
            p.hp = 9;
            p.attaque = 1;
            p.défense = 1;
            p.évasion = 3;
            p.précision = 2;
            p.vitesse = 2;
            strcpy(p.moves[0], "Pound deals 2 damages");
            strcpy(p.moves[1], "Foliage gives 1 Evasion");
            break;
            
        case 3:
            strcpy(p.nom, "Supirtle");
            p.hp = 11;
            p.attaque = 1;
            p.défense = 2;
            p.évasion = 2;
            p.précision = 1;
            p.vitesse = 2;
            strcpy(p.moves[0], "Pound deals 2 damages");
            strcpy(p.moves[1], "Shell gives 1 defense");
            break;
    }

    printf("You are fighting a %s\n", p.nom);
    
    while (p.hp > 0) {
        printf("\nWhat do you want to do ?\n");
        printf("1. Move\n");
        printf("2. Change Supémon\n");
        printf("3. Use an item\n");
        printf("4. Run away\n");
        printf("5. Capture the enemy\n");
        
        int choice;
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            printf("Invalid input!\n");
            continue;
        }

        switch (choice) {
            case 1:
                attack(&p);
                break;
            case 2:
                change(NULL);  // Temporairement NULL, à remplacer par le vrai joueur
                break;
            case 3:
                item();
                break;
            case 4:
                run();
                return 0;
            case 5:
                // capture();  // Fonction non définie
                printf("Capture not implemented yet!\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }

    return 0;
}

