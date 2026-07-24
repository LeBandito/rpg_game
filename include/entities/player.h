#pragma once

#include "entities/character.h"

class player : public character {
protected:
    std::pair<item, item> player_weapon;
    int weight_inventory;
    
public:
    // Получать деньги
    void SetMoney(const int& plus_money);

    // Тратить деньги
    void SpendMoney(const int& minus_money);

    // Добавление элементов в инвентарь
    void AddItemToInventory(const item& temporary, const int& position);

    // Смена оружия
    void ChangeWeapon();

    // Геттеры
    std::pair<item, item> GetWeapon();
};