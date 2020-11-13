//BossBase

#include "Stdafx.h"
#include "BossBase.h"
#include "EnemyYellow.h"
#include "MoveLine.h"

//ͼ������
CImageList CBossBase::m_Images;

CBossBase::CBossBase()
{
	//���ȷ��BossBaseλ��
	m_ptPos.x = rand() % (GAME_WIDTH - BOSSBASE_HEIGHT * 2);
	m_ptPos.y = 0;
	
	//ȷ��Ѫ��
	InitHP(10000);

	//�л��ƻ���
	m_nHarm = 20;

	//�ƶ��ٶ�
	m_V = 1;

	//�����ӳ�
	m_nWait = 0;

	//��ʼ�ƶ�����
	SetHorMotion(rand() % 2 ? 1 : -1);
	SetVerMotion(1);
	
}

//����
CBossBase::~CBossBase()
{
	
}

//�ƶ�
void  CBossBase::Move()
{
	//�ƶ�
	CMoveLine pMoveLine;
	pMoveLine.Move(m_ptPos, GetHorMotion(), GetVerMotion(), GetV());
		
	//���ұ߽�
	if (m_ptPos.x <= 10 || m_ptPos.x >= GAME_WIDTH - BOSSBASE_WIDTH - 20)
	{
		SetHorMotion( -GetHorMotion() );
	}
	//���±߽�
	if (m_ptPos.y <= 0 || m_ptPos.y >= GAME_HEIGHT / 4)
	{
		SetVerMotion( -GetVerMotion() );
	}
}

//��þ���
CRect CBossBase::GetRect()
{
	return CRect(m_ptPos, CPoint(m_ptPos.x + BOSSBASE_WIDTH, m_ptPos.y + BOSSBASE_HEIGHT));
}

//�Ƿ񿪻�
BOOL CBossBase::Fired()
{
	if (m_nWait == 0)
		return TRUE;
	else
		return FALSE;
}

//����ͼƬ
BOOL CBossBase::LoadImage()
{
	return CGameObject::LoadImage(m_Images, IDB_BOSSBASE, RGB(255, 255, 255), BOSSBASE_WIDTH, BOSSBASE_HEIGHT, 0);
}

//����ͼƬ
BOOL CBossBase::Draw(CDC* pDC, BOOL bPause)
{
	//��ȴ
	m_nWait++;
	if (m_nWait > 10)
		m_nWait = 0;

	if (!bPause)
	{
		Move();
	}

	//��ͼ
	//BOSS
	m_Images.Draw(pDC, 0, m_ptPos, ILD_TRANSPARENT);
	
	//����Ѫ��
	CBrush *m_pBrush;
	m_pBrush = new CBrush(RGB(255, 0, 0));
	pDC->FillRect(CRect(m_ptPos.x, m_ptPos.y - 20, m_ptPos.x + 150 * (m_nNowHP * 1.0 / GetSumHP()), m_ptPos.y - 15), m_pBrush);

	delete m_pBrush;

	return TRUE;
}

