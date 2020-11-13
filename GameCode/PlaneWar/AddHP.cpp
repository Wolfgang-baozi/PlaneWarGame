

#include "stdafx.h"
#include "AddHP.h"
#include "MoveLine.h"

//ͼ������
CImageList CAddHP::m_Images;

//����
CAddHP::CAddHP()
{
	//�߶�
	m_ptPos.y = -BLOOD_HEIGHT;

	//�����ֱλ�� 
	m_ptPos.x = rand() % (GAME_WIDTH - BLOOD_WIDTH);

	//��ʼˮƽ�ƶ�����
	m_nHorMotion = (rand() % 2 == 0) ? 1 : -1;

	//���� 1/2
	m_V = rand() % 2 + 1;

}

//����
CAddHP::~CAddHP()
{

}

//�ƶ�
void CAddHP::Move()
{
	//�ƶ�
	CMoveLine pMoveLine;
	pMoveLine.Move(m_ptPos, GetHorMotion(), 1, GetV());

	//���ұ߽��ж�
	if (m_ptPos.x < 0 || m_ptPos.x > GAME_WIDTH - 20)
		SetHorMotion( -GetHorMotion() );

}

//����ͼ�� �׵�
BOOL CAddHP::LoadImage()
{
	return CGameObject::LoadImage(m_Images, IDB_BLOOD, RGB(255, 255, 255), BLOOD_WIDTH, BLOOD_HEIGHT, 1);
}

//��ͼ
BOOL CAddHP::Draw(CDC* pDC, BOOL bPause)
{
	//�����߽�
	if (m_ptPos.y > GAME_HEIGHT) return FALSE;

	//�ƶ�
	if (!bPause)
	{
		Move();
	}
	//��ͼ
	m_Images.Draw(pDC, 0, m_ptPos, ILD_TRANSPARENT);

	return TRUE;
}

//��Ѫ
BOOL CAddHP::PropFunction(CMyPlane* & pMe)
{
	int nHP = rand() % pMe->GetSumHP() + pMe->GetSumHP() / 3;
	pMe->PlusHP(nHP);

	return FALSE;
}