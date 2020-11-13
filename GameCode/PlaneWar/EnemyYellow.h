#pragma once
#include "EnemyObject.h"
#include "resource.h"

class CEnemyYellow : public CEnemyObject
{
public:
	//构造
	CEnemyYellow(void);
	CEnemyYellow(int x, int y);

	//析构
	~CEnemyYellow();
public:

	//加载对象
	BOOL Draw(CDC* pDC, BOOL bPause);

	//获得矩形区域
	CRect GetRect();

	//是否发射子弹
	BOOL Fired();
	
	//移动
	BOOL Move();

	//绘制图片
	static BOOL LoadImage();

protected:

	//链表
	static CImageList m_Images;

	//飞机大小
	static const int ENEMYYELLOW_WIDTH = 50;
	static const int ENEMYYELLOW_HEIGHT = 35;
	

	//垂直方向 1->向下 0->停止 
	int    m_nHorMotion;

	//水平方向 1->向左 0->停止 -1->向右
	int		m_nVerMotion;
};
