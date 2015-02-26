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

	//添加回调响应函数
	void menuItemFont2Func(CCObject* sender); //更改标签内容
	void menuItemToggleFunc(CCObject* sender); //更改状态:正常,选中,禁用

};

#endif // __HELLOWORLD_SCENE_H__
