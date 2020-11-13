//直线

#pragma once
#include "BombObject.h"
#include "Stdafx.h"
#include "resource.h"

class CBombRedPoint : public CBombObject
{
public:
	//构造
	CBombRedPoint(int x, int y);

	//析构
	~CBombRedPoint(void);

	//绘图
	BOOL Draw(CDC* pDC,BOOL bPause);

	//移动
	BOOL Move();

	//获得矩形区域
	CRect GetRect()
	{
		return CRect(m_ptPos, CPoint(m_ptPos.x + BOMBREDPOINT_WIDTH, m_ptPos.y + BOMBREDPOINT_HEIGHT));
	}

	//加载图像
	static BOOL LoadImage();

private:

	//小红点 位图大小 25*25
	static const int BOMBREDPOINT_WIDTH = 25;
	static const int BOMBREDPOINT_HEIGHT = 25;

	//图像链表
	static CImageList m_Images;
};