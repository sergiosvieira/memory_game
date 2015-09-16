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
#include "TitleScene.h"
#include "GameLogic.h"

USING_NS_CC;

using namespace cocostudio::timeline;

const std::vector<std::string> EasyScene::kImages = 
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

const std::vector<std::string> EasyScene::kNodes = 
{
	"tile_node_1",
	"tile_node_2",
	"tile_node_3",
	"tile_node_4",
	"tile_node_5",
	"tile_node_6"
};

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
	m_gameLogic = new GameLogic(6, kImages);
    auto rootNode = CSLoader::createNode("EasyScene.csb");
	auto backButtonNode = rootNode->getChildByName("BackButtonNode");
	bindEvents(backButtonNode);
	auto background = rootNode->getChildByName("background");
	bindTiles(background);
    addChild(rootNode);
    return true;
}

void EasyScene::onExit()
{
	if (m_gameLogic != nullptr)
	{
		delete m_gameLogic;
	}
}

void EasyScene::onEnter()
{
	Layer::onEnter();
	this->scheduleOnce(schedule_selector(EasyScene::triggerMainAnimation), 0.1f);	
}

void EasyScene::bindEvents(cocos2d::Node* a_node)
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

void EasyScene::bindTiles(cocos2d::Node* a_node)
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
				cocos2d::Sprite* sprite = static_cast<cocos2d::Sprite*>(button->getChildByName("Sprite_1"));
				if (m_gameLogic->isFirstSelection() == true)
				{					
					std::string textureName = "res/" + m_gameLogic->spriteName(button->getTag()) + ".png";
					sprite->setTexture(CCTextureCache::sharedTextureCache()->addImage(textureName));
					m_lastSprite = sprite;
					m_gameLogic->select(button->getTag());
				}
				else
				{
					if (m_gameLogic->isMatch(button->getTag()) == false)
					{
						m_lastSprite->setTexture(CCTextureCache::sharedTextureCache()->addImage("res/question.png"));
						sprite->setTexture(CCTextureCache::sharedTextureCache()->addImage("res/question.png"));
					}
					else
					{
						std::string textureName = "res/" + m_gameLogic->spriteName(button->getTag()) + ".png";
						sprite->setTexture(CCTextureCache::sharedTextureCache()->addImage(textureName));
					}
					m_gameLogic->reset();
					m_lastSprite = nullptr;
				}
			});
		}
	}
}

void EasyScene::triggerMainAnimation(float a_dt)
{
	ActionTimeline* timeLine = CSLoader::createTimeline("EasyScene.csb");
	this->stopAllActions();
	this->runAction(timeLine);
	timeLine->play("main_animation", false);
}
