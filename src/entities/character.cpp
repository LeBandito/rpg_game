#include "entities/character.h"

character::character(std::string new_name, int new_hp, int new_max_hp, int new_shield, bool new_alive, std::array<item, 5> new_inventory): 
        name(new_name), hp(new_hp), max_hp(new_max_hp), shield(new_shield), alive(new_alive), inventory(new_inventory) {}

void character::damage(const int& bruh) {
    if (hp - bruh <= 0) {
        alive = false;
    } else {
        hp -= bruh;
    }
}

void character::heal(const int& bruh) {
    if (hp + bruh > max_hp) {
        hp = max_hp;
    } else {
        hp += bruh;
    }
}

void character::AddItemToInventory(const item& temporary, const int& position) {
    if (weight_inventory + temporary.weight > max_weight_inventory) {
        // Проработать ошибку: слишком большой вес
    } else if (inventory[position].name == "empty") {
        inventory[position] = temporary;
        weight_inventory += temporary.weight;
    } else {
        // Проработать ошибку: нет свободной позиции
    }
}

bool character::IsAlive() {
    if (hp <= 0)
        return false;
    return true;
}

void character::ShowStatistic() {
    std::cout << "Name:\t" << name << std::endl;
    std::cout << "Hp:\t" << hp << std::endl;
    std::cout << "Inventory:" << std::endl;
    for (const item& I : inventory)
        std::cout << I.name << ":\t" << I.type[0] << " | (" << I.min_effect << ", " << I.max_effect << ") | " << I.price << std::endl;
}