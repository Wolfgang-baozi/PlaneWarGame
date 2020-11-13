#include "stdafx.h"
#include "EnemyObject.h"

//构造
CEnemyObject::CEnemyObject()
{

}

//析构
CEnemyObject::~CEnemyObject()
{

}

//初始化血量
void CEnemyObject::InitHP(int nHP)
{
	this->m_nNowHP = this->m_nSumHP = nHP;
}
//破坏力
int CEnemyObject::GetHarm() const
{
	return this->m_nHarm;
}


//血量减少
void CEnemyObject::MinusHP(int HP)
{
	this->m_nNowHP -= HP;
	if (this->m_nNowHP < 0)
		this->m_nNowHP = 0;
}

//升级破坏力
void CEnemyObject::UpHarm(int nGrade)
{
	this->m_nHarm = this->m_nHarm + nGrade;
}