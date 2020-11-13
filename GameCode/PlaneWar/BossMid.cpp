//BossBase

#include "Stdafx.h"
#include "BossMid.h"
#include "EnemyYellow.h"
#include "MoveLine.h"

//图像链表
CImageList CBossMid::m_Images;

CBossMid::CBossMid()
{
	//随机确定BossMid位置
	m_ptPos.x = rand() % (GAME_WIDTH - BOSSMID_HEIGHT * 2);
	m_ptPos.y = 0;
	
	//确定血量
	InitHP(20000);

	//敌机破坏力
	m_nHarm = 50;

	//移动速度
	m_V = 1;

	//发射延迟
	m_nWait = 0;

	//初始移动方向
	SetHorMotion(rand() % 2 ? 1 : -1);
	SetVerMotion(1);
}

//析构
CBossMid::~CBossMid()
{

}

//移动
void CBossMid::Move()
{
	CMoveLine pMoveLine;
	pMoveLine.Move(m_ptPos, GetHorMotion(), GetVerMotion(), GetV());

	//左右边界
	if (m_ptPos.x <= 10 || m_ptPos.x >= GAME_WIDTH - BOSSMID_WIDTH - 20)
	{
		SetHorMotion( -GetHorMotion() );
		m_V = rand() % 2 + 1;
	}
	//上下边界
	if (m_ptPos.y <= 0 || m_ptPos.y >= 300)
	{
		SetVerMotion( -GetVerMotion() );
		m_V = rand() % 2 + 1;
	}
}

//获得矩形
CRect CBossMid::GetRect()
{
	return CRect(m_ptPos, CPoint(m_ptPos.x + BOSSMID_WIDTH, m_ptPos.y + BOSSMID_HEIGHT));
}

//是否开火
BOOL CBossMid::Fired()
{
	if( GetWait() == 0 )
		return TRUE;
	else
		return FALSE;
}


//加载图片
BOOL CBossMid::LoadImage()
{
	return CGameObject::LoadImage(m_Images, IDB_BOSSMID, RGB(255, 255, 255), BOSSMID_WIDTH, BOSSMID_HEIGHT, 0);
}

//绘制图片
BOOL CBossMid::Draw(CDC* pDC, BOOL bPause)
{
	//冷却
	m_nWait++;
	if (m_nWait > 10)
		m_nWait = 0;

	if (!bPause)
	{
		//移动
		Move();
	}

	//绘图
	//BOSS
	m_Images.Draw(pDC, 0, m_ptPos, ILD_TRANSPARENT);

	//绘制血条
	CBrush *m_pBrush;
	m_pBrush = new CBrush(RGB(255, 0, 0));
	pDC->FillRect(CRect(m_ptPos.x, m_ptPos.y - 20, m_ptPos.x + 150 * (m_nNowHP * 1.0 / GetSumHP()), m_ptPos.y - 15), m_pBrush);
	
	delete m_pBrush;

	return TRUE;
}
