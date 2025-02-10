//
// Cr\u00E9\u00E9 par axelo le 08/02/2025.
//

#include "save.h"
#include <stdio.h>
#include <string.h>
#include "inventory.h"

void saveGame(Joueur *joueur, const char *playerName) {
    char filename[64];
    sprintf(filename, "save_%s.json", playerName);
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error with saving folder creation\n");
        return;
    }
    
    fprintf(file, "{\n");
    fprintf(file, "  \"playerName\": \"%s\",\n", playerName);
    fprintf(file, "  \"inventory\": {\n");
    fprintf(file, "    \"potions\": %d,\n", potion_count);
    fprintf(file, "    \"superPotions\": %d,\n", super_potion_count);
    fprintf(file, "    \"rareCandy\": %d,\n", rare_candy_count);
    fprintf(file, "    \"supcoins\": %d\n", supcoins);
    fprintf(file, "  },\n");
    fprintf(file, "  \"team\": {\n");
    fprintf(file, "    \"nbSupemon\": %d,\n", joueur->nb_supemon);
    fprintf(file, "    \"supemons\": [\n");
    
    for (int i = 0; i < joueur->nb_supemon; i++) {
        fprintf(file, "      {\n");
        fprintf(file, "        \"name\": \"%s\",\n", joueur->equipe[i].nom);
        fprintf(file, "        \"hp\": %d,\n", joueur->equipe[i].hp);
        fprintf(file, "        \"max_hp\": %d,\n", joueur->equipe[i].max_hp);
        fprintf(file, "        \"attack\": %d,\n", joueur->equipe[i].attaque);
        fprintf(file, "        \"defense\": %d,\n", joueur->equipe[i].defense);
        fprintf(file, "        \"evasion\": %d,\n", joueur->equipe[i].evasion);
        fprintf(file, "        \"precision\": %.2f,\n", joueur->equipe[i].precision);
        fprintf(file, "        \"speed\": %.2f,\n", joueur->equipe[i].vitesse);
        fprintf(file, "        \"level\": %d,\n", joueur->equipe[i].lvl);
        fprintf(file, "        \"xp\": %d,\n", joueur->equipe[i].xp);
        fprintf(file, "        \"moves\": [\"%s\", \"%s\"]\n", 
                joueur->equipe[i].moves[0], joueur->equipe[i].moves[1]);
        fprintf(file, "      }%s\n", i < joueur->nb_supemon - 1 ? "," : "");
    }
    
    fprintf(file, "    ]\n");
    fprintf(file, "  }\n");
    fprintf(file, "}\n");
    
    fclose(file);
    printf("Game saved succesfully !\n");
}

int loadGame(Joueur *joueur, const char *playerName) {
    char filename[64];
    sprintf(filename, "save_%s.json", playerName);
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Not any saves has been found with this name \n");
        return 0;
    }

    char line[256];
    int currentPokemon = -1;
    for(int i = 0; i < MAX; i++) {
        memset(&joueur->equipe[i], 0, sizeof(Pokemon));
    }
    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, "\"potions\":")) {
            sscanf(line, "    \"potions\": %d,", &potion_count);
        }
        else if (strstr(line, "\"superPotions\":")) {
            sscanf(line, "    \"superPotions\": %d,", &super_potion_count);
        }
        else if (strstr(line, "\"rareCandy\":")) {
            sscanf(line, "    \"rareCandy\": %d,", &rare_candy_count);
        }
        else if (strstr(line, "\"supcoins\":")) {
            sscanf(line, "    \"supcoins\": %d", &supcoins);
        }
        else if (strstr(line, "\"nbSupemon\":")) {
            sscanf(line, "    \"nbSupemon\": %d,", &joueur->nb_supemon);
        }
        else if (strstr(line, "      {")) {
            currentPokemon++;
        }
        else if (strstr(line, "\"name\":") && currentPokemon >= 0) {
            sscanf(line, "        \"name\": \"%[^\"]\"", joueur->equipe[currentPokemon].nom);
        }
        else if (strstr(line, "\"hp\":") && currentPokemon >= 0) {
            sscanf(line, "        \"hp\": %d,", &joueur->equipe[currentPokemon].hp);
            joueur->equipe[currentPokemon].max_hp = joueur->equipe[currentPokemon].hp;
        }
        else if (strstr(line, "\"attack\":") && currentPokemon >= 0) {
            sscanf(line, "        \"attack\": %d,", &joueur->equipe[currentPokemon].attaque);
        }
        else if (strstr(line, "\"defense\":") && currentPokemon >= 0) {
            sscanf(line, "        \"defense\": %d,", &joueur->equipe[currentPokemon].defense);
        }
        else if (strstr(line, "\"evasion\":") && currentPokemon >= 0) {
            sscanf(line, "        \"evasion\": %d,", &joueur->equipe[currentPokemon].evasion);
        }
        else if (strstr(line, "\"precision\":") && currentPokemon >= 0) {
            sscanf(line, "        \"precision\": %lf,", &joueur->equipe[currentPokemon].precision);
        }
        else if (strstr(line, "\"speed\":") && currentPokemon >= 0) {
            sscanf(line, "        \"speed\": %lf,", &joueur->equipe[currentPokemon].vitesse);
        }
        else if (strstr(line, "\"level\":") && currentPokemon >= 0) {
            sscanf(line, "        \"level\": %d,", &joueur->equipe[currentPokemon].lvl);
        }
        else if (strstr(line, "\"xp\":") && currentPokemon >= 0) {
            sscanf(line, "        \"xp\": %d,", &joueur->equipe[currentPokemon].xp);
        }
        else if (strstr(line, "\"moves\":") && currentPokemon >= 0) {
            char move1[50], move2[50];
            sscanf(line, "        \"moves\": [\"%[^\"]\", \"%[^\"]\"", move1, move2);
            strcpy(joueur->equipe[currentPokemon].moves[0], move1);
            strcpy(joueur->equipe[currentPokemon].moves[1], move2);
        }
    }
    fclose(file);
    printf("Game charged succesfully !\n", 130);
    for(int i = 0; i < joueur->nb_supemon; i++) {
        Pokemon *p = &joueur->equipe[i];
        int baseHP;
        if (strcmp(p->nom, "Supmander") == 0) {
            baseHP = 10;
        } else if (strcmp(p->nom, "Supasaur") == 0) {
            baseHP = 9;
        } else {
            baseHP = 11;
        }
        p->max_hp = baseHP;
        for(int j = 1; j < p->lvl; j++) {
            p->max_hp = (int)(p->max_hp * 1.3);
        }
    }
    return 1;
}