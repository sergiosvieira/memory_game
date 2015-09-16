#include "GameLogic.h"
#include <algorithm>
#include <chrono>
#include <random>

using namespace std;


GameLogic::GameLogic(int a_tiles, std::vector<std::string> a_images)
{
	m_tiles = a_tiles / 2;
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::shuffle(a_images.begin(), a_images.end(), std::default_random_engine(seed));	
	for (int i = 0; i < m_tiles; ++i)
	{
		m_selectedImage.push_back(a_images.at(i));
	}
	int counter = 0;
	for (int i = 0; i < a_tiles; ++i)
	{
		m_positions.push_back(counter);
		if (i % 2 != 0)
		{
			++counter;
		}
	}
	std::shuffle(m_positions.begin(), m_positions.end(), std::default_random_engine(seed));
	m_matched.reserve(m_positions.size());
	std::fill(m_matched.begin(), m_matched.end(), false);
}

void GameLogic::select(int a_tileIndex)
{
	if (m_matched[a_tileIndex - 1] == false)
	{
		if (m_firstSelection == true)
		{
			m_tag = m_positions[a_tileIndex - 1];
			m_firstSelection = false;
		}
	}
}

std::string GameLogic::spriteName(int a_spriteIndex)
{
	std::string result = m_selectedImage[m_positions[a_spriteIndex - 1]];
	return result;
}

int GameLogic::selectedTag()
{
	return m_tag;
}


bool GameLogic::isFirstSelection()
{
	return m_firstSelection;
}

bool GameLogic::isMatch(int a_tag)
{
	bool result = (m_tag == m_positions[a_tag - 1]);
	if (result == true)
	{
		int tag = m_positions[a_tag - 1];
		for (int i = 0; i < m_positions.size(); ++i)
		{
			if (m_positions[i] == tag)
			{
				m_matched[i] = true;
			}
		}
	}
	return result;
}

void GameLogic::reset()
{
	m_firstSelection = true;
	m_tag = -1;
}
