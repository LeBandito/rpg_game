#pragma once

#include "entities/character.h"

class enemy : public character {
protected:
    item enemy_weapon;

public:
    // Отдать деньги после победы
    int ToGiveMoney();
};