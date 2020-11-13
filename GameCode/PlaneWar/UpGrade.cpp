

#include "stdafx.h"
#include "UpGrade.h"
#include "MoveLine.h"

//ͼ������
CImageList CUpGrade::m_Images;

//����
CUpGrade::CUpGrade()
{
	//�߶�
	m_ptPos.y = 0;

	//�����ֱλ�� 
	m_ptPos.x = rand() % (GAME_WIDTH - UPGRADE_WIDTH);

	//��ʼˮƽ�ƶ�����
	SetHorMotion( (rand() % 2 == 0) ? 1 : -1);

	//���� 1/2
	m_V = rand() % 2 + 1;

}

//����
CUpGrade::~CUpGrade()
{

}

//�ƶ�
void CUpGrade::Move()
{
	
	CMoveLine pMoveLine;
	pMoveLine.Move(m_ptPos, GetHorMotion(), 1, GetV());

	//���ұ߽��ж�
	if (m_ptPos.x < 0 || m_ptPos.x > GAME_WIDTH - 20)
		SetHorMotion( -GetHorMotion() );
}

//����ͼ�� �׵�
BOOL CUpGrade::LoadImage()
{
	return CGameObject::LoadImage(m_Images, IDB_UPGRADE, RGB(255, 255, 255), UPGRADE_WIDTH, UPGRADE_HEIGHT, 1);
}

//��ͼ
BOOL CUpGrade::Draw(CDC* pDC, BOOL bPause)
{
	//�����߽�
	if (m_ptPos.y > GAME_HEIGHT) return FALSE;

	if (!bPause) {
		//�ƶ�
		Move();
	}

	//��ͼ
	m_Images.Draw(pDC, 0, m_ptPos, ILD_TRANSPARENT);

	return TRUE;
}

//ս������
BOOL CUpGrade::PropFunction(CMyPlane* & pMe)
{
	pMe->AddGrade(1);

	return FALSE;
}