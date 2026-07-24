#include "battle/battle.h"

void battle::Fight(player& bruh, enemy& eminem) {
    int round(1);
    while ((bruh.GetHp() > 0) || (eminem.GetHp() > 0)) {
        std::cout << "Round " << round  << "!" << std::endl;
        // Ход Героя
        if (round % 2 == 1) {
            int choose(0);
            // Проверка коррестности
            while ((choose != 1) || (choose != 2)) {
                std::cout << "What attac?" << std::endl;
                std::cout << "1) " << bruh.GetWeapon().first.name << " | (" << bruh.GetWeapon().first.min_effect << ", " << bruh.GetWeapon().first.max_effect << ");"<< std::endl;
                std::cout << "2) " << bruh.GetWeapon().second.name << " | (" << bruh.GetWeapon().second.min_effect << ", " << bruh.GetWeapon().second.max_effect << ");"<< std::endl;
            }

            // Проработать случайную атаку и защиту! Использую Switch Case на будущее. Хочу сделать 3 вида оружия для персонажа!
            switch (choose) 
            {
            case 1:
                std::cout << "Attack = " << bruh.GetWeapon().first.max_effect - bruh.GetWeapon().first.min_effect + bruh.GetWeapon().first.min_effect << "!" << std::endl;
                eminem.damage(bruh.GetWeapon().first.max_effect - bruh.GetWeapon().first.min_effect + bruh.GetWeapon().first.min_effect);
                break;

            case 2:
                std::cout << "Attack = " << bruh.GetWeapon().second.max_effect - bruh.GetWeapon().second.min_effect + bruh.GetWeapon().second.min_effect << "!" << std::endl;
                eminem.damage(bruh.GetWeapon().second.max_effect - bruh.GetWeapon().second.min_effect + bruh.GetWeapon().second.min_effect);
                break;
            
            default:
                break;
            }

            // Результаты атаки
            eminem.ShowStatistic();

        // Ход врага
        } else {
            std::cout << "Attack = " << eminem.GetWeapon().min_effect << "!" << std::endl;
            bruh.damage(eminem.GetWeapon().min_effect);
        }
    }

    if (eminem.IsAlive()) {
        std::cout << "Enemy is still alive!\nYou're dead..." << std::endl;
    } else {
        std::cout << "You are WIN!" << std::endl;
    }
}