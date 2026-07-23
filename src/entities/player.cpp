#include "entities/player.h"

void player::GetMoney(const int& plus_money) {
    money += plus_money;
}

void player::SpendMoney(const int& minus_money) {
    money -= money;
}