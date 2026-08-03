#include "items/food_template.h"

#include <stdexcept>

// Конструктор
food_template::food_template(const std::string& new_name, const std::string& new_description, double new_weight, int new_health_effect) : 
    item_template(new_name, new_description, new_weight), health_effect(new_health_effect) {}

int food_template::Use() { return health_effect; }

// Геттеры
int food_template::GetHealthEffect() const { return health_effect; }