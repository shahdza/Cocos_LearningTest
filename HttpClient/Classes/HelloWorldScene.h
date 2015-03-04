#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
USING_NS_CC;

#include "network/HttpClient.h"
using namespace network;

class HelloWorld : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    CREATE_FUNC(HelloWorld);

public:
    void onHttpRequest(std::string type);
    void onHttpResponse(HttpClient* sender, HttpResponse* response);
};

#endif // __HELLOWORLD_SCENE_H__
