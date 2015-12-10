//Platform.cpp



//includes ---------
#include "Platform.h"
#include "cocostudio/CocoStudio.h"
#include "GameManager.h"

using namespace cocos2d;

//----------------End------------------

//--------------------------------------------------Methods Start-----------------------------------------------------------

//create/delete object method ----------------
Platform* Platform::create()
{
	Platform* myNode = new Platform();
	if (myNode->init())
	{
		myNode->autorelease();
		return myNode;
	}
	else
	{
		CC_SAFE_DELETE(myNode);
		return nullptr;
	}
	return myNode;
}
//----------------End------------------

//init ---------------
bool Platform::init()
{
	if (!Node::init())
	{
		return false;
	}

	//load platform object
	auto rootNode = CSLoader::createNode("Platform.csb");//add other platform sprite files if needed
	addChild(rootNode);

	//Position this container at left,centre. Anchor point should also be (0.0f, 0.5f).
	auto winSize = Director::getInstance()->getVisibleSize();
	this->setPosition(Vec2(0.0f, 0.0f));//add size of platform sprite
	this->setAnchorPoint(Vec2(0.0f, 0.0f));
	this->scheduleUpdate();

	//sprites 
	platform1 = (Sprite*)rootNode->getChildByName("Platform1");
	platform2 = (Sprite*)rootNode->getChildByName("Platform2");
	platform3 = (Sprite*)rootNode->getChildByName("Platform3");

	//starting position
	startPosition_left = Vec2(platform1->getBoundingBox().size.width / 2, -winSize.height * 0.33); //sets Y position to the minus of 1/3 of the screen height
	startPosition_middle = Vec2(winSize.width / 2, -winSize.height * 0.99); //sets Y position to the minus of the screen height
	startPosition_right = Vec2(winSize.width - (platform3->getBoundingBox().size.width / 2), -winSize.height * 0.66);//sets Y position to 2/3 of the screen height
	
	//Set platform speed
	platformSpeed = 3.0f;

	return true;
}
//----------------End------------------

//Update -----------------
void Platform::update(float deltaTime)
{
	if (GameManager::sharedGameManager()->isGameLive)
	{
		//Get the window size
		auto  winSize = Director::getInstance()->getVisibleSize();

		platform1->setPosition(platform1->getPosition().x, platform1->getPosition().y + platformSpeed);
		if (platform1->getPosition().y >= winSize.height + 10)
		{
			platform1->setPosition(rand_0_1() * winSize.width, -10);
			while (platform1->getPosition().x > winSize.width - (platform1->getBoundingBox().size.width / 2)
				|| platform1->getPosition().x < platform1->getBoundingBox().size.width / 2)
			{
				reset(platform1);
			}
		}

		platform2->setPosition(platform2->getPosition().x, platform2->getPosition().y + platformSpeed);
		if (platform2->getPosition().y >= winSize.height + 10)
		{
			platform2->setPosition(rand_0_1() * winSize.width, -10);
			while (platform2->getPosition().x > winSize.width - (platform2->getBoundingBox().size.width / 2)
				|| platform2->getPosition().x < platform2->getBoundingBox().size.width / 2)
			{
				reset(platform2);
			}
		}

		platform3->setPosition(platform3->getPosition().x, platform3->getPosition().y + platformSpeed);
		if (platform3->getPosition().y >= winSize.height + 10)
		{
			platform3->setPosition(rand_0_1() * winSize.width, -10);
			while (platform3->getPosition().x > winSize.width - (platform3->getBoundingBox().size.width / 2)
				|| platform3->getPosition().x < platform3->getBoundingBox().size.width / 2)
			{
				reset(platform3);
			}
		}
	}
}
//----------------End------------------


Platform::Platform()
{
	
}

Platform::~Platform()
{
	
}

void Platform::startPos()
{
	platform1->setPosition(startPosition_left);
	platform2->setPosition(startPosition_middle);
	platform3->setPosition(startPosition_right);
}


//loop/reset method ------------------
void Platform::reset(Sprite* platform)
{
	auto  winSize = Director::getInstance()->getVisibleSize();

	platform->setPosition(rand_0_1() * winSize.width, -10);
}

bool Platform::Collision(Rect colliderBox)
{
	if (platform1->getBoundingBox().intersectsRect(colliderBox)
		|| platform2->getBoundingBox().intersectsRect(colliderBox)
		|| platform3->getBoundingBox().intersectsRect(colliderBox))
	{
		return true;
	}
	return false;
}
//----------------End------------------

//------------------------------------------------------END--------------------------------------------------------------------