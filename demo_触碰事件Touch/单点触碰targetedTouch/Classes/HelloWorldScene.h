#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

using namespace cocos2d;


class HelloWorld : public cocos2d::CCLayer
{
public:
    virtual bool init();  
    static cocos2d::CCScene* scene();
    void menuCloseCallback(CCObject* pSender);
    CREATE_FUNC(HelloWorld);

	//触屏事件
	virtual bool ccTouchBegan(CCTouch* touch,CCEvent* event);
	virtual void ccTouchMoved(CCTouch* touch,CCEvent* event);
	virtual void ccTouchEnded(CCTouch* touch,CCEvent* event);

	//生命周期
	virtual void onEnter();
	virtual void onExit();
};

#endif // __HELLOWORLD_SCENE_H__
