#include "SuccessScene.h"

bool SuccessScene::init(){
	Widget* pNode = GUIReader::getInstance()->widgetFromJsonFile("UI/SuccessUi.json");
	this->addChild(pNode, 0);

	Button* continueBtn = (Button*)Helper::seekWidgetByName(pNode, "continueBtn");
	continueBtn->addTouchEventListener(this, toucheventselector(SuccessScene::continueGame));
	return true;
}

void SuccessScene::continueGame(Ref* pSender, TouchEventType type){
	if (type == TouchEventType::TOUCH_EVENT_BEGAN){
		CCLOG("GAME CONTINUE");
		Director::getInstance()->replaceScene(ChooseScene::create());
	}
}