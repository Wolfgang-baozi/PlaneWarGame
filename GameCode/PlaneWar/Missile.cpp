//CMissile : 实现文件
//

#include "Stdafx.h"
#include "Missile.h"
#include "resource.h"
#include "MoveLine.h"
#include <cmath>

CImageList CMissile::m_Images;

//构造
CMissile::CMissile(int x, int y)
{
	int nHor = rand() % 2 == 0 ? 1 : -1;
	//子弹水平运行方向 -> 静止
	SetHorMotion(nHor);

	//子弹垂直运行方向 -> 下
	SetVerMotion(1);

	//初始位置
	m_ptPos.x = m_nStaX = x;
	m_ptPos.y = y;
	
	//子弹伤害
	m_nHarm = 10;

	//移速
	m_nV = 8;

	//
	m_nMaxHor = rand() % 40 + 30;
}    

//析构
CMissile::~CMissile(void)
{

}

//移动
BOOL CMissile::Move()
{
	CMoveLine pMoveLine;
	pMoveLine.Move(m_ptPos, GetHorMotion(), GetVerMotion(), GetV());

	//超出边界
	if(m_ptPos.y < -BOMBMISSILE_HEIGHT || m_ptPos.y > GAME_HEIGHT + BOMBMISSILE_HEIGHT )
		return FALSE;
	if (m_ptPos.x < m_nStaX - m_nMaxHor || m_ptPos.x < 0 || m_ptPos.x > GAME_HEIGHT - BOMBMISSILE_HEIGHT || m_ptPos.x > m_nStaX + m_nMaxHor)
		SetHorMotion(-GetHorMotion());
	return TRUE;
}


//加载图片
BOOL CMissile::LoadImage()
{
	return CGameObject::LoadImage(m_Images, IDB_MISSILE, RGB(255, 255, 255), BOMBMISSILE_WIDTH, BOMBMISSILE_HEIGHT, 1);
}

//绘图
BOOL CMissile::Draw(CDC* pDC, BOOL bPause)
{
	if(!bPause)
	{
		//移动
		if(!Move())
			return FALSE;
	}

	//绘图
	m_Images.Draw(pDC, 0, m_ptPos, ILD_TRANSPARENT);

	return TRUE;
}