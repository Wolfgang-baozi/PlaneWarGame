
#include "stdafx.h"
#include "Counter.h"
#include <vector>
using namespace std;

//图像链表
CImageList CCounter::m_Images;

//构造
CCounter::CCounter()
{
	//初始化分数
	m_nCounter = 0;

	//位置
	m_ptPos.x = GAME_WIDTH - NUMBER_WIDTH - 30;
	//m_ptPos.x = 0;
	m_ptPos.y = 7;
}

//析构
CCounter::~CCounter()
{

}

//加分
void CCounter::PlusNum(int x)
{
	m_nCounter += x;
}

//获取总分数
int CCounter::GetCount() const
{
	return m_nCounter;
}

//存取每一位数字 返回位数
int CCounter::GetPerNumber()
{
	//总分
	int num = GetCount();

	//统计位数
	int index = 0;

	//每次存取前清空vector
	m_vNum.clear();

	//获取每一位数字
	while (num > 0) {
		m_vNum.push_back(num % 10);
		index = index + 1;
		num = num / 10;
	}
	return index;
}

//加载图像
BOOL CCounter::LoadImage()
{
	return CGameObject::LoadImage(m_Images, IDB_NUMBER, RGB(0, 0, 0), NUMBER_WIDTH, NUMBER_HEIGHT, 10);
}

//绘图
BOOL CCounter::Draw(CDC* pDC, BOOL bPause)
{
	m_ptPos.x = GAME_WIDTH - NUMBER_WIDTH - 30;

	//分数为0时
	if (m_nCounter == 0)
	{
		m_Images.Draw(pDC, 0, m_ptPos, ILD_TRANSPARENT);
		return TRUE;
	}

	//分数不为0时
	else
	{
		int index = GetPerNumber();

		//绘图
		vector<int>::iterator pos = m_vNum.begin();

		for ( ; pos != m_vNum.end() && index >= 0; pos++, --index) {
			m_Images.Draw(pDC, *pos, m_ptPos, ILD_TRANSPARENT);
			m_ptPos.x -= 22;
		}
	}

	return TRUE;
}