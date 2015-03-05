#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
USING_NS_CC;

#include "ODSocket/ODSocket.h"

class HelloWorld : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    CREATE_FUNC(HelloWorld);
    
public:
    void connectServer();
    void receiveData();
    
private:
    Size size;
    ODSocket socket;
};

#endif // __HELLOWORLD_SCENE_H__
