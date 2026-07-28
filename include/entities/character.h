#pragma once

#include "inventory/inventory.h"
#include "items/items.h"
#include <string>
#include <vector>

class character {
protected:
    int id; 
    std::string name;
    bool alive;
    int hp;
    int max_hp;
    int money;
    inventory bag;

public:
    // Минимальный конструктор
    character();

    // Полный конструктор
    character(const int& new_id, const std::string& new_name, const bool& new_alive, const int& new_hp, const int& new_max_hp, const int& new_money, 
        const inventory& new_bag);

    // Получение урона
    void damage(const int& bruh);

    // Лечение
    void heal(const int& bruh);

    // Проверка жизни
    bool IsAlive();

    // Просмотр статистики
    void ShowStatistic();

    // Просмотр инвентаря
    void ShowInventory();

    // Продажа товаров
    item SellPlayerProduct();
    // Продажа оружия
    weapon SellPlayerWeapon();
    // Продажа одежды
    clothes SellPlayerClothes();
    // Продажа зелий
    potion SellPlayerPotion();

    // Сеттеры
    void SetId(const int& new_id);
    void SetName(const std::string& new_name);
    void SetAlive(const bool& new_alive);
    void SetHp(const int& new_hp);
    void SetMaxHp(const int& new_max_hp);
    void SetMoney(const int& new_money);
    void SetBag(const inventory& new_bag);

    // Геттеры
    int GetId();
    std::string GetName();
    bool GetAlive();
    int GetHp();
    int GetMaxHp();
    int GetMoney();
    inventory GetBag();
};