// CGameGrade.cpp : ʵ���ļ�
//

#pragma once
#include "stdafx.h"
#include "GameGrade.h"
#include "resource.h"

//����
CGameGrade::CGameGrade()
{
	//�ؿ��ȼ�
	int			m_nGrade = 1;
	//�л�����
	double		m_dAshNum = 0.35;
	//�л�HP
	double		m_dAshHP = 0.2;
	//boos����
	double		m_dBossNum = 0.1;
	//BOSS��HP
	double		m_dBossHP = 0.2;
	//��������
	//��������
	//ս��HP
	double		m_dMyHP = 0.02;
	//�ӵ��˺�
	double		m_dHarm = 0.01;
}
	
//����
CGameGrade::~CGameGrade()
{

}

//��ùؿ��ȼ�
int CGameGrade::GetGrade() const
{
	return m_nGrade;
}

//�޸Ĺؿ��ȼ�
void CGameGrade::SetGrade()
{
	m_nGrade = m_nGrade + 1; 
}

//����
void CGameGrade::UpDate(int & num, int nGrade)
{
	num = num + nGrade * 2;
}

