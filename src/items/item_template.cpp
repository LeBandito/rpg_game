#include "items/item_template.h"
#include <stdexcept>

// Конструктор
item_template::item_template(const std::string& new_name, const std::string& new_description, double new_weight) {
    if ((new_name.empty()) || (new_description.empty()) || (new_weight < 0))
        throw std::invalid_argument("Error: class item_template");

    name = new_name;
    description = new_description;
    weight = new_weight;
}

// Геттеры
const std::string& item_template::GetName() const { return name; }
const std::string& item_template::GetDescription() const { return description; }
double item_template::GetWeight() const { return weight; }