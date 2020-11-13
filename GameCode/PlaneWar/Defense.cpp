

#include "stdafx.h"
#include "Defense.h"
#include "MoveLine.h"

//ͼ������
CImageList CDefense::m_Images;

//����
CDefense::CDefense()
{
	//�߶�
	m_ptPos.y = -DEFENSE_HEIGHT;

	//�����ֱλ�� 
	m_ptPos.x = rand() % (GAME_WIDTH - DEFENSE_WIDTH);

	//��ʼˮƽ�ƶ�����
	m_nHorMotion = (rand() % 2 == 0) ? 1 : -1;

	//���� 1/2
	m_V = rand() % 2 + 1;

}

//����
CDefense::~CDefense()
{

}


//�ƶ�
void CDefense::Move()
{
	CMoveLine pMoveLine;
	pMoveLine.Move(m_ptPos, GetHorMotion(), 1, GetV());

	//���ұ߽��ж�
	if (m_ptPos.x < 0 || m_ptPos.x > GAME_WIDTH - 20)
		SetHorMotion( -GetHorMotion() );
}

//����ͼ�� �׵�
BOOL CDefense::LoadImage()
{
	return CGameObject::LoadImage(m_Images, IDB_DEFENSE, RGB(255, 255, 255), DEFENSE_WIDTH, DEFENSE_HEIGHT, 1);
}

//��ͼ
BOOL CDefense::Draw(CDC* pDC, BOOL bPause)
{
	//�����߽�
	if (m_ptPos.y > GAME_HEIGHT) return FALSE;

	if (!bPause) 
	{
		//�ƶ�
		Move();
	}

	//��ͼ
	m_Images.Draw(pDC, 0, m_ptPos, ILD_TRANSPARENT);

	return TRUE;
}

//�ٻ��Ż�
BOOL CDefense::PropFunction(CMyPlane* & pMe)
{
	return TRUE;
}