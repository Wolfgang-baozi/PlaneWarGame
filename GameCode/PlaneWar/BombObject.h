#pragma once
#include "GameObject.h"

class CBombObject : public CGameObject
{
public:
	//����
	CBombObject(void);
	
	//����
	virtual ~CBombObject(void);

	virtual BOOL Draw(CDC* pDC,BOOL bPause) = 0;

public:

	//����ٶ�
	int GetV() const;

	//�޸��ӵ��ٶ�
	void SetV(int V);

	//���ˮƽλ��
	int GetHorMotion() const;
	
	//�޸�ˮƽλ��
	void SetHorMotion(int nMotion);

	//��ô�ֱλ��
	int GetVerMotion() const;

	//�޸Ĵ�ֱλ��
	void SetVerMotion(int nMotion);

	//����ӵ��˺�
	int GetHarm() const;

	//�����ӵ��˺�
	void UpHarm(int nGrade);

public:
	
	//�˺�ֵ
	int    m_nHarm;

	//�ӵ�ˮƽ���з��� 0->��ֹ��1->�� -1->��
	int    m_nHorMotion;

	//�ӵ���ֱ���з��� 0->��ֹ��1->�� -1->��
	int    m_nVerMotion;

	//�ӵ��ƶ��ٶ�
	int	   m_nV;

};