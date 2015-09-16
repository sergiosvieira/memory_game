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

class HardScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    CREATE_FUNC(HardScene);
};

#endif /* defined(__MemoryGame__HardScene__) */
