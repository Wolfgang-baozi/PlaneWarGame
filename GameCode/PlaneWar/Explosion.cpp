#include "stdafx.h"
#include "Explosion.h"

//ͼ������
CImageList CExplosion::m_Images;

//����
CExplosion::CExplosion(int x, int y) :CGameObject(x, y), m_nProcess(0)
{
	//����
	m_nProcess = 0;
}

//����
CExplosion::~CExplosion()
{

}

//����ͼ��
BOOL CExplosion::LoadImage()
{
	return CGameObject::LoadImage(m_Images, IDB_EXPLOSION, RGB(0, 0, 0), 66, 66, 8);
}

//��ͼ
BOOL CExplosion::Draw(CDC* pDC, BOOL bPause)
{
	//��ը��
	if (m_nProcess == 9)
	{
		//����
		m_nProcess = 0;
		return FALSE;
	}

	//����ͼ��ԭλ��
	m_Images.Draw(pDC, m_nProcess, m_ptPos, ILD_TRANSPARENT);
	
	//����+1
	if (!bPause)
		m_nProcess++;
	
	return TRUE;
}


