#pragma once

#include "items/items.h"
#include "items/weapons.h"
#include "items/clothes.h"
#include "items/potions.h"
#include "entities/player.h"
#include <vector>

class shop {
protected:
    // В будующем добаваить отдельно одежду, оружие, зелья, амулеты.
    std::vector<item> shop_products;
    std::vector<weapon> shop_weapons;
    std::vector<clothes> shop_clothes;
    std::vector<potion> shop_potions;

public:
    // Просмотр товаров
    int ShowProducts();
    // Просмотр оружия
    int ShowWeapons();
    // Просмотр одежды
    int ShowClothes();
    // Просмотр зелий
    int ShowPotions();

    // Покупка товаров
    void BuyProduct(const int& idx, player& bruh);
    // Покупка оружия
    void BuyWeapons(const int& idx, player& bruh);
    // Покупка одежды
    void BuyClothes(const int& idx, player& bruh);
    // Покупка зелий
    void BuyPotions(const int& idx, player& bruh);

    // Добавить возможность покупки товара!

    int OptionMenu();
    void ShopMove(const int& choose, player& bruh);

    // Сам магазин
    void GameShopping(player& bruh);

    // Сеттеры
    void SetShopProducts(const std::vector<item>& new_shop_products);
    void SetShopWeapons(const std::vector<weapon>& new_shop_weapons);
    void SetShopClothes(const std::vector<clothes>& new_shop_clothes);
    void SetShopPotions(const std::vector<potion>& new_shop_potions);
    
    // Геттеры
    std::vector<item> GetShopProducts() const;
    std::vector<weapon> GetShopWeapons() const;
    std::vector<clothes> GetShopClothes() const;
    std::vector<potion> GetShopPotions() const;

    item GetTheShopProduct(const int& idx) const;
    weapon GetTheShopWeapon(const int& idx) const;
    clothes GetTheShopClothes(const int& idx) const;
    potion GetTheShopPotion(const int& idx) const;
};
