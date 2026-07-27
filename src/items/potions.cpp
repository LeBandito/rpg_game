#include "items/potions.h"

// Сеттеры
void potion::SetPermanentDamage(const int& new_permanent_damage) { permanent_damage = new_permanent_damage; }
void potion::SetTime(const int& new_time) { time = new_time; }

// Геттеры
int potion::GetPermanentDamage() { return permanent_damage; }
int potion::GetTime() { return time; }