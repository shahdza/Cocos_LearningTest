#include "Sneaky.h"

Sneaky::Sneaky()
{
//加载摇杆按钮
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("UI.plist", "UI.png");

//摇杆
	joystick = NULL;
	joystick = new SneakyJoystick();
	joystick->initWithRect(CCRectZero); // 用原点初始化
	joystick->setAutoCenter(true); //是否自动回到中心
	joystick->setHasDeadzone(true);  //设置支持无效区域，中心半径为R的区域内不会触发
	joystick->setDeadRadius(10); // 设置中心半径10的为无效区域

	SneakyJoystickSkinnedBase* jstickSkin = new SneakyJoystickSkinnedBase();
	jstickSkin->autorelease();
	jstickSkin->init();
	
	//-- need modify start --
	jstickSkin->setBackgroundSprite(CCSprite::createWithSpriteFrameName("JoyStick-base.png")); //底座
	jstickSkin->setThumbSprite(CCSprite::createWithSpriteFrameName("JoyStick-thumb.png")); //遥控杆
	jstickSkin->setPosition(ccp(jstickSkin->getContentSize().width/2, jstickSkin->getContentSize().height/2));
	//-- need modify end --

	jstickSkin->setJoystick(joystick);
	this->addChild(jstickSkin);


//按钮A
	buttonA = NULL;
	buttonA = new SneakyButton();
	buttonA->initWithRect(CCRectZero);
	buttonA->setIsToggleable(false);
	buttonA->setIsHoldable(true); //设置在按下时，是否保持按下状态

	SneakyButtonSkinnedBase* buttonASkin = new SneakyButtonSkinnedBase();
	buttonASkin->autorelease();
	buttonASkin->init();

	//-- need modify start --
	buttonASkin->setDefaultSprite(CCSprite::createWithSpriteFrameName("button-default.png")); //默认图片
	buttonASkin->setPressSprite(CCSprite::createWithSpriteFrameName("button-pressed.png")); //按下图片
	buttonASkin->setActivatedSprite(CCSprite::createWithSpriteFrameName("button-activated.png")); //激活图片
	//buttonASkin->setDisabledSprite(CCSprite::createWithSpriteFrameName("button-disabled.png")); //失效图片
	buttonASkin->setPosition(ccp(480 - buttonASkin->getContentSize().width/2, buttonASkin->getContentSize().height/2) );
	//-- need modify end --

	buttonASkin->setButton(buttonA);
	this->addChild(buttonASkin);


	init();
}

bool Sneaky::init()
{
	CCLayer::init();
	return true;
}


//void HudLayer::inputUpdate(float dt)
//{
//
//}