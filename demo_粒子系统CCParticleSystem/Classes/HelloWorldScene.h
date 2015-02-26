#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
using namespace cocos2d;


class HelloWorld : public cocos2d::CCLayer,cocos2d::CCTouchDelegate
{
public:
	virtual bool init();  
	static cocos2d::CCScene* scene();
	CREATE_FUNC(HelloWorld);


	void testGravity();  //重力发射器模式
	void testRadius();   //半径发射器模式
	void testParticle(); //现成粒子特效 
	void testPlist();    //自定义plist粒子特效


	virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
	virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
	virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);
	virtual void onEnter();
	virtual void onExit();
};

#endif // __HELLOWORLD_SCENE_H__
