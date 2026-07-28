#include "shop/shop.h"
#include <iostream>

// Просмотр товаров
int shop::ShowProducts() {
    int idx(0);
    std::cout << "The products:" << std::endl;
    for (int i = 0; i < shop_products.size(); ++i) {
        std::cout << i + 1 << ") " << shop_products[i].GetName() << std::endl;
        std::cout << shop_products[i].GetDescription() << std::endl;
        std::cout << shop_products[i].GetPrice() << "\t" << shop_products[i].GetWeight() << std::endl;
    }
    std::cin >> idx;
    return idx;
}

// Просмотр оружия
int shop::ShowWeapons() {
    int idx(0);
    std::cout << "The weapons:" << std::endl;
    for (int i = 0; i < shop_weapons.size(); ++i) {
        std::cout << i + 1 << ") " << shop_weapons[i].GetName() << std::endl;
        std::cout << shop_weapons[i].GetDescription() << std::endl;
        std::cout << shop_products[i].GetPrice() << "\t" << shop_products[i].GetWeight() << std::endl;
        std::cout << "(" << shop_weapons[i].GetMinDamage() << ", " << shop_weapons[i].GetMaxDamage() << ") |\t" << shop_weapons[i].GetEffect() << std::endl;
    }
    std::cin >> idx;
    return idx;
}

// Просмотр одежды
int shop::ShowClothes() {
    int idx(0);
    std::cout << "The clothes:" << std::endl;
    for (int i = 0; i < shop_clothes.size(); ++i) {
        std::cout << i + 1 << ") " << shop_clothes[i].GetName() << std::endl;
        std::cout << shop_clothes[i].GetDescription() << std::endl;
        std::cout << shop_products[i].GetPrice() << "\t" << shop_products[i].GetWeight() << std::endl;
        std::cout << "(" << shop_clothes[i].GetHead() << ", " << shop_clothes[i].GetBody() << ", " << shop_clothes[i].GetHands() << ", " << 
        shop_clothes[i].GetLegs() << ", " << shop_clothes[i].GetFeet() << ")" << std::endl;
    }
    std::cin >> idx;
    return idx;
}

// Просмотр зелий
int shop::ShowPotions() {
    int idx(0);
    std::cout << "The potions:" << std::endl;
    for (int i = 0; i < shop_potions.size(); ++i) {
        std::cout << i + 1 << ") " << shop_potions[i].GetName() << std::endl;
        std::cout << shop_potions[i].GetDescription() << std::endl;
        std::cout << shop_potions[i].GetPrice() << ", " << shop_potions[i].GetWeight() << std::endl;
        std::cout << shop_potions[i].GetPermanentDamage() << ", " << shop_potions[i].GetTime() << std::endl;
    }
    std::cin >> idx;
    return idx;
}

void shop::BuyProduct(const int& idx, player& bruh) {
    // Блин. -1, т.к показывали на 1 больше
    if ((bruh.GetMoney() > shop_products[idx - 1].GetPrice()) || (bruh.GetWeightInventory() + shop_products[idx - 1].GetWeight()) < bruh.GetMaxWeightInventory()) {
        int idx_inventory(0);

        bruh.ShowInventory();

        std::cout << "Which spot?" << std::endl;
        std::cin >> idx_inventory;
        bruh.AddItemToInventory(shop_products[idx - 1], idx_inventory - 1);
    } else {
        std::cout << "Not much money!" << std::endl;
    }
}

void shop::BuyWeapons(const int& idx, player& bruh) {
    // Блин. -1, т.к показывали на 1 больше
    if ((bruh.GetMoney() > shop_weapons[idx - 1].GetPrice()) || (bruh.GetWeightInventory() + shop_weapons[idx - 1].GetWeight()) < bruh.GetMaxWeightInventory()) {
        int idx_inventory(0);

        bruh.ShowInventory();

        std::cout << "Which spot?" << std::endl;
        std::cin >> idx_inventory;
        bruh.AddItemToInventory(shop_weapons[idx - 1], idx_inventory - 1);
    } else {
        std::cout << "Not much money!" << std::endl;
    }
}

void shop::BuyClothes(const int& idx, player& bruh) {
    // Блин. -1, т.к показывали на 1 больше
    if ((bruh.GetMoney() > shop_clothes[idx - 1].GetPrice()) || (bruh.GetWeightInventory() + shop_clothes[idx - 1].GetWeight()) < bruh.GetMaxWeightInventory()) {
        int idx_inventory(0);

        bruh.ShowInventory();

        std::cout << "Which spot?" << std::endl;
        std::cin >> idx_inventory;
        bruh.AddItemToInventory(shop_clothes[idx - 1], idx_inventory - 1);
    } else {
        std::cout << "Not much money!" << std::endl;
    }
}

void shop::BuyPotions(const int& idx, player& bruh) {
    // Блин. -1, т.к показывали на 1 больше
    if ((bruh.GetMoney() > shop_potions[idx - 1].GetPrice()) || (bruh.GetWeightInventory() + shop_potions[idx - 1].GetWeight()) < bruh.GetMaxWeightInventory()) {
        int idx_inventory(0);

        bruh.ShowInventory();

        std::cout << "Which spot?" << std::endl;
        std::cin >> idx_inventory;
        bruh.AddItemToInventory(shop_potions[idx - 1], idx_inventory - 1);
    } else {
        std::cout << "Not much money!" << std::endl;
    }
}

int shop::OptionMenu() {
    int idx;

    std::cout << "Welocome to the my store!" << std::endl;
    std::cout << "What do you want?" << std::endl;
    std::cout << "1) Products." << std::endl;
    std::cout << "2) Weapons." << std::endl;
    std::cout << "3) Clothes." << std::endl;
    std::cout << "4) Potions." << std::endl;

    std::cin >> idx;
    return idx;     
}

void shop::ShopMove(const int& choose, player& bruh) {
    switch (choose)
    {
    case 1:
        BuyProduct(ShowProducts(), bruh);
        break;

    case 2:
        BuyWeapons(ShowWeapons(), bruh);
        break;
    
    case 3:
        BuyClothes(ShowClothes(), bruh);
        break;

    case 4:
        BuyPotions(ShowPotions(), bruh);
        break;

    default:
        break;
    }
}

void shop::GameShopping(player& bruh) {
    ShopMove(OptionMenu(), bruh);
}

// Сеттеры
void shop::SetShopProducts(const std::vector<item>& new_shop_products) { shop_products = new_shop_products; }
void shop::SetShopWeapons(const std::vector<weapon>& new_shop_weapons) { shop_weapons = new_shop_weapons; }
void shop::SetShopClothes(const std::vector<clothes>& new_shop_clothes) { shop_clothes = new_shop_clothes; }
void shop::SetShopPotions(const std::vector<potion>& new_shop_potions) { shop_potions = new_shop_potions; }

// Геттеры
std::vector<item> shop::GetShopProducts() const { return shop_products; }
std::vector<weapon> shop::GetShopWeapons() const { return shop_weapons; }
std::vector<clothes> shop::GetShopClothes() const { return shop_clothes; }
std::vector<potion> shop::GetShopPotions() const { return shop_potions; }

item shop::GetTheShopProduct(const int& idx) const { return shop_products[idx]; }
weapon shop::GetTheShopWeapon(const int& idx) const { return shop_weapons[idx]; }
clothes shop::GetTheShopClothes(const int& idx) const { return shop_clothes[idx]; }
potion shop::GetTheShopPotion(const int& idx) const { return shop_potions[idx]; }