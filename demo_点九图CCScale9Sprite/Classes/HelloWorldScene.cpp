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

	test("Icon.png", 1); //用Icon.png做测试
	test("CloseNormal.png", 2); //用CloseNormal.png做测试
	test("Rect.png", 3); //用Rect.png做测试

	return true;
}

/**
 *		file：图片资源名称，如"sp.png"
 *		index：第几组测试数据
 */
void HelloWorld::test(const char* file, int index)
{

//获取可视区域尺寸大小
	CCSize mysize = CCDirector::sharedDirector()->getVisibleSize();
//获取可视区域的原点位置
	CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
//屏幕正中心位置
	CCPoint midPos = ccp(mysize.width/2, mysize.height/2);


//CCSprite，精灵拉伸
	CCSprite* sprite1 = CCSprite::create(file);
	sprite1->setPosition( ccp(120 * index, mysize.height - 60) );
	this->addChild(sprite1);

	//精灵拉伸
	sprite1->setScale(2.0f);


//scale9Sprite1，不设置capInsets
	CCScale9Sprite* scale9Sprite1 = CCScale9Sprite::create(file);
	scale9Sprite1->setPosition( ccp(120 * index, mysize.height/2) );
	this->addChild(scale9Sprite1);

	//不设置capInsets，拉伸
	scale9Sprite1->setContentSize( CCSizeMake(80, 80) );


//scale9Sprite2，设置capInsets
	CCScale9Sprite* scale9Sprite2 = CCScale9Sprite::create(file);
	scale9Sprite2->setPosition( ccp(120 * index, 60) );
	this->addChild(scale9Sprite2);

	//设置capInsets，并拉伸
	scale9Sprite2->setCapInsets( CCRectMake(3, 3, 34, 34) );
	scale9Sprite2->setContentSize( CCSizeMake(80, 80) );
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
