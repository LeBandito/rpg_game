#pragma once

#include "items/items.h"
#include "items/weapons.h"
#include "items/clothes.h"
#include "items/potions.h"
#include <vector>
#include <memory>

class shop {
protected:
    // В будующем добаваить отдельно одежду, оружие, зелья, амулеты.
    std::vector<std::unique_ptr<item>> shop_inventory;

public:
    // Просмотр товаров
    int ShowShopInventory(const std::string& type);

    // Продаем предмет
    std::unique_ptr<item> SellThing(const int& choose, const std::string& type);

    // Покупаем предмет
    std::unique_ptr<item> BuyThing(const int& index);

    // Добавить возможность покупки товара!

    int OptionMenu();
    template<typename T> T shop::ShopMove(const std::vector<T>& player_choose);

    // Сам магазин
    void GameShopping();

    // Сеттер
    void SetShopInventory(const std::vector<std::unique_ptr<item>>& new_shop_inventory);
    
    // Геттеры
    std::vector<std::unique_ptr<item>> GetShopInventory() const;
};
