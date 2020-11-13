#pragma once
#include "PropObject.h"
#include "resource.h"

class CAddHP : public CPropObject
{
public:

	//����
	CAddHP(void);

	//����
	~CAddHP(void);
public:

	//��ͼ
	BOOL Draw(CDC* pDC, BOOL bPause);

	//��þ�������
	CRect GetRect()
	{
		return CRect(m_ptPos, CPoint(m_ptPos.x + BLOOD_WIDTH, m_ptPos.y + BLOOD_HEIGHT));
	}

	//�ƶ�
	void Move();

	//����ͼ��
	static BOOL LoadImage();

	//��Ѫ
	BOOL PropFunction(CMyPlane* & pMe);

private:

	//Ѫ��λͼ��С25*26
	static const int BLOOD_WIDTH = 25;
	static const int BLOOD_HEIGHT = 26;

	//ͼ������
	static CImageList m_Images;
};

