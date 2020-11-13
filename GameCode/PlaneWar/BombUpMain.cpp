
#include "Stdafx.h"
#include "BombUpMain.h"
#include "resource.h"
#include "MoveLine.h"

CImageList CBombUpMain::m_Images;

//构造
CBombUpMain::CBombUpMain(int x, int y)
{
	//子弹水平运行方向 -> 静止
	SetHorMotion(0);

	//子弹垂直运行方向 -> 下
	SetVerMotion(-1);

	//初始位置
	m_ptPos.x = x;
	m_ptPos.y = y;

	//子弹移速
	m_nV = 30;

	//子弹伤害
	m_nHarm = 80;
}

//析构
CBombUpMain::~CBombUpMain(void)
{

}


//移动
BOOL CBombUpMain::Move()
{
	CMoveLine pMoveLine;
	pMoveLine.Move(m_ptPos, GetHorMotion(), GetVerMotion(), GetV());

	//超出边界
	if(m_ptPos.y < -BOMBUPMAIN_HEIGHT && m_ptPos.x < -BOMBUPMAIN_WIDTH && m_ptPos.x > GAME_WIDTH - BOMBUPMAIN_WIDTH)
		return FALSE;

	return TRUE;
}


//加载图片
BOOL CBombUpMain::LoadImage()
{
	return CGameObject::LoadImage(m_Images, IDB_BOMBUP_MAIN, RGB(255, 255, 255), BOMBUPMAIN_WIDTH, BOMBUPMAIN_HEIGHT, 1);
}

//绘图
BOOL CBombUpMain::Draw(CDC* pDC, BOOL bPause)
{
	//移动
	if(!bPause)
	{
		if( !Move() )
			return FALSE;
	}

	//绘图
	m_Images.Draw(pDC, 0, m_ptPos, ILD_TRANSPARENT);

	return TRUE;
}