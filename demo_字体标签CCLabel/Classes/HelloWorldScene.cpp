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


/************************************************************************/
/* CCLabelTTF															*/
/************************************************************************/

/*

//创建CCLabelTTF的三种方法
	CCLabelTTF* lb1 = CCLabelTTF::create("aaaaaaaa", "arial", 20);
	CCLabelTTF* lb2 = CCLabelTTF::create("bbbbbbbb", "宋体", 40, CCSizeMake(50,100), CCTextAlignment::kCCTextAlignmentCenter);
	CCLabelTTF* lb3 = CCLabelTTF::create("cccccc", "黑体", 40, CCSizeMake(480,320), CCTextAlignment::kCCTextAlignmentRight, CCVerticalTextAlignment::kCCVerticalTextAlignmentBottom);

//设置位置,屏幕中心
	lb1->setPosition( midPos );
	lb2->setPosition( midPos );
	lb3->setPosition( midPos );

//添加到HelloWorld层中
	this->addChild(lb1);
	this->addChild(lb2);
	this->addChild(lb3);

//其他操作
	lb1->setColor( ccc3(255, 0, 0) ); //设置颜色ccc3
	lb1->setRotation(60.0f); //旋转
	lb2->setColor( cocos2d::ccBLUE ); //设置颜色ccBLUE
	lb3->setString("hello world!"); //设置文字内容

*/

/************************************************************************/
/* CCLabelAtlas															*/
/************************************************************************/

/*

//创建CCLabelTTF的方法
	CCLabelAtlas* lb4 = CCLabelAtlas::create("20140815", "fonts/digit.png", 20, 20, '0');
//设置位置
	lb4->setPosition(midPos);
//添加到HelloWorld层中
	this->addChild(lb4);

*/

/************************************************************************/
/* CCLabelBMFont														*/
/************************************************************************/

/*
//创建两个CCLabelBMFont字体
	CCLabelBMFont* lb5 = CCLabelBMFont::create("hello", "fonts/bitmapFontTest.fnt");
	CCLabelBMFont* lb6 = CCLabelBMFont::create("world", "fonts/bitmapFontTest.fnt");

//设置位置
	lb5->setPosition( midPos );
	lb6->setPosition( midPos - ccp(0,100) );

//添加到Layer层中
	this->addChild(lb5);
	this->addChild(lb6);

//属性设置
	lb5->setColor(ccRED); //设置字体颜色为红色
	lb6->setString("abc"); //设置内容

//获取某个位置的字母,像精灵一样使用
	CCSprite* lb5_c1 = (CCSprite*)lb5->getChildByTag(0); //获取第0个字母h
	CCSprite* lb5_c2 = (CCSprite*)lb5->getChildByTag(3); //获取第3个字母l
	lb5_c1->setColor(ccc3(0,255,0)); //设置为绿色
	lb5_c2->setScale(2.0f); //放大
*/

    return true;
}


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
