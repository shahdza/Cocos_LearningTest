#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
using namespace cocos2d;

#include "cocos-ext.h"
using namespace cocos2d::extension;

#include "SimpleAudioEngine.h"
using namespace CocosDenshion;

class HelloWorld : public cocos2d::CCLayer
{
public:
	virtual bool init();  
	static cocos2d::CCScene* scene();
	CREATE_FUNC(HelloWorld);


	unsigned int m_soundID; //音效编号ID
	void menuCallback(CCObject* sender); //菜单按钮回调函数
};

#endif // __HELLOWORLD_SCENE_H__
