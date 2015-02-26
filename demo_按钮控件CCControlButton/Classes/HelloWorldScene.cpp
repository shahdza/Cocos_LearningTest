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


//显示按钮状态的标签displayLabel
	displayLabel = CCLabelTTF::create("No Event", "Marker Felt", 32);
	displayLabel->setPosition( midPos + ccp(0, 100) );
	this->addChild(displayLabel);


//按钮中的背景精灵CCScale9Sprite
	CCScale9Sprite* bgNormal = CCScale9Sprite::create("btnNormal.png"); //正常背景
	CCScale9Sprite* bgHighlighted = CCScale9Sprite::create("btnHighlighted.png"); //高亮背景

//按钮中的标签CCLabelTTF
	CCLabelTTF* titleNormal = CCLabelTTF::create("Button is Normal !", "Marker Felt", 30);
	CCLabelTTF* titleHighlighted = CCLabelTTF::create("Button is Highlighted !", "Marker Felt", 30);


//创建按钮CCControlButton
	CCControlButton* btn = CCControlButton::create(titleNormal, bgNormal);
	btn->setPosition( midPos );
	this->addChild(btn);

//设置按钮高亮时的状态
	btn->setTitleLabelForState(titleHighlighted, CCControlStateHighlighted); //高亮标签
	btn->setTitleColorForState(ccRED, CCControlStateHighlighted); //红色
	btn->setBackgroundSpriteForState(bgHighlighted, CCControlStateHighlighted); //高亮背景

	//写了这句话，反而大小被固定了。没有按照label的大小进行自动伸展了
	//btn->setPreferredSize( CCSizeMake(120,40) );

//绑定事件，用于显示按钮状态
	btn->addTargetWithActionForControlEvents(this, cccontrol_selector(HelloWorld::touchDownAction), CCControlEventTouchDown); //刚刚开始触摸按钮时
	btn->addTargetWithActionForControlEvents(this, cccontrol_selector(HelloWorld::touchDragInsideAction), CCControlEventTouchDragInside);  //在内部拖动时（保持触摸状态下）
	btn->addTargetWithActionForControlEvents(this, cccontrol_selector(HelloWorld::touchDragOutsideAction), CCControlEventTouchDragOutside); //在外部拖动时（保持触摸状态下）
	btn->addTargetWithActionForControlEvents(this, cccontrol_selector(HelloWorld::touchDragEnterAction), CCControlEventTouchDragEnter);  //拖动刚进入内部时（保持触摸状态下）
	btn->addTargetWithActionForControlEvents(this, cccontrol_selector(HelloWorld::touchDragExitAction), CCControlEventTouchDragExit); //拖动刚离开内部时（保持触摸状态下）
	btn->addTargetWithActionForControlEvents(this, cccontrol_selector(HelloWorld::touchUpInsideAction), CCControlEventTouchUpInside); //在内部抬起手指（保持触摸状态下）
	btn->addTargetWithActionForControlEvents(this, cccontrol_selector(HelloWorld::touchUpOutsideAction), CCControlEventTouchUpOutside); //在外部抬起手指（保持触摸状态下）
	btn->addTargetWithActionForControlEvents(this, cccontrol_selector(HelloWorld::touchCancelAction), CCControlEventTouchCancel); //取消触点

	return true;
}

//刚刚开始触摸按钮时
void HelloWorld::touchDownAction(CCObject *senderz, CCControlEvent controlEvent)
{
	displayLabel->setString("Touch Down");
}

//在内部拖动时（保持触摸状态下）
void HelloWorld::touchDragInsideAction(CCObject *sender, CCControlEvent controlEvent)
{
	displayLabel->setString("Drag Inside");
}

//在外部拖动时（保持触摸状态下）
void HelloWorld::touchDragOutsideAction(CCObject *sender, CCControlEvent controlEvent)
{
	displayLabel->setString("Drag Outside");
}

//拖动刚进入内部时（保持触摸状态下）
void HelloWorld::touchDragEnterAction(CCObject *sender, CCControlEvent controlEvent)
{
	displayLabel->setString("Drag Enter");
}

//拖动刚离开内部时（保持触摸状态下）
void HelloWorld::touchDragExitAction(CCObject *sender, CCControlEvent controlEvent)
{
	displayLabel->setString("Drag Exit");
}

//在内部抬起手指（保持触摸状态下）
void HelloWorld::touchUpInsideAction(CCObject *sender, CCControlEvent controlEvent)
{
	displayLabel->setString("Touch Up Inside.");
}

//在外部抬起手指（保持触摸状态下）
void HelloWorld::touchUpOutsideAction(CCObject *sender, CCControlEvent controlEvent)
{
	displayLabel->setString("Touch Up Outside.");
}

//取消所有触摸
void HelloWorld::touchCancelAction(CCObject *sender, CCControlEvent controlEvent)
{
	displayLabel->setString("Touch Cancel");
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
