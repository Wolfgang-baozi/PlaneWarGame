
#pragma once
#include "BombObject.h"
#include "Stdafx.h"
#include "resource.h"

class CBombUpSub : public CBombObject
{
public:
	//����
	CBombUpSub(int x, int y);

	//����
	~CBombUpSub(void);

	//��ͼ
	BOOL Draw(CDC* pDC,BOOL bPause);

	//��þ�������
	CRect GetRect()
	{
		return CRect(m_ptPos, CPoint(m_ptPos.x + BOMBUPSUB_WIDTH, m_ptPos.y + BOMBUPSUB_HEIGHT));
	}

	//�ƶ�
	BOOL Move();

	//����ͼ��
	static BOOL LoadImage();

private:

	//Ѫ��λͼ��С 7*25
	static const int BOMBUPSUB_WIDTH = 10;
	static const int BOMBUPSUB_HEIGHT = 25;

	//ͼ������
	static	CImageList m_Images;

	//��ת����
	int		m_nX;

};