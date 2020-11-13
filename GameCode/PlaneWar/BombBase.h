
#pragma once
#include "BombObject.h"
#include "Stdafx.h"
#include "resource.h"

class CBombBase : public CBombObject
{
public:
	//构造
	CBombBase(int x, int y);

	//析构
	~CBombBase(void);

	//生成小飞机
	void AddBomb(CObList &objList,  const CPoint &pos);

	//绘图
	BOOL Draw(CDC* pDC,BOOL bPause);

	//移动
	BOOL Move();

	//获得矩形区域
	CRect GetRect()
	{
		return CRect(m_ptPos, CPoint(m_ptPos.x + BOMBBASE_WIDTH, m_ptPos.y + BOMBBASE_HEIGHT));
	}

	//加载图像
	static BOOL LoadImage();

private:

	//血包位图大小 7*25
	static const int BOMBBASE_WIDTH = 7;
	static const int BOMBBASE_HEIGHT = 25;

	//图像链表
	static	CImageList m_Images;
};