#pragma once
#include "GameObject.h"
#include "resource.h"

class CExplosion : public CGameObject
{
public:

	//����
	CExplosion(int x, int y);

	//����
	~CExplosion(void);

	//��ͼ
	BOOL Draw(CDC* pDC, BOOL bPause);

	//����ͼƬ
	static BOOL LoadImage();

	//��þ�������
	CRect GetRect()
	{
		return CRect(m_ptPos, CPoint(m_ptPos.x + EXPLOSION_HEIGHT, m_ptPos.y + EXPLOSION_HEIGHT));
	}

private:

	//ը����ͼƬ�б�
	static CImageList m_Images;
	
	//ͼ�������Ĳ�������
	int m_nProcess;

public:
	
	//��ըλͼ
	static const int  EXPLOSION_HEIGHT = 66;

};