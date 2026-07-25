#pragma once

#include "items/items.h"
#include <string>
#include <array>
#include <iostream>

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
    // Быстрый конструктор
    character(std::string new_name, int new_hp, int new_max_hp, int new_shield, int new_money, std::array<item, 5> new_inventory, int new_max_weight_inventory, bool new_alive);

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

    // Тот самый геттер для shop.h!
    int GetMoney();
    int GetHp();

    ~character() {}
};