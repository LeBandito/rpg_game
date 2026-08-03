#include "game/game.h"

#include "utils/json_manager.h"
#include "items/items.h"
#include "items/weapons.h"
#include "items/clothes.h"
#include "items/potions.h"
#include "battle/battle.h"

#include <iostream>

void game::CreatePlayer() {
    player temporary = player();

    std::cout << "Welcome to the menu of creating hero!" << std::endl;
    std::string new_name;
    std::cout << "Give a name to youre character:\t" << std::endl;
    std::cin >> new_name;

    temporary.SetName(new_name);
    temporary.SetMoney(20);
    temporary.SetHp(20);
    temporary.SetMaxHp(25);
    temporary.SetMoney(10);

    temporary.SetBag( 
        {
            1, 1, 0, 0, 
            10, 0, 
            3, 3, 2, 2, 
            {item(1, "apple", "just red apple...", 1, 1)}, 
            {weapon(2, "knife", "just knife...", 5, 2, 5, 8, 1)}, 
            {clothes()}, {potion()}
        }
    );

    bruh = temporary;
}

// Загрузка данных
void game::LoadGamePlayer() { bruh = JsonManager::LoadPlayer("player.json"); }

void game::LoadGameEnemy() { enemies = JsonManager::LoadEnemies("enemies.json"); }

void game::LoadGameShop() { 
    shopper.SetShopProducts(JsonManager::LoadItems("items.json"));
    shopper.SetShopWeapons(JsonManager::LoadWeapons("weapons.json"));
}

// Варианты меню
void game::NewGame() {
    CreatePlayer();
    LoadGameEnemy();
    LoadGameShop();
    ContinueGameMenu();
}

void game::ContinueGame() {
    std::cout << "Continue..." << std::endl;
    LoadGamePlayer();
    LoadGameEnemy();
    LoadGameShop();
    ContinueGameMenu();
}

void game::ExitGame() {
    std::cout << "Bye..." << std::endl;
}

// Игра
int game::StartGameMenu() {
    int temporary;

    std::cout << "Welcom to the RPG game!" << std::endl;
    std::cout << "1) New game." << std::endl;
    std::cout << "2) Continue." << std::endl;
    std::cout << "3) Exit." << std::endl;

    std::cin >> temporary;

    return temporary;
}

void game::GetChooseOfStartMenu() {
    int choose(0);
    while (choose != 3) {
        choose = StartGameMenu();
        switch (choose)
        {
        case 1:
            NewGame();
            break;
        
        case 2:
            ContinueGame();
            break;
        
        case 3:
            ExitGame();
            break;
        
        default:
            break;
        }
    }
}

int game::ContinueGameMenu() {
    int temporary;

    std::cout << "1) Fight." << std::endl;
    std::cout << "2) Shop." << std::endl;
    std::cout << "3) Statistic." << std::endl;
    std::cout << "4) Exit." << std::endl;

    std::cin >> temporary;

    return temporary;
}

void game::GetChooseOfContinueMenu() {
    int choose(0);
    while (choose != 4) {
        choose = ContinueGameMenu();
        switch (choose)
        {
        case 1:
            battle game_battle(bruh, enemies[idx_enemies], 1, true, false);
            game_battle.Fight();
            ++idx_enemies;
            break;
        
        case 2:
            shopper.GameShopping(bruh);
            break;
        
        case 3:
            bruh.ShowStatistic();
            bruh.ShowInventory();
            break;

        case 4:
            ExitGame();
            break;
        
        default:
            std::cout << "Invalid choice. Try again." << std::endl;
            break;
        }
    }
}


// Сеттеры
void game::SetBruh(const player& new_bruh) { bruh = new_bruh; }
void game::SetEnemies(const std::vector<enemy>& new_enemies) { enemies = new_enemies; }
void game::SetIdxEnemies(const int& new_idx_enemies) { idx_enemies = new_idx_enemies; }
void game::SetShopper(const shop& new_shopper) { shopper = new_shopper; }

// Геттеры
player game::GetBruh() const { return bruh; }
std::vector<enemy> game::GetEnemies() const { return enemies; }
int game::GetIdxEnemies() const { return idx_enemies; }
shop game::GetShopper() const { return shopper; }