#ifndef _FAILURE_SCENE_H_
#define _FAILURE_SCENE_H_
#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"
#include "extensions/cocos-ext.h"
#include "ChooseScene.h"
using namespace cocostudio;
using namespace ui;
using namespace cocos2d;
class FailureScene : public Scene{
public:
	virtual bool init();
	CREATE_FUNC(FailureScene);
private:
	void restartGame(Ref* pSender, TouchEventType type);
	void backToMenu(Ref* pSender, TouchEventType type);
};
#endif