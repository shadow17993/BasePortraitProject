#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

#define COCOS2D_DEBUG 1


USING_NS_CC;

using namespace std;
using namespace cocostudio::timeline;
// This is a test comment
Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

	auto rootNode = CSLoader::createNode("MainScene.csb");
	auto winSize = Director::getInstance()->getVisibleSize();

	addChild(rootNode);

	this->scheduleUpdate();

	speedcount = 0;
	timer = 0;

	ball = (Sprite*)rootNode->getChildByName("ball");

	timerText = (TextField*)rootNode->getChildByName("TimerText");

	platforms = (Platform*)rootNode->getChildByName("Platforms");
	platforms = Platform::create();
	this->addChild(platforms);

	

	background1 = (Sprite*)rootNode->getChildByName("background");
	background2 = (Sprite*)rootNode->getChildByName("background2");

	//---------------------------
	// Touch Listener
	//---------------------------

	auto touchListener = EventListenerTouchOneByOne::create();

	touchListener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);
	touchListener->onTouchEnded = CC_CALLBACK_2(HelloWorld::onTouchEnded, this);
	touchListener->onTouchMoved = CC_CALLBACK_2(HelloWorld::onTouchMoved, this);
	touchListener->onTouchCancelled = CC_CALLBACK_2(HelloWorld::onTouchCancelled, this);

	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);

	startButton = static_cast<ui::Button*>(rootNode->getChildByName("startButton"));
	startButton->addTouchEventListener(CC_CALLBACK_2(HelloWorld::startButtonPressed, this));
	startButton->setPosition(Vec2(winSize.width*0.5f, winSize.height*0.5f));

	GameManager::sharedGameManager()->isGameLive = false;

    return true;
}

void HelloWorld::update(float delta)
{
	auto winSize = Director::getInstance()->getVisibleSize();

	
	if (GameManager::sharedGameManager()->isGameLive)
	{

		//------------------------------------------//
		//				BALL MOVEMENT				//
		//------------------------------------------//

		Vec2 v = touchLocation - ball->getPosition();
		float l = v.length();
		v.x = v.x / l;
		v.y = v.y / l;
		ball->setPosition(ball->getPosition() - v * 3);

		if (ball->getPosition().x > winSize.width
			|| ball->getPosition().x < 0
			|| ball->getPosition().y > winSize.height
			|| ball->getPosition().y < 0)
		{
			this->EndGame();
		}


		

		//------------------------------------------//
		//			   PLATFORM COLLISION			//
		//------------------------------------------//

		if (platforms->Collision(ball->getBoundingBox()))
		{
			this->EndGame();
		}

		

		timercount++;
		if (timercount >= 60)
		{
			timer++;
			speedcount++;
			timercount = 0;
			if (speedcount >= 10)
			{
				platforms->platformSpeed = platforms->platformSpeed + 0.8f;
				speedcount = 0;
			}
		}

		timerText->setString(to_string(timer));

		//------------------------------------------//
		//			  BACKGROUND MOVEMENT			//
		//------------------------------------------//

		background1->setPosition(winSize.width / 2, background1->getPositionY() + 1.5f);
		if (background1->getPositionY() >= winSize.height * 1.5)
		{
			background1->setPosition(0, -winSize.height / 2);
		}

		background2->setPosition(winSize.width / 2, background2->getPositionY() + 1.5f);
		if (background2->getPositionY() >= winSize.height * 1.5)
		{
			background2->setPosition(0, -winSize.height / 2);
		}
	}
}

//------------------------------------------------------------------------

void HelloWorld::startButtonPressed(Ref *pSender, cocos2d::ui::Widget::TouchEventType type)
{
	CCLOG("In touch! %d", type);

	if (type == cocos2d::ui::Widget::TouchEventType::ENDED)
	{
		this->StartGame();
	}
}

//-------------------------------------------------------------------------

void HelloWorld::StartGame()
{
	auto winSize = Director::getInstance()->getVisibleSize();
	auto audio = SimpleAudioEngine::getInstance();

	GameManager::sharedGameManager()->isGameLive = true;

	ball->setPosition(winSize.width / 2, winSize.height*0.7f);

	audio->playBackgroundMusic("MechaMalfunction.wav", true);

	// Reset the score.
	GameManager::sharedGameManager()->ResetScore();

	platforms->startPos();

	

	timer = 0;
	timercount = 0;
	platforms->platformSpeed = 3.0;
	speedcount = 0;
	
	background1->setPosition(winSize.width / 2, winSize.height / 2);
	background2->setPosition(-winSize.width / 2, -winSize.height / 2);

	//Retract start button.
	auto moveTo = MoveTo::create(0.5, Vec2(-winSize.width*0.5f, winSize.height*0.5f)); // Take half a second to move off screen.
	startButton->runAction(moveTo);
}

//-------------------------------------------------------------------------

void HelloWorld::EndGame()
{
	auto audio = SimpleAudioEngine::getInstance();
	audio->setEffectsVolume(0.25f);
	audio->playEffect("Explosion.wav", false, 0.25f, 0.25f, 0.25f);
	
	audio->stopBackgroundMusic(true);

	auto winSize = Director::getInstance()->getVisibleSize();

	GameManager::sharedGameManager()->isGameLive = false;

	//Bring start button back on screen.
	auto moveTo = MoveTo::create(0.5, Vec2(winSize.width*0.5f, winSize.height*0.5f)); // Take half a second to move on screen.
	startButton->runAction(moveTo);
}

//-------------------------------------------------------------------------

bool HelloWorld::onTouchBegin(Touch* touch, Event* event)
{
	cocos2d::log("touch began");
	return true;
}

//-------------------------------------------------------------------------

void HelloWorld::onTouchEnded(Touch* touch, Event* event)
{
	cocos2d::log("touch ended");
}

//-------------------------------------------------------------------------

void HelloWorld::onTouchMoved(Touch* touch, Event* event)
{
	
	cocos2d::log("touch moved");
	if (GameManager::sharedGameManager()->isGameLive)
	{
		touchLocation = touch->getLocation();
	}
}

//-------------------------------------------------------------------------

void HelloWorld::onTouchCancelled(Touch* touch, Event* event)
{
	cocos2d::log("touch cancelled");
}

//-------------------------------------------------------------------------

