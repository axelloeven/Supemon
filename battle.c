//
// Created by axelo on 03/02/2025.
//

#include "battle.h"
#include "intro.h"
#include <stdio.h>

// This structure is used to store the information of the supemon.


typedef struct {
    char nom[50];
    int hp;
    int attaque;
    int défense;
    int évadation;
    double précision;
    double vitesse;
    char moves[2][50];
} pokemon;

// This function is used to display the information of the supemon.
void afficherPokemon(pokemon p) {
    printf("Nom : %s\n", p.nom);
    printf("HP : %d\n", p.hp);
    printf("Attaque : %d\n", p.attaque);
    printf("Défense : %d\n", p.defense);
    printf("Évasion : %d\n", p évadation);
    printf("Précision : %.2f\n", p.precision);
    printf("Vitesse : %.2f\n", p.vitesse);
    printf("Moves : %s, %s\n", p.moves[0], p.moves[1]);
}

int battle()
{
    printf("You are walking...");
    printf("A wild enemy appears!");
    int pokemonrandom = rand() % 3;
    printf("You are fighting a %s", pokemonrandom == 1 ? "Supmander" : pokemonrandom == 2 ? "Supasaur" : "Supirtle");
    pokemon p;
    if (pokemonrandom == 1)
    {
        strcpy(p.nom, "Supmander");
        p.hp = 10;
        p.attaque = 1;
        p.defense = 1;
        p.evasion = 1;
        p.précision = 2;
        p.vitesse = 2;
        strcpy(p.moves[0], "Scratch deals 3 damages");
        strcpy(p.moves[1], "Growl gives 1 attack");
    }
    if (pokemonrandom == 2)
    {
        strcpy(p.nom, "Supasaur");
        p.hp = 9;
        p.attaque = 1;
        p.defense = 1;
        p.evasion = 3;
        p.précision = 2;
        p.vitesse = 2;
        strcpy(p.moves[0], "Pound deals 2 damages");
        strcpy(p.moves[1], "Foliage gives 1 Evasion");
    if pokemonrandom == 3)
    {
        strcpy(p.nom, "Supirtle");
        p.hp = 11;
        p.attaque = 1;
        p.defense = 2;
        p.evasion = 2;
        p.précision = 1;
        p.vitesse = 2;
        strcpy(p.moves[0], "Pound deals 2 damages");
        strcpy(p.moves[1], "Shell gives 1 defense");

    afficherPokemon(p);
    printf("The battle begins!");
    printf("What do you want to do ?");
    printf("1. Move");
    printf("2. Change Supémon");
    printf("Use an item");
    printf("Run away");
    printf("Capture the enemy");
    int choice;
    scanf("%d", &choice);
    if (choice == 1)
    {
        attack(p);
    }
    if (choice == 2)
    {
        change(p);
    }
    if (choice == 3)
    {
        item(p);
    }
    if (choice == 4)
    {
        run(p);
    }
    if (choice == 5)
    {
        capture(p);
    }






    return 0;
}

void attack(pokemon p)
{
    if (p.hp <= 0)
    {
        printf("You can't attack, your Supémon is KO!");
        return;
    }

    printf("Which move do you want to use ?");
    printf("1. %s", p.moves[0]);
    printf("2. %s", p.moves[1]);
    int choice;
    scanf("%d", &choice);
    if (choice == 1)
    {
        printf("You used Scratch!");
        printf("The enemy lost 3 HP!");
        p.hp -= 3;
    }
    if (choice == 2)
    {
        printf("You used Growl!");
        printf("Your attack increased by 1!");
        p.attaque += 1;
    }
}