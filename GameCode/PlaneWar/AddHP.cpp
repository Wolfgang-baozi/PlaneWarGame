

#include "stdafx.h"
#include "AddHP.h"
#include "MoveLine.h"

//图像链表
CImageList CAddHP::m_Images;

//构造
CAddHP::CAddHP()
{
	//高度
	m_ptPos.y = -BLOOD_HEIGHT;

	//随机垂直位置 
	m_ptPos.x = rand() % (GAME_WIDTH - BLOOD_WIDTH);

	//初始水平移动方向
	m_nHorMotion = (rand() % 2 == 0) ? 1 : -1;

	//移速 1/2
	m_V = rand() % 2 + 1;

}

//析构
CAddHP::~CAddHP()
{

}

//移动
void CAddHP::Move()
{
	//移动
	CMoveLine pMoveLine;
	pMoveLine.Move(m_ptPos, GetHorMotion(), 1, GetV());

	//左右边界判定
	if (m_ptPos.x < 0 || m_ptPos.x > GAME_WIDTH - 20)
		SetHorMotion( -GetHorMotion() );

}

//加载图像 白底
BOOL CAddHP::LoadImage()
{
	return CGameObject::LoadImage(m_Images, IDB_BLOOD, RGB(255, 255, 255), BLOOD_WIDTH, BLOOD_HEIGHT, 1);
}

//绘图
BOOL CAddHP::Draw(CDC* pDC, BOOL bPause)
{
	//超出边界
	if (m_ptPos.y > GAME_HEIGHT) return FALSE;

	//移动
	if (!bPause)
	{
		Move();
	}
	//绘图
	m_Images.Draw(pDC, 0, m_ptPos, ILD_TRANSPARENT);

	return TRUE;
}

//回血
BOOL CAddHP::PropFunction(CMyPlane* & pMe)
{
	int nHP = rand() % pMe->GetSumHP() + pMe->GetSumHP() / 3;
	pMe->PlusHP(nHP);

	return FALSE;
}