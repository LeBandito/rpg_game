#pragma once

#include <string>
#include <array>

struct item {
    std::string name;
    std::array<std::string, 2> type{"weapon", "potion"};
    int max_effect;
    int min_effect;
    int price;
};