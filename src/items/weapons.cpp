#include "items/weapons.h"

#include "ctime"
#include <iostream>

// Базовый конструктор
weapon::weapon() : item(), min_damage(0), max_damage(0), effect(0) {}

// С параметрами
weapon::weapon(const int& new_id, const std::string& new_name, const std::string& new_description, const int& new_price, 
    const int& new_weight, const int& new_min_damage, const int& new_max_damage, const int& new_effect) : 
    item(new_id, new_name, new_description, new_price, new_weight), min_damage(new_min_damage), max_damage(new_max_damage), effect(new_effect) {}

void weapon::ShowInfo() const {
    std::cout << "id:\t" << id << std::endl;
    std::cout << "name:\t" << name << std::endl;
    std::cout << "description:\t" << description << std::endl;
    std::cout << "price:\t" << price << std::endl;
    std::cout << "weight:\t" << weight << std::endl;    
    std::cout << "min_damage:\t" << min_damage << std::endl;
    std::cout << "max_damage:\t" << max_damage << std::endl;  
    std::cout << "effect:\t" << effect << std::endl;
}

std::string weapon::GetType() const { return "weapon"; }

int weapon::Use() const {
    std::srand(time(NULL));
    return min_damage + std::rand() % (max_damage - min_damage + 1);
}

// Сеттеры
void weapon::SetMinDamage(const int& new_min_damage) { min_damage = new_min_damage; }
void weapon::SetMaxDamage(const int& new_max_damage) { max_damage = new_max_damage; }
void weapon::SetEffect(const int& new_effect) { effect = new_effect; }

// Геттеры
int weapon::GetMinDamage() const { return min_damage; }
int weapon::GetMaxDamage() const { return max_damage; }
int weapon::GetEffect() const { return effect; }