#pragma once
#include "GameObject.h"
#include "MyPlane.h"

class CPropObject : public CGameObject
{
public:
	//构造
	CPropObject(void);
	
	//析构
	virtual ~CPropObject(void);

	virtual BOOL Draw(CDC* pDC,BOOL bPause) = 0;

public:

	//获得水平位置
	int GetHorMotion() const;

	//修改水平位置
	void SetHorMotion(int nMotion);

	//获得移速
	int GetV() const;

	//获得ID
	int GetPropID() const;

	//功能
	virtual BOOL PropFunction(CMyPlane* & pMe) = 0;

public:

	//道具水平运动方向 0->静止，1->右 -1->左
	int		m_nHorMotion;

	//道具移动速度
	int		m_V;

	//道具ID
	int		m_nID;
};