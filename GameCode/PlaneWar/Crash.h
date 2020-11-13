//Crash.h : 定义文件
//

#pragma once

#include "stdafx.h"
#include "Counter.h"
#include "MyPlane.h"

class CCrash :public CObject
{
	enum BossStatus { unborn, born, death };
public:
	//构造
	CCrash(void);

	//析构
	virtual ~CCrash();

	//碰撞
	//敌机和我方子弹
	void MyBomb_Enemy(CObList& objList_enemy, CObList& objList_bomb, CObList& objList_boom, CCounter* & pCounter, int & bBoss, int ID);
	
	//敌机和战机
	BOOL MyPlane_Enemy(CObList & objList_enemy, CMyPlane* & pMe, CObList& objList_boom, CCounter* & pCounter, bool nNb);
	
	//战机和敌方子弹
	BOOL MyPlane_EnBomb(CObList & objList_enemy, CMyPlane* & pMe, CObList& objList_boom, bool nNb);

	//道具和飞机
	BOOL MyPlane_Prop(CObList & objList_prop, CMyPlane* & pMe);

protected:

	//指针索引
	POSITION pos1, pos2, pos3, pos4;

	//矩形
	CRect rectPlane, rect1, rect2, tmp;
};