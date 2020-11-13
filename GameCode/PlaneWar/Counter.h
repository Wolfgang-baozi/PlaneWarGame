#pragma once

#include "stdafx.h"
#include "GameObject.h"
#include "resource.h"
#include <vector>
using namespace std;

class CCounter : public CGameObject
{
public:
	
	//构造
	CCounter();
	
	//析构
	~CCounter(void);

public:

	//加分数
	void PlusNum(int x = 0);

	//获得总分
	int GetCount() const;

	//获得矩形区域
	CRect GetRect()
	{
		return CRect(m_ptPos, CPoint(m_ptPos.x, m_ptPos.y));
	}

	//加载图片
	static BOOL LoadImage();

	//获取每一位数字
	int CCounter::GetPerNumber();
	
	//绘图
	BOOL Draw(CDC* pDC, BOOL bPause);

private:
	
	//图像链表
	static CImageList m_Images;

	//位图 150*34
	static const int NUMBER_WIDTH = 22;
	static const int NUMBER_HEIGHT = 27;
	
	//计分
	int m_nCounter;

	//存每一位数字
	vector<int> m_vNum;
};

 