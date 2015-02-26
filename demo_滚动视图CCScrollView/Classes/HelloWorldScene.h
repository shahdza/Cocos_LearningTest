#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
using namespace cocos2d;

#include "cocos-ext.h"
using namespace cocos2d::extension;


class HelloWorld : public cocos2d::CCLayer,public CCScrollViewDelegate
{
public:
	virtual bool init();  
	static cocos2d::CCScene* scene();
	void menuCloseCallback(CCObject* pSender);
	CREATE_FUNC(HelloWorld);

	void test1(); //测试图片滚动
	void test2(); //测试只能纵向滚动
	void test3(); //测试背包翻页

	int pageNumber; //背包第几页
	CCMenuItemImage* pBack; //往前翻页
	CCMenuItemImage* pFront; //往后翻页
	void scrollImage(CCObject* sender); //test3的背包翻页

	void scrollViewDidScroll(CCScrollView* view); //滚动时响应的回调函数
	void scrollViewDidZoom(CCScrollView* view); //放缩时响应的回调函数
};

#endif // __HELLOWORLD_SCENE_H__
