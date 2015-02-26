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


	CCTextFieldTTF* textFieldTTF = CCTextFieldTTF::textFieldWithPlaceHolder("please input", "Marker Felt", 24);
	//CCTextFieldTTF* textFieldTTF = CCTextFieldTTF::textFieldWithPlaceHolder("please input", CCSize(100,100), CCTextAlignment::kCCTextAlignmentCenter, "Arial", 20);
	textFieldTTF->setPosition( midPos );
	this->addChild(textFieldTTF, 0, 1); //tag标记1

	//设置虚拟键盘委托对象
	textFieldTTF->setDelegate(this); 

	return true;
}


//当用户启动虚拟键盘的时候的回调函数
bool HelloWorld::onTextFieldAttachWithIME(CCTextFieldTTF* sender)
{
	//事件处理
	sender->setFontSize(30); //字体放大为30
	sender->setColor(ccYELLOW); //内容颜色: 黄色
	sender->setColorSpaceHolder(ccWHITE); //默认内容颜色: 白色

	return false; //启用键盘。若不启用键盘return true;
}

//当用户关闭虚拟键盘的时候的回调函数
bool HelloWorld::onTextFieldDetachWithIME(CCTextFieldTTF* sender)
{
	//事件处理
	sender->setFontSize(24); //字体大小还原为24
	sender->setColor(ccORANGE); //内容颜色: 橘黄
	sender->setColorSpaceHolder(ccGRAY); //默认内容颜色: 灰色

	return false; //关闭键盘。若不关闭键盘return true;
}

//当用户输入的时候的回调函数
bool HelloWorld::onTextFieldInsertText(CCTextFieldTTF* sender, const char* text, int nLen)
{
	//事件处理
	CCLOG("CharCount: %d", sender->getCharCount());

	return false; //输入字符。若不允许输入字符return true;
}

//当用户删除文字的时候的回调函数
bool HelloWorld::onTextFieldDeleteBackward(CCTextFieldTTF* sender, const char* delText, int nLen)
{
	return false; //删除字符。若不允许删除字符return true;
}


bool HelloWorld::ccTouchBegan(CCTouch* touch, CCEvent* event)
{
	CCLOG("ccTouchBegan");
	return true;
}

void HelloWorld::ccTouchMoved(CCTouch* touch, CCEvent* event)
{
	CCLOG("ccTouchMoved");
}

void HelloWorld::ccTouchEnded(CCTouch* touch, CCEvent* event)
{
	CCLOG("ccTouchEnded");

//获取触点
	CCPoint pos = touch->getLocation();

//获取textFieldTTF所在的矩形区域rect
	CCTextFieldTTF* textFieldTTF = (CCTextFieldTTF*)this->getChildByTag(1);
	float x = textFieldTTF->getPositionX() - textFieldTTF->getContentSize().width/2;
	float y = textFieldTTF->getPositionY() - textFieldTTF->getContentSize().height/2;
	float width = textFieldTTF->getContentSize().width;
	float height = textFieldTTF->getContentSize().height;
	CCRect rect = CCRectMake(x, y, width, height);

//判断触点是否触摸到文本框内部
	if( rect.containsPoint(pos) ) {
		CCLOG("attachWithIME");
		textFieldTTF->attachWithIME(); //开启虚拟键盘
	}else {
		CCLOG("detachWithIME");
		textFieldTTF->detachWithIME(); //关闭虚拟键盘
	}
}


//开启触控
void HelloWorld::onEnter()
{
	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 0, false);
	CCLayer::onEnter();
}

//删除触控
void HelloWorld::onExit()
{
	CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
	CCLayer::onExit();
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
