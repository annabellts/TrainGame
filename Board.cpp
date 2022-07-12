#include "Board.h"

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


void Board::moveTrain( char move)
{
    std::vector<int> currentTrainPosition{ getTrainCoordinates() };
    std::shared_ptr < IGameObj> currentPositionObj{ getGameBoard()[currentTrainPosition.at(0) * m_cBoardWidth + currentTrainPosition.at(1)] };

    switch (move) {
    case 'w':
        if (currentPositionObj->getIsNorthRail() && m_trainCoordinates[0] > 0) {
            m_trainCoordinates[0] -= 1;
        }
        else {
            std::cerr << "Please enter a valid move";
        }
        break;
    case 'a':
        if (currentPositionObj->getIsWestRail() && m_trainCoordinates[1] > 0) {
            m_trainCoordinates[1] -= 1;
        }
        else {
            std::cerr << "Please enter a valid move";
        }
        break;
    case 's':
        if (currentPositionObj->getIsSouthRail() && m_trainCoordinates[0] < m_cBoardHeight - 1) {
            m_trainCoordinates[0] += 1;
        }
        else {
            std::cerr << "Please enter a valid move";
        }
        break;
    case 'd':
        if (currentPositionObj->getIsEastRail() && m_trainCoordinates[1] < m_cBoardWidth) {
            m_trainCoordinates[1] += 1;
        }
        break;
    default:
    std::cerr << "Please enter a valid move";
    }
}
