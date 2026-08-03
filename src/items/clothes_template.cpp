#include "items/clothes_template.h"

#include <stdexcept>

// Конструктор
clothes_template::clothes_template(const std::string& new_name, const std::string& new_description, int new_shield, const double& new_weight) : 
    item_template(new_name, new_description, new_weight) {
    if (new_shield < 0)
        throw std::invalid_argument("Error: class clothes_template");

    shield = new_shield;
}

// Геттеры
int clothes_template::GetShield() const { return shield; }