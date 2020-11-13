

#include "stdafx.h"
#include "EnemyGreen.h"
#include "MoveLine.h"

CImageList CEnemyGreen::m_Images;

CEnemyGreen::CEnemyGreen()
{
	//飞机伤害
	m_nHarm = 10;

	//随机确定X位置
	m_ptPos.x = rand() % (GAME_WIDTH - ENEMYGREEN_WIDTH) + 1;
	m_ptPos.y = 0;
	
	//确定速度
	m_V = 6;

	//发射延迟
	m_nWait = 0;

	//血量
	InitHP(20);

	//敌机伤害
	m_nHarm = 4;

	//方向
	SetHorMotion(0);
	SetVerMotion(1);

}

//析构
CEnemyGreen::~CEnemyGreen()
{

}

//移动
BOOL CEnemyGreen::Move()
{
	CMoveLine pMoveLine;
	pMoveLine.Move(m_ptPos, GetHorMotion(), GetVerMotion(), GetV());

	//边界判断
	if (m_ptPos.y > GAME_HEIGHT + ENEMYGREEN_HEIGHT)
		return FALSE;

	return TRUE;
}


//获得矩形
CRect CEnemyGreen::GetRect()
{
	return CRect(m_ptPos, CPoint(m_ptPos.x + ENEMYGREEN_WIDTH, m_ptPos.y + ENEMYGREEN_HEIGHT));
}

//加载图像
BOOL CEnemyGreen::LoadImage()
{
	return CGameObject::LoadImage(m_Images, IDB_ENEMYGREEN, RGB(255, 255, 255), ENEMYGREEN_WIDTH, ENEMYGREEN_HEIGHT, 0);
}

//绘图
BOOL CEnemyGreen::Draw(CDC* pDC, BOOL bPause)
{
	//冷却
	m_nWait++;
	if (m_nWait > 35)
		m_nWait = 0;

	//移动
	if (!bPause)
	{
		if(!Move())
			return FALSE;
	}


	//绘图
	m_Images.Draw(pDC, 0, m_ptPos, ILD_TRANSPARENT);

	return TRUE;
}

//开火
BOOL CEnemyGreen::Fired()
{
	if (m_nWait == 0)
		return TRUE;
	else
		return FALSE;
}

