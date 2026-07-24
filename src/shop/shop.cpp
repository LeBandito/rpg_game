#include "shop/shop.h"

void shop::ShowProducts() {
    for (int i = 0; i < products.size(); ++i)
        std::cout << i + 1 << ") " << products[i].name << ":\t" << 
        products[i].type << " | (" << 
        products[i].min_effect << ", " << products[i].max_effect << ") | " << 
        products[i].price  << " | " << products[i].weight << std::endl;
}

void shop::SellProduct(const int& idx_products, const int& idx_inventory, player& bruh) {
    // Блин. -1, т.к показывали на 1 больше
    if (bruh.GetMoney() > products[idx_products - 1].price) {
        bruh.AddItemToInventory(products[idx_products - 1], idx_inventory - 1);
    } else {
        std::cout << "Not much money!" << std::endl;
    }
}