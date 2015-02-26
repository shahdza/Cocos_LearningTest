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


	test1(); //使用图片资源
	test2(); //使用精灵帧
	test3(); //使用动画帧

	return true;
}


//------------------------------------------------------------------
// 使用图片资源
//------------------------------------------------------------------
void HelloWorld::test1()
{

//获得屏幕尺寸
	CCSize mysize = CCDirector::sharedDirector()->getVisibleSize();


//创建精灵sprite
	CCSprite* sprite = CCSprite::create("Animation/dance_00.png");
	sprite->setPosition( mysize/2 - ccp(100, 0) );
	this->addChild(sprite);


//创建CCAnimation
	CCAnimation* animation = CCAnimation::create();

	//直接添加图片资源
	for(int i =1; i <= 14; i++) {
		char str[50];
		sprintf(str, "Animation/dance_%02d.png", i);

		animation->addSpriteFrameWithFileName(str); //添加动画帧
	}

	//设置属性
	animation->setRestoreOriginalFrame(true); //还原第一帧
	animation->setDelayPerUnit(2.0/14.0);     //单位帧间隔
	animation->setLoops(-1);                  //-1无限循环


//创建CCAnimate
	CCAnimate* animate = CCAnimate::create(animation);
	CCDelayTime* delay = CCDelayTime::create(2.0f);
	CCSequence* seq = CCSequence::create(delay, animate, NULL);


//执行动画动作
	sprite->runAction(seq);

}


//------------------------------------------------------------------
// 使用精灵帧
//------------------------------------------------------------------
void HelloWorld::test2()
{

//获得屏幕尺寸
	CCSize mysize = CCDirector::sharedDirector()->getVisibleSize();


//创建精灵sprite
	CCSprite* sprite = CCSprite::create("Animation/dance_00.png");
	sprite->setPosition( mysize/2 );
	this->addChild(sprite);


//创建CCAnimation
	//将plist批处理的多张图片，添加到精灵帧缓冲池中
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Animation/grossini.plist");

	//创建精灵帧CCSpriteFrame数组
	CCArray* array = new CCArray();
	for(int i =1; i <= 14; i++) {
		char str[50];
		sprintf(str, "grossini_dance_%02d.png", i);

		CCSpriteFrame* frame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(str);
		array->addObject(frame);
	}

	//使用精灵帧数组创建，单位帧间隔为2.0/14.0秒
	CCAnimation* animation = CCAnimation::createWithSpriteFrames(array, 2.0/14.0);

	//属性设置
	animation->setRestoreOriginalFrame(true); //还原第一帧
	animation->setLoops(-1);                  //无线循环


//创建CCAnimate
	CCAnimate* animate = CCAnimate::create(animation);
	CCDelayTime* delay = CCDelayTime::create(2.0f);
	CCSequence* seq = CCSequence::create(delay, animate, NULL);


//执行动画动作
	sprite->runAction(seq);

}


//------------------------------------------------------------------
// 使用动画帧
//------------------------------------------------------------------
void HelloWorld::test3()
{

//获得屏幕尺寸
	CCSize mysize = CCDirector::sharedDirector()->getVisibleSize();


//创建精灵sprite
	CCSprite* sprite = CCSprite::create("Animation/dance_00.png");
	sprite->setPosition( mysize/2 + ccp(100, 0) );
	this->addChild(sprite);


//创建CCAnimation
	//将plist批处理的多张图片，添加到精灵帧缓冲
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Animation/grossini.plist");

	//创建动画帧CCAnimationFrame数组
	CCArray* array = new CCArray();
	for(int i =1; i <= 14; i++) {
		char str[50];
		sprintf(str, "grossini_dance_%02d.png", i);

		CCSpriteFrame* frame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(str);
		CCAnimationFrame* animationFrame = new CCAnimationFrame();

		animationFrame->setSpriteFrame(frame); //设置精灵帧
		animationFrame->setDelayUnits( i );    //设置间隔帧数

		array->addObject(animationFrame);
	}

	//使用动画帧数组创建，单位帧间隔0.2秒
	CCAnimation* animation = CCAnimation::create(array, 0.2f);
	animation->setRestoreOriginalFrame(true);
	animation->setLoops(-1);


//创建CCAnimate
	CCAnimate* animate = CCAnimate::create(animation);
	CCDelayTime* delay = CCDelayTime::create(2.0f);
	CCSequence* seq = CCSequence::create(delay, animate, NULL);

//执行动画动作
	sprite->runAction(seq);

}

