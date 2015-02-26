#include "HelloWorldScene.h"

USING_NS_CC;

#include <string>
using namespace std;

#define UserDefault CCUserDefault::sharedUserDefault()


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

	CCSize mysize = CCDirector::sharedDirector()->getVisibleSize();


	CCLabelTTF* label = CCLabelTTF::create("CCUserDefault test see log", "Arial", 28);
	label->setPosition( mysize/2 );
	this->addChild(label);
	

//设置set
	UserDefault->setBoolForKey(   "bool",    true);
	UserDefault->setIntegerForKey("integer", 100);
	UserDefault->setFloatForKey(  "float",   33.33f);
	UserDefault->setDoubleForKey( "double",  44.44);
	UserDefault->setStringForKey( "string",  "1111111");


//获取get，并输出到控制台
	//通过关键字，获取数据
	bool b = UserDefault->getBoolForKey("bool");
	int i = UserDefault->getIntegerForKey("integer");
	float f = UserDefault->getFloatForKey("float");
	double d = UserDefault->getDoubleForKey("double");
	string ret = UserDefault->getStringForKey("string");

	//输出到控制台
	CCLOG( (b == true)? "bool is true" : "bool is false" );
	CCLOG("integer is %d", i);
	CCLOG("float is %f", f);
	CCLOG("double is %f", d);
	CCLOG("string is %s", ret.c_str());


//输出XML文件路径
	if( UserDefault->isXMLFileExist() ) //是否存在
	{
		string path = UserDefault->getXMLFilePath();
		CCLOG("XML file is exist!");
		CCLOG( "XML file path : %s", path.c_str() );
	}
	else
	{
		CCLOG("XML file is not exist!");
	}


//保存数据
	UserDefault->flush();


	return true;
}

