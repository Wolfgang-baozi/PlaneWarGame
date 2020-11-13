#include "Stdafx.h"
#include "MyPlane.h"
#include "PlaneObject.h"
#include "resource.h"
#include <mmsystem.h>

//MyPlane 链表
CImageList CMyPlane::m_Images[2];

//构造
CMyPlane::CMyPlane(void)
{
	//初始化子弹等待时间
	m_nWait = 0;

	//初始化飞机等级
	m_nGrade = 1;

	//初始化水平,垂直位置
	m_ptPos.x = 200;
	m_ptPos.y = 600;

	//键盘控制的移动速度
	m_V = 7;

	//血条位置
	m_ptBlood.x = 10;
	m_ptBlood.y = 10;

	//血量
	m_nNowHP = m_nSumHP = 100;

}

//析构
CMyPlane::~CMyPlane(void)
{

}

//移动
void CMyPlane::Move()
{
	m_ptPos.x = m_ptPos.x + GetHorMotion() * GetV();
	m_ptPos.y = m_ptPos.y + GetVerMotion() * GetV();
	SetHorMotion(0);
	SetVerMotion(0);
}

//获得矩形
CRect CMyPlane::GetRect()
{
	//if(GetGrade() == 3)
		return CRect( m_ptPos, CPoint(m_ptPos.x+PLANE_WIDTH, m_ptPos.y+PLANE_HEIGHT) );
	//else
		//return CRect( CPoint(m_ptPos.x + PLANE_WIDTH / 3, m_ptPos.y), CPoint(m_ptPos.x + PLANE_WIDTH * 2 / 3, m_ptPos.y + PLANE_HEIGHT));
}

//获得飞机等级
int CMyPlane::GetGrade()const
{
	return this->m_nGrade;
}

//修改等级
void CMyPlane::AddGrade(int Grade)
{
	this->m_nGrade = this->m_nGrade + Grade;
	if(this->m_nGrade > 3)
		this->m_nGrade = 3;
}

//是否发射子弹
BOOL CMyPlane::IfFired()
{
	if(GetWait() == 0)
		return TRUE;
	else
		return FALSE;
}

//敌机减血
void CMyPlane::MinusHp(int nHP)
{
	m_nNowHP -= nHP;
	if(m_nNowHP < 0)
		m_nNowHP = 0;
}

//战机加血,保证现有血量小于等于最大值
void CMyPlane::PlusHP(int nHP)
{
	m_nNowHP = m_nNowHP + nHP;
	if(m_nNowHP > m_nSumHP)
		m_nNowHP = m_nSumHP;
}

//获得发射位置
CPoint CMyPlane::GetBombPos(int nPos) const
{
	switch(nPos)
	{
		case 1:
			return CPoint(m_ptPos.x + 3, m_ptPos.y + 2);
			break;
		case 2:
			return CPoint(m_ptPos.x + PLANE_WIDTH / 3 - 4, m_ptPos.y + 25);
			break;
		case 3:
			return CPoint(m_ptPos.x + PLANE_WIDTH * 2 / 3 - 4, m_ptPos.y + 25);
			break;
		default:
			return CPoint(m_ptPos.x + PLANE_WIDTH - 12, m_ptPos.y + 2);
			break;
	}
}

//加载图像
BOOL CMyPlane::LoadImage()
{
	return CGameObject::LoadImage(m_Images[1], IDB_MYPLANE1, RGB(0, 0, 0), PLANE_WIDTH, PLANE_HEIGHT, 0);
}

//绘图
BOOL CMyPlane::Draw(CDC* pDC,BOOL bPause)
{
	//导弹发射之间的间隔--射速
	//3-4 -- 正常 5 -- 慢速
	m_nWait++;
	if(m_nWait > 3)
		m_nWait=0;

	//移动
	if(!bPause)
	{
		Move();
	}

	//防止飞机飞出边界
	//水平右边界
	if(m_ptPos.x>=GAME_WIDTH - PLANE_WIDTH - 20)
		m_ptPos.x = GAME_WIDTH - PLANE_WIDTH - 20;

	//水平左边界
	if(m_ptPos.x <= 0)
		m_ptPos.x = 0;

	//垂直上边界
	if(m_ptPos.y <= 0)
		m_ptPos.y = 0;

	//垂直下边界
	if(m_ptPos.y >= GAME_HEIGHT - PLANE_HEIGHT)
		m_ptPos.y = GAME_HEIGHT - PLANE_HEIGHT;

	//绘图
	//飞机
	int iIndex = 1;
	m_Images[iIndex].Draw(pDC,0,m_ptPos,ILD_TRANSPARENT);
	
	//绘制血条
	CBrush *m_pBrush1;
	CBrush *m_pBrush2;
	m_pBrush1 = new CBrush();
	m_pBrush1->CreateSolidBrush(RGB(243, 144, 9));
	m_pBrush2 = new CBrush();
	m_pBrush2->CreateSolidBrush(RGB(248, 155, 80));
	pDC->RoundRect(CRect(m_ptBlood.x, m_ptBlood.y, m_ptBlood.x + 200, m_ptBlood.y + 12) ,CPoint(12, 12));
	if(GetNowHP() > 0)
		pDC->FillRect(CRect(m_ptBlood.x + 5, m_ptBlood.y + 3, m_ptBlood.x + 195 * (GetNowHP() * 1.0 / GetSumHP()), m_ptBlood.y + 10), m_pBrush2);
	
	delete m_pBrush1;
	delete m_pBrush2;

	return TRUE;
}