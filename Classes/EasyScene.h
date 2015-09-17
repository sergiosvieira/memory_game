//
//  EasyScene.h
//  MemoryGame
//
//  Created by Sergio Vieira on 15/09/15.
//
//

#ifndef __MemoryGame__EasyScene__
#define __MemoryGame__EasyScene__

#include "cocos2d.h"
#include <vector>
#include <string>
#include "ui/CocosGUI.h"


class GameLogic;

class EasyScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    CREATE_FUNC(EasyScene);
private:
	bool m_locked = false;
	cocos2d::ui::Button* m_firstSelected = nullptr;
	cocos2d::ui::Button* m_secondSelected = nullptr;
	static const std::vector<std::string> kImages;
	static const std::vector<std::string> kNodes;
	GameLogic* m_game = nullptr;
	void onEnter();
	void onExit();
	void bindEvents(cocos2d::Node * a_backNode, cocos2d::Node * a_refreshNode);
	void bindTiles(cocos2d::Node * a_node);
	void triggerResetTiles(float a_dt);
	void triggerMainAnimation(float a_dt);
	void triggerAnimateFirstTile(float a_dt);
	void triggerAnimateSecondTile(float a_dt);
};
#endif /* defined(__MemoryGame__EasyScene__) */
