//
// Created by axelo on 03/02/2025.
//

#include "battle.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "choicesupemon.h"
#include "out-of-combat.h"
#include "inventory.h"
#include "save.h"
#include <math.h>

void tour_adversaire(Pokemon *monPokemon, Pokemon *enemy, Joueur *joueur, const char *playerName);

// Fonction pour calculer si une attaque est esquivée
void dodge(Pokemon *monPokemon, Pokemon *enemy) {
    double dodgeRate = (monPokemon->precision / (monPokemon->precision + enemy->evasion)) + 0.1;
    double rand_val_dodge = (double)rand() / RAND_MAX;
    if (rand_val_dodge > dodgeRate) {
        printf("The attack missed!\n");
        return;
    }
}

void attack(Pokemon *enemy, Pokemon *monPokemon)
{
    if (monPokemon->hp <= 0) {
        printf("You can't attack, your Supémon is KO!\n");
        return;
    }

    printf("Which move do you want to use?\n");
    printf("1. %s\n", monPokemon->moves[0]);
    printf("2. %s\n", monPokemon->moves[1]);

    int choice;
    scanf("%d", &choice);

    // Vérifier si l'attaque est esquivée
    dodge(monPokemon, enemy);

    int damage = 0;
    if (choice == 1) {
        // Calculating damages based on the defense of the enemy
        if (strcmp(monPokemon->nom, "Supmander") == 0) {
            damage = (monPokemon->attaque * 3) / enemy->defense;
            printf("You used Scratch! ");
        } else if (strcmp(monPokemon->nom, "Supasaur") == 0) {
            damage = (monPokemon->attaque * 2) / enemy->defense;
            printf("You used Pound! ");
        } else if (strcmp(monPokemon->nom, "Supirtle") == 0) {
            damage = (monPokemon->attaque * 2) / enemy->defense;
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
            monPokemon->evasion += 1;
        } else if (strcmp(monPokemon->nom, "Supirtle") == 0) {
            printf("You used Shell!\n");
            printf("Your defense increased by 1!\n");
            monPokemon->defense += 1;
        }
    }
}

void change(Pokemon *monPokemon, Joueur *joueur)
{
    printf("You Currently have %s out. \n", monPokemon->nom);

    printf("\n Here your team: \n");
    for (int i = 0; i < joueur->nb_supemon; i++)
    {
        printf("Supémon %d : %s\n", i + 1, joueur->equipe[i].nom);
    }
    printf("\n Which Supémon do you want to send out? \n");
    int changer;
    scanf("%d", &changer);
    *monPokemon = joueur->equipe[changer-1];
}

void item()
{
    printf("You are accessing your inventory...\n");
    inventory();
}

void run(Pokemon enemy, Pokemon monPokemon, Joueur *joueur, const char *playerName)
{
    double success_rate = monPokemon.vitesse / (monPokemon.vitesse + enemy.vitesse);
    double rand_val = (double)rand() / RAND_MAX;

    printf("Attempting to run away...\n");

    if (rand_val <= success_rate) {
        printf("You successfully ran away from the battle!\n");
        outofcombat(joueur, playerName);
    } else {
        printf("You failed to run away!\nThe battle continues...\n");
        printf("The enemy attacks!\n");
        tour_adversaire(&monPokemon, &enemy, joueur, playerName);
    }
}

void capture(Pokemon enemy, int maxhp, Joueur *joueur, const char *playerName)
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
        saveGame(joueur, playerName);
        outofcombat(joueur, playerName);
    }
    else
    {
        printf("The enemy broke free!");
    }
}
}

