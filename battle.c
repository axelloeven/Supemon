//
// Created by axelo on 03/02/2025.
//

#include "battle.h"
#include "intro.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "choicesupemon.h"
#include "supemon.h"
#include "out-of-combat.h"
#include "inventory.h"


// This function is used to display the information of the supemon.
void afficherPokemon(Pokemon p) {
    printf("Nom : %s\n", p.nom);
    printf("HP : %d\n", p.hp);
    printf("Attaque : %d\n", p.attaque);
    printf("Défense : %d\n", p.défense);
    printf("Évasion : %d\n", p.évasion);
    printf("Précision : %.2f\n", p.précision);
    printf("Vitesse : %.2f\n", p.vitesse);
    printf("Moves : %s, %s\n", p.moves[0], p.moves[1]);
}


void attack(Pokemon enemy,Pokemon monPokemon)
{
    if (monPokemon.hp <= 0)
    {
        printf("You can't attack, your Supémon is KO!");
    }

    printf("Which move do you want to use ?");
    printf("1. %s", monPokemon.moves[0]);
    printf("2. %s", monPokemon.moves[1]);
    int choice;
    scanf("%d", &choice);
    if (choice == 1)
    {
        if (strcmp(monPokemon.nom, "Supmander") == 0)
        {
            printf("You used Scratch!");
        printf("The enemy lost 3 HP!");
        enemy.hp -= 3;
        }
        else if (strcmp(monPokemon.nom, "Supasaur") == 0)
        {
            printf("You used Pound!");
            printf("The enemy lost 2 HP!");
            enemy.hp -= 2;
        }
        else if (strcmp(monPokemon.nom, "Supirtle") == 0)
        {
            printf("You used Pound!");
            printf("The enemy lost 2 HP!");
            enemy.hp -= 2;
        }
    }
    if (choice == 2)
        if (strcmp(monPokemon.nom, "Supmander") == 0)
        {
            printf("You used Growl!\n");
            printf("Your attack increased by 1!\n");
            monPokemon.attaque += 1;
        }
        else if (strcmp(monPokemon.nom, "Supasaur") == 0)
        {
            printf("You used Foliage!\n");
            printf("Your evasion increased by 1!\n");
            monPokemon.évasion += 1;
        }
        else if (strcmp(monPokemon.nom, "Supirtle") == 0)
        {
            printf("You used Shell!\n");
            printf("Your defense increased by 1!\n");
            monPokemon.défense += 1;
        }
}


void change (Pokemon monPokemon, Joueur *joueur)
{
    printf("You Currently have %s out. \n",monPokemon.nom);

    printf("\n Here your team: \n");
    for (int i = 0; i < joueur->nb_supemon; i++)
        {
            printf("Supémon %d : %s\n", i + 1, joueur->equipe[i].nom);
        }
    printf("\n Which Supémon do you want to send out? \n");
    int changer;
    scanf("%d", &changer);
    monPokemon = joueur->equipe[changer-1];
}

void item()
{
    printf("You are accessing your inventory...\n");
    inventory();
}

void run(Pokemon enemy, Pokemon monPokemon)
{
    double success_rate = monPokemon.vitesse/(monPokemon.vitesse + enemy.vitesse);
    double rand_val = (double)rand() / RAND_MAX;

    printf("Attempting to run away...\n");

    if (rand_val <= success_rate) {
        printf("You successfully ran away from the battle!\n");
    } else {
        printf("You failed to run away!\nThe battle continues.\n");
    }


}

void capture(Pokemon enemy,int maxhp, Joueur *joueur)
{
    if (joueur -> nb_supemon < MAX)
    {
    printf("You throw a Pokéball!");
    double catchrate=((enemy.hp- maxhp)/maxhp)-0.5;
    double capt = (double)rand() / RAND_MAX;
    if (capt>= catchrate)
    {
        printf("You captured the enemy! \n");
        printf("You can now use it in battle!");
        joueur -> equipe[joueur -> nb_supemon] = enemy;
        joueur -> nb_supemon++;
    }
    else
    {
        printf("The enemy broke free!");
    }
}
}


int battle(Joueur *joueur)
{
    printf("You are walking...");
    printf("A wild enemy appears!");
    Pokemon monPokemon = joueur->equipe[0];
    int pokemonrandom = rand() % 3;
    printf("You are fighting a %s", pokemonrandom == 1 ? "Supmander" : pokemonrandom == 2 ? "Supasaur" : "Supirtle");
    Pokemon enemy;
    switch (pokemonrandom) {
        case(1):
            strcpy(enemy.nom, "Supmander");
            enemy.hp = 10;
            enemy.attaque = 1;
            enemy.défense = 1;
            enemy.évasion = 1;
            enemy.précision = 2;
            enemy.vitesse = 2;
            strcpy(enemy.moves[0], "Scratch deals 3 damages");
            strcpy(enemy.moves[1], "Growl gives 1 attack");
            break;

        case(2):
            strcpy(enemy.nom, "Supasaur");
            enemy.hp = 9;
            enemy.attaque = 1;
            enemy.défense = 1;
            enemy.évasion = 3;
            enemy.précision = 2;
            enemy.vitesse = 2;
            strcpy(enemy.moves[0], "Pound deals 2 damages");
            strcpy(enemy.moves[1], "Foliage gives 1 Evasion");
            break;

        case(3):
            strcpy(enemy.nom, "Supirtle");
            enemy.hp = 11;
            enemy.attaque = 1;
            enemy.défense = 2;
            enemy.évasion = 2;
            enemy.précision = 1;
            enemy.vitesse = 2;
            strcpy(enemy.moves[0], "Pound deals 2 damages");
            strcpy(enemy.moves[1], "Shell gives 1 defense");
            break;
    }
    int maxhp = enemy.hp;
    afficherPokemon(enemy);
    afficherPokemon(monPokemon);
    printf("The battle begins!");
    printf("What do you want to do ?");
    printf("1. Move");
    printf("2. Change Supémon");
    printf("3. Use an item");
    printf("4. Run away");
    printf("5. Capture the enemy");
    int choice;
    scanf("%d", &choice);
    switch (choice) {
        case 1:
        attack(enemy,monPokemon);
            break;
        case 2:
        change(monPokemon, joueur);
            break;
        case 3:
        item(monPokemon);
            break;
        case 4:
        run(enemy,monPokemon);
            break;
        case 5:
        capture(enemy,maxhp, joueur);
            break;
        default:
            printf("Invalid choice!");
            break;
    }








    return 0;
}

