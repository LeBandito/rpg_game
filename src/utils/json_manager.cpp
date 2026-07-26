#include "utils/json_manager.h"

#include <fstream>
#include <iostream>


// Перевод из Json в наши классы
item JsonManager::FromJsonToItem(const json& data) {
    item bruh;

    bruh.SetName(data["name"]);
    bruh.SetDescription(data["description"]);
    bruh.SetPrice(data["price"]);
    bruh.SetWeight(data["weight"]);
    
    return bruh;
}

weapon JsonManager::FromJsonToWeapon(const json& data) {
    weapon bruh;

    bruh.SetMinDamage(data["min_damage"]);
    bruh.SetMaxDamage(data["max_damage"]);
    bruh.SetEffect(data["effect"]);
    
    return bruh;
}

player JsonManager::FromJsonToPlayer(const json& data) {
    player bruh;

    bruh.SetName(data["name"]);
    bruh.SetHp(data["hp"]);
    bruh.SetMaxHp(data["max_hp"]);
    bruh.SetShield(data["shield"]);
    bruh.SetMoney(data["money"]);
    bruh.SetInventory(data["inventory"]);
    bruh.SetMaxWeightInventory(data["max_weight_inventory"]);
    bruh.SetAlive(data["alive"]);
    bruh.SetPlayerWeaponFirst(FromJsonToWeapon(data["player_weapons_first"]));
    bruh.SetPlayerWeaponSecond(FromJsonToWeapon(data["player_weapons_second"]));
    bruh.SetPlayerWeapons(data["player_weapons_second"]);
    bruh.SetWeightInventory(data["weight_inventory"]);

    return bruh;
}

enemy JsonManager::FromJsonToEnemy(const json& data) {
    enemy bruh;

    bruh.SetName(data["name"]);
    bruh.SetHp(data["hp"]);
    bruh.SetMaxHp(data["max_hp"]);
    bruh.SetShield(data["shield"]);
    bruh.SetMoney(data["money"]);
    bruh.SetInventory(data["inventory"]);
    bruh.SetMaxWeightInventory(data["max_weight_inventory"]);
    bruh.SetAlive(data["alive"]);
    bruh.SetWeapon(FromJsonToWeapon(data["enemy_weapon"]));

    return bruh;
}

// Перевод из наших классов в Json
json JsonManager::FromItemToJson(const item& data) {
    json bruh;

    bruh["id"] = data.GetId();
    bruh["name"] = data.GetName();
    bruh["description"] = data.GetDescription();
    bruh["price"] = data.GetPrice();
    bruh["weight"] = data.GetWeight();
    
    return bruh;
}

json JsonManager::FromWeaponToJson(const weapon& data) {
    json bruh;

    bruh["min_damage"] = data.GetMinDamage();
    bruh["max_damage"] = data.GetMaxDamage();
    bruh["effect"] = data.GetEffect();
    
    return bruh;
}

json JsonManager::FromPlayerToJson(player& data) {
    json bruh;

    bruh["name"] = data.GetName();
    bruh["hp"] = data.GetHp();
    bruh["max_hp"] = data.GetMaxHp();
    bruh["shield"] = data.GetShield();
    bruh["money"] = data.GetMoney();

    // Особый случай - array
    json json_inventory = json::array();
    for (const item& item : data.GetInventory())
        json_inventory.push_back(FromItemToJson(item));
    
    bruh["inventory"] = json_inventory;

    bruh["max_weight_inventory"] = data.GetMaxWeightInventory();
    bruh["alive"] = data.GetAlive();
    bruh["player_weapon_first"] = FromWeaponToJson(data.GetPlayerWeaponFirst());
    bruh["player_weapon_second"] = FromWeaponToJson(data.GetPlayerWeaponSecond());

    json json_player_weapons = json::array();
    for (const weapon& p : data.GetPlayerWeapons())
        json_player_weapons.push_back(FromWeaponToJson(p));

    bruh["weight_inventory"] = data.GetWeightInventory();

    return bruh;
}

json JsonManager::FromEnemyToJson(enemy& data) {
    json bruh;

    bruh["name"] = data.GetName();
    bruh["hp"] = data.GetHp();
    bruh["max_hp"] = data.GetMaxHp();
    bruh["shield"] = data.GetShield();
    bruh["money"] = data.GetMoney();

    // Особый случай - array
    json json_inventory = json::array();
    for (const item& item : data.GetInventory())
        json_inventory.push_back(FromItemToJson(item));
    
    bruh["inventory"] = json_inventory;

    bruh["max_weight_inventory"] = data.GetMaxWeightInventory();
    bruh["alive"] = data.GetAlive();
    bruh["enemy_weapon"] = FromWeaponToJson(data.GetWeapon());

    return bruh;
}

// Читаем данные player.json
player JsonManager::LoadPlayer(const std::string& file_name) {
    player bruh;
    try {
        std::ifstream file(file_name);
        if (!file.is_open()) {
            std::cout << "Not open - " << file_name << std::endl;
            return bruh;
        }
        json j;
        file >> j;
        file.close();

        bruh = FromJsonToPlayer(j);        
        return bruh;
    } catch (const std::exception& e) {
        std::cout << "Error:\t" << e.what() << std::endl;
        return bruh;
    }
}

// Читаем данные items.json
std::vector<item> JsonManager::LoadItems(const std::string& file_name) {
    std::vector<item> game_items;
    try {
        std::ifstream file(file_name);
        if (!file.is_open()) {
            std::cout << "Not open - " << file_name << std::endl;
            return game_items;
        }
        json j;
        file >> j;
        file.close();

        for (const json& idx : j)
            game_items.push_back(FromJsonToItem(idx));

        return game_items;
    } catch (const std::exception& e) {
        std::cout << "Error:\t" << e.what() << std::endl;
        return game_items;
    }
}

// Читаем из enemies.json
std::array<enemy, 3> JsonManager::LoadEnemies(const std::string& file_name) {
    std::array<enemy, 3> game_enemies;
    try {
        std::ifstream file(file_name);
        if (!file.is_open()) {
            std::cout << "Not open - " << file_name << std::endl;
            return game_enemies;
        }
        json j;
        file >> j;
        file.close();

        int i(0);
        for (const json& idx : j) {
            game_enemies[i] = FromJsonToEnemy(idx);
            ++i;
        }

        return game_enemies;
    } catch (const std::exception& e) {
        std::cout << "Error:\t" << e.what() << std::endl;
        return game_enemies;
    }
}

// Сохранение в items.json
void JsonManager::SaveItems(const std::vector<item>& data, const std::string& file_name) {
    std::ofstream file(file_name);

    if (!file.is_open()) {
        std::cout << "Not open - " << file_name << std::endl;
    }

    json json_items = json::array();
    for (const item& d : data) 
        json_items.push_back(FromItemToJson(d));

    file << json_items;
    file.close();
}

// Сохранение в player.json
void JsonManager::SavePlayer(player& data, const std::string& file_name) {
    std::ofstream file(file_name);

    if (!file.is_open()) {
        std::cout << "Not open - " << file_name << std::endl;
    }

    file << FromPlayerToJson(data);
    file.close();
}

// Сохранение в enemies.json
void JsonManager::SaveEnemies(std::array<enemy, 3>& data, const std::string& file_name) {
    std::ofstream file(file_name);

    if (!file.is_open()) {
        std::cout << "Not open - " << file_name << std::endl;
    }

    json json_enemies = json::array();
    for (enemy& d : data) 
        json_enemies.push_back(FromEnemyToJson(d));

    file << json_enemies;
    file.close();
}