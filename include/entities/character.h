#pragma once

#include "items/items.h"
#include <string>
#include <array>

class character {
protected:
    std::string name;
    int hp;
    int max_hp;
    int shield;
    int money;
    std::array<item, 5> inventory;
    int max_weight_inventory;
    bool alive;

public:
    // Минимальный конструктор
    character();

    // Полный конструктор
    character(const std::string& new_name, const int& new_hp, const int& new_max_hp, const int& new_shield, const int& new_money, 
        const std::array<item, 5>& new_inventory, const int& new_max_weight_inventory, const bool& new_alive);

    // Урон
    void damage(const int& bruh);

    // Лечение
    void heal(const int& bruh);

    // Проверка жизни
    bool IsAlive();

    // Просмотр статистики
    void ShowStatistic();

    // Просмотр инвентаря
    void ShowInventory();

    // Сеттеры
    void SetName(const std::string& new_name);
    void SetHp(const int& new_hp);
    void SetMaxHp(const int& new_max_hp);
    void SetShield(const int& new_shield);
    void SetMoney(const int& new_money);
    void SetInventory(const std::array<item, 5>& new_inventory);
    void SetMaxWeightInventory(const int& new_max_weight_inventory);
    void SetAlive(const bool& new_alive);

    // Геттеры
    std::string GetName();
    int GetHp();
    int GetMaxHp();
    int GetShield();
    // Тот самый геттер для shop.h!
    int GetMoney();
    std::array<item, 5> GetInventory();
    int GetMaxWeightInventory();
    bool GetAlive();

    ~character() {}
};