

#include "stdafx.h"
#include "BossKing.h"
#include "EnemyYellow.h"
#include "MoveLine.h"

CImageList CBossKing::m_Images;
CBossKing::CBossKing()
{
	//���ȷ��BossMidλ��
	m_ptPos.x = rand() % (GAME_WIDTH - BOSSKING_HEIGHT * 2);
	m_ptPos.y = 0;
	
	//ȷ��Ѫ��
	InitHP(30000);

	//�л��ƻ���
	m_nHarm = 30;

	//�ƶ��ٶ�
	m_V = 1;

	//�����ӳ�
	m_nWait = 0;

	//��ʼ�ƶ�����
	SetHorMotion(rand() % 2 ? 1 : -1);
	SetVerMotion(1);

	
}

//����
CBossKing::~CBossKing()
{
	
}

//�ƶ�
void CBossKing::Move()
{
	CMoveLine pMoveLine;
	pMoveLine.Move(m_ptPos, GetHorMotion(), GetVerMotion(), GetV());
	
	//���ұ߽�
	if (m_ptPos.x <= 10 || m_ptPos.x >= GAME_WIDTH - BOSSKING_WIDTH - 20)
	{
		SetHorMotion( -GetHorMotion() );
		m_V = rand() % 2 + 2;
	}
	//���±߽�
	if (m_ptPos.y <= 0 || m_ptPos.y >= GAME_HEIGHT / 2)
	{
		SetVerMotion( -GetVerMotion() );
		m_V = rand() % 2 + 2;
	}
}

//��þ�������
CRect CBossKing::GetRect()
{
	return CRect(m_ptPos, CPoint(m_ptPos.x + BOSSKING_WIDTH, m_ptPos.y + BOSSKING_HEIGHT));
}

//����ͼƬ
BOOL CBossKing::LoadImage()
{
	return CGameObject::LoadImage(m_Images, IDB_BOSSKING, RGB(255, 255, 255), BOSSKING_WIDTH, BOSSKING_HEIGHT, 0);
}

//����ͼƬ
BOOL CBossKing::Draw(CDC* pDC, BOOL bPause)
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

//�Ƿ����ӵ�
BOOL CBossKing::Fired()
{
	if( GetWait() == 0 )
		return TRUE;
	else
		return FALSE;
}