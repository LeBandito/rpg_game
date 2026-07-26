#include "entities/character.h"

#include <iostream>

character::character(): 
    name("none"), hp(0), max_hp(0), shield(0), money(0), alive(true), inventory() {}

character::character(const std::string& new_name, const int& new_hp, const int& new_max_hp, const int& new_shield, const int& new_money, 
        const std::array<item, 5>& new_inventory, const int& new_max_weight_inventory, const bool& new_alive): 
    name(new_name), hp(new_hp), max_hp(new_max_hp), shield(new_shield), money(new_money), alive(new_alive), inventory(new_inventory) {}

void character::damage(const int& bruh) {
    if (hp - bruh <= 0) {
        alive = false;
    } else {
        hp -= bruh;
    }
}

void character::heal(const int& bruh) {
    if (hp + bruh > max_hp) {
        hp = max_hp;
    } else {
        hp += bruh;
    }
}

bool character::IsAlive() {
    if (hp <= 0)
        return false;
    return true;
}

void character::ShowStatistic() {
    std::cout << "Name:\t" << name << std::endl;
    std::cout << "Hp:\t" << hp << std::endl;
    std::cout << "Money:\t" << money << std::endl;
    std::cout << "Alive:\t" << alive << std::endl;
}

void character::ShowInventory() {
    std::cout << "Inventory:" << std::endl;
    for (int i = 0; i < inventory.size(); ++i)
        std::cout << i + 1 << ") " << inventory[i].name << ":\t" << inventory[i].type << 
        " | (" << inventory[i].min_effect << ", " << inventory[i].max_effect << ") | " << 
        inventory[i].price << " | " << inventory[i].weight << std::endl;
}

// Сеттеры
void character::SetName(const std::string& new_name) { name = new_name; }
void character::SetHp(const int& new_hp) { hp = new_hp; }
void character::SetMaxHp(const int& new_max_hp) { max_hp = new_max_hp; }
void character::SetShield(const int& new_shield) { shield = new_shield; }
void character::SetMoney(const int& new_money) { money = new_money; }
void character::SetInventory(const std::array<item, 5>& new_inventory) { inventory = new_inventory; }
void character::SetMaxWeightInventory(const int& new_max_weight_inventory) { max_weight_inventory = new_max_weight_inventory; }
void character::SetAlive(const bool& new_alive) { alive = new_alive; }

// Геттеры
std::string character::GetName() { return name; }
int character::GetHp() { return hp; }
int character::GetMaxHp() { return max_hp; }
int character::GetShield() { return shield; }
// Тот самый геттер для shop.h!
int character::GetMoney() { return money; }
std::array<item, 5> character::GetInventory() { return inventory; }
int character::GetMaxWeightInventory() { return max_weight_inventory; }
bool character::GetAlive() { return alive; }