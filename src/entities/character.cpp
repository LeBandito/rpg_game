#include "entities/character.h"

#include <iostream>

// Минимальный конструктор
character::character(): 
    id(0), name("none"), alive(true), hp(0), max_hp(0), money(0), bag() {}

// Полный конструктор
character::character(const int& new_id, const std::string& new_name, const bool& new_alive, const int& new_hp, 
    const int& new_max_hp, const int& new_money, const inventory& new_bag): 
    id(new_id), name(new_name), alive(new_alive), hp(new_hp), max_hp(new_max_hp), money(new_money), bag(new_bag) {}

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
    bag.ShowInventoryItems();
    bag.ShowInventoryWeapons();
    bag.ShowInventoryClothes();
    bag.ShowInventoryPotions();
}

// Продажа товаров
item character::SellPlayerProduct() {
    // Блин. -1, т.к показывали на 1 больше
    int index_inventory(0);
    bag.ShowInventoryItems();
    std::cout << "Number\t";
    std::cin >> index_inventory;
    
    // Отдаем товар
    return bag.GiveInventoryItems(index_inventory - 1);
}

// Продажа оружия
weapon character::SellPlayerWeapon() {
    // Блин. -1, т.к показывали на 1 больше
    int index_inventory(0);
    bag.ShowInventoryWeapons();
    std::cout << "Number\t";
    std::cin >> index_inventory;
    
    // Отдаем товар
    return bag.GiveInventoryWeapons(index_inventory - 1);
}

// Продажа одежды
clothes character::SellPlayerClothes() {
    // Блин. -1, т.к показывали на 1 больше
    int index_inventory(0);
    bag.ShowInventoryClothes();
    std::cout << "Number\t";
    std::cin >> index_inventory;
    
    // Отдаем товар
    return bag.GiveInventoryClothes(index_inventory - 1);
}

// Продажа зелий
potion character::SellPlayerPotion() {
    // Блин. -1, т.к показывали на 1 больше
    int index_inventory(0);
    bag.ShowInventoryPotions();
    std::cout << "Number\t";
    std::cin >> index_inventory;
    
    // Отдаем товар
    return bag.GiveInventoryPotions(index_inventory - 1);
}

// Сеттеры
void character::SetId(const int& new_id) { id = new_id; }
void character::SetName(const std::string& new_name) { name = new_name; }
void character::SetAlive(const bool& new_alive) { alive = new_alive; }
void character::SetHp(const int& new_hp) { hp = new_hp; }
void character::SetMaxHp(const int& new_max_hp) { max_hp = new_max_hp; }
void character::SetMoney(const int& new_money) { money = new_money; }
void character::SetBag(const inventory& new_bag) { bag = new_bag; }

// Геттеры
int character::GetId() { return id; }
std::string character::GetName() { return name; }
bool character::GetAlive() { return alive; }
int character::GetHp() { return hp; }
int character::GetMaxHp() { return max_hp; }
int character::GetMoney() { return money; }
inventory character::GetBag() { return bag; }