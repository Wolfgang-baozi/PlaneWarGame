//CNbPattern.h : 定义文件
//

#pragma once
#include "stdafx.h"
#include "GameObject.h"
#include <mmsystem.h>

class CNbPattern : public CGameObject
{
	enum Pattern { on, off };
public:
	//构造
	CNbPattern(void);
	
	//析构
	~CNbPattern(void);

	//加载图像
	static BOOL LoadImage();

	//获得矩形
	CRect GetRect();

	//绘图
	BOOL Draw(CDC* pDC,BOOL bPause);

public:

	//图像链表
	static CImageList m_Image[3];

	//位图
	static const int NB_WIDTH = 35;
	static const int NB_HEIGHT = 25;
};