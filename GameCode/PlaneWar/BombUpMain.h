
#pragma once
#include "BombObject.h"
#include "Stdafx.h"
#include "resource.h"

class CBombUpMain : public CBombObject
{
public:
	//构造
	CBombUpMain(int x, int y);

	//析构
	~CBombUpMain(void);

	//绘图
	BOOL Draw(CDC* pDC,BOOL bPause);

	//获得矩形区域
	CRect GetRect()
	{
		return CRect(m_ptPos, CPoint(m_ptPos.x + BOMBUPMAIN_WIDTH, m_ptPos.y + BOMBUPMAIN_HEIGHT));
	}

	//加载图像
	static BOOL LoadImage();

	
	//移动
	BOOL Move();


private:

	//血包位图大小 10*25
	static const int BOMBUPMAIN_WIDTH = 10;
	static const int BOMBUPMAIN_HEIGHT = 25;

	//图像链表
	static	CImageList m_Images;
};