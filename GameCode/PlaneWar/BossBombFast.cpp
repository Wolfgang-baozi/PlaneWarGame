
#include "Stdafx.h"
#include "BossBombFast.h"
#include "resource.h"
#include "MoveLine.h"
#include <mmstream.h>

CImageList CBossBombFast::m_Images[3];

//����
CBossBombFast::CBossBombFast(int x, int y) : m_nWait(0)
{
	//�ӵ�ˮƽ���з��� -> ��ֹ
	SetHorMotion(0);

	//�ӵ���ֱ���з��� -> ��
	SetVerMotion(1);

	//��ʼλ��
	m_ptPos.x = x;
	m_ptPos.y = y;

	//�ӵ�����
	m_nV = 40;

	//�ӵ��˺�
	m_nHarm = 10;

	//�ӵ�����
	m_nKindBomb = rand() % 2;
}

//����
CBossBombFast::~CBossBombFast(void)
{

}


//�ƶ�
BOOL CBossBombFast::Move()
{
	if(IfMove())
	{
		CMoveLine pMoveLine;
		pMoveLine.Move(m_ptPos, GetHorMotion(), GetVerMotion(), GetV());
		
		//�����߽�
		if(m_ptPos.y < -BOSSBOMBFAST_HEIGHT || m_ptPos.y > GAME_HEIGHT + BOSSBOMBFAST_HEIGHT)
			return FALSE;
	}

	return TRUE;
}

//����Ѿ�ͣ��ʱ��
int CBossBombFast::GetWait() const
{
	return m_nWait;
}

//����ͣ��ʱ��
void CBossBombFast::AddWait()
{
	m_nWait = m_nWait + 1;
}

//�Ƿ��ƶ�
BOOL CBossBombFast::IfMove()
{
	return GetWait() > m_nNeedWait;
}

//��ȡ�ӵ�����
int CBossBombFast::GetKingBomb() const
{
	return m_nKindBomb;
}

//�޸��ӵ�����
void CBossBombFast::SetKindBomb(int nLevel)
{
	m_nKindBomb = nLevel;
}

//����ͼƬ
BOOL CBossBombFast::LoadImage()
{
	//IDB_BOSSBOMB_PURPLE0
	//IDB_BOSSBOMB_YELLOW
	return CGameObject::LoadImage(m_Images[0], IDB_BOSSBOMB_PURPLE0, RGB(255, 255, 255), BOSSBOMBFAST_WIDTH, BOSSBOMBFAST_HEIGHT, 0)
		&& CGameObject::LoadImage(m_Images[1], IDB_BOSSBOMB_YELLOW, RGB(255, 255, 255), BOSSBOMBFAST_WIDTH, BOSSBOMBFAST_HEIGHT, 0);
}

//��ͼ
BOOL CBossBombFast::Draw(CDC* pDC, BOOL bPause)
{
	//ͣ��
	AddWait();
	
	//�ƶ�
	if(!bPause)
	{
		if(!Move())
			return FALSE;
	}

	//��ͼ
	int nKindBomb = this->GetKingBomb();
	m_Images[nKindBomb].Draw(pDC, 0, m_ptPos, ILD_TRANSPARENT);

	return TRUE;
}