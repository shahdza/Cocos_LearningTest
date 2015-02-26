#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
using namespace cocos2d;

#include "cocos-ext.h"
using namespace cocos2d::extension;

class HelloWorld : public cocos2d::CCLayer,CCEditBoxDelegate
{
public:
    virtual bool init();  
    static cocos2d::CCScene* scene();
    void menuCloseCallback(CCObject* pSender);
    CREATE_FUNC(HelloWorld);
	
	virtual void editBoxEditingDidBegin(CCEditBox* editBox); //开始编辑
	virtual void editBoxEditingDidEnd(CCEditBox* editBox); //结束编辑
	virtual void editBoxTextChanged(CCEditBox* editBox, const std::string& text); //编辑框文字改变
	virtual void editBoxReturn(CCEditBox* editBox); //触发return后的回调函数
};

#endif // __HELLOWORLD_SCENE_H__
