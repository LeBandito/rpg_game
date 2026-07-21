cmake_minimum_required(VERSION 3.20)
project(RPG_Game)

# Говорим использовать стандарт C++20 (или 17)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Добавляем все .cpp файлы
set (SOURCES
    src/main.cpp

)

# Включаем поддержку отладки (для GDB)
set(CMAKE_BUILD_TYPE Debug)