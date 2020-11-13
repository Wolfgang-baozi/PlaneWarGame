//Crash.h : �����ļ�
//

#pragma once

#include "stdafx.h"
#include "Counter.h"
#include "MyPlane.h"

class CCrash :public CObject
{
	enum BossStatus { unborn, born, death };
public:
	//����
	CCrash(void);

	//����
	virtual ~CCrash();

	//��ײ
	//�л����ҷ��ӵ�
	void MyBomb_Enemy(CObList& objList_enemy, CObList& objList_bomb, CObList& objList_boom, CCounter* & pCounter, int & bBoss, int ID);
	
	//�л���ս��
	BOOL MyPlane_Enemy(CObList & objList_enemy, CMyPlane* & pMe, CObList& objList_boom, CCounter* & pCounter, bool nNb);
	
	//ս���͵з��ӵ�
	BOOL MyPlane_EnBomb(CObList & objList_enemy, CMyPlane* & pMe, CObList& objList_boom, bool nNb);

	//���ߺͷɻ�
	BOOL MyPlane_Prop(CObList & objList_prop, CMyPlane* & pMe);

protected:

	//ָ������
	POSITION pos1, pos2, pos3, pos4;

	//����
	CRect rectPlane, rect1, rect2, tmp;
};