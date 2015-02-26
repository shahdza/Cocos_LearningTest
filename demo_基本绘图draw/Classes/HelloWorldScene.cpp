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

	CCSize mysize = CCDirector::sharedDirector()->getVisibleSize();

	CCSprite* bg = CCSprite::create("HelloWorld.png");
	bg->setPosition(mysize/2);
	this->addChild(bg,-1);

	return true;
}


void HelloWorld::draw()
{

//屏幕尺寸大小
	CCSize mysize = CCDirector::sharedDirector()->getVisibleSize();


//点
	//一个点
	ccPointSize(10);
	ccDrawColor4B(255, 25, 200, 250);
	ccDrawPoint(mysize/2);

	//多个点
	ccPointSize(30);
	ccDrawColor4B(255, 0, 0, 100);
	CCPoint Pointarray[] = {ccp(200, 150), ccp(200, 200), ccp(280, 150), ccp(280, 200)};
	ccDrawPoints(Pointarray, 4);


//直线
	glLineWidth(3);
	ccDrawColor4B(255, 255, 255, 130);
	ccDrawLine(ccp(10, 300), ccp(200, 300) );


//圆
	glLineWidth(3);
	ccDrawColor4B(255, 255, 100, 190);
	ccDrawCircle(ccp(50, 250), 40, 3.14/2, 360, true, 1, 0.5);


//矩形
	//空心
	glLineWidth(5);
	ccDrawColor4B(24, 25, 200, 140);
	ccDrawRect(ccp(10, 150), ccp(110, 200));

	//实心
	ccDrawSolidRect(ccp(10, 90), ccp(100, 140), ccc4f(255, 255, 255, 0.5f));


//多边形
	//空心
	glLineWidth(10);
	ccDrawColor4B(240, 225, 100, 130);
	CCPoint Polyarray[] = {ccp(20, 20), ccp(50, 0), ccp(250, 100), ccp(300, 100), ccp(250, 50)};
	ccDrawPoly(Polyarray, 5, 1); 

	//实心
	CCPoint Polyarray2[] = {ccp(250,30), ccp(280,300), ccp(450,0), ccp(410,130), ccp(420,50)};
	ccDrawSolidPoly(Polyarray2, 5, ccc4f(142, 245, 70, 0.3f)); 


//贝赛尔曲线
	//平面
	glLineWidth(5);
	ccDrawColor4B(100, 100, 100, 255);
	ccDrawQuadBezier(ccp(0,320), ccp(160,100), ccp(480,320), 100); 

	//立体
	glLineWidth(5);
	ccDrawColor4B(200, 200, 200, 255);
	ccDrawCubicBezier(ccp(0,0), ccp(160,300), ccp(320,20), ccp(480,320), 100);
}

