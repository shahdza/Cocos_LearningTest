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



//创建五个精灵
	CCSprite* sp = CCSprite::create("Icon.png");
	sp->setPosition( ccp(30, mysize.height - 30) );
	this->addChild(sp, 0, 100); //tag标记100

	CCSprite* sp1 = CCSprite::create("Icon.png");
	sp1->setPosition( ccp(30, mysize.height - 90) );
	this->addChild(sp1, 0, 101); //tag标记101

	CCSprite* sp2 = CCSprite::create("Icon.png");
	sp2->setPosition( ccp(30, mysize.height - 150) );
	this->addChild(sp2, 0, 102); //tag标记102

	CCSprite* sp3 = CCSprite::create("Icon.png");
	sp3->setPosition( ccp(30, mysize.height - 210) );
	this->addChild(sp3, 0, 103); //tag标记103

	CCSprite* sp4 = CCSprite::create("Icon.png");
	sp4->setPosition( ccp(30, mysize.height - 270) );
	this->addChild(sp4, 0, 104); //tag标记104
	 

//定义五个定时器,更新精灵
	this->scheduleUpdate();
	this->schedule( schedule_selector(HelloWorld::myupdate) );
	this->schedule( schedule_selector(HelloWorld::myupdate2), 1.0f );
	this->schedule( schedule_selector(HelloWorld::myupdate3), 1.0f, 5, 3.0f);
	this->scheduleOnce( schedule_selector(HelloWorld::myupdate4), 5.0f );

	return true;
}

//scheduleUpdate
void HelloWorld::update(float dt)
{
	CCSprite* sp = (CCSprite*)this->getChildByTag(100); //获取 tag=100 的精灵
	sp->setPosition( sp->getPosition() + ccp(1,0) ); //每帧移动1
}

//schedule(schedule_selector)
void HelloWorld::myupdate(float dt)
{
	CCSprite* sp1 = (CCSprite*)this->getChildByTag(101); //获取 tag=101 的精灵
	sp1->setPosition( sp1->getPosition() + ccp(1,0) ); //每帧移动1
}

//schedule(schedule_selector, interval)
void HelloWorld::myupdate2(float dt)
{
	CCSprite* sp2 = (CCSprite*)this->getChildByTag(102); //获取 tag=102 的精灵
	sp2->setPosition( sp2->getPosition() + ccp(60,0) ); //每秒移动60
}

//schedule(schedule_selector, interval, repeat, delay)
void HelloWorld::myupdate3(float dt)
{
	CCSprite* sp3 = (CCSprite*)this->getChildByTag(103); //获取 tag=103 的精灵
	sp3->setPosition( sp3->getPosition() + ccp(60,0) ); //每秒移动60
}

//scheduleOnce
void HelloWorld::myupdate4(float dt)
{
	CCSprite* sp4 = (CCSprite*)this->getChildByTag(104); //获取 tag=104 的精灵
	sp4->setPosition( sp4->getPosition() + ccp(100,0) ); //移动100
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
