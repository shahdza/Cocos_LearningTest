#include "HelloWorldScene.h"

USING_NS_CC;

CCScene* HelloWorld::scene()
{
    CCScene *scene = CCScene::create();
    HelloWorld *layer = HelloWorld::create();
    scene->addChild(layer);
    return scene;
}


bool HelloWorld::init()
{
    if ( !CCLayer::init() )
    {
        return false;
    }

	CCSize mysize = CCDirector::sharedDirector()->getVisibleSize();


//横向CCTableView
	CCTableView* tableView1 = CCTableView::create(this, CCSizeMake(250, 60));
	tableView1->setPosition(ccp(20, mysize.height/2 - 30));
	this->addChild(tableView1);

	//属性设置
	tableView1->setBounceable(false);							//关闭弹性效果
	tableView1->setDirection(kCCScrollViewDirectionHorizontal); //横向
	tableView1->setDelegate(this);								//委托代理
	tableView1->reloadData();									//加载数据


//纵向CCTableView
	CCTableView* tableView2 = CCTableView::create(this, CCSizeMake(60, 250));
	tableView2->setPosition(ccp(mysize.width - 150, mysize.height/2 - 120));
	this->addChild(tableView2);

	//属性设置
	tableView2->setDirection(kCCScrollViewDirectionVertical);	//纵向
	tableView2->setVerticalFillOrder(kCCTableViewFillTopDown);	//从小到大排列
	tableView2->setDelegate(this);								//委托代理
	tableView2->reloadData();									//加载数据


	return true;
}


//获取编号为idx的cell
CCTableViewCell* HelloWorld::tableCellAtIndex(CCTableView* table, unsigned int idx)
{
	char Icon[20];   //根据idx选中显示的图片
	char number[10]; //显示label标签的数字
	sprintf(Icon, "sp%d.png", idx%3 + 1);
	sprintf(number, "%02d", idx);

	//也可以用cell = table->cellAtIndex(idx);
	CCTableViewCell* cell = table->dequeueCell();
	
	if(!cell) 
	{
		cell = new CCTableViewCell();
		cell->autorelease(); //自动释放资源

		//添加一个精灵图片
		CCSprite* sprite = CCSprite::create(Icon);
		sprite->setAnchorPoint(CCPointZero);
		sprite->setPosition(ccp(0, 0));
		cell->addChild(sprite, 0, 1);

		//添加一个label标签
		CCLabelTTF* label = CCLabelTTF::create(number, "Arial", 20);
		label->setPosition(CCPointZero);
		label->setAnchorPoint(CCPointZero);
		cell->addChild(label, 0, 2);
	}
	else
	{
		//更换精灵图片，使用纹理
		CCTexture2D* texture = CCTextureCache::sharedTextureCache()->addImage(Icon);
		CCSprite* sprite = (CCSprite*)cell->getChildByTag(1);
		sprite->setTexture(texture);

		//更改图片编号
		CCLabelTTF* label = (CCLabelTTF*)cell->getChildByTag(2);
		label->setString(number);
	}

	return cell;
}


//根据idx来设置每项cell的尺寸大小
CCSize HelloWorld::tableCellSizeForIndex(CCTableView* table, unsigned int idx)
{
	if(idx == 2) return CCSizeMake(100,100);
	return CCSizeMake(60,60);
}


//一共多少项cell
unsigned int HelloWorld::numberOfCellsInTableView(CCTableView* table)
{
	return 10;
}


//某项cell被点击时回调函数
void HelloWorld::tableCellTouched(CCTableView* table, CCTableViewCell* cell)
{
	CCLOG("cell touched at index: %i", cell->getIdx()); //控制台输出
}


void HelloWorld::scrollViewDidScroll(cocos2d::extension::CCScrollView* view) { } //滚动时回调函数
void HelloWorld::scrollViewDidZoom(cocos2d::extension::CCScrollView* view) { }   //放缩时回调函数

