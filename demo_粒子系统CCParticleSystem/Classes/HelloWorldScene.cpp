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

	testGravity();  //重力发射器模式
	//testRadius();   //半径发射器模式
	//testParticle(); //现成粒子特效 
	//testPlist();    //自定义plist粒子特效

	return true;
}

//------------------------------------------------------------------
// 重力发射器模式
//------------------------------------------------------------------
void HelloWorld::testGravity()
{
	CCPoint mysize = CCDirector::sharedDirector()->getVisibleSize();


	CCParticleSystemQuad* quad = CCParticleSystemQuad::create();
	this->addChild(quad,1,1);


//纹理图片
	quad->setTexture( CCTextureCache::sharedTextureCache()->addImage("HelloWorld.png") ); 


//混合模式
	ccBlendFunc cbl = { GL_SRC_ALPHA , GL_ONE};
	quad->setBlendFunc(cbl);


/********************/
/*     粒子属性     */
/********************/

//粒子生命，单位：秒
	quad->setLife(3);
	quad->setLifeVar(0.25);

//大小，-1表示和初始大小一致
	quad->setStartSize(100);
	quad->setStartSizeVar(0);
	quad->setEndSize(-1);
	quad->setEndSizeVar(0);

//颜色，ccc4f：取值0~1
	quad->setStartColor( ccc4f(192/255.0, 63/255.0, 63/255.0, 63/255.0) );
	quad->setStartColorVar( ccc4f(0, 0, 0, 0) );
	quad->setEndColor( ccc4f(0, 0, 0, 0) );
	quad->setEndColorVar( ccc4f(0, 0, 0, 0) );

//旋转角度
	quad->setStartSpin(0);
	quad->setStartSpinVar(60);
	quad->setEndSpin(180);
	quad->setEndSpinVar(30);

//发射角度
	quad->setAngle(90);
	quad->setAngleVar(10);


/********************/
/*  发射器子属性    */
/********************/

//最大粒子个数
	quad->setTotalParticles(1000); 

//粒子发射器持续时间，-1为永久
	quad->setDuration(-1);

//发射速率
	quad->setEmissionRate( quad->getTotalParticles()/quad->getLife() );

//发射器位置
	quad->setPosition( mysize/2 );
	quad->setPosVar( ccp(10,10) );


//重力模式
	quad->setEmitterMode(kCCParticleModeGravity); 

//粒子位置模式
	quad->setPositionType(kCCPositionTypeFree);

//粒子速度
	quad->setSpeed(60);
	quad->setSpeedVar(20);

//重力加速度
	quad->setGravity( ccp(0, 0) ); 

//径向加速度
	quad->setRadialAccel(0);
	quad->setRadialAccelVar(0);

//切向加速度
	quad->setTangentialAccel(0);
	quad->setTangentialAccelVar(0);

}


//半径发射器模式
void HelloWorld::testRadius()
{
	CCPoint mysize = CCDirector::sharedDirector()->getVisibleSize();


	CCParticleSystemQuad* quad = CCParticleSystemQuad::create();
	this->addChild(quad,1,1);


//纹理图片
	quad->setTexture( CCTextureCache::sharedTextureCache()->addImage("HelloWorld.png") ); 


//混合模式
	ccBlendFunc cbl = { GL_SRC_ALPHA , GL_ONE};
	quad->setBlendFunc(cbl);


/********************/
/*     粒子属性     */
/********************/

//粒子生命，单位：秒
	quad->setLife(3);
	quad->setLifeVar(0.25);

//大小，-1表示和初始大小一致
	quad->setStartSize(20);
	quad->setStartSizeVar(0);
	quad->setEndSize(-1);
	quad->setEndSizeVar(0);

//颜色，ccc4f：取值0~1
	quad->setStartColor( ccc4f(192/255.0, 63/255.0, 63/255.0, 63/255.0) );
	quad->setStartColorVar( ccc4f(0, 0, 0, 0) );
	quad->setEndColor( ccc4f(0, 0, 0, 0) );
	quad->setEndColorVar( ccc4f(0, 0, 0, 0) );

//旋转角度
	quad->setStartSpin(0);
	quad->setStartSpinVar(60);
	quad->setEndSpin(180);
	quad->setEndSpinVar(30);

//发射角度
	quad->setAngle(90);
	quad->setAngleVar(10);


/********************/
/*  发射器子属性    */
/********************/

//最大粒子个数
	quad->setTotalParticles(1000); 

//粒子发射器持续时间，-1为永久
	quad->setDuration(-1);

//发射速率
	quad->setEmissionRate( quad->getTotalParticles()/quad->getLife() );

//发射器位置
	quad->setPosition( mysize/2 );
	quad->setPosVar( ccp(10,10) );


//环形模式
	quad->setEmitterMode(kCCParticleModeRadius);

//粒子位置模式
	quad->setPositionType(kCCPositionTypeFree);


//初始半径
	quad->setStartRadius(20);
	quad->setStartRadiusVar(1);
	
//结束半径，-1和初始大小一致
	quad->setEndRadius(100);
	quad->setEndRadiusVar(1);

//粒子围绕初始点，每秒旋转角度
	quad->setRotatePerSecond(360);
	quad->setRotatePerSecondVar(1);

}


//现成粒子特效
void HelloWorld::testParticle()
{
	CCParticleFire* quad = CCParticleFire::create();
	this->addChild(quad,1,1);
}


//自定义plist粒子特效
void HelloWorld::testPlist()
{
	CCPoint mysize = CCDirector::sharedDirector()->getVisibleSize();

	CCParticleSystemQuad* quad = CCParticleSystemQuad::create("1.plist");
	quad->setPosition( mysize/2 );
	this->addChild(quad,1,1);
}



bool HelloWorld::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
	CCPoint pos =pTouch->getLocation();
	CCParticleSystemQuad* quad = (CCParticleSystemQuad*)this->getChildByTag(1);
	quad->setPosition(pos);

	return true;
}

void HelloWorld::ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent)
{
	CCPoint pos =pTouch->getLocation();
	CCParticleSystemQuad* quad = (CCParticleSystemQuad*)this->getChildByTag(1);
	quad->setPosition(pos);
}

void HelloWorld::ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent)
{

}

void HelloWorld::onEnter()
{
	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this,0,false);
	CCLayer::onEnter();
}

void HelloWorld::onExit()
{
	CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
	CCLayer::onExit();
}