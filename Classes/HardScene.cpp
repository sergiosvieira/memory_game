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
#include "TitleScene.h"

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
	auto backButtonNode = rootNode->getChildByName("BackButtonNode");
	bindEvents(backButtonNode);
    addChild(rootNode);
    return true;
}

void HardScene::onEnter()
{
	Layer::onEnter();
	this->scheduleOnce(schedule_selector(HardScene::triggerMainAnimation), 0.1f);	
}

void HardScene::bindEvents(cocos2d::Node* a_node)
{
	if (a_node != nullptr)
	{
		cocos2d::ui::Button *backButton = (cocos2d::ui::Button*)a_node->getChildByName("Button_1");
		if (backButton != nullptr)
		{
			backButton->addClickEventListener([](cocos2d::Ref* a_reference)
			{
				auto director = Director::getInstance();
				director->pushScene(TransitionSlideInT::create(1, TitleScene::createScene()));
			});
		}
	}
}

void HardScene::triggerMainAnimation(float a_dt)
{
	ActionTimeline* timeLine = CSLoader::createTimeline("HardScene.csb");
	this->stopAllActions();
	this->runAction(timeLine);
	timeLine->play("main_animation", false);
}
