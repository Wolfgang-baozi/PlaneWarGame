//Back.cpp : 实现文件
//

#include "stdafx.h"
#include "Back.h"
#include "resource.h"
#include <mmsystem.h>

//3个背景图
CImageList CBack::m_Images[3];

//构造
CBack::CBack(int x, int y) : CGameObject(x, y)
{
	m_nGrade = 1;
}

//析构
CBack::~CBack()
{

}

//获得关卡等级
int CBack::GetGrade() const
{
	return m_nGrade;
}

//背景升级
void CBack::SetGrade(int nGrade)
{
	this->m_nGrade = nGrade;
}

//析构
CRect CBack::GetRect()
{
	return CRect(m_ptPos, CPoint(m_ptPos.x + GAME_WIDTH, m_ptPos.y + GAME_HEIGHT));
}

//绘图
BOOL CBack::Draw(CDC* pMemDC, BOOL bPause)
{
	//等级
	int nGrade = GetGrade();
	switch(nGrade)
	{
		case bosspattern1:
			nGrade = IDB_BACK0;
			break;
		case bosspattern2:
			nGrade = IDB_BACK1;
			break;
		case bosspattern3:
			nGrade = IDB_BACK2;
			break;
		default :
			nGrade = IDB_BACK1;
			break;
	}

	//双缓冲技术绘制背景
	static int imagelocation = 0;
	CDC memDC;
	memDC.CreateCompatibleDC(pMemDC);
	CBitmap bmpDraw;
	bmpDraw.LoadBitmapW(nGrade);//创建位图
	CBitmap* pbmpold = memDC.SelectObject(&bmpDraw);
	pMemDC->BitBlt(0, imagelocation, GAME_WIDTH, GAME_HEIGHT - imagelocation, &memDC, 0, 0, SRCCOPY);//设置动态背景
	pMemDC->BitBlt(0, 0, GAME_WIDTH, imagelocation, &memDC, 0, GAME_HEIGHT - imagelocation, SRCCOPY);
	imagelocation++;
	if (imagelocation == GAME_HEIGHT)
		imagelocation = 0;

	return TRUE;
}

//加载图像
BOOL CBack::LoadImage()
{
	return CGameObject::LoadImage(m_Images[0], IDB_BACK0, RGB(0, 0, 0), GAME_WIDTH, GAME_HEIGHT, 1)&&
		CGameObject::LoadImage(m_Images[1], IDB_BACK1, RGB(0, 0, 0), GAME_WIDTH, GAME_HEIGHT, 1) &&
		CGameObject::LoadImage(m_Images[2], IDB_BACK2, RGB(0, 0, 0), GAME_WIDTH, GAME_HEIGHT, 1);
}

