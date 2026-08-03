#pragma once

#include "items/item_template.h"

class weapon_template : public item_template {
private:
    int min_damage;
    int max_damage;

public:
    // Конструктор
    weapon_template(const std::string& new_name, const std::string& new_description, double new_weight, int new_min_damage, int new_max_damage);

    int Use();

    // Геттеры
    int GetMinDamage() const;
    int GetMaxDamage() const;
};