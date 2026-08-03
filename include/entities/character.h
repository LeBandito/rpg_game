#pragma once

class character {
private:
    int id;
    int hp;
    int max_hp;

public:
    // Конструктор с параметрами
    character(int new_id, int new_hp, int new_max_hp);

    void Heal(int plus);
    void Damage(int minus);
    bool IsAlive() const;

    // Геттеры
    int GetId() const;
    int GetHp() const;
    int GetMaxHp() const;
};