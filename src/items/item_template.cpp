#include "items/item_template.h"
#include <stdexcept>

// Конструктор
item_template::item_template(const std::string& new_name, const std::string& new_description) : name(new_name), description(new_description) {}

// Геттеры
std::string item_template::GetName() const { return name; }
std::string item_template::GetDescription() const { return description; }