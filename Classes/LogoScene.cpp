//
//  LogoScene.cpp
//  MemoryGame
//
//  Created by Sergio Vieira on 15/09/15.
//
//

#include "LogoScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "TitleScene.h"

USING_NS_CC;

using namespace cocostudio::timeline;


cocos2d::Scene* LogoScene::createScene()
{
    auto scene = Scene::create();
    auto layer = LogoScene::create();
    scene->addChild(layer);
    return scene;
}

bool LogoScene::init()
{
    if (Layer::init() == false)
    {
        return false;
    }
    auto rootNode = CSLoader::createNode("LogoScene.csb");
    addChild(rootNode);
    return true;
}

void LogoScene::onEnter()
{
    Layer::onEnter();
    this->scheduleOnce(schedule_selector(LogoScene::onFinishSplash), 3.f);
}

void LogoScene::onFinishSplash(float a_dt)
{
    Director::getInstance()->replaceScene(TitleScene::createScene());
}

