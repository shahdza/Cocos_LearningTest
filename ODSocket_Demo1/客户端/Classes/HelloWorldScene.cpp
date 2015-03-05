#include "HelloWorldScene.h"
USING_NS_CC;

#include "ODSocket/ODSocket.h"

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
    
    connectServer();
    
    return true;
}


// Socker连接
void HelloWorld::connectServer()
{
    // 初始化
    // ODSocket socket;
    socket.Init();
    socket.Create(AF_INET, SOCK_STREAM, 0);
    
    // 设置服务器的IP地址，端口号
    // 并连接服务器 Connect
    const char* ip = "127.0.0.1";
    int port = 12345;
    bool result = socket.Connect(ip, port);
    
    // 发送数据 Send
    socket.Send("login", 5);
    
    if (result) {
        CCLOG("connect to server success!");
        // 开启新线程，在子线程中，接收数据
        std::thread recvThread = std::thread(&HelloWorld::receiveData, this);
        recvThread.detach(); // 从主线程分离
    }
    else {
        CCLOG("can not connect to server");
        return;
    }
}

// 接收数据
void HelloWorld::receiveData()
{
    // 因为是强联网
    // 所以可以一直检测服务端是否有数据传来
    while (true) {
        // 接收数据 Recv
        char data[512] = "";
        int result = socket.Recv(data, 512, 0);
        printf("%d", result);
        // 与服务器的连接断开了
        if (result <= 0) break;
        
        CCLOG("%s", data);
    }
    // 关闭连接
    socket.Close();
}

