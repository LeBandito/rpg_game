#include "inventory/inventory.h"

#include <stdexcept>

// Конструктор
inventory::inventory(const std::vector<item>& new_all_inventory, int new_max_size, double new_weight, double new_max_weight) {
    if ((new_all_inventory.empty()) || (new_max_size < 0) || (new_all_inventory.size() > new_max_size) || 
        (new_weight < 0) || (new_max_weight < 0) || (new_weight > new_max_weight))
        throw std::invalid_argument("Error: class inventory");

    all_inventory = new_all_inventory;
    max_size = new_max_size;
    weight = new_weight;
    max_weight = new_max_weight;
}

// Добавление
void inventory::AddItem(item new_item) { 
    if (all_inventory.size() == max_size) {
        throw std::invalid_argument("Error: class inventory - AddItem. There is no spot in your bag!");
    } else if (weight > max_weight - new_item.GetTemplateItem()->GetWeight()) {
        throw std::invalid_argument("Error: class inventory - AddItem. Your bag is too weight!");
    } else {
        all_inventory.push_back({new_item.GetId(), std::move(new_item.GetTemplateItem())});
        weight += new_item.GetTemplateItem()->GetWeight();
    }
}    

// Удаление
void inventory::RemoveItem(int id) {
    bool check{false};
    char temporary;
    for (size_t i = 0; i < all_inventory.size(); ++i) {
        if (all_inventory[i].GetId() == id) {
            check = true;
            weight -= all_inventory[i].GetTemplateItem()->GetWeight();
            all_inventory[i].GetTemplateItem() = nullptr;
            all_inventory.erase(all_inventory.begin() + i);
        }
    }
    if (!check)
        throw std::invalid_argument("Error: class inventory - RemoveItem. The operation is not completely!");
}


// Проверка
bool inventory::Contains(int id) {
    for (const item& I : all_inventory) {
        if (I.GetId() == id)
            return true;
    }
    return false;
}

// Геттеры
double inventory::GetCurrentWeight() const { return weight; }
int inventory::GetCurrentSize() const { return all_inventory.size(); }

item inventory::ToGiveItemCopy(int id) const {
    for (const item& I : all_inventory) {
        if (I.GetId() == id)
            return I;
    }
    throw std::invalid_argument("Error: class inventory - ToGiveItemCopy. Not found!");
}

item inventory::ToGiveItemReal(int id) {
    for (const item& I : all_inventory) {
        if (I.GetId() == id) {
            return std::move(I);
        }
    }
    throw std::invalid_argument("Error: class inventory - ToGiveItemReal. Not found!");
}