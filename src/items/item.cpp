#include "items/item.h"
#include <stdexcept>

// Конструктор
item::item(int new_id) {
    if (new_id < 0)
        throw std::invalid_argument("Error: class item");

    id = new_id;
}

// Геттер
int item::GetId() const { return id; }