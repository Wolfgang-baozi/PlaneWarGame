//BossBase

#include "Stdafx.h"
#include "BossMid.h"
#include "EnemyYellow.h"
#include "MoveLine.h"

//ͼ������
CImageList CBossMid::m_Images;

CBossMid::CBossMid()
{
	//���ȷ��BossMidλ��
	m_ptPos.x = rand() % (GAME_WIDTH - BOSSMID_HEIGHT * 2);
	m_ptPos.y = 0;
	
	//ȷ��Ѫ��
	InitHP(20000);

	//�л��ƻ���
	m_nHarm = 50;

	//�ƶ��ٶ�
	m_V = 1;

	//�����ӳ�
	m_nWait = 0;

	//��ʼ�ƶ�����
	SetHorMotion(rand() % 2 ? 1 : -1);
	SetVerMotion(1);
}

//����
CBossMid::~CBossMid()
{

}

//�ƶ�
void CBossMid::Move()
{
	CMoveLine pMoveLine;
	pMoveLine.Move(m_ptPos, GetHorMotion(), GetVerMotion(), GetV());

	//���ұ߽�
	if (m_ptPos.x <= 10 || m_ptPos.x >= GAME_WIDTH - BOSSMID_WIDTH - 20)
	{
		SetHorMotion( -GetHorMotion() );
		m_V = rand() % 2 + 1;
	}
	//���±߽�
	if (m_ptPos.y <= 0 || m_ptPos.y >= 300)
	{
		SetVerMotion( -GetVerMotion() );
		m_V = rand() % 2 + 1;
	}
}

//��þ���
CRect CBossMid::GetRect()
{
	return CRect(m_ptPos, CPoint(m_ptPos.x + BOSSMID_WIDTH, m_ptPos.y + BOSSMID_HEIGHT));
}

//�Ƿ񿪻�
BOOL CBossMid::Fired()
{
	if( GetWait() == 0 )
		return TRUE;
	else
		return FALSE;
}


//����ͼƬ
BOOL CBossMid::LoadImage()
{
	return CGameObject::LoadImage(m_Images, IDB_BOSSMID, RGB(255, 255, 255), BOSSMID_WIDTH, BOSSMID_HEIGHT, 0);
}

//����ͼƬ
BOOL CBossMid::Draw(CDC* pDC, BOOL bPause)
{
	//��ȴ
	m_nWait++;
	if (m_nWait > 10)
		m_nWait = 0;

	if (!bPause)
	{
		//�ƶ�
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
