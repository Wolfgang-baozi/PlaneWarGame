

#include "stdafx.h"
#include "BossKing.h"
#include "EnemyYellow.h"
#include "MoveLine.h"

CImageList CBossKing::m_Images;
CBossKing::CBossKing()
{
	//随机确定BossMid位置
	m_ptPos.x = rand() % (GAME_WIDTH - BOSSKING_HEIGHT * 2);
	m_ptPos.y = 0;
	
	//确定血量
	InitHP(30000);

	//敌机破坏力
	m_nHarm = 30;

	//移动速度
	m_V = 1;

	//发射延迟
	m_nWait = 0;

	//初始移动方向
	SetHorMotion(rand() % 2 ? 1 : -1);
	SetVerMotion(1);

	
}

//析构
CBossKing::~CBossKing()
{
	
}

//移动
void CBossKing::Move()
{
	CMoveLine pMoveLine;
	pMoveLine.Move(m_ptPos, GetHorMotion(), GetVerMotion(), GetV());
	
	//左右边界
	if (m_ptPos.x <= 10 || m_ptPos.x >= GAME_WIDTH - BOSSKING_WIDTH - 20)
	{
		SetHorMotion( -GetHorMotion() );
		m_V = rand() % 2 + 2;
	}
	//上下边界
	if (m_ptPos.y <= 0 || m_ptPos.y >= GAME_HEIGHT / 2)
	{
		SetVerMotion( -GetVerMotion() );
		m_V = rand() % 2 + 2;
	}
}

//获得矩形区域
CRect CBossKing::GetRect()
{
	return CRect(m_ptPos, CPoint(m_ptPos.x + BOSSKING_WIDTH, m_ptPos.y + BOSSKING_HEIGHT));
}

//加载图片
BOOL CBossKing::LoadImage()
{
	return CGameObject::LoadImage(m_Images, IDB_BOSSKING, RGB(255, 255, 255), BOSSKING_WIDTH, BOSSKING_HEIGHT, 0);
}

//绘制图片
BOOL CBossKing::Draw(CDC* pDC, BOOL bPause)
{
	//冷却
	m_nWait++;
	if (m_nWait > 10)
		m_nWait = 0;

	if (!bPause)
	{
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

//是否发射子弹
BOOL CBossKing::Fired()
{
	if( GetWait() == 0 )
		return TRUE;
	else
		return FALSE;
}
