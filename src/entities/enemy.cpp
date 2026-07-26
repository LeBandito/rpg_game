#include "entities/enemy.h"

int enemy::ToGiveMoney() {
    return money;
}

// Сеттер
void enemy::SetWeapon(const weapon& new_enemy_weapon) { enemy_weapon = new_enemy_weapon; }

// Геттеры
weapon enemy::GetWeapon() const { return enemy_weapon; }