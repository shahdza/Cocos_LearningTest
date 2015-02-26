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
    
//获取可视区域尺寸大小
    CCSize mysize = CCDirector::sharedDirector()->getVisibleSize();
//获取可视区域的原点位置
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
//屏幕正中心位置
	CCPoint midPos = ccp(mysize.width/2, mysize.height/2);

//添加两个CCSprite精灵,用于多点触屏
	CCSprite* sp1 = CCSprite::create("Icon.png");
	sp1->setPosition( ccp( 100, 160 ) );
	this->addChild(sp1, 0, 1);

	CCSprite* sp2 = CCSprite::create("Icon_gray.png");
	sp2->setPosition( ccp( 200, 160) );
	this->addChild(sp2, 0, 2);

//开启多点触屏
//注意这句话必须要写,否则无法多点触屏
	this->setTouchEnabled(true);

	return true;
}


//注册多点触屏
void HelloWorld::registerWithTouchDispatcher()
{
	CCDirector::sharedDirector()->getTouchDispatcher()->addStandardDelegate(this,0);
}

//注销多点触屏
void HelloWorld::onExit()
{
	CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
	CCLayer::onExit(); //不要忘了写！
}

//触屏开始,返回值是void
void HelloWorld::ccTouchesBegan(CCSet* touches,CCEvent* event)
{
	CCLOG("ccTouchesBegan");
}

//触屏移动
void HelloWorld::ccTouchesMoved(CCSet* touches,CCEvent* event)
{
	CCLOG("ccTouchesMoved");

//创建CCSet的迭代器CCSetIterator
	CCSetIterator iter = touches->begin();

//遍历多点触点集合touches
	for( ;iter != touches->end(); iter++) 
	{
		//获取触点后，就和单点一样的处理了
		CCTouch* touch = (CCTouch*)(*iter);

		if( touch->getID() == 0) //控制精灵sp1
		{
			CCSprite* sp1 = (CCSprite*)this->getChildByTag(1);
			sp1->setPosition( touch->getLocation() );
		}
		else if( touch->getID() == 1) //控制精灵sp2
		{
			CCSprite* sp2 = (CCSprite*)this->getChildByTag(2);
			sp2->setPosition( touch->getLocation() );
		}
	}
}

//触屏结束
void HelloWorld::ccTouchesEnded(CCSet* touches,CCEvent* event)
{
	CCLOG("ccTouchesEnded");
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
