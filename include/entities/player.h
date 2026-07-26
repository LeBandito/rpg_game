#pragma once

#include "entities/character.h"
#include "items/weapons.h"

class player : public character {
protected:
    weapon player_weapon_first;
    weapon player_weapon_second;
    std::array<weapon, 2> player_weapons;
    int weight_inventory;
    
public:
    // Получать деньги
    void PlusMoney(const int& plus_money);

    // Тратить деньги
    void SpendMoney(const int& minus_money);

    // Добавление элементов в инвентарь
    void AddItemToInventory(const item& temporary, const int& position);

    // Смена оружия
    void ChangeWeapon();

    // Сеттеры
    void SetPlayerWeaponFirst(const weapon& new_player_weapon_first);
    void SetPlayerWeaponSecond(const weapon& new_player_weapon_first);
    void SetPlayerWeapons(const std::array<weapon, 2>& new_player_weapons);
    void SetWeightInventory(const int& new_weight_inventory);

    // Геттеры
    weapon GetPlayerWeaponFirst() const;
    weapon GetPlayerWeaponSecond() const;
    std::array<weapon, 2> GetPlayerWeapons() const;
    int GetWeightInventory() const;
};