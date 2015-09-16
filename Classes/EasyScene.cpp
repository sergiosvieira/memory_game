//
//  EasyScene.cpp
//  MemoryGame
//
//  Created by Sergio Vieira on 15/09/15.
//
//

#include "EasyScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

using namespace cocostudio::timeline;


cocos2d::Scene* EasyScene::createScene()
{
    auto scene = Scene::create();
    auto layer = EasyScene::create();
    scene->addChild(layer);
    return scene;
}

bool EasyScene::init()
{
    if (Layer::init() == false)
    {
        return false;
    }
    auto rootNode = CSLoader::createNode("EasyScene.csb");
    addChild(rootNode);
    return true;
}
