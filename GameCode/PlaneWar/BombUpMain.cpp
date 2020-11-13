
#include "Stdafx.h"
#include "BombUpMain.h"
#include "resource.h"
#include "MoveLine.h"

CImageList CBombUpMain::m_Images;

//����
CBombUpMain::CBombUpMain(int x, int y)
{
	//�ӵ�ˮƽ���з��� -> ��ֹ
	SetHorMotion(0);

	//�ӵ���ֱ���з��� -> ��
	SetVerMotion(-1);

	//��ʼλ��
	m_ptPos.x = x;
	m_ptPos.y = y;

	//�ӵ�����
	m_nV = 30;

	//�ӵ��˺�
	m_nHarm = 80;
}

//����
CBombUpMain::~CBombUpMain(void)
{

}


//�ƶ�
BOOL CBombUpMain::Move()
{
	CMoveLine pMoveLine;
	pMoveLine.Move(m_ptPos, GetHorMotion(), GetVerMotion(), GetV());

	//�����߽�
	if(m_ptPos.y < -BOMBUPMAIN_HEIGHT && m_ptPos.x < -BOMBUPMAIN_WIDTH && m_ptPos.x > GAME_WIDTH - BOMBUPMAIN_WIDTH)
		return FALSE;

	return TRUE;
}


//����ͼƬ
BOOL CBombUpMain::LoadImage()
{
	return CGameObject::LoadImage(m_Images, IDB_BOMBUP_MAIN, RGB(255, 255, 255), BOMBUPMAIN_WIDTH, BOMBUPMAIN_HEIGHT, 1);
}

//��ͼ
BOOL CBombUpMain::Draw(CDC* pDC, BOOL bPause)
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