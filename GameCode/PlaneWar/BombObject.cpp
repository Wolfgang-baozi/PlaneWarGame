#include "Stdafx.h"
#include "BombObject.h"
#include "resource.h"

//构造
CBombObject::CBombObject()
{
	
}

//析构
CBombObject::~CBombObject(void)
{

}

//获得子弹速度
int CBombObject::GetV() const
{
	return this->m_nV;
}

//修改子弹速度
void CBombObject::SetV(int V)
{
	this->m_nV = V;
}

//获得水平位置
int CBombObject::GetHorMotion() const
{
	return this->m_nHorMotion;
}

void CBombObject::SetHorMotion(int nMotion)
{
	this->m_nHorMotion = nMotion;
}

//获得垂直位置
int CBombObject::GetVerMotion() const
{
	return this->m_nVerMotion;
}

//修改垂直位置
void CBombObject::SetVerMotion(int nMotion)
{
	this->m_nVerMotion = nMotion;
}

//获得子弹伤害
int CBombObject::GetHarm() const
{
	return this->m_nHarm;
}

//升级子弹伤害 ->返回引用
void CBombObject::UpHarm(int nGrade)
{
	this->m_nHarm = this->m_nHarm + nGrade;
}