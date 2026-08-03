#pragma once

#include "items/item.h"

#include <vector>

class inventory {
private:
    std::vector<item> all_inventory;
    int max_size;
    double weight;
    double max_weight;

public:
    // Конструктор
    inventory(const std::vector<item>& new_all_inventory, int new_max_size, double new_weight, double new_max_weight);

    // Добавление
    void AddItem(item new_item);

    // Удаление 
    void RemoveItem(int id);

    // Проверка
    bool Contains(int id);

    // Геттеры
    double GetCurrentWeight() const;
    int GetCurrentSize() const;
    item ToGiveItemCopy(int id) const;
    item ToGiveItemReal(int id);
};