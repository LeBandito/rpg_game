#pragma once

#include <string>
#include <array>

struct item {
    std::string name;
    std::array<std::string, 4> type{"weapon", "potion", "clothes", "empty"};
    int max_effect;
    int min_effect;
    int price;
    int weight;
};