#pragma once

#include "stdafx.h"
#include "GameObject.h"

//飞机的抽象类
class CPlaneObject : public CGameObject
{
public:

	//构造
	CPlaneObject(void);

	//虚拟析构
	virtual ~CPlaneObject(void);
	
	//绘制对象
	virtual BOOL Draw(CDC* pDC, BOOL bPause) = 0;

public:

	//获得矩形区域
	virtual CRect GetRect() = 0;

	//获取发射延迟
	int GetWait();
	
	//获得移速
	int GetV() const;

	//获得水平位置
	int GetHorMotion() const;
	
	//修改水平位置
	void SetHorMotion(int nMotion);

	//获得垂直位置
	int GetVerMotion() const;

	//修改垂直位置
	void SetVerMotion(int nMotion);

	//获得现有血量
	int GetNowHP() const;

	//获得总血量
	int GetSumHP() const;

	//升级总血量
	void UpSumHP(int nGrade);

public:

	//飞机水平运行方向0->静止，1->右 -1->左
	int		m_nHorMotion;

	//飞机垂直运行方向0->静止，1->上 -1->下
	int		m_nVerMotion;

	//发射延时
	int		m_nWait;

	//移动速度
	int		m_V;

	//飞机总血量
	int		m_nSumHP;

	//飞机现有血量
	int		m_nNowHP;

	//可以拥有自己的名字吗？
	//string m_sName;
};