// CGameGrade.h : �����ļ�
//

#pragma once
#include "stdafx.h"

#include "resource.h"

class CGameGrade : public CObject
{
public:
	//����
	CGameGrade(void);
	
	//����
	~CGameGrade(void);

public:
	//��ùؿ��ȼ�
	int GetGrade() const;
	//�޸Ĺؿ��ȼ�
	void SetGrade();
	//����
	void UpDate(int & nNum, int nGrade);

public:
	
	//�ؿ��ȼ�
	int			m_nGrade;

	//�л�����
	double		m_dAshNum;

	//�л�HP
	double		m_dAshHP;

	//boos����
	double		m_dBossNum;

	//BOSS��HP
	double		m_dBossHP;

	//��������
	//��������

	//ս��HP
	double		m_dMyHP;

	//�ӵ��˺�
	double		m_dHarm;
};