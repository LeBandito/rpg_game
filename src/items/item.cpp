#include "items/item.h"
#include <stdexcept>

// Конструктор
item::item(int new_id, std::shared_ptr<item_template> new_item_type) {
    if (new_id < 0)
        throw std::invalid_argument("Error: class item");

    id = new_id;
    item_type = std::move(new_item_type);
}

// Геттер
int item::GetId() const { return id; }

// Именно копию. Просто копию
std::shared_ptr<item_template> item::GetTemplateItem() const { return item_type; }