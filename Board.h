#ifndef BOARD_H
#define BOARD_H

#include <memory>
#include<vector>
#include<string>
#include "Rail.h"

class Board {
private:
	const int m_cBoardHeight{ 20 };
	const int m_cBoardWidth{ 20 };

	std::vector<std::shared_ptr<IGameObj>> m_gameBoard{ m_cBoardHeight * m_cBoardWidth};
	//std::shared_ptr<Train> m_train;
	//std::vector<int> m_trainCoordinates;
	//std::vector<int> m_stationsLeftToVisit;

public:
	~Board() {};
	Board(std::vector<std::string> gameMap);

	int getBoardHeight() { return m_cBoardHeight; }
	int getBoardWidth() { return m_cBoardWidth; }
	std::vector<std::shared_ptr<IGameObj>> getGameBoard() { return m_gameBoard; }

	// getPossibleMoves() {}
	// applyMove() {}
	// getStationsLeftToVisit
	//getTrainCoordinates
	//getTrain
	//hasWon
};

#endif