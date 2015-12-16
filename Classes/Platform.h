#include "cocos2d.h"  

using namespace cocos2d;

//-------------End--------------

//class ------------------------

class Platform : public Node
{
	public:
		Platform();
		~Platform();

		virtual bool init() override;
		static Platform* create();
		void update(float deltaTime);
		void reset(Sprite* platform);
		void startPos();
		bool Collision(Sprite* ball);

		float	platformSpeed;

private:
	
	//Platform Sprites
	Sprite* platform1;
	Sprite* platform2;
	Sprite* platform3;

	Vec2 startPosition_right;
	Vec2 startPosition_middle;
	Vec2 startPosition_left;

	
};

