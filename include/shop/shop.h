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

    // Продажа товаров
    item SellProduct(const int& index, player& bruh);
    // Продажа оружия
    weapon SellWeapons(const int& index, player& bruh);
    // Продажа одежды
    clothes SellClothes(const int& index, player& bruh);
    // Продажа зелий
    potion SellPotions(const int& index, player& bruh);

    // Покупка товаров
    void BuyProduct(player& bruh);
    // Покупка оружия
    void BuyWeapons(player& bruh);
    // Покупка одежды
    void BuyClothes(player& bruh);
    // Покупка зелий
    void BuyPotions(player& bruh);

    // Меню продажи игрока
    int PlayerSellingMenu();
    int PlayerSellingInventory(player& bruh);

    int OptionMenu();
    void ShopMove(const int& choose);

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

    item GetTheShopProduct(const int& index) const;
    weapon GetTheShopWeapon(const int& index) const;
    clothes GetTheShopClothes(const int& index) const;
    potion GetTheShopPotion(const int& index) const;
};
