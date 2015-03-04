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
    
    onHttpRequest("get");
    CCLOG("----------------------------");
    onHttpRequest("post");
    
    return true;
}


// 发送HTTP请求
void HelloWorld::onHttpRequest(std::string type)
{
    // 创建HTTP请求
    HttpRequest* request = new HttpRequest();
    
    if (type == "get")
    {
        request->setRequestType(HttpRequest::Type::GET);
        // url后面附加数据信息
        request->setUrl("http://httpbin.org/get?name=hello&pwd=world");
    }
    else if(type == "post")
    {
        request->setRequestType(HttpRequest::Type::POST);
        request->setUrl("http://httpbin.org/post");
        // 设置post发送请求的数据信息
        std::string data = "hello world!";
        request->setRequestData(data.c_str(), data.length());
    }
    
    // HTTP响应函数
    request->setResponseCallback(CC_CALLBACK_2(HelloWorld::onHttpResponse, this));
    
    // 发送请求
    HttpClient::getInstance()->send(request);
    
    // 释放链接
    request->release();
}


// HTTP响应请求函数
void HelloWorld::onHttpResponse(HttpClient* sender, HttpResponse* response)
{
    // 没有收到响应
    if (!response)
    {
        CCLOG("no response");
        return;
    }

    int statusCode = response->getResponseCode();
    char statusString[64] = {};
    sprintf(statusString, "HTTP Status Code: %d, tag = %s", statusCode, response->getHttpRequest()->getTag());
    CCLOG("response code: %s", statusString);

    // 链接失败
    if (!response->isSucceed())
    {
        CCLOG("response failed");
        CCLOG("error buffer: %s", response->getErrorBuffer());
        return;
    }

    // 获取数据
    std::vector<char>* v = response->getResponseData();
    for (int i = 0; i < v->size(); i++)
    {
        printf("%c", v->at(i));
    }
    printf("\n");
}

