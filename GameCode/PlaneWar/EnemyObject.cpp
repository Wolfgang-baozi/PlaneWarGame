#include "stdafx.h"
#include "EnemyObject.h"

//����
CEnemyObject::CEnemyObject()
{

}

//����
CEnemyObject::~CEnemyObject()
{

}

//��ʼ��Ѫ��
void CEnemyObject::InitHP(int nHP)
{
	this->m_nNowHP = this->m_nSumHP = nHP;
}
//�ƻ���
int CEnemyObject::GetHarm() const
{
	return this->m_nHarm;
}


//Ѫ������
void CEnemyObject::MinusHP(int HP)
{
	this->m_nNowHP -= HP;
	if (this->m_nNowHP < 0)
		this->m_nNowHP = 0;
}

//�����ƻ���
void CEnemyObject::UpHarm(int nGrade)
{
	this->m_nHarm = this->m_nHarm + nGrade;
}