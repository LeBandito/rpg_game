#include "items/weapons.h"

// Сеттеры
void weapon::SetMinDamage(const int& new_min_damage) { min_damage = new_min_damage; }
void weapon::SetMaxDamage(const int& new_max_damage) { max_damage = new_max_damage; }
void weapon::SetEffect(const int& new_effect) { effect = new_effect; }

// Геттеры
int weapon::GetMinDamage() const { return min_damage; }
int weapon::GetMaxDamage() const { return max_damage; }
int weapon::GetEffect() const { return effect; }