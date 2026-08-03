#pragma once

#include "items/item_template.h"

class clothes_template : public item_template {
private:
    int shield;

public:
    // Конструктор
    clothes_template(const std::string& new_name, const std::string& new_description, int new_shield, const double& new_weight);

    // Геттеры
    int GetShield() const;
};