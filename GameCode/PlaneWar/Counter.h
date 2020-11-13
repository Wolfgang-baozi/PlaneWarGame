#pragma once

#include "stdafx.h"
#include "GameObject.h"
#include "resource.h"
#include <vector>
using namespace std;

class CCounter : public CGameObject
{
public:
	
	//����
	CCounter();
	
	//����
	~CCounter(void);

public:

	//�ӷ���
	void PlusNum(int x = 0);

	//����ܷ�
	int GetCount() const;

	//��þ�������
	CRect GetRect()
	{
		return CRect(m_ptPos, CPoint(m_ptPos.x, m_ptPos.y));
	}

	//����ͼƬ
	static BOOL LoadImage();

	//��ȡÿһλ����
	int CCounter::GetPerNumber();
	
	//��ͼ
	BOOL Draw(CDC* pDC, BOOL bPause);

private:
	
	//ͼ������
	static CImageList m_Images;

	//λͼ 150*34
	static const int NUMBER_WIDTH = 22;
	static const int NUMBER_HEIGHT = 27;
	
	//�Ʒ�
	int m_nCounter;

	//��ÿһλ����
	vector<int> m_vNum;
};

 