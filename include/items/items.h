#pragma once

#include <string>
#include <array>

class item {
public:
    std::string name;
    // std::array<std::string, 4> type{"weapon", "potion", "clothes", "empty"};
    std::string type;
    int price;
    int weight;
};