#include "entities/player.h"

#include <iostream>

void player::PlusMoney(const int& plus_money) {
    money += plus_money;
}

void player::SpendMoney(const int& minus_money) {
    money -= money;
}

void player::AddItemToInventory(const item& temporary, const int& position) {
    if (weight_inventory + temporary.GetWeight() > max_weight_inventory) {
        std::cout << "Too much weight..." << std::endl;
    } else if (inventory[position].GetName() == "none") {
        inventory[position] = temporary;
        weight_inventory += temporary.GetWeight();
    } else {
        std::cout << "The bag is full!" << std::endl;
    }
}

void player::ChangeWeapon() {
    int player_weapon_id(0);
    std::cout << "Which weapon?" << std::endl;
    std::cout << "1) " << player_weapon_first.GetName() << "?" << std::endl;
    std::cout << "2) " << player_weapon_second.GetName() << "?" << std::endl;
    std::cin >> player_weapon_id;

    std::cout << "Choose new weapon:" << std::endl;
    int idx(0);
    for (int i = 0; i < player_weapons.size(); ++i) 
        std::cout << i + 1 << ") " << player_weapons[i].GetName() << " | (" << player_weapons[i].GetMinDamage() << ", " << player_weapons[i].GetMaxDamage() << ")" << std::endl;
    std::cin >> idx;

    if (player_weapon_id == 1) {
        player_weapon_first = player_weapons[idx];
    } else if (player_weapon_id == 2) {
        player_weapon_second = player_weapons[idx];
    } else {
        std::cout << "What?" << std::endl;        
    }
}

// Сеттеры
void player::SetPlayerWeaponFirst(const weapon& new_player_weapon_first) { player_weapon_first = new_player_weapon_first; }
void player::SetPlayerWeaponSecond(const weapon& new_player_weapon_second) { player_weapon_second = new_player_weapon_second; }
void player::SetPlayerWeapons(const std::array<weapon, 2>& new_player_weapons) { player_weapons = new_player_weapons; }
void player::SetWeightInventory(const int& new_weight_inventory) { weight_inventory = new_weight_inventory; }

// Геттеры
weapon player::GetPlayerWeaponFirst() const { return player_weapon_first; }
weapon player::GetPlayerWeaponSecond() const { return player_weapon_second; }
std::array<weapon, 2> player::GetPlayerWeapons() const { return player_weapons; }
int player::GetWeightInventory() const { return weight_inventory; }