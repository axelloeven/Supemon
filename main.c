//
// Created by axelo on 03/02/2025.
//

#include "main.h"
#include "intro.h"
#include "out-of-combat.h"
#include "choicesupemon.h"
#include "battle.h"
#include "shop.h"
#include "center.h"
#include "supemon.h"
#include "inventory.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    Joueur joueur = { .nbPokemons = 0 };
    intro();
    outofcombat();
    return 0;
}