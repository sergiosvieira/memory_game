#ifndef __GAME_LOGIC__
#define __GAME_LOGIC__

#include <vector>
#include <string>

class GameLogic
{
    typedef std::vector<std::string> Vector;
public:
	GameLogic(int a_total, Vector a_tiles);
	int boardSize();
	bool isValidSelection(int a_selection);
	bool match(int a_firstSelect, int a_secondSelection);
	void performMatch(int a_firstSelect, int a_secondSelection);
	std::string tileValue(int a_selection);
protected:
    int m_total;
    std::vector<int> m_board;
    std::vector<bool> m_status;
	Vector m_tiles;
    Vector m_selected_tiles;
	void initializing();
	void selectTiles(Vector& a_tiles);
	void prepareBoard();
};

#endif /** __GAME_LOGIC__ **/