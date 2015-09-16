//
//  TitleScene.h
//  MemoryGame
//
//  Created by Sergio Vieira on 15/09/15.
//
//

#ifndef __MemoryGame__TitleScene__
#define __MemoryGame__TitleScene__

#include "cocos2d.h"

class TitleScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    CREATE_FUNC(TitleScene);
private:
	void onEnter();
	void triggerMainAnimation(float a_dt);
    void bindEvent(cocos2d::Node* a_node);
};

#endif /* defined(__MemoryGame__TitleScene__) */
