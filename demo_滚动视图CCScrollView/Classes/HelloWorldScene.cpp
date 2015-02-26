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

	test1(); //测试图片滚动
	//test2(); //测试只能纵向滚动
	//test3(); //测试背包翻页

	return true;
}


//测试图片滚动
void HelloWorld::test1()
{
	CCSize visableSize = CCSizeMake(480, 320); //屏幕大小
	CCSize mysize = CCSizeMake(960,600); //容器大小

	
//创建容器、设置大小
	CCLayerColor* scrollLayer = CCLayerColor::create( ccc4(255,255,255,255) );
	scrollLayer->setContentSize(mysize);
	
//容器中的东西
	CCSprite* bg = CCSprite::create("war.png");
	bg->setPosition( ccp(960/2.0, 600/2.0) );
	scrollLayer->addChild(bg);


//创建滚动视图CCScrollView
	CCScrollView* scrollView = CCScrollView::create();
	this->addChild(scrollView, 0, 1);
	
	//属性设置
	scrollView->setContainer(scrollLayer); //设置容器
	scrollView->setViewSize( visableSize ); //可视区域大小
	scrollView->setBounceable(true); //是否具有弹性
	
	//委托代理
	scrollView->setDelegate(this);
}


//测试只能纵向滚动
void HelloWorld::test2()
{
	CCSize visableSize = CCSizeMake(480, 320); //屏幕大小
	CCSize mysize = CCSizeMake(150,220); //容器大小

//创建容器、设置大小
	CCLayerColor* scrollLayer = CCLayerColor::create( ccc4(255,255,255,255) );
	scrollLayer->setContentSize(mysize);

//容器中添加四个按钮
	for(int i = 1; i <= 4; i++) 
	{
		char file[20];
		sprintf(file, "btn%d.png", i);
		CCSprite* btn = CCSprite::create(file);
		btn->setPosition( ccp(mysize.width/2, 220 - 50*i) );
		scrollLayer->addChild(btn);
	}

//创建滚动视图CCScrollView
	//可视区域大小150*100 、 容器为scrollLayer
	CCScrollView* scrollView = CCScrollView::create(CCSizeMake(150, 100), scrollLayer);
	scrollView->setPosition( visableSize/2 - ccp(150/2.0, 100/2.0) );
	this->addChild(scrollView, 0, 2);
	
	//设置为只能纵向滚动
	scrollView->setDirection(kCCScrollViewDirectionVertical);

	//委托代理
	scrollView->setDelegate(this);

}

//测试背包翻页
void HelloWorld::test3()
{
	CCSize visableSize = CCSizeMake(480, 320); //屏幕大小
	CCSize mysize = CCSizeMake(300,80); //容器大小

//创建容器、设置大小
	CCLayerColor* scrollLayer = CCLayerColor::create( ccc4(255,255,255,255) );
	scrollLayer->setContentSize(mysize);

//容器中添加三个图片
	for(int i = 1; i <= 3; i++) 
	{
		char file[20];
		sprintf(file, "sp%d.png", i);
		CCSprite* sp = CCSprite::create(file);
		sp->setPosition( ccp(100*i - 50, 40) );
		scrollLayer->addChild(sp);
	}

//创建滚动视图CCScrollView
	//可视区域大小100*80 、 容器为scrollLayer
	CCScrollView* scrollView = CCScrollView::create(CCSizeMake(100, 80), scrollLayer);
	scrollView->setPosition( visableSize/2 - ccp(100/2.0, 0) );
	this->addChild(scrollView, 0, 3);

	//属性设置
	scrollView->setTouchEnabled(false); //关闭触碰事件，无法触摸滚动

	//委托代理
	scrollView->setDelegate(this);


//创建背包翻页按钮
	//前翻pBack、后翻pFront
	pBack = CCMenuItemImage::create("b1.png", "b2.png", "b3.png", this, menu_selector(HelloWorld::scrollImage) );
	pFront = CCMenuItemImage::create("f1.png", "f2.png", "f3.png", this, menu_selector(HelloWorld::scrollImage) );
	pBack->setPosition( ccp(visableSize.width/2 - 100, 60) );
	pFront->setPosition( ccp(visableSize.width/2 + 100, 60) );
	CCMenu* pMenu = CCMenu::create(pBack, pFront, NULL);
	pMenu->setPosition(CCPointZero);
	this->addChild(pMenu, 0, 100);

	pBack->setEnabled(false);
	pageNumber = 0; //第0页

}

//实现翻页效果
void HelloWorld::scrollImage(CCObject* sender)
{
	CCScrollView* scrollView = (CCScrollView*)this->getChildByTag(3);

	if(sender == pBack && pBack->isEnabled() )
	{
		pageNumber = max(0, pageNumber-1); //前翻
	}
	else if( pFront->isEnabled() )
	{
		pageNumber = min(2, pageNumber+1); //后翻
	}

	//设置容器相对滚动视图的偏移量
	scrollView->setContentOffset(ccp(-100 * pageNumber, 0), true);

	pBack->setEnabled( pageNumber != 0);
	pFront->setEnabled( pageNumber != 2);
}


void HelloWorld::scrollViewDidScroll(CCScrollView* view) 
{
	CCLOG("ScrollView Moved!");
}
void HelloWorld::scrollViewDidZoom(CCScrollView* view) 
{
	CCLOG("ScrollView Scaled");
}


//关闭程序
void HelloWorld::menuCloseCallback(CCObject* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
	CCMessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
#else
    CCDirector::sharedDirector()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
#endif
}
