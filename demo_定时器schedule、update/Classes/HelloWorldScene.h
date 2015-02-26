#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

class HelloWorld : public cocos2d::CCLayer
{
public:
    virtual bool init();  
    static cocos2d::CCScene* scene();
    void menuCloseCallback(CCObject* pSender);
    CREATE_FUNC(HelloWorld);

	void update(float dt); //scheduleUpdate
	void myupdate(float dt); //schedule(schedule_selector)
	void myupdate2(float dt); //schedule(schedule_selector, interval)
	void myupdate3(float dt); //schedule(schedule_selector, interval, repeat, delay)
	void myupdate4(float dt); //scheduleOnce
};

#endif // __HELLOWORLD_SCENE_H__
