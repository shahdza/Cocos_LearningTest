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


//[1].背景图片(Layer层中)
	Sprite* bg = Sprite::create("HelloWorld.png");
	bg->setPosition(visibleSize / 2);
	this->addChild(bg);


//[2].创建裁剪节点 : holesClipper
	holesClipper = ClippingNode::create();
	holesClipper->setPosition(visibleSize / 2);
	this->addChild(holesClipper);

	//属性设置
	holesClipper->setInverted(true);        //倒置显示，未被裁剪下来的剩余部分
	holesClipper->setAlphaThreshold(0.5f);  //设置alpha透明度闸值
	holesClipper->runAction(RepeatForever::create(RotateBy::create(1, 45))); //旋转动作


//[3].创建模板 : holesStencil
	holesStencil = Node::create();
	holesClipper->setStencil(holesStencil); //设置模板节点

	//添加一个模板遮罩 ball
	holesStencil->addChild(Sprite::create("ball.png"), -1);


//[4].创建底板 : holes
	holes = Node::create();
	holesClipper->addChild(holes); //设置底板

	//添加另一个底板内容 blocks
	Sprite* content = Sprite::create("blocks.png");
	holesClipper->addChild(content, -1, "content");


//[5].触摸事件
	auto listener = EventListenerTouchAllAtOnce::create();
	listener->onTouchesBegan = CC_CALLBACK_2(HelloWorld::onTouchesBegan, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);


    return true;
}

void HelloWorld::onTouchesBegan(const std::vector<Touch*>& touches, Event *unused_event)
{
//[1].获取触点, 转换为相对holesClipper节点的 相对坐标
	Vec2 point = touches[0]->getLocation();
	point = holesClipper->convertToNodeSpace(point);


//[2].获取底板区域矩形Rect
	Sprite* content = (Sprite*)this->getChildByName("content");
	Size contentSize = content->getContentSize();
	Rect rect = Rect(-contentSize.width / 2, -contentSize.height / 2, contentSize.width, contentSize.height);


//[3].触摸点在底板内部, 进行"打洞"
	if (rect.containsPoint(point))
	{
		pokeHoleAtPoint(point);
	}
}

void HelloWorld::pokeHoleAtPoint(Vec2 point)
{
	CCLOG("Add a Hole!!!");


//[1].添加底板内容 : 一个洞的痕迹
	auto hole = Sprite::create("hole_effect.png");
	hole->setPosition(point);
	holes->addChild(hole);


//[2].添加模板内容 : 一个小洞
	auto holeStencil = Sprite::create("hole_stencil.png");
	holeStencil->setPosition(point);
	holesStencil->addChild(holeStencil);


//[3].动作效果 : 放大缩小
	holesClipper->runAction(Sequence::create(ScaleTo::create(0.05f, 1.05f), ScaleTo::create(0.05f, 1.0f), NULL));
}