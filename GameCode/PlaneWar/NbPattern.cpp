//CNbPattern.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "NbPattern.h"
#include "resource.h"
#include <mmsystem.h>

//ͼ������
CImageList CNbPattern::m_Image[3];

//����
CNbPattern::CNbPattern()
{
	//��λ��
	m_ptPos.x = 3;
	m_ptPos.y = GAME_HEIGHT - NB_HEIGHT*2;
}

//����
CNbPattern::~CNbPattern()
{

}

//����ͼ��
BOOL CNbPattern::LoadImage()
{
	return CGameObject::LoadImage( m_Image[on], IDB_NBON, RGB(0, 0, 0), NB_WIDTH, NB_HEIGHT, 0) 
		&& CGameObject::LoadImage( m_Image[off], IDB_NBOFF, RGB(0, 0, 0), NB_WIDTH, NB_HEIGHT, 0);
}

//��ͼ
BOOL CNbPattern::Draw(CDC *pDC, BOOL bPattern)
{
	//�޵�ʱ
	if (bPattern) {
		m_Image[on].Draw(pDC, 0, m_ptPos, ILD_TRANSPARENT);
	}
	//��Ϸ����ʱ
	else {
		m_Image[off].Draw(pDC, 0, m_ptPos, ILD_TRANSPARENT);
	}
	return TRUE;
}

//��þ���
CRect CNbPattern::GetRect()
{
	return CRect(m_ptPos, CPoint(m_ptPos.x + NB_WIDTH, m_ptPos.y + NB_HEIGHT));
}