#pragma once
#include "GameObject.h"
#include "resource.h"

class CExplosion : public CGameObject
{
public:

	//构造
	CExplosion(int x, int y);

	//析构
	~CExplosion(void);

	//绘图
	BOOL Draw(CDC* pDC, BOOL bPause);

	//加载图片
	static BOOL LoadImage();

	//获得矩形区域
	CRect GetRect()
	{
		return CRect(m_ptPos, CPoint(m_ptPos.x + EXPLOSION_HEIGHT, m_ptPos.y + EXPLOSION_HEIGHT));
	}

private:

	//炸弹的图片列表
	static CImageList m_Images;
	
	//图像索引的步进计数
	int m_nProcess;

public:
	
	//爆炸位图
	static const int  EXPLOSION_HEIGHT = 66;

};