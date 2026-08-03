#include "items/weapon_template.h"

#include <stdexcept>
#include <ctime>

// Фабричный метод:
weapon_template::weapon_template(const std::string& new_name, const std::string& new_description, int new_min_damage, int new_max_damage, const double& new_weight) : 
    item_template(new_name, new_description), min_damage(new_min_damage), max_damage(new_max_damage), weight(new_weight) {}

// Конструктор
weapon_template weapon_template::create_weapon(const std::string& new_name, const std::string& new_description, int new_min_damage, int new_max_damage, const double& new_weight) {
    if ((new_min_damage < 0) || (new_max_damage < 0) || (new_max_damage < new_min_damage) || (new_weight < 0))
        throw std::invalid_argument("Error: class create_weapon");

    return weapon_template(new_name, new_description, new_min_damage, new_max_damage, new_weight);
}

int weapon_template::Use() { return min_damage + std::rand() % (max_damage - min_damage + 1); }

// Геттеры
int weapon_template::GetMinDamage() const { return min_damage; }
int weapon_template::GetMaxDamage() const { return max_damage; }
double weapon_template::GetWeight() const { return weight; }