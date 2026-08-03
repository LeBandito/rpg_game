#include "items/weapon_template.h"

#include <stdexcept>

// Конструктор
weapon_template::weapon_template(const std::string& new_name, const std::string& new_description, double new_weight, int new_min_damage, int new_max_damage) :
    item_template(new_name, new_description, new_weight) {
    if ((new_min_damage < 0) || (new_max_damage < 0) || (new_max_damage < new_min_damage))
        throw std::invalid_argument("Error: class create_weapon");

    min_damage = new_min_damage;
    max_damage = new_max_damage;
}

int weapon_template::Use() { return min_damage + std::rand() % (max_damage - min_damage + 1); }

// Геттеры
int weapon_template::GetMinDamage() const { return min_damage; }
int weapon_template::GetMaxDamage() const { return max_damage; }