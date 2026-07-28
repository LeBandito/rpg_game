#include "shop/shop.h"
#include <iostream>

// Просмотр товаров
int shop::ShowProducts() {
    int index(0);
    std::cout << "The products:" << std::endl;
    for (int i = 0; i < shop_products.size(); ++i) {
        std::cout << i + 1 << std::endl;
        shop_products[i].ShowInfo();
    }
    std::cin >> index;
    return index - 1;
}

// Просмотр оружия
int shop::ShowWeapons() {
    int index(0);
    std::cout << "The weapons:" << std::endl;
    for (int i = 0; i < shop_weapons.size(); ++i) {
        std::cout << i + 1 << std::endl;
        shop_weapons[i].ShowInfo();
    }
    std::cin >> index;
    return index;
}

// Просмотр одежды
int shop::ShowClothes() {
    int index(0);
    std::cout << "The clothes:" << std::endl;
    for (int i = 0; i < shop_clothes.size(); ++i) {
        std::cout << i + 1 << std::endl;
        shop_clothes[i].ShowInfo();
    }
    std::cin >> index;
    return index;
}

// Просмотр зелий
int shop::ShowPotions() {
    int index(0);
    std::cout << "The potions:" << std::endl;
    for (int i = 0; i < shop_potions.size(); ++i) {
        std::cout << i + 1 << std::endl;
        shop_potions[i].ShowInfo();
    }
    std::cin >> index;
    return index;
}

item shop::SellProduct(const int& index, player& bruh) {
    // Блин. -1, т.к показывали на 1 больше
    if ((bruh.GetMoney() > shop_products[index - 1].GetPrice()) && (bruh.GetBag().GetWeightInventory() + shop_products[index - 1].GetWeight()) <= bruh.GetBag().GetWeightInventory()) {
        int index_inventory(0);
        bruh.GetBag().ShowInventoryItems();
        std::cout << "Number\t";
        std::cin >> index_inventory;

        // Добавлен
        bruh.AddItemToTheBag(shop_products[index - 1], index_inventory - 1);

        // Деньги потратил
        bruh.GiveMoney(shop_products[index - 1].GetPrice());
    } else {
        std::cout << "Not much money or too mauch weight!" << std::endl;
    }
}

weapon shop::SellWeapons(const int& index, player& bruh) {
    // Блин. -1, т.к показывали на 1 больше
    if ((bruh.GetMoney() > shop_weapons[index - 1].GetPrice()) && (bruh.GetBag().GetWeightInventory() + shop_weapons[index - 1].GetWeight()) <= bruh.GetBag().GetWeightInventory()) {
        int index_inventory(0);
        bruh.GetBag().ShowInventoryWeapons();
        std::cout << "Number\t";
        std::cin >> index_inventory;

        // Добавлен
        bruh.AddWeaponsToTheBag(shop_weapons[index - 1], index_inventory - 1);

        // Деньги потратил
        bruh.GiveMoney(shop_weapons[index - 1].GetPrice());
    } else {
        std::cout << "Not much money or too mauch weight!" << std::endl;
    }
}

clothes shop::SellClothes(const int& index, player& bruh) {
    // Блин. -1, т.к показывали на 1 больше
    if ((bruh.GetMoney() > shop_clothes[index - 1].GetPrice()) && (bruh.GetBag().GetWeightInventory() + shop_clothes[index - 1].GetWeight()) <= bruh.GetBag().GetWeightInventory()) {
        int index_inventory(0);
        bruh.GetBag().ShowInventoryClothes();
        std::cout << "Number\t";
        std::cin >> index_inventory;

        // Добавлен
        bruh.AddClothesToTheBag(shop_clothes[index - 1], index_inventory - 1);

        // Деньги потратил
        bruh.GiveMoney(shop_clothes[index - 1].GetPrice());
    } else {
        std::cout << "Not much money or too mauch weight!" << std::endl;
    }
}

