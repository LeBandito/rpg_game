#pragma once

#include <external/json.hpp>
#include <fstream>
#include <string>
#include <iostream>
using json = nlohmann::json;

class JsonManager {
public:
    // Сохранение в Json
    bool SaveToFile(const json& data, const std::string& file_name);

    // Читаем из файла
    json DownloadFromJson(const std::string& file_name);
};