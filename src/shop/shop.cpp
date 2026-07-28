#include "shop/shop.h"
#include <iostream>

// Просмотр товаров
int shop::ShowShopInventory(const std::string& type) {
    int choose(1);
    for (size_t i = 0; i < shop_inventory.size(); ++i) {
        if (shop_inventory[i]->GetType() == type) {
            std::cout << choose << ") " << std::endl;
            shop_inventory[i]->ShowInfo();
            ++choose;
        }
    }
    std::cin >> choose;
    return choose;
}

std::unique_ptr<item> shop::SellThing(const int& choose, const std::string& type) {
    int choose(0);
    for (size_t i = 0; i < shop_inventory.size(); ++i) {
        if (shop_inventory[i]->GetType() == type) {
            std::cout << i + 1 << ") " << std::endl;
            shop_inventory[i]->ShowInfo();
        }
    }

    std::unique_ptr<item> thing = std::move(shop_inventory[choose]);

    shop_inventory.erase(shop_inventory.begin() + choose);

    return thing;
}

int shop::OptionMenu() {
    int choose;

    std::cout << "Welocome to the my store!" << std::endl;
    std::cout << "What do you want?" << std::endl;
    std::cout << "1) Products." << std::endl;
    std::cout << "2) Weapons." << std::endl;
    std::cout << "3) Clothes." << std::endl;
    std::cout << "4) Potions." << std::endl;

    std::cin >> choose;
    return choose;     
}

template<typename T> T shop::ShopMove(const std::vector<T>& player_choose) {
    switch (OptionMenu())
    {
    case 1:
        return SellProduct(ShowProducts());
        break;

    case 2:
        return SellWeapons(ShowWeapons());
        break;
    
    case 3:
        return SellClothes(ShowClothes());
        break;

    case 4:
        return SellPotions(ShowPotions());
        break;

    default:
        break;
    }
}

void shop::GameShopping() {
    switch (OptionMenu())
    {
    case 1:
        ShopMove(ShowProducts());
        break;

    case 2:
        SellWeapons(ShowWeapons());
        break;
    
// item shop::GetTheShopProduct(const int& idx) const { return shop_products[idx]; }
// weapon shop::GetTheShopWeapon(const int& idx) const { return shop_weapons[idx]; }
// clothes shop::GetTheShopClothes(const int& idx) const { return shop_clothes[idx]; }
// potion shop::GetTheShopPotion(const int& idx) const { return shop_potions[idx]; }
    case 3:
        SellClothes(ShowClothes());
        break;

    case 4:
        SellPotions(ShowPotions());
        break;

    default:
        break;
    }
}

// Сеттер
void shop::SetShopInventory(const std::vector<std::unique_ptr<item>>& new_shop_inventory) { shop_inventory = std::move(new_shop_inventory); }

// Геттер (Так только для C++ 20. До этого, как я понял, надо писать get())
std::vector<std::unique_ptr<item>> shop::GetShopInventory() const { return shop_inventory; }