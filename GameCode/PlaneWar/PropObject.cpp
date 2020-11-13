#include "Stdafx.h"
#include "PropObject.h"

//构造
CPropObject::CPropObject()
{

}

//析构
CPropObject::~CPropObject()
{

}

//获得ID
int CPropObject::GetPropID() const
{
	return m_nID;
}

//获得水平位置
int CPropObject::GetHorMotion() const
{
	return this->m_nHorMotion;
}

//修改水平位置
void CPropObject::SetHorMotion(int nMotion)
{
	this->m_nHorMotion = nMotion;
}


//获得移速
int CPropObject::GetV() const
{
	return m_V;
}