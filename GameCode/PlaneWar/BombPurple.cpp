//CBombPurple : ʵ���ļ�
#pragma once

#include "Stdafx.h"
#include "BombPurple.h"
#include "resource.h"
#include "MoveLine.h"

CImageList CBombPurple::m_Images;

//����
CBombPurple::CBombPurple(int x, int y)
{

	//���ȷ��ͼ������
	m_nImgIndex = rand() % 2 == 0 ? 1 : -1;

	//�ӵ�ˮƽ���з��� -> ��ֹ
	SetHorMotion(m_nImgIndex);

	//�ӵ���ֱ���з��� -> ��
	SetVerMotion(1);

	//����
	m_nV = 8;

	//��ʼλ��
	m_ptPos.x = x;
	m_ptPos.y = y;

	//�ӵ��˺�
	m_nHarm = 4;
}

//����
CBombPurple::~CBombPurple(void)
{

}

//�ƶ�
BOOL CBombPurple::Move()
{
	CMoveLine pMoveLine;
	pMoveLine.Move(m_ptPos, GetHorMotion(), GetVerMotion(), GetV());

	//�����߽�
	if (m_ptPos.y < -BOMBPURPLE_HEIGHT || m_ptPos.y > GAME_HEIGHT + BOMBPURPLE_HEIGHT)
		return FALSE;
	if (m_ptPos.x < 0 || m_ptPos.x > GAME_WIDTH - BOMBPURPLE_WIDTH)
		SetHorMotion(-GetHorMotion());

	return TRUE;
}

//����ͼƬ
BOOL CBombPurple::LoadImage()
{
	return CGameObject::LoadImage(m_Images, IDB_BOMBPURPLE, RGB(255,255,255), BOMBPURPLE_WIDTH, BOMBPURPLE_HEIGHT, 1);
}

//��ͼ
BOOL CBombPurple::Draw(CDC* pDC, BOOL bPause)
{
	//�ƶ�
	if (!bPause)
	{
		if( !Move() )
			return FALSE;
	}

	//��ͼ
	m_Images.Draw(pDC, 0, m_ptPos, ILD_TRANSPARENT);

	return TRUE;
}