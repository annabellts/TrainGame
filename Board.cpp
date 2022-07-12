#include "Board.h"

Board::Board(std::vector<std::string> gameMap)
{
    for (int i = 0; i < m_cBoardHeight; i++)
    {
        for (int j = 0; j < m_cBoardWidth; j++)
        {
            if (gameMap[i][j] == ' ') {
                m_gameBoard[i * m_cBoardWidth + j] = nullptr;

            }
            else  {
                bool isNorthRail{false};
                bool isEastRail{ false };
                bool isSouthRail{ false };
                bool isWestRail{ false };

                if (i > 0 && gameMap[i - 1][j] != ' ') {
                    isNorthRail= true ;
                }

                if (j < m_cBoardWidth-1 && gameMap[i][j+1] != ' ') {
                    isEastRail = true ;
                }

                if (i < m_cBoardHeight-1 && gameMap[i + 1][j] != ' ') {
                    isSouthRail= true ;
                }


                if (j > 0 && gameMap[i][j - 1] != ' ') {
                    isWestRail = true;
                }

                if (gameMap[i][j] == '#') {
                    m_gameBoard[i * m_cBoardWidth + j] = (std::shared_ptr<IGameObj>) new Rail(isNorthRail, isEastRail, isSouthRail, isWestRail, nullptr);
                }
                else {
                    m_gameBoard[i * m_cBoardWidth + j] = (std::shared_ptr<IGameObj>) new Rail(isNorthRail, isEastRail, isSouthRail, isWestRail, std::shared_ptr<Station>(new Station(gameMap[i][j])));
                }
            }
        }
    }

}
