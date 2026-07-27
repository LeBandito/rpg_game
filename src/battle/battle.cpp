#include "battle/battle.h"

#include <iostream>
#include <ctime>

// Конструктор
battle::battle(player& new_bruh, enemy& new_eminem, const int& round, const bool& turn_side) :
    bruh(new_bruh), eminem(new_eminem), round(round), turn_side(turn_side) {}

// Виды атак Игрока
int battle::FirstPlayerAttack() {
    std::srand(time(NULL));
    // Случайное значение из диапазона 
    return bruh.GetPlayerWeaponFirst().GetMinDamage() + std::rand() % (bruh.GetPlayerWeaponFirst().GetMaxDamage() - bruh.GetPlayerWeaponFirst().GetMinDamage() + 1);
}

int battle::SecondPlayerAttack() {
    std::srand(time(NULL));
    // Случайное значение из диапазона 
    return bruh.GetPlayerWeaponSecond().GetMinDamage() + std::rand() % (bruh.GetPlayerWeaponSecond().GetMaxDamage() - bruh.GetPlayerWeaponSecond().GetMinDamage() + 1);
}

// Виды атак врага
int battle::FirstEnemyAttack() {
    std::srand(time(NULL));
    // Случайное значение из диапазона 
    return eminem.GetWeapon().GetMinDamage() + std::rand() % (eminem.GetWeapon().GetMaxDamage() - eminem.GetWeapon().GetMinDamage() + 1);
}

// Меню хода
void battle::OptionsMenuFight() {
    // Проработать варианты побега
    std::cout << "1) " << bruh.GetPlayerWeaponFirst().GetName() << " | (" << 
    bruh.GetPlayerWeaponFirst().GetMinDamage() << ", " << bruh.GetPlayerWeaponFirst().GetMaxDamage() << ");"<< std::endl;
    std::cout << "2) " << bruh.GetPlayerWeaponSecond().GetName() << " | (" << 
    bruh.GetPlayerWeaponSecond().GetMinDamage() << ", " << bruh.GetPlayerWeaponSecond().GetMaxDamage() << ");"<< std::endl;
}

// Варианты ходов
int battle::GetPlayerChoice() {
    std::cout << "Welcome to the option mune fight!" << std::endl;
    std::cout << "You won't be able to get help here..." << std::endl;
    int idx(0);

    OptionsMenuFight();
    std::cin >> idx;    
}

// Ход игрока
void battle::PlayerMove(const int& choice) {
    switch (choice)
    {
    case 1:
        eminem.damage(FirstPlayerAttack()); 
        turn_side = false;
        break;
    
    case 2:
        eminem.damage(SecondPlayerAttack()); 
        turn_side = false;
        break;
    
    default:
        turn_side = false;
        break;
    }
}

void battle::EnemyMove() {
    bruh.damage(FirstEnemyAttack());
    turn_side = true;
}

// Статистика боя
void battle::ShowBattleStatistic() {
    std::cout << "You:" << std::endl;
    bruh.ShowStatistic();

    std::cout << "Enemy:" << std::endl;
    bruh.ShowStatistic();
}

void battle::Fight() {
    std::cout << "Start FIGHT!!!" << std::endl;
    ShowBattleStatistic();
    while ((bruh.GetHp() > 0) || (eminem.GetHp() > 0)) {
        std::cout << "ROUND " << round << " FIGHT!!!" << std::endl;
        if (turn_side) {
            PlayerMove(GetPlayerChoice());
        } else {
            EnemyMove();
        }
        ++round;
    }

    if (bruh.GetHp() > 0) {
        std::cout << "You WIN!" << std::endl;
        std::cout << "You're reward:\t" << eminem.ToGiveMoney() << std::endl;
        bruh.PlusMoney(eminem.ToGiveMoney());

        eminem.ShowInventory();
        // Проработать лут + взятие оружия!
    } else {
        std::cout << "You're lose!" << std::endl;
    }
}