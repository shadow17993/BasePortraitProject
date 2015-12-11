#include "MainScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"


#define COCOS2D_DEBUG 1


USING_NS_CC;

using namespace std;
using namespace cocostudio::timeline;

Scene* MainScreen::createScene()
{
    auto scene = Scene::create();
   
    auto layer = MainScreen::create();
    
    scene->addChild(layer);

    return scene;
}

bool MainScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	auto rootNode = CSLoader::createNode("MainScene.csb");
	auto winSize = Director::getInstance()->getVisibleSize();

	addChild(rootNode);

	//set background sprites
	background1 = (Sprite*)rootNode->getChildByName("background");
	background2 = (Sprite*)rootNode->getChildByName("background2");

	//Touch listener
	auto touchListener = EventListenerTouchOneByOne::create();

	touchListener->onTouchBegan = CC_CALLBACK_2(MainScene::onTouchBegan, this);
	touchListener->onTouchEnded = CC_CALLBACK_2(MainScene::onTouchEnded, this);
	touchListener->onTouchMoved = CC_CALLBACK_2(MainScene::onTouchMoved, this);
	touchListener->onTouchCancelled = CC_CALLBACK_2(MainScene::onTouchCancelled, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);

	playButton = static_cast<ui::Button*>(rootNode->getChildByName("playButton"));
	playButton->addTouchEventListener(CC_CALLBACK_2(MainScene::startButtonPressed, this));
	playButton->setPosition(Vec2(winSize.width / 2, winSize.height / 2));

	return true;
}

void MainScene::startButtonPressed(Ref *pSender, cocos2d::ui::Widget::TouchEventType type)
{
	CCLOG("In touch! %d", type);

	if (type == cocos2d::ui::Widget::TouchEventType::ENDED)
	{
		this->playGame();
	}
}

void mainScene::playGame()
{
	auto winSize = Director::getInstance()->getVisibleSize();
	auto audio = SimpleAudioEngine::getInstance();

	//set background centre screen
	background1->setPosition(winSize.width / 2, winSize.height / 2);
	background2->setPosition(-winSize.width / 2, -winSize.height / 2);

	//Transition with fade 
	Director::getInstance()->replaceScene(TransitionFade::create(0.5, HelloWorld, Color3B(0, 255, 255)));
}

//Touch functions ---------------------------------------
bool HelloWorld::onTouchBegin(Touch* touch, Event* event)
{
	cocos2d::log("touch began");
	return true;
}

void HelloWorld::onTouchEnded(Touch* touch, Event* event)
{
	cocos2d::log("touch ended");
}

void HelloWorld::onTouchMoved(Touch* touch, Event* event)
{

	cocos2d::log("touch moved");
	if (GameManager::sharedGameManager()->isGameLive)
	{
		touchLocation = touch->getLocation();
	}
}

void HelloWorld::onTouchCancelled(Touch* touch, Event* event)
{
	cocos2d::log("touch cancelled");
}
