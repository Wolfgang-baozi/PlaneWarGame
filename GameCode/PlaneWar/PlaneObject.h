#pragma once

#include "stdafx.h"
#include "GameObject.h"

//�ɻ��ĳ�����
class CPlaneObject : public CGameObject
{
public:

	//����
	CPlaneObject(void);

	//��������
	virtual ~CPlaneObject(void);
	
	//���ƶ���
	virtual BOOL Draw(CDC* pDC, BOOL bPause) = 0;

public:

	//��þ�������
	virtual CRect GetRect() = 0;

	//��ȡ�����ӳ�
	int GetWait();
	
	//�������
	int GetV() const;

	//���ˮƽλ��
	int GetHorMotion() const;
	
	//�޸�ˮƽλ��
	void SetHorMotion(int nMotion);

	//��ô�ֱλ��
	int GetVerMotion() const;

	//�޸Ĵ�ֱλ��
	void SetVerMotion(int nMotion);

	//�������Ѫ��
	int GetNowHP() const;

	//�����Ѫ��
	int GetSumHP() const;

	//������Ѫ��
	void UpSumHP(int nGrade);

public:

	//�ɻ�ˮƽ���з���0->��ֹ��1->�� -1->��
	int		m_nHorMotion;

	//�ɻ���ֱ���з���0->��ֹ��1->�� -1->��
	int		m_nVerMotion;

	//������ʱ
	int		m_nWait;

	//�ƶ��ٶ�
	int		m_V;

	//�ɻ���Ѫ��
	int		m_nSumHP;

	//�ɻ�����Ѫ��
	int		m_nNowHP;

	//����ӵ���Լ���������
	//string m_sName;
};