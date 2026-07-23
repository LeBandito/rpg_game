#pragma once

#include "entities/character.h"
#include "items/weapons.h"

class player : public character {
protected:
    std::pair<weapon, weapon> player_weapon;
    
public:
    // Получать деньги
    void GetMoney(const int& plus_money);

    // Тратить деньги
    void SpendMoney(const int& minus_money);

    void ChangeWeapon() {
        int player_weapon_id(0);
        std::cout << "Which weapon?" << std::endl;
        std::cout << "1) " << player_weapon.first.name << "?" << std::endl;
        std::cout << "2) " << player_weapon.second.name << "?" << std::endl;
        std::cin >> player_weapon_id;

        int new_player_weapon_id(0);
        std::cout << "What choose?" << std::endl;
        for (const item& I : inventory)
            std::cout << I.name << ":\t" << I.type[0] << " | (" << I.min_effect << ", " << I.max_effect << ") | " << I.price << std::endl;
        std::cin >> new_player_weapon_id;

        if (player_weapon_id == 1) {
            player_weapon.first = inventory[new_player_weapon_id];
        }

    }
};