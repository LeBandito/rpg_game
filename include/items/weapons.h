#pragma once

#include "items/items.h"

class weapon : public item {
protected:
    int min_damage;
    int max_damage;
    int effect;

public:
    // Сеттеры
    void SetMinDamage(const int& new_min_damage);
    void SetMaxDamage(const int& new_max_damage);
    void SetEffect(const int& new_effect);

    // Геттеры
    int GetMinDamage() const;
    int GetMaxDamage() const;
    int GetEffect() const;
};