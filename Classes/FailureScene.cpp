#include "FailureScene.h"

bool FailureScene::init(){
	Widget* pNode = GUIReader::getInstance()->widgetFromJsonFile("UI/PauseUI.json");
	this->addChild(pNode, 0);

	Button* continueBtn = (Button*)Helper::seekWidgetByName(pNode, "continueBtn");
	continueBtn->addTouchEventListener(this, toucheventselector(FailureScene::continueGame));
	Button* stopBtn = (Button*)Helper::seekWidgetByName(pNode, "stopBtn");
	stopBtn->addTouchEventListener(this, toucheventselector(FailureScene::stopGame));
	return true;
}

void FailureScene::continueGame(Ref* pSender, TouchEventType type){
	if (type == TouchEventType::TOUCH_EVENT_BEGAN){
		CCLOG("GAME CONTINUE");
		Director::getInstance()->popScene();
	}
}

void FailureScene::stopGame(Ref* pSender, TouchEventType type){
	if (type == TouchEventType::TOUCH_EVENT_BEGAN){
		CCLOG("GAME STOP");
		Director::getInstance()->replaceScene(ChooseScene::create());
	}
}