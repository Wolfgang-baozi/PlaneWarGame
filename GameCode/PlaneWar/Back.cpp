//Back.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Back.h"
#include "resource.h"
#include <mmsystem.h>

//3������ͼ
CImageList CBack::m_Images[3];

//����
CBack::CBack(int x, int y) : CGameObject(x, y)
{
	m_nGrade = 1;
}

//����
CBack::~CBack()
{

}

//��ùؿ��ȼ�
int CBack::GetGrade() const
{
	return m_nGrade;
}

//��������
void CBack::SetGrade(int nGrade)
{
	this->m_nGrade = nGrade;
}

//����
CRect CBack::GetRect()
{
	return CRect(m_ptPos, CPoint(m_ptPos.x + GAME_WIDTH, m_ptPos.y + GAME_HEIGHT));
}

//��ͼ
BOOL CBack::Draw(CDC* pMemDC, BOOL bPause)
{
	//�ȼ�
	int nGrade = GetGrade();
	switch(nGrade)
	{
		case bosspattern1:
			nGrade = IDB_BACK0;
			break;
		case bosspattern2:
			nGrade = IDB_BACK1;
			break;
		case bosspattern3:
			nGrade = IDB_BACK2;
			break;
		default :
			nGrade = IDB_BACK1;
			break;
	}

	//˫���弼�����Ʊ���
	static int imagelocation = 0;
	CDC memDC;
	memDC.CreateCompatibleDC(pMemDC);
	CBitmap bmpDraw;
	bmpDraw.LoadBitmapW(nGrade);//����λͼ
	CBitmap* pbmpold = memDC.SelectObject(&bmpDraw);
	pMemDC->BitBlt(0, imagelocation, GAME_WIDTH, GAME_HEIGHT - imagelocation, &memDC, 0, 0, SRCCOPY);//���ö�̬����
	pMemDC->BitBlt(0, 0, GAME_WIDTH, imagelocation, &memDC, 0, GAME_HEIGHT - imagelocation, SRCCOPY);
	imagelocation++;
	if (imagelocation == GAME_HEIGHT)
		imagelocation = 0;

	return TRUE;
}

//����ͼ��
BOOL CBack::LoadImage()
{
	return CGameObject::LoadImage(m_Images[0], IDB_BACK0, RGB(0, 0, 0), GAME_WIDTH, GAME_HEIGHT, 1)&&
		CGameObject::LoadImage(m_Images[1], IDB_BACK1, RGB(0, 0, 0), GAME_WIDTH, GAME_HEIGHT, 1) &&
		CGameObject::LoadImage(m_Images[2], IDB_BACK2, RGB(0, 0, 0), GAME_WIDTH, GAME_HEIGHT, 1);
}

