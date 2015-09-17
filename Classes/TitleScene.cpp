//
//  TitleScene.cpp
//  MemoryGame
//
//  Created by Sergio Vieira on 15/09/15.
//
//

#include "TitleScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "EasyScene.h"
#include "HardScene.h"


USING_NS_CC;

using namespace cocostudio::timeline;


cocos2d::Scene* TitleScene::createScene()
{
    auto scene = cocos2d::Scene::create();
    auto layer = TitleScene::create();
    scene->addChild(layer);
    return scene;
}

bool TitleScene::init()
{
    if (Layer::init() == false)
    {
        return false;
    }
    auto rootNode = CSLoader::createNode("TitleScene.csb");
    auto spriteNode = rootNode->getChildByName("titlebackground_1");
    bindEvent(spriteNode);
    addChild(rootNode);
    return true;
}

void TitleScene::onEnter()
{
	Layer::onEnter();
	this->scheduleOnce(schedule_selector(TitleScene::triggerMainAnimation), 0.1f);	
}

void TitleScene::triggerMainAnimation(float a_dt)
{
	ActionTimeline* timeLine = CSLoader::createTimeline("TitleScene.csb");
	this->stopAllActions();
	this->runAction(timeLine);
	timeLine->play("subtitle_animation", true);
}

void TitleScene::bindEvent(cocos2d::Node* a_node)
{
    if (a_node != nullptr)
    {
        cocos2d::ui::Button *easyButton = (cocos2d::ui::Button*)a_node->getChildByName("EasyButton");
        if (easyButton != nullptr)
        {
            easyButton->addClickEventListener([](cocos2d::Ref* a_reference)
            {
                auto director = Director::getInstance();
                director->replaceScene(TransitionSlideInT::create(0.5f, EasyScene::createScene()));
            });
        }
        cocos2d::ui::Button *hardButton = (cocos2d::ui::Button*)a_node->getChildByName("HardButton");
        if (hardButton != nullptr)
        {
            hardButton->addClickEventListener([](cocos2d::Ref* a_reference)
            {
                auto director = Director::getInstance();
                director->replaceScene(TransitionSlideInT::create(0.5f, HardScene::createScene()));
            });
        }
    }
}