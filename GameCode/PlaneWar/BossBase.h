#pragma once

#include "stdAfx.h"
#include "EnemyObject.h"
#include "resource.h"

class CBossBase : public CEnemyObject
{
public:
	//构造
	CBossBase();

	//析构
	~CBossBase();

public:

	//获得矩形区域
	CRect GetRect();

	//是否开火
	BOOL Fired();

	//绘制图片
	static BOOL LoadImage();

	//移动
	void Move();

	//加载对象
	BOOL Draw(CDC* pDC, BOOL bPause);

protected:
	//链表
	static CImageList m_Images;

	//飞机大小
	static const int BOSSBASE_WIDTH = 150;
	static const int BOSSBASE_HEIGHT = 90;

};

