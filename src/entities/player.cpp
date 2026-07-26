#include "entities/player.h"

#include <iostream>

void player::SetMoney(const int& plus_money) {
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
    std::cout << "1) " << player_weapons_first.name << "?" << std::endl;
    std::cout << "2) " << player_weapons_second.name << "?" << std::endl;
    std::cin >> player_weapon_id;

    int new_player_weapon_id(0);
    std::cout << "What choose?" << std::endl;
    for (const item& I : inventory)
        std::cout << I.name << ":\t" << I.type << " | (" << I.min_effect << ", " << I.max_effect << ") | " << I.price << " | " << I.weight << std::endl;
    std::cin >> new_player_weapon_id;

    if ((player_weapon_id == 1) && (inventory[new_player_weapon_id].type == "weapon")) {
        player_weapons_first = inventory[new_player_weapon_id];
    } else if ((player_weapon_id == 2) && (inventory[new_player_weapon_id].type == "weapon")) {
        player_weapons_second = inventory[new_player_weapon_id];
    } else {
        std::cout << "Choose weapon!" << std::endl;
    }
}

// Сеттеры
void player::SetPlayerWeaponFirst(const item& new_player_weapons_first) { player_weapons_first = new_player_weapons_first; }
void player::SetPlayerWeaponSecond(const item& new_player_weapons_second) { player_weapons_second = new_player_weapons_second; }
void player::SetWeightInventory(const int& new_weight_inventory) { weight_inventory = new_weight_inventory; }

// Геттеры
item player::GetPlayerWeaponFirst() { return player_weapons_first; };
item player::GetPlayerWeaponSecond() { return player_weapons_second; };
int player::GetWeightInventory() { return weight_inventory; }