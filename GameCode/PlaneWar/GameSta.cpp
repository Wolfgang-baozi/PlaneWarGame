// CGameSta.cpp : 实现文件
//

#include "stdafx.h"
#include "GameSta.h"
#include "resource.h"

//图像链表
CImageList CGameSta::m_Image[4];

//构造
CGameSta::CGameSta()
{
	//通过start的位置 确定其他按钮位置
	m_ptPos.x = GAME_WIDTH / 2 - START_SIZE / 2 - 10;
	m_ptPos.y = GAME_HEIGHT - START_SIZE - 21;

	//help
	m_ptHelp.x = m_ptPos.x - BUTTON_SIZE - 10;
	m_ptHelp.y = m_ptPos.y + BUTTON_SIZE * 2 / 3 + 10;

	//hell
	m_ptHell.x = m_ptPos.x + START_SIZE + 10;
	m_ptHell.y = m_ptPos.y + BUTTON_SIZE * 2 / 3 + 10;
}

//析构
CGameSta::~CGameSta()
{

}

//获得矩形区域 ->背景
CRect CGameSta::GetRect()
{
	return CRect(CPoint(0,0), CPoint(GAME_WIDTH, GAME_HEIGHT));
}

//开始区域
CRect CGameSta::GetRectStart()
{
	return CRect(m_ptPos, CPoint(m_ptPos.x + START_SIZE, m_ptPos.y + START_SIZE));
}

//帮助区域
CRect CGameSta::GetRectHelp()
{
	return CRect(m_ptHelp, CPoint(m_ptHelp.x + BUTTON_SIZE, m_ptHelp.y + BUTTON_SIZE)); 
}

//困难模式
CRect CGameSta::GetRectHell()
{
	return CRect(m_ptHell, CPoint(m_ptHell.x + BUTTON_SIZE, m_ptHell.y + BUTTON_SIZE)); 
}

//加载图片
BOOL CGameSta::LoadImage()
{
	return CGameObject::LoadImage(m_Image[startback], IDB_STARTBACK, RGB(255, 255, 255), GAME_WIDTH - 20, GAME_HEIGHT, 0) &&
		   CGameObject::LoadImage(m_Image[startgame], IDB_STARTBUTTON, RGB(0, 0, 0), START_SIZE, START_SIZE, 0) &&
		   CGameObject::LoadImage(m_Image[help], IDB_HELP, RGB(0, 0, 0), BUTTON_SIZE, BUTTON_SIZE, 0) &&
		   CGameObject::LoadImage(m_Image[hell], IDB_HELL, RGB(0, 0, 0), BUTTON_SIZE, BUTTON_SIZE, 0) ;
}

BOOL CGameSta::Draw(CDC* pDC, BOOL bHelp)
{
	//背景
	m_Image[startback].Draw(pDC, 0, CPoint(0, 0), ILD_TRANSPARENT);
	//开始
	m_Image[startgame].Draw(pDC, 0, m_ptPos, ILD_TRANSPARENT);
	//帮助
	m_Image[help].Draw(pDC, 0, m_ptHelp, ILD_TRANSPARENT);
	//困难模式
	m_Image[hell].Draw(pDC, 0, m_ptHell, ILD_TRANSPARENT);

	if(bHelp)
	{
		AddText(pDC);
	}
	return TRUE;
}

//帮助文档
void CGameSta::AddText(CDC* pDC)
{
	int		nStaVer = 360;
	int		nDisVer  = 25;
	int		nTab = 30;
	int		nDisTab = 40;
	CFont font;
	font.CreateFont(20,
		8,
		0,
		0,
		400,
		FALSE,
		FALSE,
		0,
		ANSI_CHARSET,
		OUT_DEFAULT_PRECIS,
		CLIP_DEFAULT_PRECIS,
		DEFAULT_QUALITY,
		DEFAULT_PITCH | FF_SWISS,
		_T("微软雅黑"));  //创建新字体
	pDC->SetBkMode(TRANSPARENT);
	pDC->SetTextColor(RGB(255, 255, 255));
	CFont* pOld = pDC->SelectObject(&font);

	pDC->TextOut(nTab, nStaVer, _T("1.战机介绍："));
	pDC->TextOut(nTab + nDisTab, nStaVer + nDisVer, _T("战机有三个等级，上下左右控制战机移动，空格发射子弹"));
	pDC->TextOut(nTab, nStaVer + nDisVer * 2, _T("2.道具技能："));
	pDC->TextOut(nTab + nDisTab, nStaVer + nDisVer * 3, _T("'B'键开启无敌模式"));
	pDC->TextOut(nTab + nDisTab, nStaVer + nDisVer * 4, _T("血包：每吃一个根据总血量随机增加（至少增加一半），直至战机血量满为止"));
	pDC->TextOut(nTab + nDisTab, nStaVer + nDisVer * 5, _T("盾牌：用于召唤一个僚机"));
	pDC->TextOut(nTab + nDisTab, nStaVer + nDisVer * 6, _T("升级：用于战机升级。"));
	pDC->TextOut(nTab, nStaVer + nDisVer * 7, _T("3.规则介绍："));
	pDC->TextOut(nTab + nDisTab, nStaVer + nDisVer * 8, _T("Boss模式（无尽模式），每关难度递增"));
	pDC->TextOut(nTab + nDisTab, nStaVer + nDisVer * 9, _T("每关会在指定的敌机数后出现Boss，打败Boss即可进入下一关"));
	pDC->TextOut(nTab + nDisTab, nStaVer + nDisVer * 10, _T("困难模式关卡随机，难度递增"));
	pDC->TextOut(nTab + nDisTab, nStaVer + nDisVer * 11, _T("战机死亡，游戏结束，点击界面任意处，返回主界面"));
	pDC->SelectObject((pOld));

}
