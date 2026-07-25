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
    // Игровое меню
    void menu() {
        int choose(0);
        while ((choose != 1) || (choose != 2) || (choose != 3)) {
            // В будущем добавить возможность сохраненией!
            std::cout << "Hello! It's RPG GAME!" << std::endl;
            std::cout << "1) New game." << std::endl;
            std::cout << "2) Continue." << std::endl;
            std::cout << "3) Exit." << std::endl;
        }

        switch (choose)
        {
        case 1:
            
            break;
        
        default:
            break;
        }
    }

    // Создание персонажа
    void CreateHero() {
        std::string new_name_hero;
        std::cout << "Enter the name:\t" << std::endl;
        std::cin >> new_name_hero;
        // bruh. 
    }

    void StartGame() {

    }
};