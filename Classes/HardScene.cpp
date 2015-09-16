//
//  HardScene.cpp
//  MemoryGame
//
//  Created by Sergio Vieira on 15/09/15.
//
//

#include "HardScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

using namespace cocostudio::timeline;


cocos2d::Scene* HardScene::createScene()
{
    auto scene = Scene::create();
    auto layer = HardScene::create();
    scene->addChild(layer);
    return scene;
}

bool HardScene::init()
{
    if (Layer::init() == false)
    {
        return false;
    }
    auto rootNode = CSLoader::createNode("HardScene.csb");
    addChild(rootNode);
    return true;
}
