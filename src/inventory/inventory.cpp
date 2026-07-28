#include "inventory/inventory.h"
#include <iostream>

// Конструкторы
inventory::inventory() : size_items(), size_weapons(), size_clothes(), size_potions(), weight_inventory(), max_weight_inventory(), 
    max_size_items(), max_size_weapons(), max_size_clothes(), max_size_potions(), inventory_items(), inventory_weapons(), inventory_clothes(), inventory_potions() {}

inventory::inventory(const int& new_size_items, const int& new_size_weapons, const int& new_size_clothes, const int& new_size_potions, 
    const int& new_max_weight_inventory, const int& new_weight_inventory, 
    const int& new_max_size_items, const int& new_max_size_weapons, const int& new_max_size_clothes, const int& new_max_size_potions, 
    const std::vector<item>& new_inventory_items, const std::vector<weapon>& new_inventory_weapons, 
    const std::vector<clothes>& new_inventory_clothes, const std::vector<potion>& new_inventory_potions) :  
    size_items(new_size_items), size_weapons(new_size_weapons), size_clothes(new_size_clothes), size_potions(new_size_potions), 
    weight_inventory(new_max_weight_inventory), max_weight_inventory(new_weight_inventory), 
    max_size_items(new_max_size_items), max_size_weapons(new_max_size_weapons), max_size_clothes(new_max_size_clothes), max_size_potions(new_max_size_potions), 
    inventory_items(new_inventory_items), inventory_weapons(new_inventory_weapons), 
    inventory_clothes(new_inventory_clothes), inventory_potions(new_inventory_potions) {}

// Просмотр инвентаря (Шаблон)
template<typename T> T inventory::ShowInventory(const std::vector<T> container) {
    for (int i = 0; i < container.size(); ++i) {
        std::cout << i + 1 << ")" << std::endl;
        container[i].ShowInfo();
    }
}
void inventory::ShowInventoryItems() { ShowInventory(inventory_items); }
void inventory::ShowInventoryWeapons() { ShowInventory(inventory_weapons); }
void inventory::ShowInventoryClothes() { ShowInventory(inventory_clothes); }
void inventory::ShowInventoryPotions() { ShowInventory(inventory_potions); }

// Отдать товар (Шаблон)
template<typename T>
T inventory::GiveInventory(std::vector<T>& container, const int& index) {
    weight_inventory -= container[index].GetWeight();

    T temporary = container[index];
    container.erase(container.begin() + index);

    return temporary;
}
item inventory::GiveInventoryItems(const int& index) { return GiveInventory(inventory_items, index); }
weapon inventory::GiveInventoryWeapons(const int& index) { return GiveInventory(inventory_weapons, index); }
clothes inventory::GiveInventoryClothes(const int& index) { return GiveInventory(inventory_clothes, index); }
potion inventory::GiveInventoryPotions(const int& index) { return GiveInventory(inventory_potions, index); }

// Получить товар (Шаблон)
template<typename T> T inventory::ReceiveInventory(std::vector<T>& container, const int& index, const T& product) { 
    container[index] = product;
    weight_inventory += product.GetWeight();
}
void inventory::ReceiveInventoryItems(const int& index, const item& product) { ReceiveInventory(inventory_items, index, product); }
void inventory::ReceiveInventoryWeapons(const int& index, const weapon& product) { ReceiveInventory(inventory_weapons, index, product); }
void inventory::ReceiveInventoryClothes(const int& index, const clothes& product) { ReceiveInventory(inventory_clothes, index, product); }
void inventory::ReceiveInventoryPotions(const int& index, const potion& product) { ReceiveInventory(inventory_potions, index, product); }

// Сеттеры
// Размеры разделов
void inventory::SetSizeItems(const int& new_size_items) { size_items = new_size_items; }
void inventory::SetSizeWeapons(const int& new_size_weapons) { size_weapons = new_size_weapons; }
void inventory::SetSizeClothes(const int& new_size_clothes) { size_clothes = new_size_clothes; }
void inventory::SetSizePotions(const int& new_size_potions) { size_potions = new_size_potions; }

// Вес
void inventory::SetMaxWeightInventory(const int& new_max_weight_inventory) { max_weight_inventory = new_max_weight_inventory; }
void inventory::SetWeightInventory(const int& new_weight_inventory) { weight_inventory = new_weight_inventory; }

// Максимальный размер разделов
void inventory::SetMaxSizeItems(const int& new_max_size_items) { max_size_items = new_max_size_items; }
void inventory::SetMaxSizeWeapons(const int& new_max_size_weapons) { max_size_weapons = new_max_size_weapons; }
void inventory::SetMaxSizeClothes(const int& new_max_size_clothes) { max_size_clothes = new_max_size_clothes; }
void inventory::SetMaxSizePotions(const int& new_max_size_potions) { max_size_potions = new_max_size_potions; }

// Разделы
void inventory::SetInventoryItems(const std::vector<item>& new_inventory_items) { inventory_items = new_inventory_items; }
void inventory::SetInventoryWeapons(const std::vector<weapon>& new_inventory_weapons) { inventory_weapons = new_inventory_weapons; }
void inventory::SetInventoryClothes(const std::vector<clothes>& new_inventory_clothes) { inventory_clothes = new_inventory_clothes; }
void inventory::SetInventoryPotions(const std::vector<potion>& new_inventory_potions) { inventory_potions = new_inventory_potions; }

// Геттеры
// Размеры разделов
int inventory::GetSizeItems() { return size_items; }
int inventory::GetSizeWeapons() { return size_weapons; }
int inventory::GetSizeClothes() { return size_clothes; }
int inventory::GetSizePotions() { return size_potions; }

// Вес
int inventory::GetMaxWeightInventory() { return max_weight_inventory; }
int inventory::GetWeightInventory() { return weight_inventory; }

// Максимальный размер разделов
int inventory::GetMaxSizeItems() { return max_size_items; }
int inventory::GetMaxSizeWeapons() { return max_size_weapons; }
int inventory::GetMaxSizeClothes() { return max_size_clothes; }
int inventory::GetMaxSizePotions() { return max_size_potions; }

// Разделы
item inventory::GetInventoryItems(const int& index) { return inventory_items[index]; }
weapon inventory::GetInventoryWeapons(const int& index) { return inventory_weapons[index]; }
clothes inventory::GetInventoryClothes(const int& index) { return inventory_clothes[index]; }
potion inventory::GetInventoryPotions(const int& index) { return inventory_potions[index]; }