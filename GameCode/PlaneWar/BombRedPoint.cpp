
#include "Stdafx.h"
#include "BombRedPoint.h"
#include "MoveLine.h"

CImageList CBombRedPoint::m_Images;

//����
CBombRedPoint::CBombRedPoint(int x, int y)
{
	//�ӵ�ˮƽ���з��� -> ��ֹ
	SetHorMotion(0);

	//�ӵ���ֱ���з��� -> ��
	SetVerMotion(1);

	//��ʼλ��
	m_ptPos.x = x;
	m_ptPos.y = y;

	//�ӵ�����
	m_nV = 8;

	//�ӵ��˺�
	m_nHarm = 3;
}

//����
CBombRedPoint::~CBombRedPoint(void)
{

}

//�ƶ�
BOOL CBombRedPoint::Move()
{
	CMoveLine pMoveLine;
	pMoveLine.Move(m_ptPos, GetHorMotion(), GetVerMotion(), GetV());

	//�����߽�
	if(m_ptPos.y < -BOMBREDPOINT_HEIGHT || m_ptPos.y > GAME_HEIGHT + BOMBREDPOINT_HEIGHT)
		return FALSE;

	return TRUE;
}

//����ͼƬ
BOOL CBombRedPoint::LoadImage()
{
	return CGameObject::LoadImage(m_Images, IDB_BOMBREDPOINT, RGB(0,0,0), BOMBREDPOINT_WIDTH, BOMBREDPOINT_HEIGHT, 0);
}

//��ͼ
BOOL CBombRedPoint::Draw(CDC* pDC, BOOL bPause)
{
	//�ƶ�
	if(!bPause)
	{
		if( !Move() )
			return FALSE;
	}

	//��ͼ
	m_Images.Draw(pDC, 0, m_ptPos, ILD_TRANSPARENT);

	return TRUE;
}