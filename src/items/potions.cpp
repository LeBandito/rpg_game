#include "items/potions.h"

#include <iostream>

void potion::ShowInfo() const {
    std::cout << "id:\t" << id << std::endl;
    std::cout << "name:\t" << name << std::endl;
    std::cout << "description:\t" << description << std::endl;
    std::cout << "price:\t" << price << std::endl;
    std::cout << "weight:\t" << weight << std::endl;
    std::cout << "permanent_damage:\t" << permanent_damage << std::endl;
    std::cout << "time:\t" << time << std::endl;
}
std::string potion::GetType() const { return "potion"; }
int potion::Use() const { return permanent_damage; }

// Сеттеры
void potion::SetPermanentDamage(const int& new_permanent_damage) { permanent_damage = new_permanent_damage; }
void potion::SetTime(const int& new_time) { time = new_time; }

// Геттеры
int potion::GetPermanentDamage() { return permanent_damage; }
int potion::GetTime() { return time; }