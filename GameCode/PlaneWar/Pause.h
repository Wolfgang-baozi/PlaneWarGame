// CPause.h : 定义文件
//

#pragma once
#include "stdafx.h"
#include "GameObject.h"
#include "resource.h"
#include <mmsystem.h>

class CPause : public CGameObject
{
	enum Button { pause, back, continuebutton };
public:
	//构造
	CPause(void);

	//析构
	~CPause(void);

	//加载图像
	static BOOL LoadImage();

	//绘图
	BOOL Draw(CDC *pDC, BOOL bPause);

	//获得矩形 -> 停止
	CRect GetRectStop();

	//获得矩形 -> 继续
	CRect GetRectGo();

	//获得矩形 -> 返回
	CRect GetRect();

	//是否暂停
	void PauseButton(bool & bPause);

private:

	//图像链表
	static CImageList m_Image[3];

	//位图
	//puase continue
	static const int BUTTON_WIDTH = 20;
	static const int BUTTON_HEIGHT = 20;
	//go back
	static const int BACK_WIDTH = 20;
	static const int BACK_HEIGHT = 20;

	//返回键位置
	CPoint			 m_ptBack;
};