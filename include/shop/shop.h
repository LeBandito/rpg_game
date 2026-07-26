#pragma once

#include "items/items.h"
#include "items/weapons.h"
#include "items/clothes.h"
#include "items/potion.h"
#include "entities/player.h"
#include <array>

class shop {
protected:
    // В будующем добаваить отдельно одежду, оружие, зелья, амулеты.
    std::array<item, 20> shop_products;
    std::array<weapon, 20> shop_weapons;
    std::array<clothes, 20> shop_clothes;
    std::array<potion, 20> shop_potions;

public:
    // Просмотр товаров
    void ShowProducts();
    // Просмотр оружия
    void ShowWeapons();
    // Просмотр одежды
    void ShowClothes();
    // Просмотр зелий
    void ShowPotions();

    // Продажа товара
    /* Ух! Это было круто! Я и забыл, что protected позволяет использовать поля только своему классу и наследникам, 
    но shop-то не наследует! Поэтому создал get-тер в character.h! */
    void SellProduct(const int& idx_products, const int& idx_inventory, player& bruh);

    // Добавить возможность покупки товара!

    // Сеттеры
    void SetShopProducts(const std::array<item, 20>& new_shop_products);
    void SetShopWeapons(const std::array<weapon, 20>& new_shop_weapons);
    void SetShopClothes(const std::array<clothes, 20>& new_shop_clothes);
    void SetShopPotions(const std::array<potion, 20>& new_shop_potions);
    
    // Геттеры
    std::array<item, 20> GetShopProducts(const std::array<item, 20>& new_shop_products) const;
    std::array<weapon, 20> GetShopWeapons(const std::array<weapon, 20>& new_shop_weapons) const;
    std::array<clothes, 20> GetShopClothes(const std::array<clothes, 20>& new_shop_clothes) const;
    std::array<potion, 20> GetShopPotions(const std::array<potion, 20>& new_shop_potions) const;
};
