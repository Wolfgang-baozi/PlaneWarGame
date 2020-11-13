#pragma once
#include "EnemyObject.h"
#include "resource.h"

class CBossMid : public CEnemyObject
{
public:
	//构造
	CBossMid(void);

	//析构
	~CBossMid(void);

public:

	//获得矩形区域
	CRect GetRect();

	//是否开火
	BOOL Fired();

	//移动
	void Move();

	//绘制图片
	static BOOL LoadImage();

	//加载对象
	BOOL Draw(CDC* pDC, BOOL bPause);

protected:
	//链表
	static CImageList m_Images;

	//飞机大小
	static const int BOSSMID_WIDTH = 150;
	static const int BOSSMID_HEIGHT = 90;


};
