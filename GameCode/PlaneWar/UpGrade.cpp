

#include "stdafx.h"
#include "UpGrade.h"
#include "MoveLine.h"

//图像链表
CImageList CUpGrade::m_Images;

//构造
CUpGrade::CUpGrade()
{
	//高度
	m_ptPos.y = 0;

	//随机垂直位置 
	m_ptPos.x = rand() % (GAME_WIDTH - UPGRADE_WIDTH);

	//初始水平移动方向
	SetHorMotion( (rand() % 2 == 0) ? 1 : -1);

	//移速 1/2
	m_V = rand() % 2 + 1;

}

//析构
CUpGrade::~CUpGrade()
{

}

//移动
void CUpGrade::Move()
{
	
	CMoveLine pMoveLine;
	pMoveLine.Move(m_ptPos, GetHorMotion(), 1, GetV());

	//左右边界判定
	if (m_ptPos.x < 0 || m_ptPos.x > GAME_WIDTH - 20)
		SetHorMotion( -GetHorMotion() );
}

//加载图像 白底
BOOL CUpGrade::LoadImage()
{
	return CGameObject::LoadImage(m_Images, IDB_UPGRADE, RGB(255, 255, 255), UPGRADE_WIDTH, UPGRADE_HEIGHT, 1);
}

//绘图
BOOL CUpGrade::Draw(CDC* pDC, BOOL bPause)
{
	//超出边界
	if (m_ptPos.y > GAME_HEIGHT) return FALSE;

	if (!bPause) {
		//移动
		Move();
	}

	//绘图
	m_Images.Draw(pDC, 0, m_ptPos, ILD_TRANSPARENT);

	return TRUE;
}

//战机升级
BOOL CUpGrade::PropFunction(CMyPlane* & pMe)
{
	pMe->AddGrade(1);

	return FALSE;
}