#pragma once

#include "items/item_template.h"

class potion_template : public item_template {
private:
    int health_effect;
    int effect_duration;

public:
    // Конструктор
    potion_template(const std::string& new_name, const std::string& new_description, double new_weight, int new_health_effect, int new_effect_duration);

    // Геттеры
    int GetHealthEffect() const;
    int GetEffectDuration() const;
};