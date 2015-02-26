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


//创建显示Slider值的标签
	label = CCLabelTTF::create("50.0", "Arial", 32);
	label->setPosition( midPos + ccp(0, 100) );
	this->addChild(label);


//创建滑块控件CCControlSlider
	CCControlSlider* slider = CCControlSlider::create("sliderTrack.png", "sliderProgress.png", "sliderThumb.png");
	slider->setPosition( midPos );
	this->addChild(slider);

	//设置属性
	slider->setMinimumValue(0); //设置滑块最小值
	slider->setMaximumValue(100); //设置滑块最大值
	slider->setMinimumAllowedValue(20); //设置允许滑动的最小值
	slider->setMaximumAllowedValue(80); //设置允许滑动的最大值
	slider->setValue(50); //设置当前滑块的值

	//绑定事件，当滑块的值改变时触发控件事件
	slider->addTargetWithActionForControlEvents(this, cccontrol_selector(HelloWorld::valueChanged), CCControlEventValueChanged);


	return true;
}

//事件响应函数，值改变时，修改label标签的内容
void HelloWorld::valueChanged(CCObject* sender, CCControlEvent controlEvent)
{
//获取事件委托者：滑块控制CCControlSlider
	CCControlSlider* slider = (CCControlSlider*)sender;

//修改label的值，显示滑块的当前值
	//sprintf为C语言中的字符串格式转换，这里将float转换为字符串
	char str[50];
	sprintf(str, "%f", slider->getValue() );  //字符串格式转换
	label->setString(str);
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
