

#include "stdafx.h"
#include "EnemyGreen.h"
#include "MoveLine.h"

CImageList CEnemyGreen::m_Images;

CEnemyGreen::CEnemyGreen()
{
	//�ɻ��˺�
	m_nHarm = 10;

	//���ȷ��Xλ��
	m_ptPos.x = rand() % (GAME_WIDTH - ENEMYGREEN_WIDTH) + 1;
	m_ptPos.y = 0;
	
	//ȷ���ٶ�
	m_V = 6;

	//�����ӳ�
	m_nWait = 0;

	//Ѫ��
	InitHP(20);

	//�л��˺�
	m_nHarm = 4;

	//����
	SetHorMotion(0);
	SetVerMotion(1);

}

//����
CEnemyGreen::~CEnemyGreen()
{

}

//�ƶ�
BOOL CEnemyGreen::Move()
{
	CMoveLine pMoveLine;
	pMoveLine.Move(m_ptPos, GetHorMotion(), GetVerMotion(), GetV());

	//�߽��ж�
	if (m_ptPos.y > GAME_HEIGHT + ENEMYGREEN_HEIGHT)
		return FALSE;

	return TRUE;
}


//��þ���
CRect CEnemyGreen::GetRect()
{
	return CRect(m_ptPos, CPoint(m_ptPos.x + ENEMYGREEN_WIDTH, m_ptPos.y + ENEMYGREEN_HEIGHT));
}

//����ͼ��
BOOL CEnemyGreen::LoadImage()
{
	return CGameObject::LoadImage(m_Images, IDB_ENEMYGREEN, RGB(255, 255, 255), ENEMYGREEN_WIDTH, ENEMYGREEN_HEIGHT, 0);
}

//��ͼ
BOOL CEnemyGreen::Draw(CDC* pDC, BOOL bPause)
{
	//��ȴ
	m_nWait++;
	if (m_nWait > 35)
		m_nWait = 0;

	//�ƶ�
	if (!bPause)
	{
		if(!Move())
			return FALSE;
	}


	//��ͼ
	m_Images.Draw(pDC, 0, m_ptPos, ILD_TRANSPARENT);

	return TRUE;
}

//����
BOOL CEnemyGreen::Fired()
{
	if (m_nWait == 0)
		return TRUE;
	else
		return FALSE;
}

