// CGameGrade.cpp : 实现文件
//

#pragma once
#include "stdafx.h"
#include "GameGrade.h"
#include "resource.h"

//构造
CGameGrade::CGameGrade()
{
	//关卡等级
	int			m_nGrade = 1;
	//敌机数量
	double		m_dAshNum = 0.35;
	//敌机HP
	double		m_dAshHP = 0.2;
	//boos数量
	double		m_dBossNum = 0.1;
	//BOSS的HP
	double		m_dBossHP = 0.2;
	//道具种类
	//道具种类
	//战机HP
	double		m_dMyHP = 0.02;
	//子弹伤害
	double		m_dHarm = 0.01;
}
	
//析构
CGameGrade::~CGameGrade()
{

}

//获得关卡等级
int CGameGrade::GetGrade() const
{
	return m_nGrade;
}

//修改关卡等级
void CGameGrade::SetGrade()
{
	m_nGrade = m_nGrade + 1; 
}

//增长
void CGameGrade::UpDate(int & num, int nGrade)
{
	num = num + nGrade * 2;
}

