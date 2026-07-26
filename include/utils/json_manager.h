#pragma once

#include "entities/player.h"
#include "entities/enemy.h"
#include "items/items.h"

#include <string>

#include <nlohmann/json.hpp>
using json = nlohmann::json;


class JsonManager {
public:
    // Перевод из Json в наши классы
    item FromJsonToItem(const json& data);
    player FromJsonToPlayer(const json& data);
    enemy FromJsonToEnemy(const json& data);

    // Перевод из наших классов в Json
    json FromItemToJson(const item& data);
    json FromPlayerToJson(player& data);
    json FromEnemyToJson(enemy& data); 


    // Читаем данные player.json
    player LoadPlayer(const std::string& file_name);
    // Читаем данные items.json
    std::vector<item> LoadItems(const std::string& file_name);
    // Читаем из enemies.json
    std::array<enemy, 3> LoadEnemies(const std::string& file_name);


    // Сохранение в items.json
    void SaveItems(const std::vector<item>& data, const std::string& file_name);
    // Сохранение в player.json
    void SavePlayer(player& data, const std::string& file_name);
    // Сохранение в enemies.json
    void SaveEnemies(std::array<enemy, 3>& data, const std::string& file_name);
};