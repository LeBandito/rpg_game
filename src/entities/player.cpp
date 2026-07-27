#include "entities/player.h"

#include <iostream>

// Конструктор по умолчанию
player::player() : character(), player_weapon_first(weapon()), player_weapon_second(weapon()), weight_inventory(0) {
    for (int i = 0; i < player_weapons.size(); ++i)
        player_weapons[i] = weapon();
}

// Конструктор с параметрами
player::player(const std::string& new_name, const int& new_hp, const int& new_max_hp, const int& new_money, const std::array<item, 5>& new_inventory, 
    const int& new_max_weight_inventory, const bool& new_alive, const weapon& new_player_weapon_first, const weapon& new_player_weapon_second, 
    const std::array<weapon, 2>& new_player_weapons, const int& new_weight_inventory) : 
    character(new_name, new_hp, new_max_hp, new_money, new_inventory, new_max_weight_inventory, new_alive), player_weapon_first(new_player_weapon_first), 
    player_weapon_second(new_player_weapon_second), player_weapons(new_player_weapons), weight_inventory(new_weight_inventory) {} 


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