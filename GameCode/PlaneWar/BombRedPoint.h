//ֱ��

#pragma once
#include "BombObject.h"
#include "Stdafx.h"
#include "resource.h"

class CBombRedPoint : public CBombObject
{
public:
	//����
	CBombRedPoint(int x, int y);

	//����
	~CBombRedPoint(void);

	//��ͼ
	BOOL Draw(CDC* pDC,BOOL bPause);

	//�ƶ�
	BOOL Move();

	//��þ�������
	CRect GetRect()
	{
		return CRect(m_ptPos, CPoint(m_ptPos.x + BOMBREDPOINT_WIDTH, m_ptPos.y + BOMBREDPOINT_HEIGHT));
	}

	//����ͼ��
	static BOOL LoadImage();

private:

	//С��� λͼ��С 25*25
	static const int BOMBREDPOINT_WIDTH = 25;
	static const int BOMBREDPOINT_HEIGHT = 25;

	//ͼ������
	static CImageList m_Images;
};