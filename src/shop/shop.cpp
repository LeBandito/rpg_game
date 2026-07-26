#include "shop/shop.h"
#include <iostream>

// Просмотр товаров
void shop::ShowProducts() {
    std::cout << "The products:" << std::endl;
    for (int i = 0; i < shop_products.size(); ++i) {
        std::cout << i + 1 << ") " << shop_products[i].GetName() << std::endl;
        std::cout << shop_products[i].GetDescription() << std::endl;
        std::cout << shop_products[i].GetPrice() << "\t" << shop_products[i].GetWeight() << std::endl;
    }
}

// Просмотр оружия
void shop::ShowWeapons() {
    std::cout << "The weapons:" << std::endl;
    for (int i = 0; i < shop_weapons.size(); ++i) {
        std::cout << i + 1 << ") " << shop_weapons[i].GetName() << std::endl;
        std::cout << shop_weapons[i].GetDescription() << std::endl;
        std::cout << shop_products[i].GetPrice() << "\t" << shop_products[i].GetWeight() << std::endl;
        std::cout << "(" << shop_weapons[i].GetMinDamage() << ", " << shop_weapons[i].GetMaxDamage() << ") |\t" << shop_weapons[i].GetEffect() << std::endl;
    }
}

// Просмотр одежды
void shop::ShowClothes() {
    std::cout << "The clothes:" << std::endl;
    for (int i = 0; i < shop_clothes.size(); ++i) {
        std::cout << i + 1 << ") " << shop_clothes[i].GetName() << std::endl;
        std::cout << shop_clothes[i].GetDescription() << std::endl;
        std::cout << shop_products[i].GetPrice() << "\t" << shop_products[i].GetWeight() << std::endl;
        std::cout << "(" << shop_clothes[i].GetHead() << ", " << shop_clothes[i].GetBody() << ", " << shop_clothes[i].GetHands() << ", " << 
        shop_clothes[i].GetLegs() << ", " << shop_clothes[i].GetFeet() << ")" << std::endl;
    }
}

// Просмотр зелий
void shop::ShowPotions() {
    std::cout << "The potions:" << std::endl;
    for (int i = 0; i < shop_potions.size(); ++i) {
        std::cout << i + 1 << ") " << shop_potions[i].GetName() << std::endl;
        std::cout << shop_potions[i].GetDescription() << std::endl;
        std::cout << shop_potions[i].GetPrice() << ", " << shop_potions[i].GetWeight() << std::endl;
        std::cout << shop_potions[i].GetPermanentDamage() << ", " << shop_potions[i].GetTime() << std::endl;
    }
}

void shop::SellProduct(const int& idx_products, const int& idx_inventory, player& bruh) {
    // Блин. -1, т.к показывали на 1 больше
    if (bruh.GetMoney() > products[idx_products - 1].price) {
        bruh.AddItemToInventory(products[idx_products - 1], idx_inventory - 1);
    } else {
        std::cout << "Not much money!" << std::endl;
    }
}

// Сеттеры
void shop::SetShopProducts(const std::array<item, 20>& new_shop_products) { shop_products = new_shop_products; }
void shop::SetShopWeapons(const std::array<weapon, 20>& new_shop_weapons) { shop_weapons = new_shop_weapons; }
void shop::SetShopClothes(const std::array<clothes, 20>& new_shop_clothes) { shop_clothes = new_shop_clothes; }
void shop::SetShopPotions(const std::array<potion, 20>& new_shop_potions) { shop_potions = new_shop_potions; }

// Геттеры
std::array<item, 20> shop::GetShopProducts(const std::array<item, 20>& new_shop_products) const { return shop_products; }
std::array<weapon, 20> shop::GetShopWeapons(const std::array<weapon, 20>& new_shop_weapons) const { return shop_weapons; }
std::array<clothes, 20> shop::GetShopClothes(const std::array<clothes, 20>& new_shop_clothes) const { return shop_clothes; }
std::array<potion, 20> shop::GetShopPotions(const std::array<potion, 20>& new_shop_potions) const { return shop_potions; }