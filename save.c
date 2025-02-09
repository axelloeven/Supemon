//
// Created by axelo on 08/02/2025.
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
        printf("Erreur lors de la création du fichier de sauvegarde.\n");
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
    printf("Partie sauvegardée avec succès !\n");
}

int loadGame(Joueur *joueur, const char *playerName) {
    char filename[64];
    sprintf(filename, "save_%s.json", playerName);
    
    FILE *file = fopen(filename, "r");  // Mode texte au lieu de binaire
    if (file == NULL) {
        printf("Aucune sauvegarde trouvée pour ce joueur.\n");
        return 0;
    }

    // Buffer pour lire le fichier ligne par ligne
    char line[256];
    char value[256];
    
    while (fgets(line, sizeof(line), file)) {
        // Lecture de l'inventaire
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
        // Lecture du nombre de Supémon
        else if (strstr(line, "\"nbSupemon\":")) {
            sscanf(line, "    \"nbSupemon\": %d,", &joueur->nb_supemon);
        }
        // Lecture des Supémon
        else if (strstr(line, "\"name\":")) {
            int index = joueur->nb_supemon - 1;
            sscanf(line, "        \"name\": \"%[^\"]\"", joueur->equipe[index].nom);
        }
        else if (strstr(line, "\"hp\":")) {
            int index = joueur->nb_supemon - 1;
            sscanf(line, "        \"hp\": %d,", &joueur->equipe[index].hp);
        }
        else if (strstr(line, "\"attack\":")) {
            int index = joueur->nb_supemon - 1;
            sscanf(line, "        \"attack\": %d,", &joueur->equipe[index].attaque);
        }
        else if (strstr(line, "\"defense\":")) {
            int index = joueur->nb_supemon - 1;
            sscanf(line, "        \"defense\": %d,", &joueur->equipe[index].defense);
        }
        else if (strstr(line, "\"evasion\":")) {
            int index = joueur->nb_supemon - 1;
            sscanf(line, "        \"evasion\": %d,", &joueur->equipe[index].evasion);
        }
        else if (strstr(line, "\"precision\":")) {
            int index = joueur->nb_supemon - 1;
            sscanf(line, "        \"precision\": %lf,", &joueur->equipe[index].precision);
        }
        else if (strstr(line, "\"speed\":")) {
            int index = joueur->nb_supemon - 1;
            sscanf(line, "        \"speed\": %lf,", &joueur->equipe[index].vitesse);
        }
        else if (strstr(line, "\"level\":")) {
            int index = joueur->nb_supemon - 1;
            sscanf(line, "        \"level\": %d,", &joueur->equipe[index].lvl);
        }
        else if (strstr(line, "\"xp\":")) {
            int index = joueur->nb_supemon - 1;
            sscanf(line, "        \"xp\": %d,", &joueur->equipe[index].xp);
        }
        else if (strstr(line, "\"moves\":")) {
            int index = joueur->nb_supemon - 1;
            sscanf(line, "        \"moves\": [\"%[^\"]\", \"%[^\"]\"", 
                  joueur->equipe[index].moves[0], 
                  joueur->equipe[index].moves[1]);
        }
    }
    
    fclose(file);
    printf("Partie chargée avec succès !\n");
    return 1;
}
    
