//CPause.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Pause.h"
#include "resource.h"
#include <mmsystem.h>

//ͼ������
CImageList CPause::m_Image[3];

//����
CPause::CPause()
{
	//��ͣ, ������λ��
	m_ptPos.x = 6;
	m_ptPos.y = GAME_HEIGHT - BUTTON_HEIGHT - BACK_HEIGHT - 40;

	//m_ptPos.x = GAME_WIDTH / 2;
	//m_ptPos.y = GAME_HEIGHT / 2;

	//���ؼ�
	m_ptBack.x = 6;
	m_ptBack.y = GAME_HEIGHT - BUTTON_HEIGHT - BACK_HEIGHT - 70;
}

//����
CPause::~CPause()
{

}

//����ͼ��
BOOL CPause::LoadImage()
{
	return CGameObject::LoadImage( m_Image[pause], IDB_PAUSE, RGB(0, 0, 0), BUTTON_WIDTH, BUTTON_HEIGHT, 0) 
		&& CGameObject::LoadImage( m_Image[continuebutton], IDB_CONTINUE, RGB(0, 0, 0), BUTTON_WIDTH, BUTTON_HEIGHT, 0)
		&& CGameObject::LoadImage( m_Image[back], IDB_BACKBUTTON, RGB(255, 255, 255), BACK_WIDTH, BACK_HEIGHT, 0);
}

//��ͼ
BOOL CPause::Draw(CDC *pDC, BOOL bPause)
{
	//������ͣʱ
	if (bPause) 
	{
		m_Image[back].Draw(pDC, 0, m_ptBack, ILD_TRANSPARENT);
		m_Image[pause].Draw(pDC, 0, m_ptPos, ILD_TRANSPARENT);
	}
	//��Ϸ����ʱ
	else 
	{
		m_Image[continuebutton].Draw(pDC, 0, m_ptPos, ILD_TRANSPARENT);
	}
	return TRUE;
}

//��þ��� -> ֹͣ
CRect CPause::GetRectStop()
{
	return CRect(m_ptPos, CPoint(m_ptPos.x + BUTTON_WIDTH, m_ptPos.y + BUTTON_HEIGHT));
}

//��þ��� -> ����
CRect CPause::GetRectGo()
{
	return CRect(m_ptPos, CPoint(m_ptPos.x + BUTTON_WIDTH, m_ptPos.y + BUTTON_HEIGHT));
}

//��þ��� -> ����
CRect CPause::GetRect()
{
	return CRect(m_ptBack, CPoint(m_ptBack.x + BACK_WIDTH, m_ptBack.y + BACK_HEIGHT));
}

//�޸���ͣ״̬
void CPause::PauseButton(bool & bPause)
{
	bPause = !bPause;
}