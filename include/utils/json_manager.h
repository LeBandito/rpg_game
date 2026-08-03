#pragma once

#include "entities/player.h"
#include "entities/enemy.h"
#include "items/items.h"
#include "items/weapons.h"
#include "items/potions.h"
#include "items/clothes.h"

#include <string>

#include <nlohmann/json.hpp>
using json = nlohmann::json;

// Переход на static

class JsonManager {
public:
    // Перевод из Json в наши классы
    static item FromJsonToItem(const json& data);
    static weapon FromJsonToWeapon(const json& data);
    static player FromJsonToPlayer(const json& data);
    static enemy FromJsonToEnemy(const json& data);

    // Перевод из наших классов в Json
    static json FromItemToJson(const item& data);
    static json FromWeaponToJson(const weapon& data);
    static json FromPlayerToJson(player& data);
    static json FromEnemyToJson(enemy& data); 


    // Читаем данные player.json
    static player LoadPlayer(const std::string& file_name);
    // Читаем данные items.json
    static std::vector<item> LoadItems(const std::string& file_name);
    // Читаем из enemies.json
    static std::vector<enemy> LoadEnemies(const std::string& file_name);
    // Читаем из weapons.json
    static std::vector<weapon> LoadWeapons(const std::string& file_name);
    // Читаем из potions.json
    static std::vector<potion> LoadPotions(const std::string& file_name);
    // Читаем из clothes.json
    static std::vector<clothes> LoadClothes(const std::string& file_name);


    // Сохранение в items.json
    static void SaveItems(const std::vector<item>& data, const std::string& file_name);
    // Сохранение в player.json
    static void SavePlayer(player& data, const std::string& file_name);
    // Сохранение в enemies.json
    static void SaveEnemies(std::vector<enemy>& data, const std::string& file_name);
};