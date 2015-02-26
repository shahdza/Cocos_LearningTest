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

//添加一个CCSprite精灵
	CCSprite* sp = CCSprite::create("Icon.png");
	sp->setPosition( midPos );
	this->addChild(sp, 0, 1);

	return true;
}


//触屏开始
bool HelloWorld::ccTouchBegan(CCTouch* touch,CCEvent * event) 
{
	CCLOG("ccTouchBegan");

//获取CCSprite精灵
	CCSprite* sp = (CCSprite*)this->getChildByTag(1);

//设置精灵的坐标为: 当前触点位置
	CCPoint pTouch = touch->getLocation();
	sp->setPosition( pTouch );

	return true;
}

//触屏移动
void HelloWorld::ccTouchMoved(CCTouch* touch,CCEvent* event) 
{
	CCLOG("ccTouchMoved");

//获取可视区域尺寸大小
	CCSize mysize = CCDirector::sharedDirector()->getVisibleSize();

//获取CCSprite精灵
	CCSprite* sp = (CCSprite*)this->getChildByTag(1);

//实现触屏移动
	CCPoint pos = touch->getDelta(); //获得触屏滑动的偏移量
	CCPoint currentPos = sp->getPosition(); //获得精灵的当前坐标

	currentPos = ccpAdd(currentPos, pos); //精灵+偏移量 后的坐标

	sp->setPosition(currentPos); //设置触屏移动后的坐标
}


//触屏结束
void HelloWorld::ccTouchEnded(CCTouch* touch,CCEvent* event) 
{
	CCLOG("ccTouchEnded");

//获取CCSprite精灵
	CCSprite* sp = (CCSprite*)this->getChildByTag(1);

//设置精灵的坐标为: 触屏开始时的触点位置
	CCPoint touchStartPos = touch->getStartLocation();
	sp->setPosition( touchStartPos );
}


//开启触屏监听
void HelloWorld::onEnter() 
{
	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this,0,false);
	CCLayer::onEnter();//一定不要忘了
}

//关闭触屏监听
void HelloWorld::onExit()
{
	CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
	CCLayer::onExit();//一定不要忘了
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
