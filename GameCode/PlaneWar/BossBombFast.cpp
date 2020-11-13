
#include "Stdafx.h"
#include "BossBombFast.h"
#include "resource.h"
#include "MoveLine.h"
#include <mmstream.h>

CImageList CBossBombFast::m_Images[3];

//构造
CBossBombFast::CBossBombFast(int x, int y) : m_nWait(0)
{
	//子弹水平运行方向 -> 静止
	SetHorMotion(0);

	//子弹垂直运行方向 -> 下
	SetVerMotion(1);

	//初始位置
	m_ptPos.x = x;
	m_ptPos.y = y;

	//子弹移速
	m_nV = 40;

	//子弹伤害
	m_nHarm = 10;

	//子弹种类
	m_nKindBomb = rand() % 2;
}

//析构
CBossBombFast::~CBossBombFast(void)
{

}


//移动
BOOL CBossBombFast::Move()
{
	if(IfMove())
	{
		CMoveLine pMoveLine;
		pMoveLine.Move(m_ptPos, GetHorMotion(), GetVerMotion(), GetV());
		
		//超出边界
		if(m_ptPos.y < -BOSSBOMBFAST_HEIGHT || m_ptPos.y > GAME_HEIGHT + BOSSBOMBFAST_HEIGHT)
			return FALSE;
	}

	return TRUE;
}

//获得已经停留时间
int CBossBombFast::GetWait() const
{
	return m_nWait;
}

//增加停留时间
void CBossBombFast::AddWait()
{
	m_nWait = m_nWait + 1;
}

//是否移动
BOOL CBossBombFast::IfMove()
{
	return GetWait() > m_nNeedWait;
}

//获取子弹种类
int CBossBombFast::GetKingBomb() const
{
	return m_nKindBomb;
}

//修改子弹种类
void CBossBombFast::SetKindBomb(int nLevel)
{
	m_nKindBomb = nLevel;
}

//加载图片
BOOL CBossBombFast::LoadImage()
{
	//IDB_BOSSBOMB_PURPLE0
	//IDB_BOSSBOMB_YELLOW
	return CGameObject::LoadImage(m_Images[0], IDB_BOSSBOMB_PURPLE0, RGB(255, 255, 255), BOSSBOMBFAST_WIDTH, BOSSBOMBFAST_HEIGHT, 0)
		&& CGameObject::LoadImage(m_Images[1], IDB_BOSSBOMB_YELLOW, RGB(255, 255, 255), BOSSBOMBFAST_WIDTH, BOSSBOMBFAST_HEIGHT, 0);
}

//绘图
BOOL CBossBombFast::Draw(CDC* pDC, BOOL bPause)
{
	//停留
	AddWait();
	
	//移动
	if(!bPause)
	{
		if(!Move())
			return FALSE;
	}

	//绘图
	int nKindBomb = this->GetKingBomb();
	m_Images[nKindBomb].Draw(pDC, 0, m_ptPos, ILD_TRANSPARENT);

	return TRUE;
}