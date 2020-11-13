// CGameGrade.h : 定义文件
//

#pragma once
#include "stdafx.h"

#include "resource.h"

class CGameGrade : public CObject
{
public:
	//构造
	CGameGrade(void);
	
	//析构
	~CGameGrade(void);

public:
	//获得关卡等级
	int GetGrade() const;
	//修改关卡等级
	void SetGrade();
	//增长
	void UpDate(int & nNum, int nGrade);

public:
	
	//关卡等级
	int			m_nGrade;

	//敌机数量
	double		m_dAshNum;

	//敌机HP
	double		m_dAshHP;

	//boos数量
	double		m_dBossNum;

	//BOSS的HP
	double		m_dBossHP;

	//道具种类
	//道具种类

	//战机HP
	double		m_dMyHP;

	//子弹伤害
	double		m_dHarm;
};