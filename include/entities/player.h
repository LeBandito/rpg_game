#pragma once

#include "entities/character.h"
#include "items/weapons.h"

class player : public character {
protected:
    weapon player_weapon_first;
    weapon player_weapon_second;
    
public:
    // Конструктор по умолчанию
    player();
    // Конструктор с параметрами
    player(const int& new_id, const std::string& new_name, const bool& new_alive, const int& new_hp, const int& new_max_hp, const int& new_money, 
        const inventory& new_bag, const weapon& new_player_weapon_first, const weapon& new_player_weapon_second);

    // Получать деньги
    void ReceiveMoney(const int& cash);

    // Тратить деньги
    int GiveMoney(const int& minus_money);

    // Добавление элементов в инвентарь
    void AddItemToTheBag(const item& temporary, const int& index);
    void AddWeaponsToTheBag(const weapon& temporary, const int& index);
    void AddClothesToTheBag(const clothes& temporary, const int& index);
    void AddPotionsToTheBag(const potion& temporary, const int& index);

    // Смена оружия
    void ChangeWeapon();

    // Сеттеры
    void SetPlayerWeaponFirst(const weapon& new_player_weapon_first);
    void SetPlayerWeaponSecond(const weapon& new_player_weapon_first);

    // Геттеры
    weapon GetPlayerWeaponFirst() const;
    weapon GetPlayerWeaponSecond() const;
};