#pragma once

#include "entities/player.h"
#include "entities/enemy.h"
#include "shop/shop.h"

class game {
protected:
    player bruh;
    std::vector<enemy> enemies;
    int idx_enemies;
    shop shopper;

public:
    // Создание персонажа
    void CreatePlayer();

    // Загрузка данных
    void LoadGamePlayer();
    void LoadGameEnemy();
    void LoadGameShop();

    // Варианты меню
    void NewGame();
    void ContinueGame();
    void ExitGame();

    // Выбор оппонента
    void FightSpecificEnemy();

    // Игра
    int StartGameMenu();
    void GetChooseOfStartMenu(const int& idx);
    int ContinueGameMenu();
    void GetChooseOfContinueMenu(const int& idx);

    // Сеттеры
    void SetBruh(const player& new_bruh);
    void SetEnemies(const std::vector<enemy>& new_enemies);
    void SetIdxEnemies(const int& new_idx_enemies);
    void SetShopper(const shop& new_shopper);

    // Геттеры
    player GetBruh() const;
    std::vector<enemy> GetEnemies() const;
    int GetIdxEnemies() const;
    shop GetShopper() const;
};