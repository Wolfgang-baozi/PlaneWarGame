#include "Stdafx.h"
#include "BombObject.h"
#include "resource.h"

//����
CBombObject::CBombObject()
{
	
}

//����
CBombObject::~CBombObject(void)
{

}

//����ӵ��ٶ�
int CBombObject::GetV() const
{
	return this->m_nV;
}

//�޸��ӵ��ٶ�
void CBombObject::SetV(int V)
{
	this->m_nV = V;
}

//���ˮƽλ��
int CBombObject::GetHorMotion() const
{
	return this->m_nHorMotion;
}

void CBombObject::SetHorMotion(int nMotion)
{
	this->m_nHorMotion = nMotion;
}

//��ô�ֱλ��
int CBombObject::GetVerMotion() const
{
	return this->m_nVerMotion;
}

//�޸Ĵ�ֱλ��
void CBombObject::SetVerMotion(int nMotion)
{
	this->m_nVerMotion = nMotion;
}

//����ӵ��˺�
int CBombObject::GetHarm() const
{
	return this->m_nHarm;
}

//�����ӵ��˺� ->��������
void CBombObject::UpHarm(int nGrade)
{
	this->m_nHarm = this->m_nHarm + nGrade;
}