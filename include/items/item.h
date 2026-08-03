#pragma once

#include "items/item_template.h"

#include <memory>

class item {
private:
    int id;
    std::shared_ptr<item_template> item_type;

public:
    // Конструктор
    item(int new_id, std::shared_ptr<item_template> new_item_type);

    // Геттер
    int GetId() const;
    std::shared_ptr<item_template> GetTemplateItem() const;
};