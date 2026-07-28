#pragma once

#include "items/items.h"

class weapon : public item {
protected:
    int min_damage;
    int max_damage;
    int effect;

public:
    // Базовый конструктор
    weapon();
    // С параметрами
    weapon(const int& new_id, const std::string& new_name, const std::string& new_description, const int& new_price, 
        const int& new_weight, const int& new_min_damage, const int& new_max_damage, const int& new_effect);

    void ShowInfo() const override;
    std::string GetType() const override;
    int Use() const override;

    // Сеттеры
    void SetMinDamage(const int& new_min_damage);
    void SetMaxDamage(const int& new_max_damage);
    void SetEffect(const int& new_effect);

    // Геттеры
    int GetMinDamage() const;
    int GetMaxDamage() const;
    int GetEffect() const;
};