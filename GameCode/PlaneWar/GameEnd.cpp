// CGameEnd.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "GameEnd.h"
#include "resource.h"

//ͼ������
CImageList CGameEnd::m_Image;

//����
CGameEnd::CGameEnd()
{
	//ͨ��start��λ�� ȷ��������ťλ��
	m_ptPos.x = 150;
	m_ptPos.y = 200;

}

//����
CGameEnd::~CGameEnd()
{

}

//��þ�������
CRect CGameEnd::GetRect()
{
	return CRect(m_ptPos, CPoint(m_ptPos.x + END_WIDTH, m_ptPos.y + END_HEIGHT));
}

//����ͼƬ
BOOL CGameEnd::LoadImage()
{
	return CGameObject::LoadImage(m_Image, IDB_END, RGB(40, 40, 40), END_WIDTH, END_HEIGHT, 0);
}

BOOL CGameEnd::Draw(CDC* pDC, BOOL bHelp)
{
	//END
	m_Image.Draw(pDC, 0, m_ptPos, ILD_TRANSPARENT);

	return TRUE;
}