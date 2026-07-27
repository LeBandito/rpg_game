#include "items/weapons.h"

// Базовый конструктор
weapon::weapon() : item(), min_damage(0), max_damage(0), effect(0) {}

// С параметрами
weapon::weapon(const int& new_id, const std::string& new_name, const std::string& new_description, const int& new_price, 
    const int& new_weight, const int& new_min_damage, const int& new_max_damage, const int& new_effect) : 
    item(new_id, new_name, new_description, new_price, new_weight), min_damage(new_min_damage), max_damage(new_max_damage), effect(new_effect) {}

// Сеттеры
void weapon::SetMinDamage(const int& new_min_damage) { min_damage = new_min_damage; }
void weapon::SetMaxDamage(const int& new_max_damage) { max_damage = new_max_damage; }
void weapon::SetEffect(const int& new_effect) { effect = new_effect; }

// Геттеры
int weapon::GetMinDamage() const { return min_damage; }
int weapon::GetMaxDamage() const { return max_damage; }
int weapon::GetEffect() const { return effect; }