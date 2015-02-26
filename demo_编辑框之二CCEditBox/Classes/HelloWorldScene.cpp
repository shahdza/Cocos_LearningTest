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

	

//编辑框尺寸大小
	CCSize editBoxSize = CCSizeMake(mysize.width - 100, 60);


//用户名editBoxName
	CCEditBox* editBoxName = CCEditBox::create(editBoxSize, CCScale9Sprite::create("green_edit.png"));
	editBoxName->setPosition( ccp(mysize.width/2, mysize.height*3/4) );
	this->addChild(editBoxName);

	//属性设置
	editBoxName->setFontName("fonts/Paint Boy.ttf");
	editBoxName->setFontSize(20);
	editBoxName->setFontColor(ccRED);
	editBoxName->setPlaceHolder("Name:");
	editBoxName->setPlaceholderFontColor(ccWHITE);
	editBoxName->setMaxLength(8);

	//模式类型设置
	editBoxName->setInputMode(kEditBoxInputModeSingleLine);
	editBoxName->setInputFlag(kEditBoxInputFlagInitialCapsAllCharacters);
	editBoxName->setReturnType(kKeyboardReturnTypeDefault);

	//委托代理对象this
	editBoxName->setDelegate(this);


//密码editBoxPassword
	CCEditBox* editBoxPassword = CCEditBox::create(editBoxSize, CCScale9Sprite::create("orange_edit.png"));
	editBoxPassword->setPosition( midPos );
	this->addChild(editBoxPassword);

	//属性设置
	editBoxPassword->setFont("fonts/Marker Felt.ttf", 30);
	editBoxPassword->setFontColor(ccGREEN);
	editBoxPassword->setPlaceHolder("Password:");
	editBoxPassword->setMaxLength(6);

	//模式设置
	editBoxPassword->setInputFlag(kEditBoxInputFlagPassword);
	editBoxPassword->setReturnType(kKeyboardReturnTypeDone);

	//委托代理对象this
	editBoxPassword->setDelegate(this);
	

//邮箱editBoxEmail
	CCEditBox* editBoxEmail = CCEditBox::create(editBoxSize, CCScale9Sprite::create("yellow_edit.png"));
	editBoxEmail->setPosition( ccp(mysize.width/2, mysize.height/4) );
	this->addChild(editBoxEmail);

	//属性设置
	editBoxEmail->setFont("fonts/Marker Felt.ttf", 30);
	editBoxEmail->setPlaceHolder("Email:");

	//模式类型设置
	editBoxEmail->setInputMode(kEditBoxInputModeEmailAddr);
	editBoxEmail->setReturnType(kKeyboardReturnTypeSend);

	//委托代理对象this
	editBoxEmail->setDelegate(this);

	return true;
}


//开始编辑
void HelloWorld::editBoxEditingDidBegin(CCEditBox* editBox)
{
	CCLog("editBox %p DidBegin !", editBox);
}

//结束编辑
void HelloWorld::editBoxEditingDidEnd(CCEditBox* editBox)
{
	CCLog("editBox %p DidEnd !", editBox);
}

//编辑框内容改变
void HelloWorld::editBoxTextChanged(CCEditBox* editBox, const std::string& text)
{
	CCLog("editBox %p TextChanged, text: %s ", editBox, text.c_str());
}

//触发return返回
void HelloWorld::editBoxReturn(CCEditBox* editBox)
{
	CCLog("editBox %p was returned !",editBox);
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
