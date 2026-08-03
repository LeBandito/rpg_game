#include "entities/character.h"
#include <stdexcept>

// Конструктор с параметрами
character::character(int new_id, int new_hp, int new_max_hp) {
    if ((new_hp < 0) || (new_hp > new_max_hp) || (new_max_hp < 0))
        throw std::invalid_argument("Error: class character");

    id = new_id;
    hp = new_hp;
    max_hp = new_max_hp;
}

void character::Heal(int plus) {
    if (plus < 0)
        throw std::invalid_argument("Error: character heal < 0"); 
    
    if (plus > max_hp - hp) {
        hp = max_hp;
    } else {
        hp += plus;
    }
}

void character::Damage(int minus) {
    if (minus < 0)
        throw std::invalid_argument("Error: character damage > 0"); 
    
    if (minus >= hp) {
        hp = 0;
    } else {
        hp -= minus;
    }
}

bool character::IsAlive() const { return hp > 0; }

// Геттеры
int character::GetId() const { return id; }
int character::GetHp() const { return hp; }
int character::GetMaxHp() const { return max_hp; }