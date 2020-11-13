#pragma once
#include "PlaneObject.h"

class CEnemyObject : public CPlaneObject
{
public:
	//����
	CEnemyObject();

	//����
	virtual ~CEnemyObject();

	//���ƶ���
	virtual BOOL Draw(CDC* pDC, BOOL bPause) = 0;

	//��þ�������
	virtual CRect GetRect() = 0;

	//�Ƿ����ӵ�
	virtual BOOL Fired() = 0; 

	//�л�Ѫ����iHP
	void MinusHP(int HP);

	//��ȡ�л�ײ��ʱ���ƻ���
	int GetHarm() const; 

	//��ʼ��Ѫ��
	void InitHP(int nHP);

	//�����ƻ���
	void UpHarm(int nGrade);

protected:

	//�л��ƻ���
	int m_nHarm; 
};


