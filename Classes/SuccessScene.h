#ifndef _SUCCESS_SCENE_H_
#define _SUCCESS_SCENE_H_
#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"
#include "extensions/cocos-ext.h"
#include "ChooseScene.h"
using namespace cocostudio;
using namespace ui;
using namespace cocos2d;
class SuccessScene : public Scene{
public:
	virtual bool init();
	CREATE_FUNC(SuccessScene);
private:
	void continueGame(Ref* pSender, TouchEventType type);
};
#endif