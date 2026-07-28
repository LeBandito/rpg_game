#include "entities/player.h"

#include "shop/shop.h"

#include <iostream>

// Конструктор по умолчанию
player::player() : character(), player_weapon_first(weapon()), player_weapon_second(weapon()) {}

// Конструктор с параметрами
player::player(const int& new_id, const std::string& new_name, const bool& new_alive, const int& new_hp, 
    const int& new_max_hp, const int& new_money, const inventory& new_bag, const weapon& new_player_weapon_first, const weapon& new_player_weapon_second) : 
    character(new_id, new_name, new_alive, new_hp, new_max_hp, new_money, new_bag), 
    player_weapon_first(new_player_weapon_first), player_weapon_second(new_player_weapon_second) {} 


void player::ReceiveMoney(const int& cash) {
    money += cash;
}

int player::GiveMoney(const int& minus_money) {
    money -= minus_money;
    return minus_money;
}

void player::AddItemToTheBag(const item& temporary, const int& index) {
    if (bag.GetWeightInventory() + temporary.GetWeight() > bag.GetMaxWeightInventory()) {
        std::cout << "Too much weight..." << std::endl;
    } else if (bag.GetInventoryItems(index).GetName() == "none") {
        bag.ReceiveInventoryItems(index, temporary);
    } else {
        std::cout << "The bag is full!" << std::endl;
    }
}

void player::AddWeaponsToTheBag(const weapon& temporary, const int& index) {
    if (bag.GetWeightInventory() + temporary.GetWeight() > bag.GetMaxWeightInventory()) {
        std::cout << "Too much weight..." << std::endl;
    } else if (bag.GetInventoryWeapons(index).GetName() == "none") {
        bag.ReceiveInventoryItems(index, temporary);
    } else {
        std::cout << "The bag is full!" << std::endl;
    }
}

void player::AddClothesToTheBag(const clothes& temporary, const int& index) {
    if (bag.GetWeightInventory() + temporary.GetWeight() > bag.GetMaxWeightInventory()) {
        std::cout << "Too much weight..." << std::endl;
    } else if (bag.GetInventoryClothes(index).GetName() == "none") {
        bag.ReceiveInventoryItems(index, temporary);
    } else {
        std::cout << "The bag is full!" << std::endl;
    }
}

void player::AddPotionsToTheBag(const potion& temporary, const int& index) {
    if (bag.GetWeightInventory() + temporary.GetWeight() > bag.GetMaxWeightInventory()) {
        std::cout << "Too much weight..." << std::endl;
    } else if (bag.GetInventoryPotions(index).GetName() == "none") {
        bag.ReceiveInventoryItems(index, temporary);
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
    int index(0);
    bag.ShowInventoryWeapons();
    std::cout << "Number:\t";
    std::cin >> index;

    if (player_weapon_id == 1) {
        player_weapon_first = bag.GiveInventoryWeapons(index - 1);
    } else if (player_weapon_id == 2) {
        player_weapon_second = bag.GiveInventoryWeapons(index - 1);
    } else {
        std::cout << "What?" << std::endl;        
    }
}

// Сеттеры
void player::SetPlayerWeaponFirst(const weapon& new_player_weapon_first) { player_weapon_first = new_player_weapon_first; }
void player::SetPlayerWeaponSecond(const weapon& new_player_weapon_second) { player_weapon_second = new_player_weapon_second; }

// Геттеры
weapon player::GetPlayerWeaponFirst() const { return player_weapon_first; }
weapon player::GetPlayerWeaponSecond() const { return player_weapon_second; }