#include "Board.h"

#include <iostream>

//creates the board according to gameMap
//adds trainstation to rail if provided
//checks adjacent rails, where train can move to
Board::Board(std::vector<std::string> gameMap)
{
    bool isFirst{ true };
    for (int row = 0; row < m_cBoardHeight; row++)
    {
        for (int clm = 0; clm < m_cBoardWidth; clm++)
        {
            if (gameMap[row][clm] == ' ') {
                m_gameBoard[row * m_cBoardWidth + clm] = nullptr;

            }
            else  {
                bool isNorthRail{false};
                bool isEastRail{ false };
                bool isSouthRail{ false };
                bool isWestRail{ false };

                if (row > 0 && gameMap[row - 1][clm] != ' ') {
                    isNorthRail= true ;
                }

                if (clm < m_cBoardWidth-1 && gameMap[row][clm+1] != ' ') {
                    isEastRail = true ;
                }

                if (row < m_cBoardHeight-1 && gameMap[row + 1][clm] != ' ') {
                    isSouthRail= true ;
                }


                if (clm > 0 && gameMap[row][clm - 1] != ' ') {
                    isWestRail = true;
                }
              
                if (gameMap[row][clm] == '#') {
                    m_gameBoard[row * m_cBoardWidth + clm] = (std::shared_ptr<IGameObj>) new Rail(isNorthRail, isEastRail, isSouthRail, isWestRail, nullptr);
                    if (isFirst) {
                        m_train = std::shared_ptr<Train>(new Train);
                        m_trainCoordinates = { row,clm };
                        isFirst = false;
                    }
                }
                else {
                    std::shared_ptr<Station> currentStation;
                    currentStation=std::shared_ptr<Station>(new Station(gameMap[row][clm]));
                    m_stationList.push_back(currentStation);
                    m_gameBoard[row * m_cBoardWidth + clm] = (std::shared_ptr<IGameObj>) new Rail(isNorthRail, isEastRail, isSouthRail, isWestRail, currentStation);
                } 
            }
        }
    }
    

}

//moves the train along the rail grid, only stops at intersections or stations, can only turn back on stations
void Board::moveTrain( char move)
{
    std::vector<int> currentTrainPosition{ getTrainCoordinates() };
    char currentTrainOrientation{ getTrain()->getOrientation() };
    std::shared_ptr < IGameObj> currentPositionObj{ getGameBoard()[currentTrainPosition.at(0) * m_cBoardWidth + currentTrainPosition.at(1)] };

    switch (move) {
    case 'w':
        if (currentPositionObj->getIsNorthRail() && (currentPositionObj->getStation() || currentTrainOrientation != 's')) {
            getTrain()->setOrientation('n');
            do  {
                m_trainCoordinates[0] -= 1;
                currentTrainPosition = getTrainCoordinates() ;
                currentPositionObj = getGameBoard()[currentTrainPosition.at(0) * m_cBoardWidth + currentTrainPosition.at(1)] ;
            } while (currentPositionObj->getIsNorthRail() && !currentPositionObj->getIsWestRail() && !currentPositionObj->getIsEastRail() && currentPositionObj->getStation()==nullptr);
        }
        else {
            std::cerr << "Please enter a valid move";
        }
        break;
    case 'a':
        if (currentPositionObj->getIsWestRail() && (currentPositionObj->getStation() || currentTrainOrientation != 'e')) {
            getTrain()->setOrientation('w');
            do {
                m_trainCoordinates[1] -= 1;
                currentTrainPosition = getTrainCoordinates();
                currentPositionObj = getGameBoard()[currentTrainPosition.at(0) * m_cBoardWidth + currentTrainPosition.at(1)];
            } while (currentPositionObj->getIsWestRail() && !currentPositionObj->getIsNorthRail() && !currentPositionObj->getIsSouthRail() && currentPositionObj->getStation() == nullptr);
        }
        else {
            std::cerr << "Please enter a valid move";
        }
        break;
    case 's':
        if (currentPositionObj->getIsSouthRail() && (currentPositionObj->getStation() || currentTrainOrientation != 'n')) {
            getTrain()->setOrientation('s');
            do {
                m_trainCoordinates[0] += 1;
                currentTrainPosition = getTrainCoordinates();
                currentPositionObj = getGameBoard()[currentTrainPosition.at(0) * m_cBoardWidth + currentTrainPosition.at(1)];
            } while (currentPositionObj->getIsSouthRail() && !currentPositionObj->getIsWestRail() && !currentPositionObj->getIsEastRail() && currentPositionObj->getStation() == nullptr);
        }
        else {
            std::cerr << "Please enter a valid move";
        }
        break;
    case 'd':
        if (currentPositionObj->getIsEastRail() && (currentPositionObj->getStation() || currentTrainOrientation != 'w')) {
            getTrain()->setOrientation('e');
            do {
                m_trainCoordinates[1] += 1;
                currentTrainPosition = getTrainCoordinates();
                currentPositionObj = getGameBoard()[currentTrainPosition.at(0) * m_cBoardWidth + currentTrainPosition.at(1)];
            } while (currentPositionObj->getIsEastRail() && !currentPositionObj->getIsNorthRail() && !currentPositionObj->getIsSouthRail() && currentPositionObj->getStation() == nullptr);
        }
        break;
    default:
    std::cerr << "Please enter a valid move";
    }
}
