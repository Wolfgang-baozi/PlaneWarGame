#pragma once
#include "PropObject.h"
#include "resource.h"

class CDefense : public CPropObject
{
public:

	//构造
	CDefense(void);

	//析构
	~CDefense(void);
public:

	//绘图
	BOOL Draw(CDC* pDC, BOOL bPause);

	//获得矩形区域
	CRect GetRect()
	{
		return CRect(m_ptPos, CPoint(m_ptPos.x + DEFENSE_WIDTH, m_ptPos.y + DEFENSE_HEIGHT));
	}

	//加载图像
	static BOOL LoadImage();

	
	//移动
	void Move();

	//防护盾
	BOOL PropFunction(CMyPlane* & pMe);

private:

	//血包位图大小 25*22
	static const int DEFENSE_WIDTH = 25;
	static const int DEFENSE_HEIGHT = 22;

	//图像链表
	static CImageList m_Images;
};

