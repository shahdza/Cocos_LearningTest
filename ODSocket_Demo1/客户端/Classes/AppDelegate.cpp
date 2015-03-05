#include "AppDelegate.h"
#include "HelloWorldScene.h"

USING_NS_CC;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

bool AppDelegate::applicationDidFinishLaunching() {
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
        glview = GLView::create("My Game");
        glview->setFrameSize(480, 320);
        director->setOpenGLView(glview);
    }

    glview->setDesignResolutionSize(480, 320, ResolutionPolicy::SHOW_ALL);
    
    director->setDisplayStats(true);
    director->setAnimationInterval(1.0 / 60);

    auto scene = HelloWorld::createScene();
    director->runWithScene(scene);

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}

void AppDelegate::loadRecources()
{
    FileUtils::getInstance()->addSearchPath("fonts");
    FileUtils::getInstance()->addSearchPath("shader");
}

