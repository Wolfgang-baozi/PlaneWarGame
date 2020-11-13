
#pragma once
#include "BombObject.h"
#include "Stdafx.h"
#include "resource.h"

class CBombBase : public CBombObject
{
public:
	//����
	CBombBase(int x, int y);

	//����
	~CBombBase(void);

	//����С�ɻ�
	void AddBomb(CObList &objList,  const CPoint &pos);

	//��ͼ
	BOOL Draw(CDC* pDC,BOOL bPause);

	//�ƶ�
	BOOL Move();

	//��þ�������
	CRect GetRect()
	{
		return CRect(m_ptPos, CPoint(m_ptPos.x + BOMBBASE_WIDTH, m_ptPos.y + BOMBBASE_HEIGHT));
	}

	//����ͼ��
	static BOOL LoadImage();

private:

	//Ѫ��λͼ��С 7*25
	static const int BOMBBASE_WIDTH = 7;
	static const int BOMBBASE_HEIGHT = 25;

	//ͼ������
	static	CImageList m_Images;
};