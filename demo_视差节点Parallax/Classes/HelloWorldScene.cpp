// V3.4
#include "HelloWorldScene.h"
USING_NS_CC;


Scene* HelloWorld::createScene()
{
    auto scene = Scene::create();
    auto layer = HelloWorld::create();
    scene->addChild(layer);
    return scene;
}


bool HelloWorld::init()
{
    if ( !Layer::init() ) return false;

//[1] 可视区域尺寸大小
    Size vSize = Director::getInstance()->getVisibleSize();
    
    
//[2] 创建子节点
    Sprite* bg = Sprite::create("HelloWorld.png");
    bg->setAnchorPoint(Vec2(0, 0)); // 锚点(0, 0)
    bg->setName("HelloWorld");
    
    //Bug: 在ParallaxNode上的精灵，对其setPosition是无效的
    //     具体看运行结果
    bg->setPosition(Vec2(100, 100)); // 设置bg的坐标位置
    
    Sprite* ball = Sprite::create("Ball.png");
    ball->setAnchorPoint(Vec2(0.5, 0.5)); // 锚点(0.5, 0.5)
    ball->setName("Ball");
    
    Sprite* smile = Sprite::create("Smile.png");
    smile->setAnchorPoint(Vec2(0, 0)); // 锚点(0, 0)
    smile->setName("Smile");

    
//[3] 创建ParallaxNode，并添加子节点
    // 创建视差节点类
    ParallaxNode* parallaxNode = ParallaxNode::create();
    this->addChild(parallaxNode, 0, "parallaxNode");
    
    // 添加子节点
    //  addChild(node, zOrder, ratio, offset);
    parallaxNode->addChild(bg, 0, Vec2(0.5, 0.5), Vec2(0, 0));
    parallaxNode->addChild(ball, 1, Vec2(1, 1), Vec2(vSize.width/2, vSize.height/2));
    parallaxNode->addChild(smile, 1, Vec2(4, 4), Vec2(0, 0));
    
    
//[4] 添加触摸事件
    this->addTouch();
    
    return true;
}


void HelloWorld::addTouch()
{
    EventDispatcher* dispatcher = this->getEventDispatcher();
    EventListenerTouchOneByOne* listener = EventListenerTouchOneByOne::create();
    listener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);
    listener->onTouchMoved = CC_CALLBACK_2(HelloWorld::onTouchMoved, this);
    listener->onTouchEnded = CC_CALLBACK_2(HelloWorld::onTouchEnded, this);
    dispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}


bool HelloWorld::onTouchBegan(Touch* pTouch, Event* pEvent)
{
    return true;
}

// 移动 ParallaxNode 节点
void HelloWorld::onTouchMoved(Touch* pTouch, Event* pEvent)
{
    Vec2 delta = pTouch->getDelta();
    // 移动 ParallaxNode 节点
    // 所有子节点的位置，也会随之改变
    ParallaxNode* parallaxNode = (ParallaxNode*)this->getChildByName("parallaxNode");
    parallaxNode->setPosition(parallaxNode->getPosition() + delta);
}

// 触摸结束后，输出每个节点的位置信息
void HelloWorld::onTouchEnded(Touch* pTouch, Event* pEvent)
{
    ParallaxNode* parallaxNode = (ParallaxNode*)this->getChildByName("parallaxNode");
    // 按名称获取子节点
    Sprite* bg = (Sprite*)parallaxNode->getChildByName("HelloWorld");
    Sprite* ball = (Sprite*)parallaxNode->getChildByName("Ball");
    Sprite* smile = (Sprite*)parallaxNode->getChildByName("Smile");
    
    // 输出坐标位置信息
    CCLOG("parallax   : %f %f", parallaxNode->getPositionX(), parallaxNode->getPositionY());
    CCLOG("HelloWorld : %f %f", bg->getPositionX(), bg->getPositionY());
    CCLOG("ball       : %f %f", ball->getPositionX(), ball->getPositionY());
    CCLOG("smile      : %f %f", smile->getPositionX(), smile->getPositionY());
    CCLOG("---------------------------------------");
}

