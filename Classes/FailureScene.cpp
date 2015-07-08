#include "FailureScene.h"
#include "ChooseLayer.h"

bool FailureScene::init(){
	Widget* pNode = GUIReader::getInstance()->widgetFromJsonFile("UI/FailureUi.json");
	this->addChild(pNode, 0);

	Button* restartBtn = (Button*)Helper::seekWidgetByName(pNode, "restartBtn");
	restartBtn->addTouchEventListener(this, toucheventselector(FailureScene::restartGame));
	Button* backBtn = (Button*)Helper::seekWidgetByName(pNode, "backBtn");
	backBtn->addTouchEventListener(this, toucheventselector(FailureScene::backToMenu));
	return true;
}

void FailureScene::restartGame(Ref* pSender, TouchEventType type){
	if (type == TouchEventType::TOUCH_EVENT_BEGAN){
		CCLOG("GAME CONTINUE");
		auto chooseLayer = ChooseLayer::create();
		chooseLayer->startGame(nullptr, TouchEventType::TOUCH_EVENT_ENDED);
	}
}

void FailureScene::backToMenu(Ref* pSender, TouchEventType type){
	if (type == TouchEventType::TOUCH_EVENT_BEGAN){
		CCLOG("GAME STOP");
		Director::getInstance()->replaceScene(ChooseScene::create());
	}
}