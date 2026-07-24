#include "entities/player.h"

void player::GetMoney(const int& plus_money) {
    money += plus_money;
}

void player::SpendMoney(const int& minus_money) {
    money -= money;
}

void player::AddItemToInventory(const item& temporary, const int& position) {
    if (weight_inventory + temporary.weight > max_weight_inventory) {
        std::cout << "Too much weight..." << std::endl;
    } else if (inventory[position].name == "empty") {
        inventory[position] = temporary;
        weight_inventory += temporary.weight;
    } else {
        std::cout << "The bag is full!" << std::endl;
    }
}

void player::ChangeWeapon() {
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

    if ((player_weapon_id == 1) && (inventory[new_player_weapon_id].type == "weapon")) {
        player_weapon.first = inventory[new_player_weapon_id];
    } else {
        std::cout << "Choose weapon!" << std::endl;
    }
}