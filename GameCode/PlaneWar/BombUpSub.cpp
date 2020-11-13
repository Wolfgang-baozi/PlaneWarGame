
#include "Stdafx.h"
#include "BombUpSub.h"
#include "resource.h"
#include "MoveLine.h"

CImageList CBombUpSub::m_Images;

//����
CBombUpSub::CBombUpSub(int x, int y)
{
	//�ӵ�ˮƽ���з��� -> ��ֹ
	SetHorMotion(rand() % 2 == 0 ? 1 : -1);

	//�ӵ���ֱ���з��� -> ��
	SetVerMotion(-1);

	//��ʼλ��
	m_ptPos.x = m_nX = x;
	m_ptPos.y = y;

	//�ӵ�����
	m_nV = 20;

	//�ӵ��˺�
	m_nHarm = 80;
}

//����
CBombUpSub::~CBombUpSub(void)
{

}

//�ƶ�
BOOL CBombUpSub::Move()
{

	CMoveLine pMoveLine;
	pMoveLine.Move(m_ptPos, GetHorMotion(), GetVerMotion(), GetV());


	if (m_ptPos.y < -BOMBUPSUB_HEIGHT || m_ptPos.y > GAME_HEIGHT + BOMBUPSUB_HEIGHT)
		return FALSE;

	if (m_ptPos.x < 0 || m_ptPos.x > GAME_WIDTH - BOMBUPSUB_WIDTH)
		SetHorMotion(-GetHorMotion());

	return TRUE;
}

//����ͼƬ
BOOL CBombUpSub::LoadImage()
{
	return CGameObject::LoadImage(m_Images, IDB_BOMBUP_SUB, RGB(255, 255, 255), BOMBUPSUB_WIDTH, BOMBUPSUB_HEIGHT, 1);
}

//��ͼ
BOOL CBombUpSub::Draw(CDC* pDC, BOOL bPause)
{
	//�ƶ�
	if(!Move())
		return FALSE;

	//��ͼ
	m_Images.Draw(pDC, 0, m_ptPos, ILD_TRANSPARENT);

	return TRUE;
}