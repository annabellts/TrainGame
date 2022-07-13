#include "Gamecontroller.h"

#include <iostream>


int main()
{
    std::cout << "Choose Map: \n 0: Germany \n 1: Local \n";
    int map;
    std::string fileName;
    std::cin >> map;
    switch (map) {
    case 0:
        fileName = "GermanyMap.txt";
        break;
    case 1:
        fileName = "LocalMap.txt";
        break;
    default:
        std::cout << "Unkown Map";
        return 1;
    }
    GameController game(fileName);
    game.PlayGame();
}
