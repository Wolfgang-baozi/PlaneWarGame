#pragma once

#include "stdafx.h"
#include "PlaneObject.h"

class CMyPlane : public CPlaneObject
{
public:

	//����
	CMyPlane();

	//����
	~CMyPlane(void);

	//��÷ɻ��ȼ�
	int GetGrade() const;

	//�޸ĵȼ�
	void AddGrade(int Grade);

	//��÷���λ��
	CPoint GetBombPos(int nPos) const;

	//��ͼ
	BOOL Draw(CDC* pDC,BOOL bPause);

	//����ͼƬ
	static BOOL LoadImage();

	//�ƶ�
	void Move();


	//��þ���
	CRect GetRect();

	//�Ƿ����ӵ�
	BOOL IfFired();

	//ս����Ѫ
	void MinusHp(int nHP); 

	//ս����Ѫ
	void PlusHP(int nHP);
	
public:
	//λ�� -- 50�� λ�� -- 60
	static const int PLANE_WIDTH = 100;
	static const int PLANE_HEIGHT = 59;
private:

	//����λͼ����
	static CImageList m_Images[2];

	//�ɻ��ȼ�
	int m_nGrade;

	//Ѫ��λ��
	CPoint m_ptBlood;

};
