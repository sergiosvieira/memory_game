#ifndef __GAME_LOGIC__
#define __GAME_LOGIC__

#include <vector>
#include <string>

class GameLogic
{
public:
	GameLogic(int a_tiles, std::vector<std::string> a_images);
	void select(int a_tileIndex);
	std::string spriteName(int a_spriteIndex);
	int selectedTag();
	bool isFirstSelection();
	bool isMatch(int a_tag);
	void reset();
protected:
	int m_tiles = 0;
	int m_tag = -1;
	bool m_firstSelection = true;
	std::vector<std::string> m_selectedImage;
	std::vector<int> m_positions;
	std::vector<bool> m_matched;
};

#endif /** __GAME_LOGIC__ **/