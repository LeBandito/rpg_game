cmake_minimum_required(VERSION 3.20)
project(RPG_Game)

set(CMAKE_CXX_STANDARD 20)

add_executable(RPG_Game
    src/main.cpp
    src/game/game.cpp
    src/battle/battle.cpp
    src/entities/character.cpp
    src/entities/player.cpp
    src/entities/enemy.cpp
    src/shop/shop.cpp
    src/items/items.cpp
)

# Для удобного поиска заголовочных файлов
target_include_directories(RPG_Game PRIVATE include)