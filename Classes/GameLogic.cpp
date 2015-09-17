#include "GameLogic.h"
#include <algorithm>
#include <chrono>
#include <random>

using namespace std;

GameLogic::GameLogic(int a_total, Vector a_tiles)
{
	m_tiles.resize(a_tiles.size());
	std::copy(a_tiles.begin(), a_tiles.end(), m_tiles.begin());
    m_total = a_total;
    initializing();
    selectTiles(a_tiles);
    prepareBoard();
}

/** Public Methods **/
int GameLogic::boardSize()
{
	return m_total;
}

bool GameLogic::isValidSelection(int a_selection)
{
	return m_status[a_selection] == false;
}

bool GameLogic::match(int a_firstSelect, int a_secondSelection)
{
	return m_board[a_firstSelect] == m_board[a_secondSelection];
}

void GameLogic::performMatch(int a_firstSelect, int a_secondSelection)
{
    m_status[a_firstSelect] = true;
    m_status[a_secondSelection] = true;
}

std::string GameLogic::tileValue(int a_selection)
{
	return m_tiles[m_board[a_selection]];
}

/** Protected Methods **/
void GameLogic::initializing()
{
    m_board.resize(m_total);
    m_status.resize(m_total);
}

void GameLogic::selectTiles(Vector & a_tiles)
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    m_selected_tiles.resize(m_total / 2);
    std::shuffle(a_tiles.begin(), a_tiles.end(), std::default_random_engine(seed));
    std::copy(a_tiles.begin(), a_tiles.begin() + m_total / 2, m_selected_tiles.begin());
}

void GameLogic::prepareBoard()
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    int counter = -1;
    int value = 0;
    std::generate(m_board.begin(), m_board.end(), [&counter, &value]()
    {
        if (counter % 2 == 1)
        {
            ++value;
        }
        ++counter;
        return value;
    });
    std::shuffle(m_board.begin(), m_board.end(), std::default_random_engine(seed));
}
