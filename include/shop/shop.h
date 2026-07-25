#pragma once

#include <nlohmann/json.hpp>
#include "items/items.h"
#include "entities/player.h"
#include <array>

class shop {
protected:
    // В будующем добаваить отдельно одежду, оружие, зелья, амулеты.
    std::array<item, 20> products;

public:
    // Просмотр товаров
    void ShowProducts();

    // Продажа товара
    /* Ух! Это было круто! Я и забыл, что protected позволяет использовать поля только своему классу и наследникам, 
    но shop-то не наследует! Поэтому создал get-тер в character.h! */
    void SellProduct(const int& idx_products, const int& idx_inventory, player& bruh);

    // Добавить возможность покупки товара!
};
