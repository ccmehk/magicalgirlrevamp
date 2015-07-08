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
private:
	//加载可选英雄
	void loadHeroes();
	//初始化
	void initHeroMsg();
	//设置当前英雄
	//void setCurHeroMsg(int index,int heroIndex);

	//按钮回调函数
	void startGame(Ref* pSender,ui::TouchEventType type);
	
	void backToMenu(Ref* pSender,ui::TouchEventType type);

private:
	Widget* pNode;


	Armature* hero1;
	Armature* hero2;
	Armature* hero3;

	friend class FailureScene;
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