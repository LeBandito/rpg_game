#include "entities/enemy.h"

int enemy::ToGiveMoney() {
    return money;
}

// Сеттер
void enemy::SetWeapon(const item& new_enemy_weapon) { enemy_weapon = new_enemy_weapon; }

// Геттеры
item enemy::GetWeapon() { return enemy_weapon; }