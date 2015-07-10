#ifndef _STORY_SCENE_H_
#define _STORY_SCENE_H_
#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"
#include "extensions/cocos-ext.h"
#include "ChooseScene.h"
using namespace cocostudio;
using namespace ui;
using namespace cocos2d;
class StoryScene : public Scene{
public:
	virtual bool init();
	CREATE_FUNC(StoryScene);

	void startGame(Ref* pSender, TouchEventType type);
private:
	void skipStory(Ref* pSender, TouchEventType type);
};
#endif