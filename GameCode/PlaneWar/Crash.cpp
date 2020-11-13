// CCrash.cpp : ʵ���ļ�
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

//����
CCrash::CCrash(void)
{

}

//����
CCrash::~CCrash()
{

}

//�л����ҷ��ӵ�
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
				//�л���Ѫ
				pe->MinusHP(pb->GetHarm()); 
				objList_boom.AddTail(new CExplosion(pb->GetPoint().x, pb->GetPoint().y));
				objList_bomb.RemoveAt(pos4);
				delete pb;
				if (pe->GetNowHP() <= 0)
				{
					//�Ʒ�ϵͳ
					pCounter->PlusNum(pe->GetSumHP());
					//BOSS����ʱ,�ı��ʶ
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

//ս���͵л�
BOOL CCrash::MyPlane_Enemy(CObList & objList_enemy, CMyPlane* & pMe, CObList & objList_boom, CCounter* & pCounter, bool nNb)
{
	rect1 = pMe->GetRect();
	for (pos1 = objList_enemy.GetHeadPosition(); (pos2 = pos1) != NULL; )
	{
		CEnemyObject* pe = (CEnemyObject*)objList_enemy.GetNext(pos1);
		rect2 = pe->GetRect();
		if (tmp.IntersectRect(&rect1, &rect2))
		{
			pCounter->PlusNum(pe->GetSumHP());//�Ʒ�ϵͳ
			objList_boom.AddTail(new CExplosion(pe->GetPoint().x, pe->GetPoint().y));
			//���޵�ģʽ��,ս����Ѫ
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

//ս���͵з��ӵ�
BOOL  CCrash::MyPlane_EnBomb(CObList & objList_enbomb, CMyPlane* & pMe, CObList& objList_boom, bool nNb)
{
	//���ս����������
	rect1 = pMe->GetRect();
	
	//�����л��ӵ�
	for (pos1 = objList_enbomb.GetHeadPosition(); (pos2 = pos1) != NULL; ) 
	{
		//��õл��ӵ�����
		CBombObject* pb = (CBombObject*)objList_enbomb.GetNext(pos1);

		//����ӵ���������
		rect2 = pb->GetRect();

		//�ж��ӵ���ս���Ƿ���ײ
		if (tmp.IntersectRect(&rect1, &rect2))
		{
			//���޵�ģʽ��,ս����Ѫ
			if(!nNb)
			{
				pMe->MinusHp(pb->GetHarm());
			}
			if(pMe->GetNowHP() <= 0)
			{
				objList_boom.AddTail(new CExplosion(pMe->GetPoint().x, pMe->GetPoint().y));
				return FALSE;
			}
			//��ӱ�ըЧ��
			objList_boom.AddTail(new CExplosion(pb->GetPoint().x, pb->GetPoint().y));
			//�Ƴ��ӵ�
			objList_enbomb.RemoveAt(pos2);
			delete pb;
		}
	}
	return TRUE;
}

//���ߺͷɻ�
BOOL CCrash::MyPlane_Prop(CObList & objList_prop, CMyPlane* & pMe)
{
	//���ս����������
	rect1 = pMe->GetRect();
	
	//�����л��ӵ�
	for (pos1 = objList_prop. GetHeadPosition(); (pos2 = pos1) != NULL; ) 
	{
		//��õл����߶���
		CPropObject* pb = (CPropObject*)objList_prop.GetNext(pos1);

		//��õ��߾�������
		rect2 = pb->GetRect();

		//�ж��ӵ��͵����Ƿ���ײ
		if (tmp.IntersectRect(&rect1, &rect2))
		{
			//����Ч��
			if( pb->PropFunction(pMe) )
			{
				//�Ƴ����߶���
				objList_prop.RemoveAt(pos2);
				delete pb;

				return TRUE;
			}
			//�Ƴ����߶���
			objList_prop.RemoveAt(pos2);
			delete pb;
		}
	}

	return FALSE;
}