potion shop::SellPotions(const int& index, player& bruh) {
    // Блин. -1, т.к показывали на 1 больше
    if ((bruh.GetMoney() > shop_potions[index - 1].GetPrice()) && (bruh.GetBag().GetWeightInventory() + shop_potions[index - 1].GetWeight()) <= bruh.GetBag().GetWeightInventory()) {
        int index_inventory(0);
        bruh.GetBag().ShowInventoryPotions();
        std::cout << "Number\t";
        std::cin >> index_inventory;

        // Добавлен
        bruh.AddPotionsToTheBag(shop_potions[index - 1], index_inventory - 1);

        // Деньги потратил
        bruh.GiveMoney(shop_potions[index - 1].GetPrice());
    } else {
        std::cout << "Not much money or too mauch weight!" << std::endl;
    }
}

// Покупка товаров
void shop::BuyProduct(player& bruh) {
    // Ахахахахх РЫНОЧЕК ПОРЕШАЛ АХАХАХАХХ
    bruh.ReceiveMoney((bruh.SellPlayerProduct().GetPrice() * 7) / 10);
    shop_products.push_back(bruh.SellPlayerProduct());
}

// Покупка оружия
void shop::BuyWeapons(player& bruh) {
    // Ахахахахх РЫНОЧЕК ПОРЕШАЛ АХАХАХАХХ
    bruh.ReceiveMoney((bruh.SellPlayerWeapon().GetPrice() * 7) / 10);
    shop_products.push_back(bruh.SellPlayerWeapon());
}

// Покупка одежды
void shop::BuyClothes(player& bruh) {
    // Ахахахахх РЫНОЧЕК ПОРЕШАЛ АХАХАХАХХ
    bruh.ReceiveMoney((bruh.SellPlayerClothes().GetPrice() * 7) / 10);
    shop_products.push_back(bruh.SellPlayerClothes());
}

// Покупка зелий
void shop::BuyPotions(player& bruh) {
    // Ахахахахх РЫНОЧЕК ПОРЕШАЛ АХАХАХАХХ
    bruh.ReceiveMoney((bruh.SellPlayerPotion().GetPrice() * 7) / 10);
    shop_products.push_back(bruh.SellPlayerPotion());
}

// Меню продажи игрока
int shop::PlayerSellingMenu() {
    int index;

    std::cout << "What sell?" << std::endl;
    std::cout << "1) Products." << std::endl;
    std::cout << "2) Weapons." << std::endl;
    std::cout << "3) Clothes." << std::endl;
    std::cout << "4) Potions." << std::endl;
    std::cout << "5) leave!" << std::endl;

    std::cin >> index;
    return index;   
}

int shop::PlayerSellingInventory(player& bruh) {
    int choose(0);
    while (choose != 5) {
        choose = PlayerSellingMenu();
        switch (choose)
        {
        case 1:
            BuyProduct(bruh);
            break;

        case 2:
            BuyWeapons(bruh);
            break;
        
        case 3:
            BuyClothes(bruh);
            break;

        case 4:
            BuyPotions(bruh);
            break;

        case 5:
            std::cout << "Back!" << std::endl;
            break;

        default:
            break;
        }
    }
}

int shop::OptionMenu() {
    int index;

    std::cout << "Welocome to the my store!" << std::endl;
    std::cout << "What do you want?" << std::endl;
    std::cout << "1) Products." << std::endl;
    std::cout << "2) Weapons." << std::endl;
    std::cout << "3) Clothes." << std::endl;
    std::cout << "4) Potions." << std::endl;
    std::cout << "5) Sell." << std::endl;
    std::cout << "6) leave." << std::endl;

    std::cin >> index;
    return index;     
}

void shop::GameShopping(player& bruh) {
    int choose(0);
    while (choose != 5) {
        choose = OptionMenu();
        switch (choose)
        {
        case 1:
            SellProduct(ShowProducts(), bruh);
            break;

        case 2:
            SellWeapons(ShowWeapons(), bruh);
            break;
        
        case 3:
            SellClothes(ShowClothes(), bruh);
            break;

        case 4:
            SellPotions(ShowPotions(), bruh);
            break;

        case 5:
            PlayerSellingInventory(bruh);
            break;

        case 6:
            std::cout << "Bye!" << std::endl;
            break;

        default:
            break;
        }
    }
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

item shop::GetTheShopProduct(const int& index) const { return shop_products[index]; }
weapon shop::GetTheShopWeapon(const int& index) const { return shop_weapons[index]; }
clothes shop::GetTheShopClothes(const int& index) const { return shop_clothes[index]; }
potion shop::GetTheShopPotion(const int& index) const { return shop_potions[index]; }