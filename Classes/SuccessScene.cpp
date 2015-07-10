#include "SuccessScene.h"
#include "ChooseLayer.h"

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
		auto chooseLayer = ChooseLayer::create();
		chooseLayer->startGame2(nullptr, TouchEventType::TOUCH_EVENT_ENDED);
	}
}