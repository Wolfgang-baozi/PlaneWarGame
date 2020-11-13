
#include "stdafx.h"
#include "EnemyRed.h"
#include "MoveLine.h"

CImageList CEnemyRed::m_Images;

CEnemyRed::CEnemyRed()
{
	//随机确定图像索引
	m_nImgIndex = rand() % 2;
	
	//确定位置
	m_ptPos.x =  rand() % ( GAME_WIDTH -ENEMYRED_WIDTH );
	m_ptPos.y = 0;

	//根据图像索引确定方向
	SetHorMotion(0);
	SetVerMotion(1);
	
	//随机确定速度
	m_V = 6;

	//冷却时间
	m_nWait = 0;

	//血量
	InitHP(20);

	//伤害值
	m_nHarm = 4;
}

//析构
CEnemyRed::~CEnemyRed()
{

}

//移动
BOOL CEnemyRed::Move()
{
	CMoveLine pMoveLine;
	pMoveLine.Move(m_ptPos, GetHorMotion(), GetVerMotion(), GetV());

	
	//边界判断
	if (m_ptPos.y > GAME_HEIGHT || m_ptPos.y < 0)
		return FALSE;
		
	return TRUE;
}

//获得矩形区域
CRect CEnemyRed::GetRect()
{
	return CRect(m_ptPos, CPoint(m_ptPos.x + ENEMYRED_WIDTH, m_ptPos.y + ENEMYRED_HEIGHT));
}

//加载图片
BOOL CEnemyRed::LoadImage()
{
	return CGameObject::LoadImage(m_Images, IDB_ENEMYRED, RGB(255, 255, 255), ENEMYRED_WIDTH, ENEMYRED_HEIGHT, 0);
}

//绘图
BOOL CEnemyRed::Draw(CDC* pDC, BOOL bPause)
{
	//只有一发导弹
	m_nWait++;
	if (m_nWait > 30)
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

//是否开火
BOOL CEnemyRed::Fired()
{
	if (m_nWait == 0)
		return TRUE;
	else
		return FALSE;
}

