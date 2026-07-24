#pragma once

#include <string>

class item {
public:
    std::string name;
    // std::array<std::string, 4> type{"weapon", "potion", "clothes", "empty"};
    std::string type;
    std::string effect;
    int min_effect;
    int max_effect;
    int price;
    int weight;
};