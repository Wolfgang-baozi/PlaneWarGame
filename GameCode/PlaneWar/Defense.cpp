

#include "stdafx.h"
#include "Defense.h"
#include "MoveLine.h"

//图像链表
CImageList CDefense::m_Images;

//构造
CDefense::CDefense()
{
	//高度
	m_ptPos.y = -DEFENSE_HEIGHT;

	//随机垂直位置 
	m_ptPos.x = rand() % (GAME_WIDTH - DEFENSE_WIDTH);

	//初始水平移动方向
	m_nHorMotion = (rand() % 2 == 0) ? 1 : -1;

	//移速 1/2
	m_V = rand() % 2 + 1;

}

//析构
CDefense::~CDefense()
{

}


//移动
void CDefense::Move()
{
	CMoveLine pMoveLine;
	pMoveLine.Move(m_ptPos, GetHorMotion(), 1, GetV());

	//左右边界判定
	if (m_ptPos.x < 0 || m_ptPos.x > GAME_WIDTH - 20)
		SetHorMotion( -GetHorMotion() );
}

//加载图像 白底
BOOL CDefense::LoadImage()
{
	return CGameObject::LoadImage(m_Images, IDB_DEFENSE, RGB(255, 255, 255), DEFENSE_WIDTH, DEFENSE_HEIGHT, 1);
}

//绘图
BOOL CDefense::Draw(CDC* pDC, BOOL bPause)
{
	//超出边界
	if (m_ptPos.y > GAME_HEIGHT) return FALSE;

	if (!bPause) 
	{
		//移动
		Move();
	}

	//绘图
	m_Images.Draw(pDC, 0, m_ptPos, ILD_TRANSPARENT);

	return TRUE;
}

//召唤僚机
BOOL CDefense::PropFunction(CMyPlane* & pMe)
{
	return TRUE;
}