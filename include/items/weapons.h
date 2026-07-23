#pragma once

#include "items/items.h"
#include <array>
#include <string>

class weapon : public item {
    int min_damage;
    int max_damage;
    std::array<std::string, 4> effect{"fire", "toxin", "ice", "none"};
};