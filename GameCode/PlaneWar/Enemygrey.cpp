

#include "stdafx.h"
#include "EnemyGrey.h"
#include "MoveLine.h"

CImageList CEnemyGrey::m_Images;

CEnemyGrey::CEnemyGrey()
{
	//伤害值
	m_nHarm = 10;

	//随机确定X位置
	m_ptPos.x = rand() % (GAME_WIDTH - ENEMYGREY_HEIGHT * 2);
	m_ptPos.y = 0;

	//随机确定图像索引
	m_nImgIndex = rand() % 2;

	//根据图像索引确定方向 初始 -> 向下飞
	SetVerMotion(1);
	SetHorMotion(0);

	//如果是图像索引是偶数 -> 向上飞
	if (m_nImgIndex % 2 != 0)
	{
		SetVerMotion(-1);
		m_ptPos.y = GAME_HEIGHT + ENEMYGREY_HEIGHT;
	}

	//随机速度
	m_V = rand() % 12 + 2;

	//冷却时间
	m_nWait = 0;

	//血量
	InitHP(10);

	//敌机伤害
	m_nHarm = 2;
}

//析构
CEnemyGrey::~CEnemyGrey()
{

}

//移动
BOOL  CEnemyGrey::Move()
{
	CMoveLine pMoveLine;
	pMoveLine.Move(m_ptPos, GetHorMotion(), GetVerMotion(), GetV());

	//边界判断
	if (m_ptPos.y > GAME_HEIGHT && m_ptPos.y < 0)
		return FALSE;

	return TRUE;
}

//获得矩形区域
CRect CEnemyGrey::GetRect()
{
	return CRect(m_ptPos, CPoint(m_ptPos.x + ENEMYGREY_HEIGHT, m_ptPos.y + ENEMYGREY_HEIGHT));
}

//加载图像
BOOL CEnemyGrey::LoadImage()
{
	return CGameObject::LoadImage(m_Images, IDB_ENEMYGREY, RGB(0, 0, 0), ENEMYGREY_HEIGHT, ENEMYGREY_HEIGHT, 0);
}

//绘图
BOOL CEnemyGrey::Draw(CDC* pDC, BOOL bPause)
{
	//发射延迟
	m_nWait++;
	if (m_nWait > 40)
		m_nWait = 0;

	//移动
	if (!bPause)
	{
		if( !Move() )
			return FALSE;
	}

	//绘图
	m_Images.Draw(pDC, m_nImgIndex, m_ptPos, ILD_TRANSPARENT);

	return TRUE;
}

//是否开火
BOOL CEnemyGrey::Fired()
{
	if (m_nWait == 0)
		return TRUE;
	else
		return FALSE;
}
