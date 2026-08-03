#pragma once

#include "items/item_template.h"

class weapon_template : public item_template {
private:
    int min_damage;
    int max_damage;
    double weight;

    // Фабричный метод:
    weapon_template(const std::string& new_name, const std::string& new_description, int new_min_damage, int new_max_damage, const double& new_weight);

public:
    // Конструктор
    static weapon_template create_weapon(const std::string& new_name, const std::string& new_description, int new_min_damage, int new_max_damage, const double& new_weight);

    int Use();

    // Геттеры
    int GetMinDamage() const;
    int GetMaxDamage() const;
    double GetWeight() const;
};