#include "Stdafx.h"
#include "PropObject.h"

//����
CPropObject::CPropObject()
{

}

//����
CPropObject::~CPropObject()
{

}

//���ID
int CPropObject::GetPropID() const
{
	return m_nID;
}

//���ˮƽλ��
int CPropObject::GetHorMotion() const
{
	return this->m_nHorMotion;
}

//�޸�ˮƽλ��
void CPropObject::SetHorMotion(int nMotion)
{
	this->m_nHorMotion = nMotion;
}


//�������
int CPropObject::GetV() const
{
	return m_V;
}