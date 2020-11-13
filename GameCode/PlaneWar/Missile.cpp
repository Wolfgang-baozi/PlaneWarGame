//CMissile : ʵ���ļ�
//

#include "Stdafx.h"
#include "Missile.h"
#include "resource.h"
#include "MoveLine.h"
#include <cmath>

CImageList CMissile::m_Images;

//����
CMissile::CMissile(int x, int y)
{
	int nHor = rand() % 2 == 0 ? 1 : -1;
	//�ӵ�ˮƽ���з��� -> ��ֹ
	SetHorMotion(nHor);

	//�ӵ���ֱ���з��� -> ��
	SetVerMotion(1);

	//��ʼλ��
	m_ptPos.x = m_nStaX = x;
	m_ptPos.y = y;
	
	//�ӵ��˺�
	m_nHarm = 10;

	//����
	m_nV = 8;

	//
	m_nMaxHor = rand() % 40 + 30;
}    

//����
CMissile::~CMissile(void)
{

}

//�ƶ�
BOOL CMissile::Move()
{
	CMoveLine pMoveLine;
	pMoveLine.Move(m_ptPos, GetHorMotion(), GetVerMotion(), GetV());

	//�����߽�
	if(m_ptPos.y < -BOMBMISSILE_HEIGHT || m_ptPos.y > GAME_HEIGHT + BOMBMISSILE_HEIGHT )
		return FALSE;
	if (m_ptPos.x < m_nStaX - m_nMaxHor || m_ptPos.x < 0 || m_ptPos.x > GAME_HEIGHT - BOMBMISSILE_HEIGHT || m_ptPos.x > m_nStaX + m_nMaxHor)
		SetHorMotion(-GetHorMotion());
	return TRUE;
}


//����ͼƬ
BOOL CMissile::LoadImage()
{
	return CGameObject::LoadImage(m_Images, IDB_MISSILE, RGB(255, 255, 255), BOMBMISSILE_WIDTH, BOMBMISSILE_HEIGHT, 1);
}

//��ͼ
BOOL CMissile::Draw(CDC* pDC, BOOL bPause)
{
	if(!bPause)
	{
		//�ƶ�
		if(!Move())
			return FALSE;
	}

	//��ͼ
	m_Images.Draw(pDC, 0, m_ptPos, ILD_TRANSPARENT);

	return TRUE;
}