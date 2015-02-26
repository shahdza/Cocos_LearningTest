#include "SneakyButtonSkinnedBase.h"

using namespace cocos2d;

SneakyButtonSkinnedBase::~SneakyButtonSkinnedBase()
{
	if (defaultSprite)
	{
		defaultSprite->release();
		defaultSprite = NULL;
	}
	if (activatedSprite)
	{
		activatedSprite->release();
		activatedSprite = NULL;
	}
	if (disabledSprite)
	{
		disabledSprite->release();
		disabledSprite = NULL;
	}
	if (pressSprite)
	{
		pressSprite->release();
		pressSprite = NULL;
	}
	if (button)
	{
		button->release();
		button = NULL;
	}
}

bool SneakyButtonSkinnedBase::init() //Possible errors here
{
	bool pRet = false;
	if(CCLayer::init()){
		this->defaultSprite = NULL;
		//defaultSprite->retain();
		this->activatedSprite = NULL;
		//activatedSprite->retain();
		this->disabledSprite = NULL;
		//disabledSprite->retain();
		this->pressSprite = NULL;
		//pressSprite->retain();
		this->button = NULL;
		//button->retain();

		this->schedule(schedule_selector(SneakyButtonSkinnedBase::watchSelf));
		pRet = true;
	}
	return pRet;
}

void SneakyButtonSkinnedBase::watchSelf(float delta) //Be Careful Here
{
	if (!this->button->getStatus()){
		if(disabledSprite){
			disabledSprite->setVisible(true);
		}
		else {
			disabledSprite->setVisible(false);
		}
	}
	else {
		if(!this->button->getIsActive()){
			pressSprite->setVisible(false);
			if(this->button->getValue() == false){
				activatedSprite->setVisible(false);
				if(defaultSprite){
					defaultSprite->setVisible(true);
				}
			}
			else {
				activatedSprite->setVisible(true);
			}
		}
		else {
			defaultSprite->setVisible(false);
			if(pressSprite){
				pressSprite->setVisible(true);
			}
		}
	}
}

void SneakyButtonSkinnedBase::setContentSize(CCSize s)
{
	CCLayer::setContentSize(s);
	////////defaultSprite->setContentSize(s);
	//button->setRadius(s.width/2);
}

void SneakyButtonSkinnedBase::setDefaultSprite(CCSprite *aSprite)
{
	if(defaultSprite){
		if(defaultSprite->getParent())
			defaultSprite->getParent()->removeChild(defaultSprite, true);
		defaultSprite->release();
	}
	aSprite->retain();
	defaultSprite = aSprite; //Check again here
	if(aSprite){
		this->addChild(defaultSprite, 0);

		this->setContentSize(defaultSprite->getContentSize());
	}
}

void SneakyButtonSkinnedBase::setActivatedSprite(CCSprite *aSprite)
{
	if(activatedSprite){
		if(activatedSprite->getParent())
			activatedSprite->getParent()->removeChild(activatedSprite, true);
		activatedSprite->release();
	}
	aSprite->retain();
	activatedSprite = aSprite;
	if(aSprite){
		this->addChild(activatedSprite, 1);
		
		this->setContentSize(activatedSprite->getContentSize());
	}
}

void SneakyButtonSkinnedBase::setDisabledSprite(CCSprite *aSprite)
{
	if(disabledSprite){
		if(disabledSprite->getParent())
			disabledSprite->getParent()->removeChild(disabledSprite, true);
		disabledSprite->release();
	}
	aSprite->retain();
	disabledSprite = aSprite;
	if(aSprite){
		this->addChild(disabledSprite, 2);
		
		this->setContentSize(disabledSprite->getContentSize());
	}
}

void SneakyButtonSkinnedBase::setPressSprite(CCSprite *aSprite)
{
	if(pressSprite){
		if(pressSprite->getParent())
			pressSprite->getParent()->removeChild(pressSprite, true);
		pressSprite->release();
	}
	aSprite->retain();
	pressSprite = aSprite;
	if(aSprite){
		this->addChild(pressSprite, 3);
		
		this->setContentSize(pressSprite->getContentSize());
	}
}

void SneakyButtonSkinnedBase::setButton(SneakyButton *aButton)
{
	if(button){
		if(button->getParent())
			button->getParent()->removeChild(button, true);
		button->release();
	}
	aButton->retain();
	button = aButton;
	if(aButton){
		this->addChild(button, 4);
		if(defaultSprite)
			button->setRadius(defaultSprite->boundingBox().size.width/2);
	}
}
