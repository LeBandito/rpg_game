#include "items/potion_template.h"

#include <stdexcept>

// Конструктор
potion_template::potion_template(const std::string& new_name, const std::string& new_description, double new_weight, int new_health_effect, int new_effect_duration) : 
    item_template(new_name, new_description, new_weight) {
    if (new_effect_duration < 0)
        throw std::invalid_argument("Error: class potion_template");

    health_effect = new_health_effect;
    effect_duration = new_effect_duration;
}

// Геттеры
int potion_template::GetHealthEffect() const { return health_effect; }
int potion_template::GetEffectDuration() const { return effect_duration; }