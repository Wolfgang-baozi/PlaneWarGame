// Plane.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "GameObject.h"
#include "PlaneObject.h"
// Plane

//����
CPlaneObject::CPlaneObject(void) : m_nHorMotion(0),m_nVerMotion(0)
{
	
}

//����
CPlaneObject::~CPlaneObject()
{

}

//��ȡ�����ӳ�
int CPlaneObject::GetWait()
{
	return m_nWait;
}

//�������
int CPlaneObject::GetV() const
{
	return m_V;
}

//���ˮƽλ��
int CPlaneObject::GetHorMotion() const
{
	return this->m_nHorMotion;
}

//�޸�ˮƽλ��
void CPlaneObject::SetHorMotion(int nMotion)
{
	this->m_nHorMotion = nMotion;
}

//��ô�ֱλ��
int CPlaneObject::GetVerMotion() const
{
	return this->m_nVerMotion;
}

//�޸Ĵ�ֱλ��
void CPlaneObject::SetVerMotion(int nMotion)
{
	this->m_nVerMotion = nMotion;
}

//�������Ѫ��
int CPlaneObject::GetNowHP() const
{
	return this->m_nNowHP;
}

	//�����Ѫ��
int CPlaneObject::GetSumHP() const
{
	return this->m_nSumHP;
}


//������Ѫ��
void CPlaneObject::UpSumHP(int nGrade)
{
	this->m_nSumHP = this->m_nSumHP + nGrade;
}