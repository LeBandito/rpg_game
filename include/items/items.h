#pragma once

#include <string>

class item {
protected:
    int id;
    std::string name;
    std::string description;
    int price;
    int weight;

public:
    // Минимальный конструктор
    item();
    // Максимальный конструктор
    item(const int& new_id, const std::string& new_name, const std::string& new_description, const int& new_price, const int& new_weight);

    // Нужны для переопределения
    virtual void ShowInfo() const;
    virtual std::string GetType() const;
    virtual int Use() const;

    // Сеттеры *теперь виртуальные!
    void SetId(const int& new_id);
    void SetName(const std::string& new_name);
    void SetDescription(const std::string& new_description);
    void SetPrice(const int& new_price);
    void SetWeight(const int& new_weight);

    // Геттеры
    int GetId() const;
    std::string GetName() const;
    std::string GetDescription() const;
    int GetPrice() const;
    int GetWeight() const;

    // Виртуальный деструктор для умного указателя
    virtual ~item() = default;
};