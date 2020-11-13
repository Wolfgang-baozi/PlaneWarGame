#pragma once
#include "PropObject.h"
#include "resource.h"

class CDefense : public CPropObject
{
public:

	//����
	CDefense(void);

	//����
	~CDefense(void);
public:

	//��ͼ
	BOOL Draw(CDC* pDC, BOOL bPause);

	//��þ�������
	CRect GetRect()
	{
		return CRect(m_ptPos, CPoint(m_ptPos.x + DEFENSE_WIDTH, m_ptPos.y + DEFENSE_HEIGHT));
	}

	//����ͼ��
	static BOOL LoadImage();

	
	//�ƶ�
	void Move();

	//������
	BOOL PropFunction(CMyPlane* & pMe);

private:

	//Ѫ��λͼ��С 25*22
	static const int DEFENSE_WIDTH = 25;
	static const int DEFENSE_HEIGHT = 22;

	//ͼ������
	static CImageList m_Images;
};

