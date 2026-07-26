#include "game/game.h"
#include <iostream>

int main() {
    std::cout << "Just Example!" << std::endl;
    int a;
    std::cout << "Enter a:\t";
    std::cin >> a;
    
    std::cout << "a is\t" << a << std::endl;

    // Великое начало!
    game game_first;
    game_first.run();

    return 0;
}