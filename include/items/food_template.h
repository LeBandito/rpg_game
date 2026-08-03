#pragma once

#include "items/item_template.h"

class food_template : public item_template {
private:
    int health_effect;

public:
    // Конструктор
    food_template(const std::string& new_name, const std::string& new_description, double new_weight, int new_health_effect);

    int Use();

    // Геттеры
    int GetHealthEffect() const;
};