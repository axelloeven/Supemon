//
// Created by axelo on 03/02/2025.
//

#include "battle.h"
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


void attack(Pokemon *enemy, Pokemon *monPokemon)
{
    if (monPokemon->hp <= 0)
    {
        printf("You can't attack, your Supémon is KO!\n");
        return;
    }

    printf("Which move do you want to use?\n");
    printf("1. %s\n", monPokemon->moves[0]);
    printf("2. %s\n", monPokemon->moves[1]);

    int choice;
    scanf("%d", &choice);

    // Calculating the dodge rate
    double dodgeRate = (monPokemon->précision / (monPokemon->précision + enemy->évasion)) + 0.1;
    double rand_val_dodge = (double)rand() / RAND_MAX;
    if (rand_val_dodge > dodgeRate)
    {
        printf("The attack missed!\n");
        return;
    }

    int damage = 0;
    if (choice == 1) {
        // Calculating damages based on the defense of the enemy
        if (strcmp(monPokemon->nom, "Supmander") == 0) {
            damage = (monPokemon->attaque * 3) / enemy->défense;
            printf("You used Scratch! ");
        } else if (strcmp(monPokemon->nom, "Supasaur") == 0) {
            damage = (monPokemon->attaque * 2) / enemy->défense;
            printf("You used Pound! ");
        } else if (strcmp(monPokemon->nom, "Supirtle") == 0) {
            damage = (monPokemon->attaque * 2) / enemy->défense;
            printf("You used Pound! ");
        }

        double round_chance = (double)rand() / RAND_MAX;
        if (round_chance < 0.5)
            damage = (int)floor(damage);
        else
            damage = (int)ceil(damage);

        enemy->hp -= damage;
        printf("The enemy lost %d HP!\n", damage);
    }
    else if (choice == 2) {
        if (strcmp(monPokemon->nom, "Supmander") == 0) {
            printf("You used Growl!\n");
            printf("Your attack increased by 1!\n");
            monPokemon->attaque += 1;
        } else if (strcmp(monPokemon->nom, "Supasaur") == 0) {
            printf("You used Foliage!\n");
            printf("Your evasion increased by 1!\n");
            monPokemon->évasion += 1;
        } else if (strcmp(monPokemon->nom, "Supirtle") == 0) {
            printf("You used Shell!\n");
            printf("Your defense increased by 1!\n");
            monPokemon->défense += 1;
        }
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

void run(Pokemon enemy, Pokemon *monPokemon)
{
    double success_rate = monPokemon->vitesse / (monPokemon->vitesse + enemy.vitesse);
    double rand_val = (double)rand() / RAND_MAX;  // Générer un nombre aléatoire entre 0 et 1

    printf("Attempting to run away...\n");

    if (rand_val <= success_rate) {
        printf("You successfully ran away from the battle!\n");
    } else {
        printf("You failed to run away!\nThe battle continues...\n");
        printf("The enemy attacks!\n");

        int move_choice = rand() % 2; 

        if (move_choice == 0) {
            if (strcmp(enemy.nom, "Supmander") == 0) {
                printf("The enemy used Scratch!\n");
                printf("You lost 3 HP!\n");
                monPokemon->hp -= 3;
            } else if (strcmp(enemy.nom, "Supasaur") == 0) {
                printf("The enemy used Pound!\n");
                printf("You lost 2 HP!\n");
                monPokemon->hp -= 2;
            } else if (strcmp(enemy.nom, "Supirtle") == 0) {
                printf("The enemy used Pound!\n");
                printf("You lost 2 HP!\n");
                monPokemon->hp -= 2;
            }
        } else {
            if (strcmp(enemy.nom, "Supmander") == 0) {
                printf("The enemy used Growl!\n");
                printf("The enemy's attack increased by 1!\n");
                enemy.attaque += 1;
            } else if (strcmp(enemy.nom, "Supasaur") == 0) {
                printf("The enemy used Foliage!\n");
                printf("The enemy's evasion increased by 1!\n");
                enemy.évasion += 1;
            } else if (strcmp(enemy.nom, "Supirtle") == 0) {
                printf("The enemy used Shell!\n");
                printf("The enemy's defense increased by 1!\n");
                enemy.défense += 1;
            }
        }
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

void tour_adversaire(Pokemon *monPokemon, Pokemon *enemy)
{
    int move_choice = rand() % 2;

    double dodgeRate = (enemy->précision / (enemy->précision + monPokemon->évasion)) + 0.1;
    double rand_val_dodge = (double)rand() / RAND_MAX;
    if (rand_val_dodge > dodgeRate)
    {
        printf("The enemy's attack missed!\n");
        return;
    }

    if (move_choice == 0) {
        // Enemy uses basic attack
        int damage = 0;
        if (strcmp(enemy->nom, "Supmander") == 0) {
            damage = (enemy->attaque * 3) / monPokemon->défense;
            printf("The enemy used Scratch! ");
        } else if (strcmp(enemy->nom, "Supasaur") == 0) {
            damage = (enemy->attaque * 2) / monPokemon->défense;
            printf("The enemy used Pound! ");
        } else if (strcmp(enemy->nom, "Supirtle") == 0) {
            damage = (enemy->attaque * 2) / monPokemon->défense;
            printf("The enemy used Pound! ");
        }
        // Add random chance to round up or down
        double round_chance = (double)rand() / RAND_MAX;
        if (round_chance < 0.5)
            damage = (int)floor(damage);
        else
            damage = (int)ceil(damage);

        monPokemon->hp -= damage;
        printf("You lost %d HP!\n", damage);
    } else {
        // Enemy uses special attack
        if (strcmp(enemy->nom, "Supmander") == 0) {
            printf("The enemy used Growl!\n");
            printf("The enemy's attack increased by 1!\n");
            enemy->attaque += 1;
        } else if (strcmp(enemy->nom, "Supasaur") == 0) {
            printf("The enemy used Foliage!\n");
            printf("The enemy's evasion increased by 1!\n");
            enemy->évasion += 1;
        } else if (strcmp(enemy->nom, "Supirtle") == 0) {
            printf("The enemy used Shell!\n");
            printf("The enemy's defense increased by 1!\n");
            enemy->défense += 1;
        }
    }
}

int tousSupemonsKO(Joueur *joueur)
{
    for (int i = 0; i < joueur->nb_supemon; i++) {
        if (joueur->equipe[i].hp > 0) {
            return 0; 
        }
    }
    return 1; 
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

    // Comparaison des vitesses pour déterminer qui commence
    int playerStarts = monPokemon.vitesse >= enemy.vitesse; // Si la vitesse du joueur est plus grande ou égale, il commence

    int game_over = 0;
    while (!game_over) {
        if (playerStarts) {
            printf("Your turn!\n");
            printf("What do you want to do?\n");
            printf("1. Move\n");
            printf("2. Change Supémon\n");
            printf("3. Use an item\n");
            printf("4. Run away\n");
            printf("5. Capture the enemy\n");
            
            int choice;
            if (monPokemon.hp <= 0) {
                printf("Your Supémon is KO! You need to switch to another Supémon.\n");
                change(monPokemon, joueur);
                // Vérifier à nouveau si tous les Supémons sont KO
                if (tousSupemonsKO(joueur)) {
                    printf("All your Supémons are KO! You lost the battle.\n");
                    game_over = 1;
                    break;
                }
            }
            
            switch (choice) {
                case 1:
                    attack(&enemy, &monPokemon);
                    break;
                case 2:
                    change(monPokemon, joueur);
                    break;
                case 3:
                    item();
                    break;
                case 4:
                    run(enemy, &monPokemon);
                    break;
                case 5:
                    capture(enemy, maxhp, joueur);
                    break;
                default:
                    printf("Invalid choice!\n");
                    break;
            }
        } else {
            // Si c'est l'ennemi qui commence, il agit d'abord
            printf("It's the enemy's turn!\n");
            tour_adversaire(&monPokemon, &enemy);
        }

        // Vérifier si l'adversaire ou le joueur est KO
        if (monPokemon.hp <= 0) {
            printf("Your Supémon is KO! You need to switch to another Supémon.\n");
            change(monPokemon, joueur);  // Permet au joueur de changer de Supémon
            if (tousSupemonsKO(joueur)) {
                printf("All your Supémons are KO! You lost the battle.\n");
                game_over = 1;
                break;
            }
        }
        
        if (enemy.hp <= 0) {
            printf("You defeated the enemy!\n");
            int reward = (rand() % 401) + 100;
            printf("You earned %d Supcoins!\n", reward);
            game_over = 1;
            break;
        }

        // Tour suivant
        playerStarts = !playerStarts; // Inverser qui commence le tour
    }
    
    return 0;
}

