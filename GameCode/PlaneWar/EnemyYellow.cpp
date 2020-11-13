

#include "stdafx.h"
#include "EnemyYellow.h"
#include "MoveLine.h"

//图像链表
CImageList CEnemyYellow::m_Images;

//构造
CEnemyYellow::CEnemyYellow()
{

	//随机确定X位置
	m_ptPos.x = rand() % (GAME_WIDTH - ENEMYYELLOW_WIDTH) - 10;
	m_ptPos.y = 0;

	//移动方向 ->水平不动,竖直向下
	SetHorMotion(0);
	SetVerMotion(1);

	//随机确定速度
	m_V = rand() % 15 + 2;

	//血量
	InitHP(15);

	//黄色小飞机的伤害值
	m_nHarm = 3;
}

CEnemyYellow::CEnemyYellow(int x, int y)
{

	//确定X位置
	m_ptPos.x = x;
	m_ptPos.y = y;

	//移动方向 ->水平不动,竖直向下
	SetHorMotion(0);
	SetVerMotion(1);

	//随机确定速度
	m_V = rand() % 10 + 6;

	//血量
	InitHP(15);

	//黄色小飞机的伤害值
	m_nHarm = 3;

}

//析构
CEnemyYellow::~CEnemyYellow()
{

}


//移动
BOOL CEnemyYellow::Move()
{
	CMoveLine pMoveLine;
	pMoveLine.Move(m_ptPos, GetHorMotion(), GetVerMotion(), GetV());

	//边界判断
	if (m_ptPos.y > GAME_HEIGHT || m_ptPos.y < 0)
		return FALSE;

	return TRUE;
}

//获得矩形
CRect CEnemyYellow::GetRect()
{
	return CRect(m_ptPos, CPoint(m_ptPos.x + ENEMYYELLOW_WIDTH, m_ptPos.y + ENEMYYELLOW_HEIGHT));
}

//加载图像
BOOL CEnemyYellow::LoadImage()
{
	return CGameObject::LoadImage(m_Images, IDB_ENEMYYELLOW, RGB(255, 255, 255), ENEMYYELLOW_WIDTH, ENEMYYELLOW_HEIGHT, 0);
}

//绘图
BOOL CEnemyYellow::Draw(CDC* pDC, BOOL bPause)
{
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

//是否发射子弹
BOOL CEnemyYellow::Fired()
{
	return FALSE;
}