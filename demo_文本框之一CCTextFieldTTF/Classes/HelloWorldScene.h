#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
using namespace cocos2d;


class HelloWorld : public cocos2d::CCLayer,cocos2d::CCTextFieldDelegate
{
public:
    virtual bool init();  
    static cocos2d::CCScene* scene();
    void menuCloseCallback(CCObject* pSender);
    CREATE_FUNC(HelloWorld);

	virtual bool onTextFieldAttachWithIME(CCTextFieldTTF* sender); //当用户启动虚拟键盘的时候的回调函数
	virtual bool onTextFieldDetachWithIME(CCTextFieldTTF* sender); //当用户关闭虚拟键盘的时候的回调函数
	virtual bool onTextFieldInsertText(CCTextFieldTTF* sender, const char* text, int nLen); //当用户输入的时候的回调函数
	virtual bool onTextFieldDeleteBackward(CCTextFieldTTF* sender, const char* delText, int nLen); //当用户删除文字的时候的回调函数

	//开启触控
	virtual bool ccTouchBegan(CCTouch* touch, CCEvent* event);
	virtual void ccTouchMoved(CCTouch* touch, CCEvent* event);
	virtual void ccTouchEnded(CCTouch* touch, CCEvent* event);
	virtual void onEnter();
	virtual void onExit();
};

#endif // __HELLOWORLD_SCENE_H__
