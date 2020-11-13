// GameObject.cpp : 实现文件
//

#include "stdafx.h"
#include "GameObject.h"

// CGameObject

//构造
CGameObject::CGameObject(int x,int y) : m_ptPos(x, y)
{
	
}

//析构
CGameObject::~CGameObject()
{

}

//加载图像
BOOL CGameObject::LoadImage(CImageList& imgList, UINT bmpID, COLORREF crMask, int cx, int cy, int nInitial)
{
	//构造位图对象bmp
	CBitmap bmp;

	//位图是否存在
	if(!bmp.LoadBitmap(bmpID))
		return FALSE;

	//创建位图链表并判断是否成功
	if(!imgList.Create(cx, cy, ILC_COLOR24|ILC_MASK, nInitial, 0))
		return FALSE;

	//将位图和其掩码加入图像链表
	imgList.Add(&bmp, crMask);

	return TRUE;
}

