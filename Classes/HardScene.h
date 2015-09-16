//
//  HardScene.h
//  MemoryGame
//
//  Created by Sergio Vieira on 15/09/15.
//
//

#ifndef __MemoryGame__HardScene__
#define __MemoryGame__HardScene__

#include "cocos2d.h"

class GameLogic;

class HardScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
	void onEnter();
	void onExit();
	void bindEvents(cocos2d::Node * a_node);
	void bindTiles(cocos2d::Node * a_node);
	void triggerMainAnimation(float a_dt);
    CREATE_FUNC(HardScene);
private:
	static const std::vector<std::string> kImages;
	static const std::vector<std::string> kNodes;
	GameLogic* m_gameLogic;
	cocos2d::Sprite* m_lastSprite = nullptr;
};

#endif /* defined(__MemoryGame__HardScene__) */
