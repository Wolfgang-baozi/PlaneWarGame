
#pragma once
#include "BombObject.h"
#include "Stdafx.h"
#include "resource.h"

class CBombUpMain : public CBombObject
{
public:
	//����
	CBombUpMain(int x, int y);

	//����
	~CBombUpMain(void);

	//��ͼ
	BOOL Draw(CDC* pDC,BOOL bPause);

	//��þ�������
	CRect GetRect()
	{
		return CRect(m_ptPos, CPoint(m_ptPos.x + BOMBUPMAIN_WIDTH, m_ptPos.y + BOMBUPMAIN_HEIGHT));
	}

	//����ͼ��
	static BOOL LoadImage();

	
	//�ƶ�
	BOOL Move();


private:

	//Ѫ��λͼ��С 10*25
	static const int BOMBUPMAIN_WIDTH = 10;
	static const int BOMBUPMAIN_HEIGHT = 25;

	//ͼ������
	static	CImageList m_Images;
};