#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
using namespace cocos2d;

#include "cocos-ext.h"
using namespace cocos2d::extension;


class HelloWorld : public cocos2d::CCLayer,public CCTableViewDataSource, public CCTableViewDelegate
{
public:
	virtual bool init();  
	static cocos2d::CCScene* scene();
	CREATE_FUNC(HelloWorld);


	//继承于CCTableViewDataSource
	virtual CCSize tableCellSizeForIndex(CCTableView* table, unsigned int idx);      //根据idx来设置每项cell的尺寸大小
	virtual CCTableViewCell* tableCellAtIndex(CCTableView* table, unsigned int idx); //获取编号为idx的cell
	virtual unsigned int numberOfCellsInTableView(CCTableView* table);               //一共多少项cell

	//继承于CCTableViewDelegate
	virtual void tableCellTouched(CCTableView* table, CCTableViewCell* cell);        //某项cell被点击时回调函数
	virtual void scrollViewDidScroll(cocos2d::extension::CCScrollView* view);        //滚动时回调函数
	virtual void scrollViewDidZoom(cocos2d::extension::CCScrollView* view);          //放缩时回调函数
};

#endif // __HELLOWORLD_SCENE_H__
