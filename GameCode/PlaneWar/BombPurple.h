//始终追踪的导弹
#pragma once
#include "BombObject.h"

class CBombPurple : public CBombObject
{
public:
	//构造
	CBombPurple(int x, int y);

	//析构
	~CBombPurple(void);

	//绘图
	BOOL Draw(CDC* pDC,BOOL bPause);

	//获得矩形区域
	CRect GetRect()
	{
		return CRect(m_ptPos, CPoint(m_ptPos.x + BOMBPURPLE_WIDTH, m_ptPos.y + BOMBPURPLE_HEIGHT));
	}

	//移动
	BOOL Move();

	//加载图像
	static BOOL LoadImage();

private:

	//紫色圈圈 位图大小 25*25
	static const int BOMBPURPLE_WIDTH = 25;
	static const int BOMBPURPLE_HEIGHT = 25;

	//图像链表
	static	CImageList m_Images;

	//图像索引
	int m_nImgIndex;
};