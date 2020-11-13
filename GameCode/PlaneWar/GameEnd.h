// CGameEnd.h : 实现文件
//

#pragma once
#include "stdafx.h"
#include "GameObject.h"
#include "resource.h"
#include <mmsystem.h>

class CGameEnd : public CGameObject
{
	enum Type { startback, startgame, help, rank, hell, smile};
public:
	
	//构造
	CGameEnd(void);
	
	//析构
	~CGameEnd(void);

public:

	//绘图
	BOOL Draw(CDC* pDC, BOOL bPause);

	//获得区域
	CRect GetRect();
	
	//加载图片
	static BOOL LoadImage();

private:

	//图像链表
	static CImageList m_Image;

	//位图大小
	static const int END_WIDTH = 300;
	static const int END_HEIGHT = 150;

};

