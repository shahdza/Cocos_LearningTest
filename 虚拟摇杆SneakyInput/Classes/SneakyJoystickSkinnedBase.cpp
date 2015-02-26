#include "SneakyJoystickSkinnedBase.h"

using namespace cocos2d;


//////////////////////////////////////////////////////////////////////////


SneakyJoystickSkinnedBase::~SneakyJoystickSkinnedBase()
{
	if (backgroundSprite)
	{
		backgroundSprite->release();
		backgroundSprite = NULL;
	}
	if (thumbSprite)
	{
		thumbSprite->release();
		thumbSprite = NULL;
	}

	if (joystick)
	{
		joystick->release();
		joystick = NULL;
	}
}

bool SneakyJoystickSkinnedBase::init()
{
	bool pRet = false;
	if(CCLayer::init()){
		this->backgroundSprite = NULL;

		this->thumbSprite = NULL;

		this->joystick = NULL;

		this->schedule(schedule_selector(SneakyJoystickSkinnedBase::updatePositions));
		pRet = true;
	}
	return pRet;	
}

void SneakyJoystickSkinnedBase::updatePositions(float delta)
{
	if(joystick && thumbSprite)
		thumbSprite->setPosition(joystick->getStickPosition());
}

void SneakyJoystickSkinnedBase::setContentSize(CCSize s)
{
	CCLayer::setContentSize(s);
	////////backgroundSprite->setContentSize(s);
	//joystick.joystickRadius = s.width/2;
}

void SneakyJoystickSkinnedBase::setBackgroundSprite(CCSprite *aSprite)
{
	if(backgroundSprite){
		if(backgroundSprite->getParent())
			backgroundSprite->getParent()->removeChild(backgroundSprite, true);
		backgroundSprite->release();
	}
	aSprite->retain();
	backgroundSprite = aSprite;
	if(aSprite){
		this->addChild(backgroundSprite, 0);
		
		this->setContentSize(backgroundSprite->getContentSize());
	}
}

void SneakyJoystickSkinnedBase::setThumbSprite(CCSprite *aSprite)
{
	if(thumbSprite){
		if(thumbSprite->getParent())
			thumbSprite->getParent()->removeChild(thumbSprite, true);
		thumbSprite->release();
	}
	aSprite->retain();
	thumbSprite = aSprite;
	if(aSprite){
		this->addChild(thumbSprite, 1);
		
		//joystick->setThumbRadius(thumbSprite->getContentSize().width/2);
	}
}

void SneakyJoystickSkinnedBase::setJoystick(SneakyJoystick *aJoystick)
{
	if(joystick){
		if(joystick->getParent())
			joystick->getParent()->removeChild(joystick, true);
		joystick->release();
	}
	aJoystick->retain();
	joystick = aJoystick;
	if(aJoystick){
		this->addChild(aJoystick, 2);
		if(thumbSprite)
			joystick->setThumbRadius(thumbSprite->boundingBox().size.width/2);
		else
			joystick->setThumbRadius(0);
		
		if(backgroundSprite)
			joystick->setJoystickRadius(backgroundSprite->boundingBox().size.width/2);
	}
}