#ifndef _CHOOSELAYER_H_
#define _CHOOSELAYER_H_
#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"
#include "extensions/cocos-ext.h"
USING_NS_CC;
using namespace cocostudio;
using namespace ui;
class HeroItem;
class ChooseLayer : public Layer{
public:
	virtual bool init();
	CREATE_FUNC(ChooseLayer);

	void startGame(Ref* pSender, ui::TouchEventType type);
	void startGame2(Ref* pSender, ui::TouchEventType type);

	void enterStory1(Ref* pSender, ui::TouchEventType type);
private:
	//���ؿ�ѡӢ��
	void loadHeroes();
	//��ʼ��
	void initHeroMsg();
	
	void backToMenu(Ref* pSender,ui::TouchEventType type);

private:
	Widget* pNode;


	Armature* hero1;
	Armature* hero2;
	Armature* hero3;

	friend class FailureScene;
	SpriteFrameCache* sfc;
	Sprite* ms;
};

class HeroItem : public Ref{
friend class ChooseLayer;
public:
	HeroItem(const std::string& name,const int id,const std::string& resourceName,const int o_x,const int o_y);
	~HeroItem();
private:
	std::string name;
	std::string resourceName;
	int id;
	int o_x;
	int o_y;
};
#endif