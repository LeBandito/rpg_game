#pragma once

#include <string>

class item_template {
private:
    std::string name;
    std::string description;
    double weight;

public:
    // Конструктор
    item_template(const std::string& new_name, const std::string& new_description, double new_weight);

    // Геттеры
    const std::string& GetName() const;
    const std::string& GetDescription() const;
    double GetWeight() const;
};