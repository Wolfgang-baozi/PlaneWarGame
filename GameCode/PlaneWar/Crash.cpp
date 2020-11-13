// CCrash.cpp : 实现文件
//

#include "stdafx.h"
#include "GameObject.h"
#include "Explosion.h"
#include "Crash.h"
#include "EnemyObject.h"
#include "BombObject.h"
#include "Counter.h"
#include "Myplane.h"
#include "PropObject.h"

//构造
CCrash::CCrash(void)
{

}

//析构
CCrash::~CCrash()
{

}

//敌机和我方子弹
void CCrash::MyBomb_Enemy(CObList & objList_enemy, CObList & objList_bomb, CObList & objList_boom, CCounter* & pCounter, int & bBoss, int ID)
{
	for (pos1 = objList_enemy.GetHeadPosition(); (pos2 = pos1) != NULL; )
	{
		CEnemyObject* pe = (CEnemyObject*)objList_enemy.GetNext(pos1);
		rect1 = pe->GetRect();
		for (pos3 = objList_bomb.GetHeadPosition(); (pos4 = pos3) != NULL; )
		{
			CBombObject* pb = (CBombObject*)objList_bomb.GetNext(pos3);
			rect2 = pb->GetRect();
			if (tmp.IntersectRect(&rect1, &rect2))
			{
				//敌机减血
				pe->MinusHP(pb->GetHarm()); 
				objList_boom.AddTail(new CExplosion(pb->GetPoint().x, pb->GetPoint().y));
				objList_bomb.RemoveAt(pos4);
				delete pb;
				if (pe->GetNowHP() <= 0)
				{
					//计分系统
					pCounter->PlusNum(pe->GetSumHP());
					//BOSS死亡时,改变标识
					if(ID == 4)
					{
						bBoss = death;
					}
					objList_boom.AddTail(new CExplosion(pe->GetPoint().x, pe->GetPoint().y));
					objList_enemy.RemoveAt(pos2);
					delete pe;
					break;
				}
			}
		}
	}
}

//战机和敌机
BOOL CCrash::MyPlane_Enemy(CObList & objList_enemy, CMyPlane* & pMe, CObList & objList_boom, CCounter* & pCounter, bool nNb)
{
	rect1 = pMe->GetRect();
	for (pos1 = objList_enemy.GetHeadPosition(); (pos2 = pos1) != NULL; )
	{
		CEnemyObject* pe = (CEnemyObject*)objList_enemy.GetNext(pos1);
		rect2 = pe->GetRect();
		if (tmp.IntersectRect(&rect1, &rect2))
		{
			pCounter->PlusNum(pe->GetSumHP());//计分系统
			objList_boom.AddTail(new CExplosion(pe->GetPoint().x, pe->GetPoint().y));
			//非无敌模式下,战机减血
			if(!nNb)
			{	
				pMe->MinusHp(pe->GetHarm());
			}
			if (pMe->GetNowHP() <= 0)
			{
				objList_boom.AddTail(new CExplosion(pMe->GetPoint().x, pMe->GetPoint().y));
				return false;
			}
			objList_enemy.RemoveAt(pos2);
			delete pe;
		}
	}
	return true;
}

//战机和敌方子弹
BOOL  CCrash::MyPlane_EnBomb(CObList & objList_enbomb, CMyPlane* & pMe, CObList& objList_boom, bool nNb)
{
	//获得战机矩形区域
	rect1 = pMe->GetRect();
	
	//遍历敌机子弹
	for (pos1 = objList_enbomb.GetHeadPosition(); (pos2 = pos1) != NULL; ) 
	{
		//获得敌机子弹对象
		CBombObject* pb = (CBombObject*)objList_enbomb.GetNext(pos1);

		//获得子弹矩形区域
		rect2 = pb->GetRect();

		//判断子弹和战机是否碰撞
		if (tmp.IntersectRect(&rect1, &rect2))
		{
			//非无敌模式下,战机减血
			if(!nNb)
			{
				pMe->MinusHp(pb->GetHarm());
			}
			if(pMe->GetNowHP() <= 0)
			{
				objList_boom.AddTail(new CExplosion(pMe->GetPoint().x, pMe->GetPoint().y));
				return FALSE;
			}
			//添加爆炸效果
			objList_boom.AddTail(new CExplosion(pb->GetPoint().x, pb->GetPoint().y));
			//移除子弹
			objList_enbomb.RemoveAt(pos2);
			delete pb;
		}
	}
	return TRUE;
}

//道具和飞机
BOOL CCrash::MyPlane_Prop(CObList & objList_prop, CMyPlane* & pMe)
{
	//获得战机矩形区域
	rect1 = pMe->GetRect();
	
	//遍历敌机子弹
	for (pos1 = objList_prop. GetHeadPosition(); (pos2 = pos1) != NULL; ) 
	{
		//获得敌机道具对象
		CPropObject* pb = (CPropObject*)objList_prop.GetNext(pos1);

		//获得道具矩形区域
		rect2 = pb->GetRect();

		//判断子弹和道具是否碰撞
		if (tmp.IntersectRect(&rect1, &rect2))
		{
			//道具效果
			if( pb->PropFunction(pMe) )
			{
				//移除道具对象
				objList_prop.RemoveAt(pos2);
				delete pb;

				return TRUE;
			}
			//移除道具对象
			objList_prop.RemoveAt(pos2);
			delete pb;
		}
	}

	return FALSE;
}