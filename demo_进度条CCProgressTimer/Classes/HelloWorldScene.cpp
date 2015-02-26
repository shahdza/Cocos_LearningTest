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

//获得屏幕尺寸
	CCSize mysize = CCDirector::sharedDirector()->getVisibleSize();

	
//原始图片
	CCSprite* bg = CCSprite::create("Icon.png");
	bg->setPosition( mysize/2 + ccp(0, 100) );
	this->addChild(bg);


//条形进度条pro1
	CCSprite* bg1 = CCSprite::create("Icon.png");
	CCProgressTimer* pro1 = CCProgressTimer::create(bg1);
	pro1->setPosition( ccp(130, 100) );
	this->addChild(pro1);

	//条形，定义进度条方式：从右到左显示
	pro1->setType(kCCProgressTimerTypeBar);
	pro1->setBarChangeRate( ccp(1, 0) );
	pro1->setMidpoint( ccp(1, 0) );
	//pro1->setReverseProgress(true); //反进度显示


//扇形进度条pro2
	CCSprite* bg2 = CCSprite::create("Icon.png");
	CCProgressTimer* pro2 = CCProgressTimer::create(bg2);
	pro2->setPosition( ccp(350, 100) );
	this->addChild(pro2);

	//扇形，圆心ccp(0.3 , 0.7)
	pro2->setType(kCCProgressTimerTypeRadial);
	pro2->setMidpoint( ccp(0.3, 0.7) );
	//pro2->setReverseProgress(true); //逆时针


//进度动作
	CCProgressTo* ac1 = CCProgressTo::create(2.0f, 100);
	CCProgressFromTo* ac2 = CCProgressFromTo::create(2.0f, 30, 100);

	pro1->runAction( CCRepeatForever::create(ac1) ); //从0到100
	pro2->runAction( CCRepeatForever::create(ac2) ); //从30到100

	return true;
}

