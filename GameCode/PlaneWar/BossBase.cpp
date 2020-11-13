//BossBase

#include "Stdafx.h"
#include "BossBase.h"
#include "EnemyYellow.h"
#include "MoveLine.h"

//图像链表
CImageList CBossBase::m_Images;

CBossBase::CBossBase()
{
	//随机确定BossBase位置
	m_ptPos.x = rand() % (GAME_WIDTH - BOSSBASE_HEIGHT * 2);
	m_ptPos.y = 0;
	
	//确定血量
	InitHP(10000);

	//敌机破坏力
	m_nHarm = 20;

	//移动速度
	m_V = 1;

	//发射延迟
	m_nWait = 0;

	//初始移动方向
	SetHorMotion(rand() % 2 ? 1 : -1);
	SetVerMotion(1);
	
}

//析构
CBossBase::~CBossBase()
{
	
}

//移动
void  CBossBase::Move()
{
	//移动
	CMoveLine pMoveLine;
	pMoveLine.Move(m_ptPos, GetHorMotion(), GetVerMotion(), GetV());
		
	//左右边界
	if (m_ptPos.x <= 10 || m_ptPos.x >= GAME_WIDTH - BOSSBASE_WIDTH - 20)
	{
		SetHorMotion( -GetHorMotion() );
	}
	//上下边界
	if (m_ptPos.y <= 0 || m_ptPos.y >= GAME_HEIGHT / 4)
	{
		SetVerMotion( -GetVerMotion() );
	}
}

//获得矩形
CRect CBossBase::GetRect()
{
	return CRect(m_ptPos, CPoint(m_ptPos.x + BOSSBASE_WIDTH, m_ptPos.y + BOSSBASE_HEIGHT));
}

//是否开火
BOOL CBossBase::Fired()
{
	if (m_nWait == 0)
		return TRUE;
	else
		return FALSE;
}

//加载图片
BOOL CBossBase::LoadImage()
{
	return CGameObject::LoadImage(m_Images, IDB_BOSSBASE, RGB(255, 255, 255), BOSSBASE_WIDTH, BOSSBASE_HEIGHT, 0);
}

//绘制图片
BOOL CBossBase::Draw(CDC* pDC, BOOL bPause)
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

