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
/* Test																	*/
/************************************************************************/


/*
 *	创建CCMenuItemLabel
 *		使用CCLabelTTF创建
 */
	CCLabelTTF* lb1 = CCLabelTTF::create("aaaaaa", "Arial", 32);
	CCMenuItemLabel* menuItemLabel = CCMenuItemLabel::create(lb1);
	//设置位置
	menuItemLabel->setPosition( ccp(120, mysize.height-50) ); 

/*
 *	创建CCMenuItemAtlasFont
 *		创建方式与CCLabelAtlas类似
 */
	CCMenuItemAtlasFont* menuItemAtlas = CCMenuItemAtlasFont::create("20140818", "fonts/digit.png", 20, 20, '0');
	menuItemAtlas->setPosition( ccp(120, mysize.height-120) );


/*
 *	创建CCMenuItemFont
 *		创建了两个，有无附带回调响应函数
 */
	//设置CCMenuItemFont创建时的默认字体大小
	CCMenuItemFont::setFontSize(50);

	//不带回调响应函数，tag编号为1
	CCMenuItemFont* menuItemFont1 = CCMenuItemFont::create("11111");
	menuItemFont1->setTag(1);

	//触碰后，执行回调函数menuItemFont2Func。更改menuItemFont1的内容
	CCMenuItemFont* menuItemFont2 = CCMenuItemFont::create("Change1", this, menu_selector(HelloWorld::menuItemFont2Func) ); //回调
	
	menuItemFont2->setFontSizeObj(32); //设置字体大小
	menuItemFont1->setPosition( ccp(120, mysize.height-190) ); //设置位置
	menuItemFont2->setPosition( ccp(120, mysize.height-260) ); //设置位置


/*
 *	创建CCMenu，tag编号为100
 *		菜单项menuItemLabel, menuItemAtlas, menuItemFont1, menuItemFont2
 */
	CCMenu* menu = CCMenu::create(menuItemLabel, menuItemAtlas, menuItemFont1, menuItemFont2, NULL);
	
	//设置位置为(0,0)，与HelloWorld层重合
	menu->setPosition(CCPointZero); 
	
	//将CCMenu菜单添加到CCLayer中， tag编号为100
	this->addChild(menu, 0, 100); 


/*
 *	创建CCMenuItemSprite
 *		参数为CCSprite精灵
 */
	CCSprite* sp1 = CCSprite::create("sp1.png");
	CCSprite* sp2 = CCSprite::create("sp2.png");
	CCSprite* sp3 = CCSprite::create("sp3.png");
	CCMenuItemSprite* menuItemSprite = CCMenuItemSprite::create(sp1, sp2, sp3 );

	menuItemSprite->setPosition( ccp(mysize.width/2 + 50, mysize.height/2 + 50) );
	menu->addChild(menuItemSprite); //添加到菜单层中
	menuItemSprite->setTag(2); //tag编号为2

/*
 *	创建CCMenuItemImage
 *		参数变成纹理图片png
 */
	//使用CCMenuItemImage创建一个关闭程序的菜单项按钮
	CCMenuItemImage* menuItemImage = CCMenuItemImage::create("CloseNormal.png", "CloseSelected.png", this, menu_selector(HelloWorld::menuCloseCallback) ); //回调
	menuItemImage->setPosition( ccp(mysize.width - 40, mysize.height - 40) );
	menu->addChild(menuItemImage); //添加到菜单层中


/*
 *	创建CCMenuItemToggle
 *		参数为CCMenuItem子类
 */
	CCMenuItemFont::setFontSize(20);
	CCMenuItemFont* menuItemFont3 = CCMenuItemFont::create("Toggle_Normal");
	CCMenuItemFont* menuItemFont4 = CCMenuItemFont::create("Toggle_Selected");
	CCMenuItemImage* menuItemImage2 = CCMenuItemImage::create("sp3.png", "sp1.png");
	
	//创建CCMenuItemToggle，回调函数：更改menuItemSprite的状态。
	CCMenuItemToggle* menuItemToggle = CCMenuItemToggle::createWithTarget(this, menu_selector(HelloWorld::menuItemToggleFunc), 
																				menuItemFont3, menuItemFont4, NULL ); //菜单项参数列表
	menuItemToggle->setPosition( ccp(mysize.width/2 + 50, mysize.height/2 - 50) ); //设置位置

	//将menuItemImage2添加到menuItemToggle中
	menuItemToggle->addSubItem(menuItemImage2);

	menu->addChild(menuItemToggle); //添加到菜单层中


    return true;
}


/*
 *		回调函数menuItemFont2Func
 */

//变化menuItemFont1的内容
void HelloWorld::menuItemFont2Func(CCObject* sender)
{
	
//获取menuItemFont2
	CCMenuItemFont* menuItemFont2 = (CCMenuItemFont*)sender;

//从CCLayer中获取CCMenu菜单
	CCMenu* menu = (CCMenu*)this->getChildByTag(100);

//获取menuItemFont1，其tag为1
	//！！！注意！！！
	//		tag是相对父节点而言的：this的子节点中没有tag为1，而menuItemFont1是menu中tag为1的子节点。
	CCMenuItemFont* menuItemFont1 = (CCMenuItemFont*)menu->getChildByTag(1);
	

//更改menuItemFont1的内容
	//获取menuItemFont2显示的标签内容
	CCLabelTTF* lb = (CCLabelTTF*)menuItemFont2->getLabel();

	//strcmp判断是否等于Change1
	if( strcmp( lb->getString() , "Change1") == 0 ) { 
		lb->setString("Change2");
		menuItemFont1->setString("22222");
	}else {
		lb->setString("Change1");
		menuItemFont1->setString("11111");
	}
}


/*
 *		回调函数menuItemToggleFunc
 */

//更改状态:正常,选中,禁用
void HelloWorld::menuItemToggleFunc(CCObject* sender)
{
	
//获取menuItemToggle
	CCMenuItemToggle* menuItemToggle = (CCMenuItemToggle*)sender;

//从CCLayer中获取CCMenu菜单
	CCMenu* menu = (CCMenu*)this->getChildByTag(100);

//获取menuItemSprite
	CCMenuItemSprite* menuItemSprite = (CCMenuItemSprite*)menu->getChildByTag(2);


//根据menuItemToggle当前被选中的是哪一项,来设置menuItemSprite的状态
	switch( menuItemToggle->getSelectedIndex() ) {
		case 0: //正常
			menuItemSprite->setEnabled(true);
			break;
		case 1: //选中
			menuItemSprite->selected();
			break;
		case 2: //禁用
			menuItemSprite->setEnabled(false);
			break;
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
