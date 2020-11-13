//ʼ��׷�ٵĵ���
#pragma once
#include "BombObject.h"

class CBombPurple : public CBombObject
{
public:
	//����
	CBombPurple(int x, int y);

	//����
	~CBombPurple(void);

	//��ͼ
	BOOL Draw(CDC* pDC,BOOL bPause);

	//��þ�������
	CRect GetRect()
	{
		return CRect(m_ptPos, CPoint(m_ptPos.x + BOMBPURPLE_WIDTH, m_ptPos.y + BOMBPURPLE_HEIGHT));
	}

	//�ƶ�
	BOOL Move();

	//����ͼ��
	static BOOL LoadImage();

private:

	//��ɫȦȦ λͼ��С 25*25
	static const int BOMBPURPLE_WIDTH = 25;
	static const int BOMBPURPLE_HEIGHT = 25;

	//ͼ������
	static	CImageList m_Images;

	//ͼ������
	int m_nImgIndex;
};