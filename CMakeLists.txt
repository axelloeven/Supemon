cmake_minimum_required(VERSION 3.30)
project(Supemon C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Supemon
    intro.c
    main.c
    out-of-combat.c
    battle.c
    shop.c
    center.c
    supemon.c
    save.c
        inventory.c
)
