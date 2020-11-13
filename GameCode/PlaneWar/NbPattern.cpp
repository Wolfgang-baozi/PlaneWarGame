//CNbPattern.cpp : 实现文件
//

#include "stdafx.h"
#include "NbPattern.h"
#include "resource.h"
#include <mmsystem.h>

//图像链表
CImageList CNbPattern::m_Image[3];

//构造
CNbPattern::CNbPattern()
{
	//键位置
	m_ptPos.x = 3;
	m_ptPos.y = GAME_HEIGHT - NB_HEIGHT*2;
}

//析构
CNbPattern::~CNbPattern()
{

}

//加载图像
BOOL CNbPattern::LoadImage()
{
	return CGameObject::LoadImage( m_Image[on], IDB_NBON, RGB(0, 0, 0), NB_WIDTH, NB_HEIGHT, 0) 
		&& CGameObject::LoadImage( m_Image[off], IDB_NBOFF, RGB(0, 0, 0), NB_WIDTH, NB_HEIGHT, 0);
}

//绘图
BOOL CNbPattern::Draw(CDC *pDC, BOOL bPattern)
{
	//无敌时
	if (bPattern) {
		m_Image[on].Draw(pDC, 0, m_ptPos, ILD_TRANSPARENT);
	}
	//游戏进行时
	else {
		m_Image[off].Draw(pDC, 0, m_ptPos, ILD_TRANSPARENT);
	}
	return TRUE;
}

//获得矩形
CRect CNbPattern::GetRect()
{
	return CRect(m_ptPos, CPoint(m_ptPos.x + NB_WIDTH, m_ptPos.y + NB_HEIGHT));
}