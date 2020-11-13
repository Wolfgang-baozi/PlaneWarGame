//CPause.cpp : 实现文件
//

#include "stdafx.h"
#include "Pause.h"
#include "resource.h"
#include <mmsystem.h>

//图像链表
CImageList CPause::m_Image[3];

//构造
CPause::CPause()
{
	//暂停, 继续键位置
	m_ptPos.x = 6;
	m_ptPos.y = GAME_HEIGHT - BUTTON_HEIGHT - BACK_HEIGHT - 40;

	//m_ptPos.x = GAME_WIDTH / 2;
	//m_ptPos.y = GAME_HEIGHT / 2;

	//返回键
	m_ptBack.x = 6;
	m_ptBack.y = GAME_HEIGHT - BUTTON_HEIGHT - BACK_HEIGHT - 70;
}

//析构
CPause::~CPause()
{

}

//加载图像
BOOL CPause::LoadImage()
{
	return CGameObject::LoadImage( m_Image[pause], IDB_PAUSE, RGB(0, 0, 0), BUTTON_WIDTH, BUTTON_HEIGHT, 0) 
		&& CGameObject::LoadImage( m_Image[continuebutton], IDB_CONTINUE, RGB(0, 0, 0), BUTTON_WIDTH, BUTTON_HEIGHT, 0)
		&& CGameObject::LoadImage( m_Image[back], IDB_BACKBUTTON, RGB(255, 255, 255), BACK_WIDTH, BACK_HEIGHT, 0);
}

//绘图
BOOL CPause::Draw(CDC *pDC, BOOL bPause)
{
	//画面暂停时
	if (bPause) 
	{
		m_Image[back].Draw(pDC, 0, m_ptBack, ILD_TRANSPARENT);
		m_Image[pause].Draw(pDC, 0, m_ptPos, ILD_TRANSPARENT);
	}
	//游戏进行时
	else 
	{
		m_Image[continuebutton].Draw(pDC, 0, m_ptPos, ILD_TRANSPARENT);
	}
	return TRUE;
}

//获得矩形 -> 停止
CRect CPause::GetRectStop()
{
	return CRect(m_ptPos, CPoint(m_ptPos.x + BUTTON_WIDTH, m_ptPos.y + BUTTON_HEIGHT));
}

//获得矩形 -> 继续
CRect CPause::GetRectGo()
{
	return CRect(m_ptPos, CPoint(m_ptPos.x + BUTTON_WIDTH, m_ptPos.y + BUTTON_HEIGHT));
}

//获得矩形 -> 返回
CRect CPause::GetRect()
{
	return CRect(m_ptBack, CPoint(m_ptBack.x + BACK_WIDTH, m_ptBack.y + BACK_HEIGHT));
}

//修改暂停状态
void CPause::PauseButton(bool & bPause)
{
	bPause = !bPause;
}