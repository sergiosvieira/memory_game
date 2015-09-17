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
	"tile_node_6",
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
	m_game = new GameLogic(8, kImages);
    auto rootNode = CSLoader::createNode("HardScene.csb");
	auto backButtonNode = rootNode->getChildByName("BackButton");
	auto refreshButtonNode = rootNode->getChildByName("RefreshButton");
	bindEvents(backButtonNode, refreshButtonNode);
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
	if (m_game != nullptr)
	{
		delete m_game;
	}
}

void HardScene::bindEvents(cocos2d::Node* a_backNode, cocos2d::Node* a_refreshNode)
{
	if (a_backNode != nullptr)
	{
		cocos2d::ui::Button *button = (cocos2d::ui::Button*)a_backNode->getChildByName("Button_1");
		if (button != nullptr)
		{
			button->addClickEventListener([](cocos2d::Ref* a_reference)
			{
				auto director = Director::getInstance();
				director->pushScene(TransitionSlideInT::create(0.5f, TitleScene::createScene()));
			});
		}
	}
	if (a_refreshNode != nullptr)
	{
		cocos2d::ui::Button *button = (cocos2d::ui::Button*)a_refreshNode->getChildByName("Button_1");
		if (button != nullptr)
		{
			button->addClickEventListener([](cocos2d::Ref* a_reference)
			{
				auto director = Director::getInstance();
				director->pushScene(TransitionSlideInT::create(0.5f, HardScene::createScene()));
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
				if (m_locked == false)
				{			
					if (m_firstSelected == nullptr)
					{
						if (m_game->isValidSelection(button->getTag() - 1) == true)
						{
							m_firstSelected = button;
							cocos2d::Sprite* sprite = static_cast<cocos2d::Sprite*>(m_firstSelected->getChildByName("Sprite_1"));
							sprite->setTexture(CCTextureCache::sharedTextureCache()->addImage("res/" + m_game->tileValue(button->getTag() - 1) + ".png"));
						}
					}
					else if (m_secondSelected == nullptr)
					{
						if (m_game->isValidSelection(button->getTag() - 1) == true
							&& m_game->isValidSelection(m_firstSelected->getTag() - 1) == true
							&& m_firstSelected->getTag() != button->getTag())
						{
							m_secondSelected = button;
							cocos2d::Sprite* sprite = static_cast<cocos2d::Sprite*>(m_secondSelected->getChildByName("Sprite_1"));
							sprite->setTexture(CCTextureCache::sharedTextureCache()->addImage("res/" + m_game->tileValue(button->getTag() - 1) + ".png"));
							m_locked = true;
							int first = m_firstSelected->getTag() - 1;
							int second = m_secondSelected->getTag() - 1;
							if (m_game->match(first, second) == true)
							{
								m_game->performMatch(first, second);
								m_firstSelected = nullptr;
								m_secondSelected = nullptr;
								m_locked = false;
							}
							else
							{
								this->scheduleOnce(schedule_selector(HardScene::triggerResetTiles), 0.5f);
							}
						}
					}
				}
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

void HardScene::triggerResetTiles(float a_dt)
{
	this->scheduleOnce(schedule_selector(HardScene::triggerAnimateFirstTile), 0.2f);
	this->scheduleOnce(schedule_selector(HardScene::triggerAnimateSecondTile), 0.25f);
}

void HardScene::triggerAnimateFirstTile(float a_dt)
{
	ActionTimeline* timeLine = CSLoader::createTimeline("TileNode.csb");	
	m_firstSelected->stopAllActions();
	m_firstSelected->runAction(timeLine);
	timeLine->play("tile_animation", false);
	cocos2d::Sprite* secondSprite = static_cast<cocos2d::Sprite*>(m_firstSelected->getChildByName("Sprite_1"));						
	secondSprite->setTexture(CCTextureCache::sharedTextureCache()->addImage("res/question.png"));	
	m_firstSelected = nullptr;
}

void HardScene::triggerAnimateSecondTile(float a_dt)
{
	ActionTimeline* timeLine = CSLoader::createTimeline("TileNode.csb");	
	m_secondSelected->stopAllActions();
	m_secondSelected->runAction(timeLine);
	timeLine->play("tile_animation", false);
	cocos2d::Sprite* secondSprite = static_cast<cocos2d::Sprite*>(m_secondSelected->getChildByName("Sprite_1"));						
	secondSprite->setTexture(CCTextureCache::sharedTextureCache()->addImage("res/question.png"));	
	m_secondSelected = nullptr;
	m_locked = false;
}
