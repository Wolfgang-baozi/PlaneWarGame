
#pragma once
#include "BombObject.h"
#include "Stdafx.h"
#include "resource.h"

class CBombUpSub : public CBombObject
{
public:
	//构造
	CBombUpSub(int x, int y);

	//析构
	~CBombUpSub(void);

	//绘图
	BOOL Draw(CDC* pDC,BOOL bPause);

	//获得矩形区域
	CRect GetRect()
	{
		return CRect(m_ptPos, CPoint(m_ptPos.x + BOMBUPSUB_WIDTH, m_ptPos.y + BOMBUPSUB_HEIGHT));
	}

	//移动
	BOOL Move();

	//加载图像
	static BOOL LoadImage();

private:

	//血包位图大小 7*25
	static const int BOMBUPSUB_WIDTH = 10;
	static const int BOMBUPSUB_HEIGHT = 25;

	//图像链表
	static	CImageList m_Images;

	//旋转中轴
	int		m_nX;

};