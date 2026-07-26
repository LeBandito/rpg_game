#pragma once

#include "items/items.h"

class potion : public item {
protected:
    int permanent_damage;
    int time;

public:
    // Сеттеры
    void SetPermanentDamage(const int& new_permanent_damage);
    void SetTime(const int& new_time);

    // Геттеры
    int GetPermanentDamage();
    int GetTime();
};