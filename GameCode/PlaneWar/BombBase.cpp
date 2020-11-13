
#include "Stdafx.h"
#include "BombBase.h"
#include "resource.h"
#include "MoveLine.h"

CImageList CBombBase::m_Images;

//构造
CBombBase::CBombBase(int x, int y)
{
	//子弹水平运行方向 -> 静止
	SetHorMotion(0);

	//子弹垂直运行方向 -> 下
	SetVerMotion(-1);

	//初始位置
	m_ptPos.x = x;
	m_ptPos.y = y;

	//子弹移速
	m_nV = 20;

	//子弹伤害
	m_nHarm = 100;
}

//析构
CBombBase::~CBombBase(void)
{

}

//移动
BOOL CBombBase:: Move()
{
	CMoveLine pMoveLine;
	pMoveLine.Move(m_ptPos, GetHorMotion(), GetVerMotion(), GetV());

	//超出边界
	if(m_ptPos.y < -BOMBBASE_HEIGHT && m_ptPos.x < -BOMBBASE_WIDTH && m_ptPos.x > GAME_WIDTH - BOMBBASE_WIDTH)
		return FALSE;

	return TRUE;
}

//加载图片
BOOL CBombBase::LoadImage()
{
	return CGameObject::LoadImage(m_Images, IDB_BOMBBASE, RGB(255, 255, 255), BOMBBASE_WIDTH, BOMBBASE_HEIGHT, 1);
}

//绘图
BOOL CBombBase::Draw(CDC* pDC, BOOL bPause)
{
	//移动
	if(!bPause)
	{
		if( !Move() )
			return FALSE;
	}

	//绘图
	m_Images.Draw(pDC, 0, m_ptPos, ILD_TRANSPARENT);

	return TRUE;
}