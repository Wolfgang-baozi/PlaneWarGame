
#include "stdafx.h"
#include "EnemyRed.h"
#include "MoveLine.h"

CImageList CEnemyRed::m_Images;

CEnemyRed::CEnemyRed()
{
	//���ȷ��ͼ������
	m_nImgIndex = rand() % 2;
	
	//ȷ��λ��
	m_ptPos.x =  rand() % ( GAME_WIDTH -ENEMYRED_WIDTH );
	m_ptPos.y = 0;

	//����ͼ������ȷ������
	SetHorMotion(0);
	SetVerMotion(1);
	
	//���ȷ���ٶ�
	m_V = 6;

	//��ȴʱ��
	m_nWait = 0;

	//Ѫ��
	InitHP(20);

	//�˺�ֵ
	m_nHarm = 4;
}

//����
CEnemyRed::~CEnemyRed()
{

}

//�ƶ�
BOOL CEnemyRed::Move()
{
	CMoveLine pMoveLine;
	pMoveLine.Move(m_ptPos, GetHorMotion(), GetVerMotion(), GetV());

	
	//�߽��ж�
	if (m_ptPos.y > GAME_HEIGHT || m_ptPos.y < 0)
		return FALSE;
		
	return TRUE;
}

//��þ�������
CRect CEnemyRed::GetRect()
{
	return CRect(m_ptPos, CPoint(m_ptPos.x + ENEMYRED_WIDTH, m_ptPos.y + ENEMYRED_HEIGHT));
}

//����ͼƬ
BOOL CEnemyRed::LoadImage()
{
	return CGameObject::LoadImage(m_Images, IDB_ENEMYRED, RGB(255, 255, 255), ENEMYRED_WIDTH, ENEMYRED_HEIGHT, 0);
}

//��ͼ
BOOL CEnemyRed::Draw(CDC* pDC, BOOL bPause)
{
	//ֻ��һ������
	m_nWait++;
	if (m_nWait > 30)
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

//�Ƿ񿪻�
BOOL CEnemyRed::Fired()
{
	if (m_nWait == 0)
		return TRUE;
	else
		return FALSE;
}

