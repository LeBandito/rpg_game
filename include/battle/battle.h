#pragma once

#include "entities/enemy.h"
#include "entities/player.h"
#include <ctime>

class battle {
protected:
    player& bruh;
    enemy& eminem;
    int round;
    bool turn_side;
    bool stop;

public:
    // Конструктор
    battle(player& new_bruh, enemy& new_eminem, const int& new_round, const bool& new_turn_side, const bool& new_stop);

    // Виды атак Игрока
    int FirstPlayerAttack();
    int SecondPlayerAttack();
    // Ход игрока
    void PlayerMove(const int& choice);

    // Виды атак врага
    int FirstEnemyAttack();
    // Ход противника
    void EnemyMove();

    // Меню хода
    void OptionsMenuFight();
    // Варианты ходов
    int GetPlayerChoice();
    // Статистика боя
    void ShowBattleStatistic();

    // Начало боя. :)
    void Fight();
};