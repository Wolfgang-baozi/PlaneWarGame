#pragma once
#include "PropObject.h"
#include "resource.h"

class CUpGrade : public CPropObject
{
public:

	//����
	CUpGrade(void);

	//����
	~CUpGrade(void);
public:

	//��ͼ
	BOOL Draw(CDC* pDC, BOOL bPause);

	//��þ�������
	CRect GetRect()
	{
		return CRect(m_ptPos, CPoint(m_ptPos.x + UPGRADE_WIDTH, m_ptPos.y + UPGRADE_HEIGHT));
	}

	//�ƶ�
	void Move();

	//����ͼ��
	static BOOL LoadImage();

	//ս������
	BOOL PropFunction(CMyPlane* & pMe);

private:

	//���� λͼ��С 25*23
	static const int UPGRADE_WIDTH = 25;
	static const int UPGRADE_HEIGHT = 23;

	//ͼ������
	static CImageList m_Images;
};

