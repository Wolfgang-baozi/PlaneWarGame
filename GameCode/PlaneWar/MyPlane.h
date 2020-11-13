#pragma once

#include "stdafx.h"
#include "PlaneObject.h"

class CMyPlane : public CPlaneObject
{
public:

	//构造
	CMyPlane();

	//析构
	~CMyPlane(void);

	//获得飞机等级
	int GetGrade() const;

	//修改等级
	void AddGrade(int Grade);

	//获得发射位置
	CPoint GetBombPos(int nPos) const;

	//绘图
	BOOL Draw(CDC* pDC,BOOL bPause);

	//加载图片
	static BOOL LoadImage();

	//移动
	void Move();


	//获得矩形
	CRect GetRect();

	//是否发射子弹
	BOOL IfFired();

	//战机减血
	void MinusHp(int nHP); 

	//战机加血
	void PlusHP(int nHP);
	
public:
	//位宽 -- 50， 位高 -- 60
	static const int PLANE_WIDTH = 100;
	static const int PLANE_HEIGHT = 59;
private:

	//生成位图链表
	static CImageList m_Images[2];

	//飞机等级
	int m_nGrade;

	//血条位置
	CPoint m_ptBlood;

};