void tour_adversaire(Pokemon *monPokemon, Pokemon *enemy, Joueur *joueur, const char *playerName)
{
    int move_choice = rand() % 2;

    double dodgeRate = (enemy->precision / (enemy->precision + monPokemon->evasion)) + 0.1;
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
            damage = (enemy->attaque * 3) / monPokemon->defense;
            printf("The enemy used Scratch! ");
        } else if (strcmp(enemy->nom, "Supasaur") == 0) {
            damage = (enemy->attaque * 2) / monPokemon->defense;
            printf("The enemy used Pound! ");
        } else if (strcmp(enemy->nom, "Supirtle") == 0) {
            damage = (enemy->attaque * 2) / monPokemon->defense;
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
        saveGame(joueur, playerName);
    } else {
        // Enemy uses special attack
        if (strcmp(enemy->nom, "Supmander") == 0) {
            printf("The enemy used Growl!\n");
            printf("The enemy's attack increased by 1!\n");
            enemy->attaque += 1;
        } else if (strcmp(enemy->nom, "Supasaur") == 0) {
            printf("The enemy used Foliage!\n");
            printf("The enemy's evasion increased by 1!\n");
            enemy->evasion += 1;
        } else if (strcmp(enemy->nom, "Supirtle") == 0) {
            if (monPokemon-> attaque = enemy->defense+1 )
                move_choice = 0;
            else if (monPokemon-> attaque = enemy->defense-1 )
                printf("The enemy used Shell!\n");
                printf("The enemy's defense increased by 1!\n");
                enemy->defense += 1;
        }
    }
}

int tousSupemonsKO(Joueur *joueur)
{
    for (int i = 0; i < joueur->nb_supemon; i++) {
        if (joueur->equipe[i].hp > 0) {
            return 0;  // Au moins un Pokémon est encore en vie
        }
    }
    return 1;  // Tous les Pokémon sont KO
}

