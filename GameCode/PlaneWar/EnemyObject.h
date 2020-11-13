#pragma once
#include "PlaneObject.h"

class CEnemyObject : public CPlaneObject
{
public:
	//构造
	CEnemyObject();

	//析构
	virtual ~CEnemyObject();

	//绘制对象
	virtual BOOL Draw(CDC* pDC, BOOL bPause) = 0;

	//获得矩形区域
	virtual CRect GetRect() = 0;

	//是否发射子弹
	virtual BOOL Fired() = 0; 

	//敌机血量减iHP
	void MinusHP(int HP);

	//获取敌机撞击时的破坏力
	int GetHarm() const; 

	//初始化血量
	void InitHP(int nHP);

	//升级破坏力
	void UpHarm(int nGrade);

protected:

	//敌机破坏力
	int m_nHarm; 
};


