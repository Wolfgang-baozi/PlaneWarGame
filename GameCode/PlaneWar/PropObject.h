#pragma once
#include "GameObject.h"
#include "MyPlane.h"

class CPropObject : public CGameObject
{
public:
	//����
	CPropObject(void);
	
	//����
	virtual ~CPropObject(void);

	virtual BOOL Draw(CDC* pDC,BOOL bPause) = 0;

public:

	//���ˮƽλ��
	int GetHorMotion() const;

	//�޸�ˮƽλ��
	void SetHorMotion(int nMotion);

	//�������
	int GetV() const;

	//���ID
	int GetPropID() const;

	//����
	virtual BOOL PropFunction(CMyPlane* & pMe) = 0;

public:

	//����ˮƽ�˶����� 0->��ֹ��1->�� -1->��
	int		m_nHorMotion;

	//�����ƶ��ٶ�
	int		m_V;

	//����ID
	int		m_nID;
};