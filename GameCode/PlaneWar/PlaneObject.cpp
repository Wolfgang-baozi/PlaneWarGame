// Plane.cpp : 实现文件
//

#include "stdafx.h"
#include "GameObject.h"
#include "PlaneObject.h"
// Plane

//构造
CPlaneObject::CPlaneObject(void) : m_nHorMotion(0),m_nVerMotion(0)
{
	
}

//析构
CPlaneObject::~CPlaneObject()
{

}

//获取发射延迟
int CPlaneObject::GetWait()
{
	return m_nWait;
}

//获得移速
int CPlaneObject::GetV() const
{
	return m_V;
}

//获得水平位置
int CPlaneObject::GetHorMotion() const
{
	return this->m_nHorMotion;
}

//修改水平位置
void CPlaneObject::SetHorMotion(int nMotion)
{
	this->m_nHorMotion = nMotion;
}

//获得垂直位置
int CPlaneObject::GetVerMotion() const
{
	return this->m_nVerMotion;
}

//修改垂直位置
void CPlaneObject::SetVerMotion(int nMotion)
{
	this->m_nVerMotion = nMotion;
}

//获得现有血量
int CPlaneObject::GetNowHP() const
{
	return this->m_nNowHP;
}

	//获得总血量
int CPlaneObject::GetSumHP() const
{
	return this->m_nSumHP;
}


//升级总血量
void CPlaneObject::UpSumHP(int nGrade)
{
	this->m_nSumHP = this->m_nSumHP + nGrade;
}