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


//显示第一组开关的状态
	label = CCLabelTTF::create("ON", "Marker Felt", 100);
	label->setPosition( midPos - ccp(100, 0) );
	this->addChild(label);

//第一组开关
	CCSprite* bg1 = CCSprite::create("ControlSwith_bg.png");
	CCSprite* on1 = CCSprite::create("ControlSwith_on.png");
	CCSprite* off1 = CCSprite::create("ControlSwith_off.png");
	CCSprite* thumb1 = CCSprite::create("ControlSwith_thumb.png");
	CCControlSwitch* controlSwitch1 = CCControlSwitch::create(bg1, on1, off1, thumb1);
	controlSwitch1->setPosition( midPos - ccp(100, 100) );
	this->addChild(controlSwitch1);

	//绑定事件
	controlSwitch1->addTargetWithActionForControlEvents(this, cccontrol_selector(HelloWorld::valueChanged), CCControlEventValueChanged);


//第二组开关
	CCSprite* bg2 = CCSprite::create("switch-mask.png");
	CCSprite* on2 = CCSprite::create("switch-off.png");
	CCSprite* off2 = CCSprite::create("switch-on.png");
	CCSprite* thumb2 = CCSprite::create("switch-thumb.png");
	CCLabelTTF* TTFon = CCLabelTTF::create("on", "Arial", 20);
	CCLabelTTF* TTFoff = CCLabelTTF::create("off", "Arial", 20);
	CCControlSwitch* controlSwitch2 = CCControlSwitch::create(bg2, on2, off2, thumb2, TTFon, TTFoff);
	controlSwitch2->setPosition( midPos - ccp(-100, 100) );
	this->addChild(controlSwitch2);

	return true;
}

//事件响应函数
void HelloWorld::valueChanged(CCObject* sender, CCControlEvent controlEvent)
{
//获取事件的传递者CCControlSwitch
	CCControlSwitch* controlSwitch = (CCControlSwitch*)sender;
	
//根据开关控件的状态，设置label标签的内容
	if( controlSwitch->isOn() ) 
	{
		label->setString("ON");
	}
	else 
	{
		label->setString("OFF");
	}
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
