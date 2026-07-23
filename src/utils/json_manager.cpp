#include "utils/json_manager.h"

bool JsonManager::SaveToFile(const json& data, const std::string& file_name) {
    std::ofstream file(file_name);

    if (!file.is_open()) {
        std::cout << "Not open - " << file_name << std::endl;
        return false;
    }
    
    file << data;
    return true;
}

json JsonManager::DownloadFromJson(const std::string& file_name) {
    try {
        std::ifstream file(file_name);
            if (!file.is_open()) {
                std::cout << "Not open - " << file_name << std::endl;
                return json::object();
           }

           json temporary;
           file >> temporary;
           return temporary;
    } catch (const std::exception& e) {
        std::cout << "Error:\t" << e.what() << std::endl;
        return json::object();
    }
}

