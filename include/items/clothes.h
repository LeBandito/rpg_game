#pragma once
#include "items/items.h"

class clothes : public item {
protected:
    int head;
    int body;
    int hands;
    int legs;
    int feet;

public:
    // Сеттеры
    void GetHead(const int& new_head);
    void SetBody(const int& new_body);
    void SetHands(const int& new_hands);
    void SetLegs(const int& new_legs);
    void SetFeet(const int& new_feet);

    // Геттеры
    int GetHead();
    int GetBody();
    int GetHands();
    int GetLegs();
    int GetFeet();
};