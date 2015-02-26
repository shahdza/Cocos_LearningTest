#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
using namespace cocos2d;


class HelloWorld : public cocos2d::CCLayer
{
public:
	virtual bool init();  
	static cocos2d::CCScene* scene();
	CREATE_FUNC(HelloWorld);

	void test1(); //使用图片资源
	void test2(); //使用精灵帧
	void test3(); //使用动画帧
};

#endif // __HELLOWORLD_SCENE_H__
