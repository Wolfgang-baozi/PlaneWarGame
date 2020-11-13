//朝着战机发射
//之后直线飞行

#pragma once
#include "BombObject.h"

class CMissile : public CBombObject
{
public:
	//构造
	CMissile(int x, int y);

	//析构
	~CMissile(void);

	//绘图
	BOOL Draw(CDC* pDC, BOOL bPause);

	//移动
	BOOL Move();

	//获得矩形区域
	CRect GetRect()
	{
		return CRect(m_ptPos, CPoint(m_ptPos.x + BOMBMISSILE_WIDTH, m_ptPos.y + BOMBMISSILE_HEIGHT));
	}

	//加载图像
	static BOOL LoadImage();

private:

	//导弹位图大小 20*35
	static const int BOMBMISSILE_WIDTH = 20;
	static const int BOMBMISSILE_HEIGHT = 35;

	//图像链表
	static	CImageList m_Images;

	//水平最大距离
	int		m_nMaxHor;

	//初始位置
	int		m_nStaX;

};