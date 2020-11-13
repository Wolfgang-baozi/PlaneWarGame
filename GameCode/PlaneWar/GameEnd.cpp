// CGameEnd.cpp : 实现文件
//

#include "stdafx.h"
#include "GameEnd.h"
#include "resource.h"

//图像链表
CImageList CGameEnd::m_Image;

//构造
CGameEnd::CGameEnd()
{
	//通过start的位置 确定其他按钮位置
	m_ptPos.x = 150;
	m_ptPos.y = 200;

}

//析构
CGameEnd::~CGameEnd()
{

}

//获得矩形区域
CRect CGameEnd::GetRect()
{
	return CRect(m_ptPos, CPoint(m_ptPos.x + END_WIDTH, m_ptPos.y + END_HEIGHT));
}

//加载图片
BOOL CGameEnd::LoadImage()
{
	return CGameObject::LoadImage(m_Image, IDB_END, RGB(40, 40, 40), END_WIDTH, END_HEIGHT, 0);
}

BOOL CGameEnd::Draw(CDC* pDC, BOOL bHelp)
{
	//END
	m_Image.Draw(pDC, 0, m_ptPos, ILD_TRANSPARENT);

	return TRUE;
}