#pragma once
#include "GameObject.h"

class CBombObject : public CGameObject
{
public:
	//构造
	CBombObject(void);
	
	//析构
	virtual ~CBombObject(void);

	virtual BOOL Draw(CDC* pDC,BOOL bPause) = 0;

public:

	//获得速度
	int GetV() const;

	//修改子弹速度
	void SetV(int V);

	//获得水平位置
	int GetHorMotion() const;
	
	//修改水平位置
	void SetHorMotion(int nMotion);

	//获得垂直位置
	int GetVerMotion() const;

	//修改垂直位置
	void SetVerMotion(int nMotion);

	//获得子弹伤害
	int GetHarm() const;

	//升级子弹伤害
	void UpHarm(int nGrade);

public:
	
	//伤害值
	int    m_nHarm;

	//子弹水平运行方向 0->静止，1->右 -1->左
	int    m_nHorMotion;

	//子弹垂直运行方向 0->静止，1->上 -1->下
	int    m_nVerMotion;

	//子弹移动速度
	int	   m_nV;

};