//
// Created by axelo on 03/02/2025.
//
#include <stdio.h>
#include <stdlib.h>
#include "shop.h"

int shop() {

  printf("Welcome to the shop !\n");
  printf("What do you want to do ?\n");
  printf("1. Buy an object\n");
  printf("2. Sell an object\n");
  int choicebs;
  if (choicebs == 1)
  {
    printf("What do yoy want to buy ?\n");
    printf("1. Potion (100 Supcoins), It gives +5PV to your Supemon \n");
    printf("2. Super Potion (300 Supcoins), It gives +10PV to your Supemon \n");
    prinf("3. Rare Candy (700 Supcoins), It gives +1 level to your Supemon \n");
    printf("4. Back to the shop menu\n");
    int choicebuy;
    scanf("%d", &choicebuy);
    if (choicebuy == 1)
    {
      if (supcoins >= 100)
      {
        supcoins -= 100;
        pv += 5;
        printf("You bought a potion !\n");
        shop();
      }
      else
      {
        printf("You don't have enough Supcoins !\n");
        shop();
      }
    }
    if (choicebuy == 2)
    {
      if (supcoins >= 300)
      {
        supcoins -= 300;
        pv += 10;
        printf("You bought a super potion !\n");
        shop();
      }
      else
      {
        printf("You don't have enough Supcoins !\n");
        shop();
      }
    }
    if (choicebuy == 3)
    {
      if (supcoins >= 700)
      {
        supcoins -= 700;
        level += 1;
        printf("You bought a rare candy !\n");
        shop();
      }
      else
      {
        printf("You don't have enough Supcoins !\n");
        shop();
      }
    }
    if (choicebuy == 4)
    {
      shop();
    }

  }
  if (choicebs ==2 )
  {
      printf("What do you want to sell ?\n");
      printf("1. Potion (50 Supcoins)\n");
      printf("2. Super Potion (150 Supcoins)\n");
      printf("3. Rare Candy (350 Supcoins)\n");
      printf("4. Back to the shop menu\n");
      int choicesell;
      scanf("%d", &choicesell);
      if (choicesell == 1)
      {
          if (potion_count > 0)
          {
              potion_count -= 1;
              supcoins += 50;
              printf("You sold a potion !\n");
              shop();
          }
          else
          {
              printf("You don't have any potions to sell !\n");
              shop();
          }
      }
      if (choicesell == 2)
      {
          if (super_potion_count > 0)
          {
              super_potion_count -= 1;
              supcoins += 150;
              printf("You sold a super potion !\n");
              shop();
          }
          else
          {
              printf("You don't have any super potions to sell !\n");
              shop();
          }
      }
      if (choicesell == 3)
      {
          if (rare_candy_count > 0)
          {
              rare_candy_count -= 1;
              supcoins += 350;
              printf("You sold a rare candy !\n");
              shop();
          }
          else
          {
              printf("You don't have any rare candies to sell !\n");
              shop();
          }
      }
      if (choicesell == 4)
      {
          shop();
      }


      return 0;
  }
}