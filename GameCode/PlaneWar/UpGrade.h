#pragma once
#include "PropObject.h"
#include "resource.h"

class CUpGrade : public CPropObject
{
public:

	//构造
	CUpGrade(void);

	//析构
	~CUpGrade(void);
public:

	//绘图
	BOOL Draw(CDC* pDC, BOOL bPause);

	//获得矩形区域
	CRect GetRect()
	{
		return CRect(m_ptPos, CPoint(m_ptPos.x + UPGRADE_WIDTH, m_ptPos.y + UPGRADE_HEIGHT));
	}

	//移动
	void Move();

	//加载图像
	static BOOL LoadImage();

	//战机升级
	BOOL PropFunction(CMyPlane* & pMe);

private:

	//升级 位图大小 25*23
	static const int UPGRADE_WIDTH = 25;
	static const int UPGRADE_HEIGHT = 23;

	//图像链表
	static CImageList m_Images;
};

