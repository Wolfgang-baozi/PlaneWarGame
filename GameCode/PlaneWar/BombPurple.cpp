//CBombPurple : 实现文件
#pragma once

#include "Stdafx.h"
#include "BombPurple.h"
#include "resource.h"
#include "MoveLine.h"

CImageList CBombPurple::m_Images;

//构造
CBombPurple::CBombPurple(int x, int y)
{

	//随机确定图像索引
	m_nImgIndex = rand() % 2 == 0 ? 1 : -1;

	//子弹水平运行方向 -> 静止
	SetHorMotion(m_nImgIndex);

	//子弹垂直运行方向 -> 下
	SetVerMotion(1);

	//移速
	m_nV = 8;

	//初始位置
	m_ptPos.x = x;
	m_ptPos.y = y;

	//子弹伤害
	m_nHarm = 4;
}

//析构
CBombPurple::~CBombPurple(void)
{

}

//移动
BOOL CBombPurple::Move()
{
	CMoveLine pMoveLine;
	pMoveLine.Move(m_ptPos, GetHorMotion(), GetVerMotion(), GetV());

	//超出边界
	if (m_ptPos.y < -BOMBPURPLE_HEIGHT || m_ptPos.y > GAME_HEIGHT + BOMBPURPLE_HEIGHT)
		return FALSE;
	if (m_ptPos.x < 0 || m_ptPos.x > GAME_WIDTH - BOMBPURPLE_WIDTH)
		SetHorMotion(-GetHorMotion());

	return TRUE;
}

//加载图片
BOOL CBombPurple::LoadImage()
{
	return CGameObject::LoadImage(m_Images, IDB_BOMBPURPLE, RGB(255,255,255), BOMBPURPLE_WIDTH, BOMBPURPLE_HEIGHT, 1);
}

//绘图
BOOL CBombPurple::Draw(CDC* pDC, BOOL bPause)
{
	//移动
	if (!bPause)
	{
		if( !Move() )
			return FALSE;
	}

	//绘图
	m_Images.Draw(pDC, 0, m_ptPos, ILD_TRANSPARENT);

	return TRUE;
}