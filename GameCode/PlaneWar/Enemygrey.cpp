

#include "stdafx.h"
#include "EnemyGrey.h"
#include "MoveLine.h"

CImageList CEnemyGrey::m_Images;

CEnemyGrey::CEnemyGrey()
{
	//�˺�ֵ
	m_nHarm = 10;

	//���ȷ��Xλ��
	m_ptPos.x = rand() % (GAME_WIDTH - ENEMYGREY_HEIGHT * 2);
	m_ptPos.y = 0;

	//���ȷ��ͼ������
	m_nImgIndex = rand() % 2;

	//����ͼ������ȷ������ ��ʼ -> ���·�
	SetVerMotion(1);
	SetHorMotion(0);

	//�����ͼ��������ż�� -> ���Ϸ�
	if (m_nImgIndex % 2 != 0)
	{
		SetVerMotion(-1);
		m_ptPos.y = GAME_HEIGHT + ENEMYGREY_HEIGHT;
	}

	//����ٶ�
	m_V = rand() % 12 + 2;

	//��ȴʱ��
	m_nWait = 0;

	//Ѫ��
	InitHP(10);

	//�л��˺�
	m_nHarm = 2;
}

//����
CEnemyGrey::~CEnemyGrey()
{

}

//�ƶ�
BOOL  CEnemyGrey::Move()
{
	CMoveLine pMoveLine;
	pMoveLine.Move(m_ptPos, GetHorMotion(), GetVerMotion(), GetV());

	//�߽��ж�
	if (m_ptPos.y > GAME_HEIGHT && m_ptPos.y < 0)
		return FALSE;

	return TRUE;
}

//��þ�������
CRect CEnemyGrey::GetRect()
{
	return CRect(m_ptPos, CPoint(m_ptPos.x + ENEMYGREY_HEIGHT, m_ptPos.y + ENEMYGREY_HEIGHT));
}

//����ͼ��
BOOL CEnemyGrey::LoadImage()
{
	return CGameObject::LoadImage(m_Images, IDB_ENEMYGREY, RGB(0, 0, 0), ENEMYGREY_HEIGHT, ENEMYGREY_HEIGHT, 0);
}

//��ͼ
BOOL CEnemyGrey::Draw(CDC* pDC, BOOL bPause)
{
	//�����ӳ�
	m_nWait++;
	if (m_nWait > 40)
		m_nWait = 0;

	//�ƶ�
	if (!bPause)
	{
		if( !Move() )
			return FALSE;
	}

	//��ͼ
	m_Images.Draw(pDC, m_nImgIndex, m_ptPos, ILD_TRANSPARENT);

	return TRUE;
}

//�Ƿ񿪻�
BOOL CEnemyGrey::Fired()
{
	if (m_nWait == 0)
		return TRUE;
	else
		return FALSE;
}
