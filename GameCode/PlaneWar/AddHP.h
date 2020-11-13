#pragma once
#include "PropObject.h"
#include "resource.h"

class CAddHP : public CPropObject
{
public:

	//构造
	CAddHP(void);

	//析构
	~CAddHP(void);
public:

	//绘图
	BOOL Draw(CDC* pDC, BOOL bPause);

	//获得矩形区域
	CRect GetRect()
	{
		return CRect(m_ptPos, CPoint(m_ptPos.x + BLOOD_WIDTH, m_ptPos.y + BLOOD_HEIGHT));
	}

	//移动
	void Move();

	//加载图像
	static BOOL LoadImage();

	//回血
	BOOL PropFunction(CMyPlane* & pMe);

private:

	//血包位图大小25*26
	static const int BLOOD_WIDTH = 25;
	static const int BLOOD_HEIGHT = 26;

	//图像链表
	static CImageList m_Images;
};

