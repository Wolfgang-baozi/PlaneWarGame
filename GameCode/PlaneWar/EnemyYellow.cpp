

#include "stdafx.h"
#include "EnemyYellow.h"
#include "MoveLine.h"

//ͼ������
CImageList CEnemyYellow::m_Images;

//����
CEnemyYellow::CEnemyYellow()
{

	//���ȷ��Xλ��
	m_ptPos.x = rand() % (GAME_WIDTH - ENEMYYELLOW_WIDTH) - 10;
	m_ptPos.y = 0;

	//�ƶ����� ->ˮƽ����,��ֱ����
	SetHorMotion(0);
	SetVerMotion(1);

	//���ȷ���ٶ�
	m_V = rand() % 15 + 2;

	//Ѫ��
	InitHP(15);

	//��ɫС�ɻ����˺�ֵ
	m_nHarm = 3;
}

CEnemyYellow::CEnemyYellow(int x, int y)
{

	//ȷ��Xλ��
	m_ptPos.x = x;
	m_ptPos.y = y;

	//�ƶ����� ->ˮƽ����,��ֱ����
	SetHorMotion(0);
	SetVerMotion(1);

	//���ȷ���ٶ�
	m_V = rand() % 10 + 6;

	//Ѫ��
	InitHP(15);

	//��ɫС�ɻ����˺�ֵ
	m_nHarm = 3;

}

//����
CEnemyYellow::~CEnemyYellow()
{

}


//�ƶ�
BOOL CEnemyYellow::Move()
{
	CMoveLine pMoveLine;
	pMoveLine.Move(m_ptPos, GetHorMotion(), GetVerMotion(), GetV());

	//�߽��ж�
	if (m_ptPos.y > GAME_HEIGHT || m_ptPos.y < 0)
		return FALSE;

	return TRUE;
}

//��þ���
CRect CEnemyYellow::GetRect()
{
	return CRect(m_ptPos, CPoint(m_ptPos.x + ENEMYYELLOW_WIDTH, m_ptPos.y + ENEMYYELLOW_HEIGHT));
}

//����ͼ��
BOOL CEnemyYellow::LoadImage()
{
	return CGameObject::LoadImage(m_Images, IDB_ENEMYYELLOW, RGB(255, 255, 255), ENEMYYELLOW_WIDTH, ENEMYYELLOW_HEIGHT, 0);
}

//��ͼ
BOOL CEnemyYellow::Draw(CDC* pDC, BOOL bPause)
{
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

//�Ƿ����ӵ�
BOOL CEnemyYellow::Fired()
{
	return FALSE;
}