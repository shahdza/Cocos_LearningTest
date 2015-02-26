#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
using namespace cocos2d;

#include "cocos-ext.h"
using namespace cocos2d::extension;


class HelloWorld : public cocos2d::CCLayer
{
public:
    virtual bool init();  
    static cocos2d::CCScene* scene();
    void menuCloseCallback(CCObject* pSender);
    CREATE_FUNC(HelloWorld);

	CCLabelTTF* label; //显示滑块数值的Label
	void valueChanged(CCObject* sender, CCControlEvent controlEvent); //当值改变时触发的控件事件
};

#endif // __HELLOWORLD_SCENE_H__
