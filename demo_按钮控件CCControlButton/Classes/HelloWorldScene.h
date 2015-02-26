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


	CCLabelTTF* displayLabel; //显示按钮状态的label
	void touchDownAction(CCObject* sender, CCControlEvent controlEvent); //刚刚开始触摸按钮时
	void touchDragInsideAction(CCObject* sender, CCControlEvent controlEvent); //在内部拖动时（保持触摸状态下）
	void touchDragOutsideAction(CCObject* sender, CCControlEvent controlEvent); //在外部拖动时（保持触摸状态下）
	void touchDragEnterAction(CCObject* sender, CCControlEvent controlEvent); //拖动刚进入内部时（保持触摸状态下）
	void touchDragExitAction(CCObject* sender, CCControlEvent controlEvent); //拖动刚离开内部时（保持触摸状态下）
	void touchUpInsideAction(CCObject* sender, CCControlEvent controlEvent); //在内部抬起手指（保持触摸状态下）
	void touchUpOutsideAction(CCObject* sender, CCControlEvent controlEvent); //在外部抬起手指（保持触摸状态下）
	void touchCancelAction(CCObject* sender, CCControlEvent controlEvent); //取消触点

};

#endif // __HELLOWORLD_SCENE_H__
