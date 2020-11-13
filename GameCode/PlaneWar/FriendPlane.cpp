#include "Stdafx.h"
#include "FriendPlane.h"
#include "PlaneObject.h"
#include "resource.h"
#include "MoveLine.h"

//MyPlane ����
CImageList CFriendPlane::m_Images;

//����
CFriendPlane::CFriendPlane(void)
{
	//��ʼ���ӵ��ȴ�ʱ��
	m_nWait = 0;

	//��ʼ���ɻ��ȼ�
	m_nLevel = 1;

	//��ʼ��ˮƽ,��ֱλ��
	m_ptPos.x = 100;
	m_ptPos.y = GAME_HEIGHT * 3 / 5;

	//���̿��Ƶ��ƶ��ٶ�
	m_V = 6;

	//�Ż�������ʱ��
	m_nLifeTime = 900;

	//�ƶ�����
	SetHorMotion(rand() % 2 == 2 ? 1 : -1);
	SetVerMotion(rand() % 2 == 2 ? 1 : -1);
}

//����
CFriendPlane::~CFriendPlane(void)
{

}

//�ƶ�
void CFriendPlane::Move()
{
	CMoveLine pMoveLine;
	pMoveLine.Move(m_ptPos, GetHorMotion(), GetVerMotion(), GetV());

	//���ұ߽�
	if (m_ptPos.x <= 10 || m_ptPos.x >= GAME_WIDTH - PLANE_WIDTH - 20)
		{
			SetHorMotion( -GetHorMotion() );
			m_V = rand() % 4 + 1;
		}
			//���±߽�
	if (m_ptPos.y <= GAME_HEIGHT * 3 / 5 || m_ptPos.y >= GAME_HEIGHT * 4 /5)
		{
			SetVerMotion( -GetVerMotion() );
			m_V = rand() % 4 + 1;
		}
}

//�Ƿ����ӵ�
BOOL CFriendPlane::IfFired()
{
	if(GetWait() == 0)
		return TRUE;
	else
		return FALSE;
}

//�������ʱ��
int CFriendPlane::GetLifeTime() const
{
	return this->m_nLifeTime;
}

//�޸�����ʱ��
int CFriendPlane::SetLifeTime(int LifeTime)
{
	return this->m_nLifeTime = LifeTime;
}

//��÷���λ��
CPoint CFriendPlane::GetBombPos(int nPos) const
{
	switch(nPos)
	{
		case 1:
			return CPoint(m_ptPos.x + 3, m_ptPos.y + 2);
			break;
		case 2:
			return CPoint(m_ptPos.x + PLANE_WIDTH / 3 - 4, m_ptPos.y + 25);
			break;
		case 3:
			return CPoint(m_ptPos.x + PLANE_WIDTH * 2 / 3 - 4, m_ptPos.y + 25);
			break;
		default:
			return CPoint(m_ptPos.x + PLANE_WIDTH - 12, m_ptPos.y + 2);
			break;
	}
}

//����ͼ��
BOOL CFriendPlane::LoadImage()
{
	//����ͼƬ���ɹ�����true
	return CGameObject::LoadImage(m_Images, IDB_FRIENDPLANE, RGB(255, 255,255), PLANE_WIDTH, PLANE_HEIGHT, 1);
}

//��ͼ
BOOL CFriendPlane::Draw(CDC* pDC, BOOL bPause)
{
	//��������֮��ļ��--����
	//3-4 -- ���� 5 -- ����
	m_nWait++;
	if(m_nWait > 3)
		m_nWait=0;
	
	//��������ʱ��
	SetLifeTime(GetLifeTime() - 1);
	if(GetLifeTime() <= 0)
	{
		SetLifeTime(0);
		return FALSE;
	}

	//�ƶ�
	if(!bPause)
	{
		//�ƶ�
		Move();

	}

	//��ͼ
	m_Images.Draw(pDC,0,m_ptPos,ILD_TRANSPARENT);

	return TRUE;
}