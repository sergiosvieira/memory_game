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
#include "GameLogic.h"

USING_NS_CC;

using namespace cocostudio::timeline;

const std::vector<std::string> HardScene::kImages = 
{
	"01",
	"02",
	"03",
	"04",
	"05",
	"06",
	"07",
	"08",
	"09",
	"10"
};

const std::vector<std::string> HardScene::kNodes = 
{
	"tile_node_1",
	"tile_node_2",
	"tile_node_3",
	"tile_node_4",
	"tile_node_5",
	"tile_node_6"
	"tile_node_7",
	"tile_node_8"
};


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
	m_gameLogic = new GameLogic(8, kImages);
    auto rootNode = CSLoader::createNode("HardScene.csb");
	auto backButtonNode = rootNode->getChildByName("BackButtonNode");
	bindEvents(backButtonNode);
	bindTiles(rootNode);
    addChild(rootNode);
    return true;
}

void HardScene::onEnter()
{
	Layer::onEnter();
	this->scheduleOnce(schedule_selector(HardScene::triggerMainAnimation), 0.1f);	
}

void HardScene::onExit()
{
	if (m_gameLogic != nullptr)
	{
		delete m_gameLogic;
	}
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

void HardScene::bindTiles(cocos2d::Node* a_node)
{
	int counter = 1;
	for (const std::string& tileName : kNodes)
	{
		cocos2d::Node* tileNode = a_node->getChildByName(tileName);
		if (tileNode != nullptr)
		{			
			cocos2d::ui::Button* button = static_cast<cocos2d::ui::Button*>(tileNode->getChildByName("Button_1"));			
			button->setTag(counter++);
			button->addClickEventListener([=](cocos2d::Ref* a_reference) 
			{
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
