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

class GameLogic;

class EasyScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    CREATE_FUNC(EasyScene);
private:
	static const std::vector<std::string> kImages;
	static const std::vector<std::string> kNodes;
	GameLogic* m_gameLogic = nullptr;
	cocos2d::Sprite* m_lastSprite = nullptr;
	void onEnter();
	void onExit();
	void bindEvents(cocos2d::Node* a_node);
	void bindTiles(cocos2d::Node * a_node);
	void triggerMainAnimation(float a_dt);
};
#endif /* defined(__MemoryGame__EasyScene__) */
