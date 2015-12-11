#ifndef __MAIN_SCENE_H__
#define __MAIN_SCENE_H__

#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include "ui/CocosGUI.h"
#include "GameManager.h"

using namespace cocos2d;
using namespace cocos2d::ui;
using namespace CocosDenshion;

class MainScene : public cocos2d::Layer
{
public:
	
	static cocos2d::Scene* createScene();

	virtual bool init();

	CREATE_FUNC(MainScene);

	void update(float delta);

	virtual bool onTouchBegin(cocos2d::Touch*, cocos2d::Event*);
	virtual void onTouchEnded(cocos2d::Touch*, cocos2d::Event*);
	virtual void onTouchMoved(cocos2d::Touch*, cocos2d::Event*);
	virtual void onTouchCancelled(cocos2d::Touch*, cocos2d::Event*);

	void startButtonPressed(Ref *sender, cocos2d::ui::Widget::TouchEventType type);

	void playGame();

private:
	Button* startButton;
	Sprite* background1;
	Sprite* background2;
	Vec2 touchLocation;
};

#endif 