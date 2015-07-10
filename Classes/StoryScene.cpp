#include "StoryScene.h"
#include "GameScene.h"
#include "HeroMessageUtil.h"
#include "StageMessageUtil.h"

bool StoryScene::init(){
	Widget* pNode = GUIReader::getInstance()->widgetFromJsonFile("UI/story_1.json");
	this->addChild(pNode, 0);

	Button* skipBtn = (Button*)Helper::seekWidgetByName(pNode, "skipBtn");
	skipBtn->addTouchEventListener(this, toucheventselector(StoryScene::skipStory));
	return true;
}

void StoryScene::skipStory(Ref* pSender, TouchEventType type){
	if (type == TouchEventType::TOUCH_EVENT_BEGAN){
		CCLOG("GAME CONTINUE");
		startGame(nullptr, TouchEventType::TOUCH_EVENT_ENDED);
	}
}

void StoryScene::startGame(Ref* pSender, TouchEventType type){
	if (type == TouchEventType::TOUCH_EVENT_ENDED){

		GameScene* scene = GameScene::create();
		/*scene->setHeroTeam(
		HeroMessageUtil::getInstance()->getMessageById(heroArray[cur_hero1_index].id),
		HeroMessageUtil::getInstance()->getMessageById(heroArray[cur_hero2_index].id),
		HeroMessageUtil::getInstance()->getMessageById(heroArray[cur_hero3_index].id)
		);*/
		scene->setHeroTeam(
			HeroMessageUtil::getInstance()->getMessageById(1001));
		scene->setMonsterDeq(StageMessageUtil::getInstance()->getMessageById(3003).monsterDeq);
		Director::getInstance()->replaceScene(scene);
	}
}