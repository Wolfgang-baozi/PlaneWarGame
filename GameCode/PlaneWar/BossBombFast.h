//停留一会
//直线 快速移动

#pragma once
#include "BombObject.h"
#include "Stdafx.h"
#include "resource.h"

class CBossBombFast : public CBombObject
{
public:
	//构造
	CBossBombFast(int x, int y);

	//析构
	~CBossBombFast(void);

	//绘图
	BOOL Draw(CDC* pDC,BOOL bPause);

	//获得已经停留时间
	int GetWait() const;

	//增加停留时间
	void AddWait();

	//是否移动
	BOOL IfMove();

	//获取子弹种类
	int GetKingBomb() const;

	//修改子弹种类
	void SetKindBomb(int nLevel);

	
	//移动
	BOOL Move();


	//获得矩形区域
	CRect GetRect()
	{
		return CRect(m_ptPos, CPoint(m_ptPos.x + BOSSBOMBFAST_WIDTH, m_ptPos.y + BOSSBOMBFAST_HEIGHT));
	}

	//加载图像
	static BOOL LoadImage();

private:

	//子弹位图大小 20*35 
	//两种子弹一样大
	static const int BOSSBOMBFAST_WIDTH = 20;
	static const int BOSSBOMBFAST_HEIGHT = 25;

	//图像链表
	static			 CImageList m_Images[3];

	//子弹已经停留时间
	int				 m_nWait;

	//子弹需要停留时间
	static const int m_nNeedWait = 90;

	//发射子弹种类 1 -> 紫色, 2 -> 黄色
	int				 m_nKindBomb;
};