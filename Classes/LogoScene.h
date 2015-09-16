//
//  LogoScene.h
//  MemoryGame
//
//  Created by Sergio Vieira on 15/09/15.
//
//

#ifndef __MemoryGame__LogoScene__
#define __MemoryGame__LogoScene__

#include "cocos2d.h"

class LogoScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    CREATE_FUNC(LogoScene);
private:
    void onEnter();
    void onFinishSplash(float a_dt);
};

#endif /* defined(__MemoryGame__LogoScene__) */
