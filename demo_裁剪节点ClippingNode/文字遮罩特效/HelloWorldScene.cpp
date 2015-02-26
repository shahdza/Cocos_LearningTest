#include "HelloWorldScene.h"
#include "AppMacros.h"

USING_NS_CC;
using namespace std;



Scene* HelloWorld::scene()
{
	Scene* scene = Scene::create();

	HelloWorld* layer = HelloWorld::create();
    scene->addChild(layer);
    return scene;
}


bool HelloWorld::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    visibleSize = Director::getInstance()->getVisibleSize();
	winSize = Director::getInstance()->getWinSize();
    origin = Director::getInstance()->getVisibleOrigin();


	Sprite* bg = Sprite::create("HelloWorld.png");
	bg->setPosition(visibleSize / 2);
	//this->addChild(bg, -1);


	Sprite* gameTitle = Sprite::create("game_title.png");

	Size clipSize = gameTitle->getContentSize();

	Sprite* spark = Sprite::create("spark.png");
	spark->setPosition(-clipSize.width, 0);


	ClippingNode* clippingNode = ClippingNode::create();
	clippingNode->setAlphaThreshold(0);
	clippingNode->setContentSize(clipSize);
	clippingNode->setPosition(visibleSize / 2);
	this->addChild(clippingNode);


	clippingNode->setStencil(gameTitle);   //设置模板

	clippingNode->addChild(gameTitle, 1);  //先添加标题,会完全显示出来,因为跟模板一样大小
	clippingNode->addChild(spark,2);       //会被裁减
	

	MoveTo* moveAction = MoveTo::create(2.0f, Vec2(clipSize.width, 0));
	MoveTo* moveBackAction = MoveTo::create(2.0f, Vec2(-clipSize.width, 0));
	Sequence* seq = Sequence::create(moveAction, moveBackAction, NULL);
	RepeatForever* repeatAction = RepeatForever::create(seq);
	spark->runAction(repeatAction); //进行左右移动的重复动作

    return true;
}


