#include "Stdafx.h"
#include "FriendPlane.h"
#include "PlaneObject.h"
#include "resource.h"
#include "MoveLine.h"

//MyPlane 链表
CImageList CFriendPlane::m_Images;

//构造
CFriendPlane::CFriendPlane(void)
{
	//初始化子弹等待时间
	m_nWait = 0;

	//初始化飞机等级
	m_nLevel = 1;

	//初始化水平,垂直位置
	m_ptPos.x = 100;
	m_ptPos.y = GAME_HEIGHT * 3 / 5;

	//键盘控制的移动速度
	m_V = 6;

	//僚机的生存时间
	m_nLifeTime = 900;

	//移动方向
	SetHorMotion(rand() % 2 == 2 ? 1 : -1);
	SetVerMotion(rand() % 2 == 2 ? 1 : -1);
}

//析构
CFriendPlane::~CFriendPlane(void)
{

}

//移动
void CFriendPlane::Move()
{
	CMoveLine pMoveLine;
	pMoveLine.Move(m_ptPos, GetHorMotion(), GetVerMotion(), GetV());

	//左右边界
	if (m_ptPos.x <= 10 || m_ptPos.x >= GAME_WIDTH - PLANE_WIDTH - 20)
		{
			SetHorMotion( -GetHorMotion() );
			m_V = rand() % 4 + 1;
		}
			//上下边界
	if (m_ptPos.y <= GAME_HEIGHT * 3 / 5 || m_ptPos.y >= GAME_HEIGHT * 4 /5)
		{
			SetVerMotion( -GetVerMotion() );
			m_V = rand() % 4 + 1;
		}
}

//是否发射子弹
BOOL CFriendPlane::IfFired()
{
	if(GetWait() == 0)
		return TRUE;
	else
		return FALSE;
}

//获得生存时间
int CFriendPlane::GetLifeTime() const
{
	return this->m_nLifeTime;
}

//修改生存时间
int CFriendPlane::SetLifeTime(int LifeTime)
{
	return this->m_nLifeTime = LifeTime;
}

//获得发射位置
CPoint CFriendPlane::GetBombPos(int nPos) const
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
BOOL CFriendPlane::LoadImage()
{
	//加载图片，成功返回true
	return CGameObject::LoadImage(m_Images, IDB_FRIENDPLANE, RGB(255, 255,255), PLANE_WIDTH, PLANE_HEIGHT, 1);
}

//绘图
BOOL CFriendPlane::Draw(CDC* pDC, BOOL bPause)
{
	//导弹发射之间的间隔--射速
	//3-4 -- 正常 5 -- 慢速
	m_nWait++;
	if(m_nWait > 3)
		m_nWait=0;
	
	//控制生存时间
	SetLifeTime(GetLifeTime() - 1);
	if(GetLifeTime() <= 0)
	{
		SetLifeTime(0);
		return FALSE;
	}

	//移动
	if(!bPause)
	{
		//移动
		Move();

	}

	//绘图
	m_Images.Draw(pDC,0,m_ptPos,ILD_TRANSPARENT);

	return TRUE;
}