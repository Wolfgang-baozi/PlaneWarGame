// GameObject.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "GameObject.h"

// CGameObject

//����
CGameObject::CGameObject(int x,int y) : m_ptPos(x, y)
{
	
}

//����
CGameObject::~CGameObject()
{

}

//����ͼ��
BOOL CGameObject::LoadImage(CImageList& imgList, UINT bmpID, COLORREF crMask, int cx, int cy, int nInitial)
{
	//����λͼ����bmp
	CBitmap bmp;

	//λͼ�Ƿ����
	if(!bmp.LoadBitmap(bmpID))
		return FALSE;

	//����λͼ�����ж��Ƿ�ɹ�
	if(!imgList.Create(cx, cy, ILC_COLOR24|ILC_MASK, nInitial, 0))
		return FALSE;

	//��λͼ�����������ͼ������
	imgList.Add(&bmp, crMask);

	return TRUE;
}

