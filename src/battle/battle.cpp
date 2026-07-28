#include "battle/battle.h"

#include <iostream>
#include <ctime>

// Конструктор
battle::battle(player& new_bruh, enemy& new_eminem, const int& new_round, const bool& new_turn_side, const bool& new_stop) :
    bruh(new_bruh), eminem(new_eminem), round(round), turn_side(turn_side), stop(new_stop) {}

// Виды атак Игрока
int battle::FirstPlayerAttack() { return bruh.GetPlayerWeaponFirst().Use(); }
int battle::SecondPlayerAttack() { return bruh.GetPlayerWeaponSecond().Use(); }

// Виды атак врага
int battle::FirstEnemyAttack() { return eminem.GetWeapon().Use(); }

// Меню хода
void battle::OptionsMenuFight() {
    // Проработать варианты побега
    std::cout << "1) " << bruh.GetPlayerWeaponFirst().GetName() << " | (" << 
    bruh.GetPlayerWeaponFirst().GetMinDamage() << ", " << bruh.GetPlayerWeaponFirst().GetMaxDamage() << ");"<< std::endl;
    std::cout << "2) " << bruh.GetPlayerWeaponSecond().GetName() << " | (" << 
    bruh.GetPlayerWeaponSecond().GetMinDamage() << ", " << bruh.GetPlayerWeaponSecond().GetMaxDamage() << ");"<< std::endl;
    std::cout << "3) Escape! Chance - 10%" << std::endl;
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
    std::srand(std::time(NULL));
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
    
    case 3:
        if ((std::rand() % 100) > 10) {
            std::cout << "The escape was a success!" << std::endl;
            stop = true;
        } else {
            bruh.damage(FirstEnemyAttack() * 2); 
            turn_side = false;
        }
        break;
    
    default:
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
    while ((bruh.GetHp() > 0) || (eminem.GetHp() > 0) || stop) {
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
        bruh.ReceiveMoney(eminem.ToGiveMoney());

        int index;
        std::cout << "What sell?" << std::endl;
        std::cout << "1) Products." << std::endl;
        std::cout << "2) Weapons." << std::endl;
        std::cout << "3) Clothes." << std::endl;
        std::cout << "4) Potions." << std::endl;
        std::cout << "5) leave!" << std::endl;
        std::cin >> index;
        eminem.ShowInventory();
        // Проработать лут + взятие оружия!
    } else {
        std::cout << "You're lose!" << std::endl;
    }
}