#include "Stdafx.h"
#include "MyPlane.h"
#include "PlaneObject.h"
#include "resource.h"
#include <mmsystem.h>

//MyPlane ����
CImageList CMyPlane::m_Images[2];

//����
CMyPlane::CMyPlane(void)
{
	//��ʼ���ӵ��ȴ�ʱ��
	m_nWait = 0;

	//��ʼ���ɻ��ȼ�
	m_nGrade = 1;

	//��ʼ��ˮƽ,��ֱλ��
	m_ptPos.x = 200;
	m_ptPos.y = 600;

	//���̿��Ƶ��ƶ��ٶ�
	m_V = 7;

	//Ѫ��λ��
	m_ptBlood.x = 10;
	m_ptBlood.y = 10;

	//Ѫ��
	m_nNowHP = m_nSumHP = 100;

}

//����
CMyPlane::~CMyPlane(void)
{

}

//�ƶ�
void CMyPlane::Move()
{
	m_ptPos.x = m_ptPos.x + GetHorMotion() * GetV();
	m_ptPos.y = m_ptPos.y + GetVerMotion() * GetV();
	SetHorMotion(0);
	SetVerMotion(0);
}

//��þ���
CRect CMyPlane::GetRect()
{
	//if(GetGrade() == 3)
		return CRect( m_ptPos, CPoint(m_ptPos.x+PLANE_WIDTH, m_ptPos.y+PLANE_HEIGHT) );
	//else
		//return CRect( CPoint(m_ptPos.x + PLANE_WIDTH / 3, m_ptPos.y), CPoint(m_ptPos.x + PLANE_WIDTH * 2 / 3, m_ptPos.y + PLANE_HEIGHT));
}

//��÷ɻ��ȼ�
int CMyPlane::GetGrade()const
{
	return this->m_nGrade;
}

//�޸ĵȼ�
void CMyPlane::AddGrade(int Grade)
{
	this->m_nGrade = this->m_nGrade + Grade;
	if(this->m_nGrade > 3)
		this->m_nGrade = 3;
}

//�Ƿ����ӵ�
BOOL CMyPlane::IfFired()
{
	if(GetWait() == 0)
		return TRUE;
	else
		return FALSE;
}

//�л���Ѫ
void CMyPlane::MinusHp(int nHP)
{
	m_nNowHP -= nHP;
	if(m_nNowHP < 0)
		m_nNowHP = 0;
}

//ս����Ѫ,��֤����Ѫ��С�ڵ������ֵ
void CMyPlane::PlusHP(int nHP)
{
	m_nNowHP = m_nNowHP + nHP;
	if(m_nNowHP > m_nSumHP)
		m_nNowHP = m_nSumHP;
}

//��÷���λ��
CPoint CMyPlane::GetBombPos(int nPos) const
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
BOOL CMyPlane::LoadImage()
{
	return CGameObject::LoadImage(m_Images[1], IDB_MYPLANE1, RGB(0, 0, 0), PLANE_WIDTH, PLANE_HEIGHT, 0);
}

//��ͼ
BOOL CMyPlane::Draw(CDC* pDC,BOOL bPause)
{
	//��������֮��ļ��--����
	//3-4 -- ���� 5 -- ����
	m_nWait++;
	if(m_nWait > 3)
		m_nWait=0;

	//�ƶ�
	if(!bPause)
	{
		Move();
	}

	//��ֹ�ɻ��ɳ��߽�
	//ˮƽ�ұ߽�
	if(m_ptPos.x>=GAME_WIDTH - PLANE_WIDTH - 20)
		m_ptPos.x = GAME_WIDTH - PLANE_WIDTH - 20;

	//ˮƽ��߽�
	if(m_ptPos.x <= 0)
		m_ptPos.x = 0;

	//��ֱ�ϱ߽�
	if(m_ptPos.y <= 0)
		m_ptPos.y = 0;

	//��ֱ�±߽�
	if(m_ptPos.y >= GAME_HEIGHT - PLANE_HEIGHT)
		m_ptPos.y = GAME_HEIGHT - PLANE_HEIGHT;

	//��ͼ
	//�ɻ�
	int iIndex = 1;
	m_Images[iIndex].Draw(pDC,0,m_ptPos,ILD_TRANSPARENT);
	
	//����Ѫ��
	CBrush *m_pBrush1;
	CBrush *m_pBrush2;
	m_pBrush1 = new CBrush();
	m_pBrush1->CreateSolidBrush(RGB(243, 144, 9));
	m_pBrush2 = new CBrush();
	m_pBrush2->CreateSolidBrush(RGB(248, 155, 80));
	pDC->RoundRect(CRect(m_ptBlood.x, m_ptBlood.y, m_ptBlood.x + 200, m_ptBlood.y + 12) ,CPoint(12, 12));
	if(GetNowHP() > 0)
		pDC->FillRect(CRect(m_ptBlood.x + 5, m_ptBlood.y + 3, m_ptBlood.x + 195 * (GetNowHP() * 1.0 / GetSumHP()), m_ptBlood.y + 10), m_pBrush2);
	
	delete m_pBrush1;
	delete m_pBrush2;

	return TRUE;
}