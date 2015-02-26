#ifndef __SNEAKY_JOYSTICK_H__
#define __SNEAKY_JOYSTICK_H__

#include "cocos2d.h"

class SneakyJoystick : public cocos2d::CCNode, public cocos2d::CCTargetedTouchDelegate 
{
protected:
	virtual ~SneakyJoystick();
	virtual void onEnterTransitionDidFinish();
	virtual void onExit();

//////////////////////////////////////////////////////////////////////////
	
	float joystickRadiusSq;
	float thumbRadiusSq;
	float deadRadiusSq;

	CC_SYNTHESIZE_READONLY(cocos2d::CCPoint, stickPosition, StickPosition);
	CC_SYNTHESIZE_READONLY(float, degrees, Degrees);
	CC_SYNTHESIZE_READONLY(cocos2d::CCPoint, velocity, Velocity);
	CC_SYNTHESIZE(bool, autoCenter, AutoCenter);
	CC_SYNTHESIZE_READONLY(bool, isDPad, IsDPad);
	CC_SYNTHESIZE(bool, hasDeadzone, HasDeadzone);
	CC_SYNTHESIZE(int, numberOfDirections, NumberOfDirections);

	CC_SYNTHESIZE_READONLY(float, joystickRadius, JoystickRadius);
	CC_SYNTHESIZE_READONLY(float, thumbRadius, ThumbRadius);
	CC_SYNTHESIZE_READONLY(float, deadRadius, DeadRadius);

	bool initWithRect(cocos2d::CCRect rect);
	void setIsDPad(bool b);
	void setJoystickRadius(float r);
	void setThumbRadius(float r);
	void setDeadRadius(float r);

	virtual bool ccTouchBegan(cocos2d::CCTouch *touch, cocos2d::CCEvent *event);
	virtual void ccTouchMoved(cocos2d::CCTouch *touch, cocos2d::CCEvent *event);
	virtual void ccTouchEnded(cocos2d::CCTouch *touch, cocos2d::CCEvent *event);
	virtual void ccTouchCancelled(cocos2d::CCTouch *touch, cocos2d::CCEvent *event);

	void touchDelegateRelease();
	void touchDelegateRetain();

private:
	void updateVelocity(cocos2d::CCPoint point);
	void setTouchRadius();

};

#endif //__SNEAKY_JOYSTICK_H__
