// CGameSta.h : 实现文件
//

#pragma once
#include "stdafx.h"
#include "GameObject.h"
#include "resource.h"
#include <mmsystem.h>

class CGameSta : public CGameObject
{
	enum Type { startback, startgame, help, rank, hell};
public:
	
	//构造
	CGameSta(void);
	
	//析构
	~CGameSta(void);

public:

	//绘图
	BOOL Draw(CDC* pDC, BOOL bPause);

	//获得背景区域
	CRect GetRect();

	//获得开始区域
	CRect GetRectStart();

	//帮助区域
	CRect GetRectHelp();

	//困难模式
	CRect GetRectHell();
	
	//加载图片
	static BOOL LoadImage();

	//帮助
	void AddText(CDC* pDC);

private:

	//图像链表
	static CImageList m_Image[4];

	//位图大小
	//start button
	static const int START_SIZE = 120;
	//help button
	static const int BUTTON_SIZE  = 30;

	//位置
	CPoint		m_ptHelp; //help
	CPoint		m_ptHell; //hell
};

