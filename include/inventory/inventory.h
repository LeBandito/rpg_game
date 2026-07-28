#pragma once

#include "items/items.h"
#include "items/weapons.h"
#include "items/clothes.h"
#include "items/potions.h"
#include <vector>

class inventory {
protected:
    // Размеры разделов
    int size_items;
    int size_weapons;
    int size_clothes;
    int size_potions;

    // Вес
    int weight_inventory;
    int max_weight_inventory;

    // Максимальный размер разделов
    int max_size_items;
    int max_size_weapons;
    int max_size_clothes;
    int max_size_potions;

    // Разделы
    std::vector<item> inventory_items;
    std::vector<weapon> inventory_weapons;
    std::vector<clothes> inventory_clothes;
    std::vector<potion> inventory_potions;

public:
    // Конструкторы
    inventory();
    inventory(const int& new_size_items, const int& new_size_weapons, const int& new_size_clothes, const int& new_size_potions, 
        const int& new_max_weight_inventory, const int& new_weight_inventory, 
        const int& new_max_size_items, const int& new_max_size_weapons, const int& new_max_size_clothes, const int& new_max_size_potions, 
        const std::vector<item>& new_inventory_items, const std::vector<weapon>& new_inventory_weapons, 
        const std::vector<clothes>& new_inventory_clothes, const std::vector<potion>& new_inventory_potions);

    // Просмотр инвентаря (Шаблон)
    template<typename T> T ShowInventory(const std::vector<T> container);
    void ShowInventoryItems();
    void ShowInventoryWeapons();
    void ShowInventoryClothes();
    void ShowInventoryPotions();

    // Отдать товар (Шаблон)
    template<typename T> T GiveInventory(std::vector<T>& container, const int& index);
    item GiveInventoryItems(const int& index);
    weapon GiveInventoryWeapons(const int& index);
    clothes GiveInventoryClothes(const int& index);
    potion GiveInventoryPotions(const int& index);

    // Получить товар (Шаблон)
    template<typename T> T ReceiveInventory(std::vector<T>& container, const int& index, const T& product);
    void ReceiveInventoryItems(const int& index, const item& product);
    void ReceiveInventoryWeapons(const int& index, const weapon& product);
    void ReceiveInventoryClothes(const int& index, const clothes& product);
    void ReceiveInventoryPotions(const int& index, const potion& product);

    // Сеттеры
    // Размеры разделов
    void SetSizeItems(const int& new_size_items);
    void SetSizeWeapons(const int& new_size_weapons);
    void SetSizeClothes(const int& new_size_clothes);
    void SetSizePotions(const int& new_size_potions);

    // Вес
    void SetMaxWeightInventory(const int& new_max_weight_inventory);
    void SetWeightInventory(const int& new_weight_inventory);

    // Максимальный размер разделов
    void SetMaxSizeItems(const int& new_max_size_items);
    void SetMaxSizeWeapons(const int& new_max_size_weapons);
    void SetMaxSizeClothes(const int& new_max_size_clothes);
    void SetMaxSizePotions(const int& new_max_size_potions);

    // Разделы
    void SetInventoryItems(const std::vector<item>& new_inventory_items);
    void SetInventoryWeapons(const std::vector<weapon>& new_inventory_weapons);
    void SetInventoryClothes(const std::vector<clothes>& new_inventory_clothes);
    void SetInventoryPotions(const std::vector<potion>& new_inventory_potions);

    // Геттеры
    // Размеры разделов
    int GetSizeItems();
    int GetSizeWeapons();
    int GetSizeClothes();
    int GetSizePotions();

    // Вес
    int GetMaxWeightInventory();
    int GetWeightInventory();

    // Максимальный размер разделов
    int GetMaxSizeItems();
    int GetMaxSizeWeapons();
    int GetMaxSizeClothes();
    int GetMaxSizePotions();

    // Разделы
    item GetInventoryItems(const int& index);
    weapon GetInventoryWeapons(const int& index);
    clothes GetInventoryClothes(const int& index);
    potion GetInventoryPotions(const int& index);
};