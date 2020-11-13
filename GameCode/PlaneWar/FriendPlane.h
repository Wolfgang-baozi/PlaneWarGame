#pragma once

#include "MyPlane.h"

class CFriendPlane :public CPlaneObject
{
public:
	//构造
	CFriendPlane();

	//析构
	~CFriendPlane(void);

	//获得发射位置
	CPoint GetBombPos(int nPos) const;

	//绘图
	BOOL Draw(CDC* pDC,BOOL bPause);

	//加载图片
	static BOOL LoadImage();

	//移动
	void Move();


	//获得矩形
	CRect GetRect()
	{
		return CRect(m_ptPos,CPoint(m_ptPos.x+PLANE_WIDTH,m_ptPos.y+PLANE_HEIGHT));
	}

	//是否发射子弹
	BOOL IfFired();

	//获得生存时间
	int GetLifeTime() const;

	//修改生存时间
	int SetLifeTime(int LifeTime);
	
public:
	//位图 119*170
	static const int PLANE_WIDTH = 59;
	static const int PLANE_HEIGHT = 80;
private:

	//生成位图链表
	static CImageList m_Images;

	//飞机等级
	int m_nLevel;

	//僚机存在时间
	int m_nLifeTime;
};
