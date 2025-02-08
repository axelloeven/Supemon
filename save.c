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
    
    // Écrire en format JSON
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

int loadGame(Joueur *joueur, char *playerName) {
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
        // ... ajouter d'autres lectures de propriétés si nécessaire
    }
    
    fclose(file);
    printf("Partie chargée avec succès !\n");
    return 1;
}
    
