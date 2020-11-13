
#include "Stdafx.h"
#include "BombRedPoint.h"
#include "MoveLine.h"

CImageList CBombRedPoint::m_Images;

//构造
CBombRedPoint::CBombRedPoint(int x, int y)
{
	//子弹水平运行方向 -> 静止
	SetHorMotion(0);

	//子弹垂直运行方向 -> 下
	SetVerMotion(1);

	//初始位置
	m_ptPos.x = x;
	m_ptPos.y = y;

	//子弹移速
	m_nV = 8;

	//子弹伤害
	m_nHarm = 3;
}

//析构
CBombRedPoint::~CBombRedPoint(void)
{

}

//移动
BOOL CBombRedPoint::Move()
{
	CMoveLine pMoveLine;
	pMoveLine.Move(m_ptPos, GetHorMotion(), GetVerMotion(), GetV());

	//超出边界
	if(m_ptPos.y < -BOMBREDPOINT_HEIGHT || m_ptPos.y > GAME_HEIGHT + BOMBREDPOINT_HEIGHT)
		return FALSE;

	return TRUE;
}

//加载图片
BOOL CBombRedPoint::LoadImage()
{
	return CGameObject::LoadImage(m_Images, IDB_BOMBREDPOINT, RGB(0,0,0), BOMBREDPOINT_WIDTH, BOMBREDPOINT_HEIGHT, 0);
}

//绘图
BOOL CBombRedPoint::Draw(CDC* pDC, BOOL bPause)
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