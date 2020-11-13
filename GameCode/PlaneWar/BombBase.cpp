
#include "Stdafx.h"
#include "BombBase.h"
#include "resource.h"
#include "MoveLine.h"

CImageList CBombBase::m_Images;

//����
CBombBase::CBombBase(int x, int y)
{
	//�ӵ�ˮƽ���з��� -> ��ֹ
	SetHorMotion(0);

	//�ӵ���ֱ���з��� -> ��
	SetVerMotion(-1);

	//��ʼλ��
	m_ptPos.x = x;
	m_ptPos.y = y;

	//�ӵ�����
	m_nV = 20;

	//�ӵ��˺�
	m_nHarm = 100;
}

//����
CBombBase::~CBombBase(void)
{

}

//�ƶ�
BOOL CBombBase:: Move()
{
	CMoveLine pMoveLine;
	pMoveLine.Move(m_ptPos, GetHorMotion(), GetVerMotion(), GetV());

	//�����߽�
	if(m_ptPos.y < -BOMBBASE_HEIGHT && m_ptPos.x < -BOMBBASE_WIDTH && m_ptPos.x > GAME_WIDTH - BOMBBASE_WIDTH)
		return FALSE;

	return TRUE;
}

//����ͼƬ
BOOL CBombBase::LoadImage()
{
	return CGameObject::LoadImage(m_Images, IDB_BOMBBASE, RGB(255, 255, 255), BOMBBASE_WIDTH, BOMBBASE_HEIGHT, 1);
}

//��ͼ
BOOL CBombBase::Draw(CDC* pDC, BOOL bPause)
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