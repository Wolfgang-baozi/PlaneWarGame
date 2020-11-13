#include "stdafx.h"
#include "Explosion.h"

//图像链表
CImageList CExplosion::m_Images;

//构造
CExplosion::CExplosion(int x, int y) :CGameObject(x, y), m_nProcess(0)
{
	//步进
	m_nProcess = 0;
}

//析构
CExplosion::~CExplosion()
{

}

//加载图像
BOOL CExplosion::LoadImage()
{
	return CGameObject::LoadImage(m_Images, IDB_EXPLOSION, RGB(0, 0, 0), 66, 66, 8);
}

//绘图
BOOL CExplosion::Draw(CDC* pDC, BOOL bPause)
{
	//爆炸后
	if (m_nProcess == 9)
	{
		//重置
		m_nProcess = 0;
		return FALSE;
	}

	//绘制图像原位置
	m_Images.Draw(pDC, m_nProcess, m_ptPos, ILD_TRANSPARENT);
	
	//步进+1
	if (!bPause)
		m_nProcess++;
	
	return TRUE;
}


