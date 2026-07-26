#pragma once

#include "entities/player.h"
#include "entities/enemy.h"
#include "shop/shop.h"

class game {
protected:
    player bruh;
    std::array<enemy, 3> enemies;
    shop shopper;
    int idx_enemies;

public:
    // Создание персонажа
    void CreateHero() {
        std::cout << "Welcome to the menu of creating hero!" << std::endl;
        std::string new_name;
        std::cout << "Give a name to youre character:\t" << std::endl;
        std::cin >> new_name;

    }

};