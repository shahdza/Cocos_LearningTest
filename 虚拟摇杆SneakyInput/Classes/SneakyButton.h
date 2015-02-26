#ifndef __SNEAKY_BUTTON_H__
#define __SNEAKY_BUTTON_H__

#include "cocos2d.h"

class SneakyButton : public cocos2d::CCNode, public cocos2d::CCTargetedTouchDelegate
{
protected:
	virtual void onEnterTransitionDidFinish();
	virtual void onExit();

//////////////////////////////////////////////////////////////////////////

	cocos2d::CCPoint center;
	float radiusSq;

	cocos2d::CCRect bounds;

	CC_SYNTHESIZE(bool, status, Status);
	CC_SYNTHESIZE_READONLY(bool, active, IsActive);
	CC_SYNTHESIZE_READONLY(bool, value, Value);
	CC_SYNTHESIZE(bool, isHoldable, IsHoldable);
	CC_SYNTHESIZE(bool, isToggleable, IsToggleable);
	CC_SYNTHESIZE(float, rateLimit, RateLimit);

	CC_SYNTHESIZE_READONLY(float, radius, Radius);


	bool initWithRect(cocos2d::CCRect rect);
	void limiter(float delta);
	void setRadius(float r);

	virtual bool ccTouchBegan(cocos2d::CCTouch *touch, cocos2d::CCEvent *event);
	virtual void ccTouchMoved(cocos2d::CCTouch *touch, cocos2d::CCEvent *event);
	virtual void ccTouchEnded(cocos2d::CCTouch *touch, cocos2d::CCEvent *event);
	virtual void ccTouchCancelled(cocos2d::CCTouch *touch, cocos2d::CCEvent *event);

	void touchDelegateRelease();
	void touchDelegateRetain();
};

#endif