#pragma once

#include "items/item_template.h"

class item {
private:
    int id;
    item_template template_item;

public:
    // Конструктор
    item(int new_id);

    // Геттер
    int GetId() const;
};