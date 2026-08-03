#pragma once

#include <string>

class item_template {
private:
    std::string name;
    std::string description;

public:
    // Конструктор
    item_template(const std::string& new_name, const std::string& new_description);

    // Геттеры
    std::string GetName() const;
    std::string GetDescription() const;
};