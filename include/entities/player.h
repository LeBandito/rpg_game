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
    // Конструктор по умолчанию
    player();
    // Конструктор с параметрами
    player(const std::string& new_name, const int& new_hp, const int& new_max_hp, const int& new_money, const std::array<item, 5>& new_inventory, 
        const int& new_max_weight_inventory, const bool& new_alive, const weapon& new_player_weapon_first, const weapon& new_player_weapon_second, 
        const std::array<weapon, 2>& new_player_weapons, const int& new_weight_inventory);

    // Получать деньги
    void PlusMoney(const int& plus_money);

    // Тратить деньги
    void SpendMoney(const int& minus_money);

    // Добавление элементов в инвентарь
    void AddItemToInventory(const item& temporary, const int& position);

    // Смена оружия
    void ChangeWeapon();

    // Покупка товаров
    void BuyProduct(const int& idx);
    // Покупка оружия
    void BuyWeapons(const int& idx);
    // Покупка одежды
    void BuyClothes(const int& idx);
    // Покупка зелий
    void BuyPotions(const int& idx);

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