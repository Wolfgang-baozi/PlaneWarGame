
#include "Stdafx.h"
#include "BombUpSub.h"
#include "resource.h"
#include "MoveLine.h"

CImageList CBombUpSub::m_Images;

//构造
CBombUpSub::CBombUpSub(int x, int y)
{
	//子弹水平运行方向 -> 静止
	SetHorMotion(rand() % 2 == 0 ? 1 : -1);

	//子弹垂直运行方向 -> 下
	SetVerMotion(-1);

	//初始位置
	m_ptPos.x = m_nX = x;
	m_ptPos.y = y;

	//子弹移速
	m_nV = 20;

	//子弹伤害
	m_nHarm = 80;
}

//析构
CBombUpSub::~CBombUpSub(void)
{

}

//移动
BOOL CBombUpSub::Move()
{

	CMoveLine pMoveLine;
	pMoveLine.Move(m_ptPos, GetHorMotion(), GetVerMotion(), GetV());


	if (m_ptPos.y < -BOMBUPSUB_HEIGHT || m_ptPos.y > GAME_HEIGHT + BOMBUPSUB_HEIGHT)
		return FALSE;

	if (m_ptPos.x < 0 || m_ptPos.x > GAME_WIDTH - BOMBUPSUB_WIDTH)
		SetHorMotion(-GetHorMotion());

	return TRUE;
}

//加载图片
BOOL CBombUpSub::LoadImage()
{
	return CGameObject::LoadImage(m_Images, IDB_BOMBUP_SUB, RGB(255, 255, 255), BOMBUPSUB_WIDTH, BOMBUPSUB_HEIGHT, 1);
}

//绘图
BOOL CBombUpSub::Draw(CDC* pDC, BOOL bPause)
{
	//移动
	if(!Move())
		return FALSE;

	//绘图
	m_Images.Draw(pDC, 0, m_ptPos, ILD_TRANSPARENT);

	return TRUE;
}