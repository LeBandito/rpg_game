#pragma once

#include "entities/character.h"
#include "items/weapons.h"

class enemy : public character {
protected:
    weapon enemy_weapon;

public:
    // Отдать деньги после победы
    int ToGiveMoney();

    // Отдать оружие
    weapon ToGiveWeapon();

    // Сеттер
    void SetWeapon(const weapon& new_enemy_weapon);

    // Геттеры
    weapon GetWeapon() const;
};