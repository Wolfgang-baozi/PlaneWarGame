
#include "stdafx.h"
#include "Counter.h"
#include <vector>
using namespace std;

//ͼ������
CImageList CCounter::m_Images;

//����
CCounter::CCounter()
{
	//��ʼ������
	m_nCounter = 0;

	//λ��
	m_ptPos.x = GAME_WIDTH - NUMBER_WIDTH - 30;
	//m_ptPos.x = 0;
	m_ptPos.y = 7;
}

//����
CCounter::~CCounter()
{

}

//�ӷ�
void CCounter::PlusNum(int x)
{
	m_nCounter += x;
}

//��ȡ�ܷ���
int CCounter::GetCount() const
{
	return m_nCounter;
}

//��ȡÿһλ���� ����λ��
int CCounter::GetPerNumber()
{
	//�ܷ�
	int num = GetCount();

	//ͳ��λ��
	int index = 0;

	//ÿ�δ�ȡǰ���vector
	m_vNum.clear();

	//��ȡÿһλ����
	while (num > 0) {
		m_vNum.push_back(num % 10);
		index = index + 1;
		num = num / 10;
	}
	return index;
}

//����ͼ��
BOOL CCounter::LoadImage()
{
	return CGameObject::LoadImage(m_Images, IDB_NUMBER, RGB(0, 0, 0), NUMBER_WIDTH, NUMBER_HEIGHT, 10);
}

//��ͼ
BOOL CCounter::Draw(CDC* pDC, BOOL bPause)
{
	m_ptPos.x = GAME_WIDTH - NUMBER_WIDTH - 30;

	//����Ϊ0ʱ
	if (m_nCounter == 0)
	{
		m_Images.Draw(pDC, 0, m_ptPos, ILD_TRANSPARENT);
		return TRUE;
	}

	//������Ϊ0ʱ
	else
	{
		int index = GetPerNumber();

		//��ͼ
		vector<int>::iterator pos = m_vNum.begin();

		for ( ; pos != m_vNum.end() && index >= 0; pos++, --index) {
			m_Images.Draw(pDC, *pos, m_ptPos, ILD_TRANSPARENT);
			m_ptPos.x -= 22;
		}
	}

	return TRUE;
}