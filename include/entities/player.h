#pragma once

#include "entities/character.h"

class player : public character {
protected:
    item player_weapons_first;
    item player_weapons_second;
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

    // Сеттеры
    void SetPlayerWeaponFirst(const item& new_player_weapons_first);
    void SetPlayerWeaponSecond(const item& new_player_weapons_second);
    void SetWeightInventory(const int& new_weight_inventory);

    // Геттеры
    item GetPlayerWeaponFirst();
    item GetPlayerWeaponSecond();
    int GetWeightInventory();
};