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

bool character::IsAlive() {
    if (hp <= 0)
        return false;
    return true;
}

void character::ShowStatistic() {
    std::cout << "Name:\t" << name << std::endl;
    std::cout << "Hp:\t" << hp << std::endl;
    std::cout << "Money:\t" << money << std::endl;
    std::cout << "Alive:\t" << alive << std::endl;
}

void character::ShowInventory() {
    std::cout << "Inventory:" << std::endl;
    for (int i = 0; i < inventory.size(); ++i)
        std::cout << i + 1 << ") " << inventory[i].name << ":\t" << inventory[i].type << 
        " | (" << inventory[i].min_effect << ", " << inventory[i].max_effect << ") | " << 
        inventory[i].price << " | " << inventory[i].weight << std::endl;
}

int character::GetMoney() {
    return money;
}

int character::GetHp() {
    return hp;
}