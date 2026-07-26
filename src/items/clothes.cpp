#include "items/clothes.h"

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