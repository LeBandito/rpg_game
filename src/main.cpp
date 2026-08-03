#include <ctime>

#include "game/game.h"

int main() {
    std::srand(std::time(NULL));

    // Великое начало!
    game game_first;
    game_first.StartGameMenu();

    return 0;
}