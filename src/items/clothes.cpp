#include "items/clothes.h"

#include <iostream>

void clothes::ShowInfo() const {
    std::cout << "id:\t" << id << std::endl;
    std::cout << "name:\t" << name << std::endl;
    std::cout << "description:\t" << description << std::endl;
    std::cout << "price:\t" << price << std::endl;
    std::cout << "weight:\t" << weight << std::endl;
    std::cout << "head:\t" << head << std::endl;
    std::cout << "body:\t" << body << std::endl;
    std::cout << "hands:\t" << hands << std::endl;
    std::cout << "legs:\t" << legs << std::endl;
    std::cout << "feet:\t" << feet << std::endl;
}

std::string clothes::GetType() const { return "clothes"; }

int clothes::Use() const { 
    if (head != 0) {
        return head;
    } else if (body != 0) {
        return body;
    } else if (hands != 0) {
        return hands;
    } else if (legs != 0) {
        return legs;
    } else if (feet != 0) {
        return feet;
    } else {
        return 0; 
    }
}

// Сеттеры
void clothes::GetHead(const int& new_head) { head = new_head; }
void clothes::SetBody(const int& new_body) { body = new_body; }
void clothes::SetHands(const int& new_hands) { hands = new_hands; }
void clothes::SetLegs(const int& new_legs) { legs = new_legs; }
void clothes::SetFeet(const int& new_feet) { feet = new_feet; }

// Геттеры
int clothes::GetHead() { return head; }
int clothes::GetBody() { return body; }
int clothes::GetHands() { return hands; }
int clothes::GetLegs() { return legs; }
int clothes::GetFeet() { return feet; }