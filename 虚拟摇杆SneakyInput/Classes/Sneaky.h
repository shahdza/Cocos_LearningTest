#ifndef __SNEAKY_H__
#define __SNEAKY_H__

#include "cocos2d.h"
using namespace cocos2d;

#include "SneakyInput/SneakyButtonSkinnedBase.h"
#include "SneakyInput/SneakyJoystickSkinnedBase.h"

class Sneaky : public CCLayer
{
public :
	Sneaky();
	bool init();

	SneakyButton* buttonA;
	SneakyButton* buttonB;
	SneakyJoystick* joystick;

	//void inputUpdate(float dt);
};

#endif //__SNEAKY_H__