int battle(Joueur *joueur, const char *playerName)
{
    printf("You are walking...\n");
    printf("A wild enemy appears!\n");
    

    Pokemon *monPokemon = &joueur->equipe[0];

    
    int pokemonrandom = rand() % 3;
    printf("You are fighting a %s\n", pokemonrandom == 1 ? "Supmander" : pokemonrandom == 2 ? "Supasaur" : "Supirtle");
    Pokemon enemy = {0};  // Initialiser tous les champs à 0
    
    switch (pokemonrandom) {
    case 1:
        strcpy(enemy.nom, "Supmander");
        enemy.lvl = monPokemon->lvl;
        enemy.xp = 0;
        enemy.hp = 10;
        enemy.attaque = 1;
        enemy.defense = 1;
        enemy.evasion = 1;
        enemy.precision = 2.0;
        enemy.vitesse = 2.0;
        

        for(int i = 1; i < enemy.lvl; i++) {
            enemy.hp = (int)(enemy.hp * 1.3);
            enemy.attaque = (int)(enemy.attaque * 1.3);
            enemy.defense = (int)(enemy.defense * 1.3);
            enemy.evasion = (int)(enemy.evasion * 1.3);
            enemy.precision = enemy.precision * 1.3;
            enemy.vitesse = enemy.vitesse * 1.3;
        }
        strcpy(enemy.moves[0], "Scratch deals 3 damages");
        strcpy(enemy.moves[1], "Growl gives 1 attack");
        break;

    case 2:
        strcpy(enemy.nom, "Supasaur");
        enemy.lvl = monPokemon->lvl;
        enemy.xp = 0;
        enemy.hp = 9;
        enemy.attaque = 1;
        enemy.defense = 1;
        enemy.evasion = 3;
        enemy.precision = 2.0;
        enemy.vitesse = 2.0;
        
        for(int i = 1; i < enemy.lvl; i++) {
            enemy.hp = (int)(enemy.hp * 1.3);
            enemy.attaque = (int)(enemy.attaque * 1.3);
            enemy.defense = (int)(enemy.defense * 1.3);
            enemy.evasion = (int)(enemy.evasion * 1.3);
            enemy.precision = enemy.precision * 1.3;
            enemy.vitesse = enemy.vitesse * 1.3;
        }
        strcpy(enemy.moves[0], "Pound deals 2 damages");
        strcpy(enemy.moves[1], "Foliage gives 1 Evasion");
        break;

    default:
        strcpy(enemy.nom, "Supirtle");
        enemy.lvl = monPokemon->lvl;
        enemy.xp = 0;
        enemy.hp = 11;
        enemy.attaque = 1;
        enemy.defense = 2;
        enemy.evasion = 2;
        enemy.precision = 1.0;
        enemy.vitesse = 2.0;
        
        for(int i = 1; i < enemy.lvl; i++) {
            enemy.hp = (int)(enemy.hp * 1.3);
            enemy.attaque = (int)(enemy.attaque * 1.3);
            enemy.defense = (int)(enemy.defense * 1.3);
            enemy.evasion = (int)(enemy.evasion * 1.3);
            enemy.precision = enemy.precision * 1.3;
            enemy.vitesse = enemy.vitesse * 1.3;
        }
        strcpy(enemy.moves[0], "Pound deals 2 damages");
        strcpy(enemy.moves[1], "Shell gives 1 defense");
        break;
    }
    int maxhp = enemy.hp;
    afficherPokemon(enemy);
    afficherPokemon(*monPokemon);
    printf("The battle begins!\n");


    int playerStarts = monPokemon->vitesse >= enemy.vitesse;
    if (monPokemon->vitesse == enemy.vitesse) {
        playerStarts = rand() % 2;
    }

    int game_over = 0;
    while (!game_over) {

        if (monPokemon->hp <= 0) {
            if (tousSupemonsKO(joueur)) {
                printf("All your Supémons are KO! You lost the battle.\n");
                game_over = 1;
                outofcombat(joueur, playerName);
                return 0;
            } else {
                printf("Your Supémon is KO! You need to switch to another Supémon.\n");
                change(monPokemon, joueur);
                continue;
            }
        }

        if (playerStarts) {
            printf("Your turn!\n");
            printf("What do you want to do?\n");
            printf("1. Move\n");
            printf("2. Change Supémon\n");
            printf("3. Use an item\n");
            printf("4. Run away\n");
            printf("5. Capture the enemy\n");

            int choice;
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    attack(&enemy, monPokemon);
                    break;
                case 2:
                    change(monPokemon, joueur);
                    break;
                case 3:
                    item();
                    break;
                case 4:
                    run(enemy, *monPokemon, joueur, playerName);
                    return 0;
                case 5:
                    capture(enemy, maxhp, joueur, playerName);
                    return 0;
                default:
                    printf("Invalid choice!\n");
                    continue;
            }
        } else {
            printf("Enemy's turn!\n");
            tour_adversaire(monPokemon, &enemy, joueur, playerName);
            
            // Vérifier si le joueur est KO après l'attaque de l'ennemi
            if (monPokemon->hp <= 0) {
                if (tousSupemonsKO(joueur)) {
                    printf("All your Supémons are KO! You lost the battle.\n");
                    game_over = 1;
                    outofcombat(joueur, playerName);
                    return 0;
                } else {
                    printf("Your Supémon is KO! You need to switch to another Supémon.\n");
                    change(monPokemon, joueur);
                }
            }
            
            playerStarts = 1;  // Passer le tour au joueur
            continue;  // Recommencer la boucle pour le tour du joueur
        }

        // Vérifier l'état du combat après chaque tour complet
        if (enemy.hp <= 0) {
            printf("You defeated the enemy!\n");
            int reward = (rand() % 401) + 100;
            printf("You earned %d Supcoins!\n", reward);
            supcoins += reward;
            joueur->equipe[0].xp += 500*enemy.lvl;
            if (lvlup(&joueur->equipe[0], joueur, playerName)) {
                printf("%s grew to level %d!\n", joueur->equipe[0].nom, joueur->equipe[0].lvl);
            }
            game_over = 1;
            saveGame(joueur, playerName);
        }

        // Alterner les tours seulement si le combat n'est pas terminé
        if (!game_over) {
            playerStarts = !playerStarts;
        }
    }

    outofcombat(joueur, playerName);
    return 0;
}


