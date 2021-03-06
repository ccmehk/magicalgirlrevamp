#include "ChooseLayer.h"
#include "GameScene.h"
#include "HeroMessageUtil.h"
#include "StageMessageUtil.h"
#include "MenuScene.h"
#include "StoryScene.h"

bool ChooseLayer::init(){
	/*
	sfc = SpriteFrameCache::getInstance();
	sfc->addSpriteFramesWithFile("showClick.plist");
	ms = Sprite::createWithSpriteFrameName("showClick.png");
	addChild(ms);
	*/
	pNode = GUIReader::getInstance()->widgetFromJsonFile("UI/ChooseLayerUI.json");
	this->addChild(pNode,0);

	Button* enterBtn = (Button*)Helper::seekWidgetByName(pNode,"stage1");
	enterBtn->addTouchEventListener(this,toucheventselector(ChooseLayer::enterStory1));

	Button* backBtn = (Button*)Helper::seekWidgetByName(pNode,"backBtn");
	backBtn->addTouchEventListener(this,toucheventselector(ChooseLayer::backToMenu));
	
	initHeroMsg();

	return true;
}

void ChooseLayer::initHeroMsg(){
	
	hero1 = nullptr;
	hero2 = nullptr;
	hero3 = nullptr;
}

HeroItem::HeroItem(const std::string& name,const int id,const std::string& resourceName,const int ox,const int oy){
	this->name = name;
	this->resourceName = resourceName;
	this->id = id;
	this->o_x = ox;
	this->o_y = oy;
}
HeroItem::~HeroItem(){

}

void ChooseLayer::enterStory1(Ref* pSender, TouchEventType type){
	if (type == TouchEventType::TOUCH_EVENT_ENDED){

		StoryScene* scene = StoryScene::create();
		Director::getInstance()->replaceScene(scene);
	}
}


void ChooseLayer::startGame(Ref* pSender,TouchEventType type){
	if(type == TouchEventType::TOUCH_EVENT_ENDED){


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

void ChooseLayer::startGame2(Ref* pSender, TouchEventType type){
	if (type == TouchEventType::TOUCH_EVENT_ENDED){

		GameScene* scene = GameScene::create();
		/*scene->setHeroTeam(
		HeroMessageUtil::getInstance()->getMessageById(heroArray[cur_hero1_index].id),
		HeroMessageUtil::getInstance()->getMessageById(heroArray[cur_hero2_index].id),
		HeroMessageUtil::getInstance()->getMessageById(heroArray[cur_hero3_index].id)
		);*/
		scene->setHeroTeam(
			HeroMessageUtil::getInstance()->getMessageById(1001),
			HeroMessageUtil::getInstance()->getMessageById(1002),
			HeroMessageUtil::getInstance()->getMessageById(1004));
		scene->setMonsterDeq(StageMessageUtil::getInstance()->getMessageById(3001).monsterDeq);
		Director::getInstance()->replaceScene(scene);
	}
}

void ChooseLayer::backToMenu(Ref* pSender,TouchEventType type){
	if(type == TouchEventType::TOUCH_EVENT_ENDED){
		Director::getInstance()->replaceScene(MenuScene::create());
	}
}