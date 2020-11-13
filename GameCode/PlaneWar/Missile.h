//����ս������
//֮��ֱ�߷���

#pragma once
#include "BombObject.h"

class CMissile : public CBombObject
{
public:
	//����
	CMissile(int x, int y);

	//����
	~CMissile(void);

	//��ͼ
	BOOL Draw(CDC* pDC, BOOL bPause);

	//�ƶ�
	BOOL Move();

	//��þ�������
	CRect GetRect()
	{
		return CRect(m_ptPos, CPoint(m_ptPos.x + BOMBMISSILE_WIDTH, m_ptPos.y + BOMBMISSILE_HEIGHT));
	}

	//����ͼ��
	static BOOL LoadImage();

private:

	//����λͼ��С 20*35
	static const int BOMBMISSILE_WIDTH = 20;
	static const int BOMBMISSILE_HEIGHT = 35;

	//ͼ������
	static	CImageList m_Images;

	//ˮƽ������
	int		m_nMaxHor;

	//��ʼλ��
	int		m_nStaX;

};