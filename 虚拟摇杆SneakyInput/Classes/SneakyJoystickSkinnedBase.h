#ifndef __JOYSTICK_SKINNED_H__
#define __JOYSTICK_SKINNED_H__

#include "cocos2d.h"
#include "SneakyJoystick.h"

class SneakyJoystickSkinnedBase : public cocos2d::CCLayer
{

	CREATE_FUNC(SneakyJoystickSkinnedBase);
	virtual ~SneakyJoystickSkinnedBase();

//////////////////////////////////////////////////////////////////////////

	CC_SYNTHESIZE_READONLY(cocos2d::CCSprite *, backgroundSprite, BackgroundSprite);
	CC_SYNTHESIZE_READONLY(cocos2d::CCSprite *, thumbSprite, ThumbSprite);
	CC_SYNTHESIZE_READONLY(SneakyJoystick *, joystick, Joystick);	

	bool init();
	void updatePositions(float delta);
	void setContentSize(cocos2d::CCSize s);
	void setBackgroundSprite(cocos2d::CCSprite *aSprite);
	void setThumbSprite(cocos2d::CCSprite *aSprite);
	void setJoystick(SneakyJoystick *aJoystick);
};

#endif //__JOYSTICK_SKINNED_H__
