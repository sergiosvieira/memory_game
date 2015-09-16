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

class EasyScene : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    CREATE_FUNC(EasyScene);
};
#endif /* defined(__MemoryGame__EasyScene__) */
