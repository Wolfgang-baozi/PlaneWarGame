 #pragma once
#include "EnemyObject.h"
#include "resource.h"

class CBossKing :public CEnemyObject
{
public:
	//构造
	CBossKing();

	//析构
	~CBossKing();

public:
	//加载对象
	BOOL Draw(CDC* pDC, BOOL bPause);

	//获得矩形区域
	CRect GetRect();

	//是否开火
	BOOL Fired();

	//移动
	void Move();

	//绘制图片
	static BOOL LoadImage();

protected:
	//链表
	static CImageList m_Images;

	//飞机大小
	static const int BOSSKING_WIDTH = 150;
	static const int BOSSKING_HEIGHT = 90;
};

