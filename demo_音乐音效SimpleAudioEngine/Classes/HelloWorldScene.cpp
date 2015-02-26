#include "HelloWorldScene.h"

USING_NS_CC;


//音效文件
//Android平台只支持OGG的音效格式
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	#define EFFECT_FILE        "music/effect2.ogg"
#elif( CC_TARGET_PLATFORM == CC_PLATFORM_MARMALADE)
	#define EFFECT_FILE        "music/effect1.raw"
#else
	#define EFFECT_FILE        "music/effect1.wav"
#endif

//音乐文件
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
#define MUSIC_FILE        "music/music.mid"
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_BLACKBERRY || CC_TARGET_PLATFORM == CC_PLATFORM_LINUX )
#define MUSIC_FILE        "music/background.ogg"
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
#define MUSIC_FILE        "music/background.wav"
#else
#define MUSIC_FILE        "music/background.mp3"
#endif



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

//预加载音乐音效
	SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic(MUSIC_FILE);
	SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic(EFFECT_FILE);


//创建控制音乐音效的菜单按钮
	std::string testItems[] = {
		"play background music",
		"stop background music",
		"pause background music",
		"resume background music",
		"rewind background music",
		"is background music playing",

		"play effect",
		"play effect repeatly",
		"stop effect",
		"pause effect",
		"resume effect",
		"pause all effects",
		"resume all effects",
		"stop all effects",
		"unload effect",

		"add background music volume",
		"sub background music volume",
		"add effects volume",
		"sub effects volume"
	};

//创建菜单
	CCMenu* pMenu = CCMenu::create();
	pMenu->setContentSize(CCSizeMake(480,1000));

	for (int i = 0; i < 19; ++i)
	{
		CCLabelTTF* label = CCLabelTTF::create(testItems[i].c_str(), "Arial", 24);
		CCMenuItemLabel* pMenuItem = CCMenuItemLabel::create(label, this, menu_selector(HelloWorld::menuCallback));
		pMenuItem->setPosition( ccp(mysize.width/2, 1000 - (i+1)*50 ) );
		pMenu->addChild(pMenuItem, 0, i);
	}


//将菜单作为容器，放入滚动视图中
	CCScrollView* scrollView = CCScrollView::create(CCSizeMake(480, 320), pMenu);
	scrollView->setDirection(kCCScrollViewDirectionVertical);
	scrollView->setPosition(CCPointZero);
	pMenu->setPosition( ccp(0, 320-1000) );
	this->addChild(scrollView);


	return true;
}


void HelloWorld::menuCallback(CCObject* sender)
{

//获取菜单按钮编号
	int idx = ((CCMenuItem*)sender)->getTag();


	switch(idx)
	{
//音乐控制
	case 0: SimpleAudioEngine::sharedEngine()->playBackgroundMusic(MUSIC_FILE, true); break; //播放音乐，循环
	case 1: SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();                 break; //停止音乐
	case 2: SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();                break; //暂停音乐
	case 3: SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();               break; //恢复音乐
	case 4: SimpleAudioEngine::sharedEngine()->rewindBackgroundMusic();               break; //重播音乐
	case 5:
		if (SimpleAudioEngine::sharedEngine()->isBackgroundMusicPlaying())                   //是否正在播放背景音乐
		{
			CCLOG("background music is playing");
		}
		else
		{
			CCLOG("background music is not playing");
		}
		break;

//音效控制
	case 6: m_soundID = SimpleAudioEngine::sharedEngine()->playEffect(EFFECT_FILE);        break; //播放音效，不循环
	case 7: m_soundID = SimpleAudioEngine::sharedEngine()->playEffect(EFFECT_FILE, true);  break; //播放音效，循环
	case 8: SimpleAudioEngine::sharedEngine()->stopEffect(m_soundID);                      break; //停止指定ID的音效
	case 9: SimpleAudioEngine::sharedEngine()->pauseEffect(m_soundID);                     break; //暂停指定ID的音效
	case 10: SimpleAudioEngine::sharedEngine()->resumeEffect(m_soundID);                   break; //恢复指定ID的音效
	case 11: SimpleAudioEngine::sharedEngine()->pauseAllEffects();                         break; //暂停所有音效
	case 12: SimpleAudioEngine::sharedEngine()->resumeAllEffects();                        break; //恢复所有音效
	case 13: SimpleAudioEngine::sharedEngine()->stopAllEffects();                          break; //停止所有音效
	case 14: SimpleAudioEngine::sharedEngine()->unloadEffect(EFFECT_FILE);                 break; //卸载音效

//音量控制
	case 15:
		SimpleAudioEngine::sharedEngine()->setBackgroundMusicVolume(SimpleAudioEngine::sharedEngine()->getBackgroundMusicVolume() + 0.1f);
		break;
	case 16:
		SimpleAudioEngine::sharedEngine()->setBackgroundMusicVolume(SimpleAudioEngine::sharedEngine()->getBackgroundMusicVolume() - 0.1f);
		break;
	case 17:
		SimpleAudioEngine::sharedEngine()->setEffectsVolume(SimpleAudioEngine::sharedEngine()->getEffectsVolume() + 0.1f);
		break;
	case 18:
		SimpleAudioEngine::sharedEngine()->setEffectsVolume(SimpleAudioEngine::sharedEngine()->getEffectsVolume() - 0.1f);
		break;
	}

}