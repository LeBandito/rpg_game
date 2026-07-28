#include "items/items.h"
#include <iostream>

// Минимальный конструктор
item::item(): id(0), name("none"), description("none"), price(0), weight(0) {}
// Максимальный конструктор
item::item(const int& new_id, const std::string& new_name, const std::string& new_description, const int& new_price, const int& new_weight) : 
    id(new_id), name(new_name), description(new_description),  price(new_price), weight(new_weight) {}

std::string item::GetType() const { return "item"; }

void item::ShowInfo() const {
    std::cout << "id:\t" << id << std::endl;
    std::cout << "name:\t" << name << std::endl;
    std::cout << "description:\t" << description << std::endl;
    std::cout << "price:\t" << price << std::endl;
    std::cout << "weight:\t" << weight << std::endl;
}

// Сеттры
void item::SetId(const int& new_id) { id = new_id; }
void item::SetName(const std::string& new_name) { name = new_name; }
void item::SetDescription(const std::string& new_description) { description = new_description; }
void item::SetPrice(const int& new_price) { price = new_price; }
void item::SetWeight(const int& new_weight) { weight = new_weight; }

// Геттеры
int item::GetId() const { return id; }
std::string item::GetName() const { return name; }
std::string item::GetDescription() const { return description; }
int item::GetPrice() const { return price; }
int item::GetWeight() const { return weight; }
