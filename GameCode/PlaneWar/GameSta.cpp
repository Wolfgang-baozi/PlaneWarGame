// CGameSta.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "GameSta.h"
#include "resource.h"

//ͼ������
CImageList CGameSta::m_Image[4];

//����
CGameSta::CGameSta()
{
	//ͨ��start��λ�� ȷ��������ťλ��
	m_ptPos.x = GAME_WIDTH / 2 - START_SIZE / 2 - 10;
	m_ptPos.y = GAME_HEIGHT - START_SIZE - 21;

	//help
	m_ptHelp.x = m_ptPos.x - BUTTON_SIZE - 10;
	m_ptHelp.y = m_ptPos.y + BUTTON_SIZE * 2 / 3 + 10;

	//hell
	m_ptHell.x = m_ptPos.x + START_SIZE + 10;
	m_ptHell.y = m_ptPos.y + BUTTON_SIZE * 2 / 3 + 10;
}

//����
CGameSta::~CGameSta()
{

}

//��þ������� ->����
CRect CGameSta::GetRect()
{
	return CRect(CPoint(0,0), CPoint(GAME_WIDTH, GAME_HEIGHT));
}

//��ʼ����
CRect CGameSta::GetRectStart()
{
	return CRect(m_ptPos, CPoint(m_ptPos.x + START_SIZE, m_ptPos.y + START_SIZE));
}

//��������
CRect CGameSta::GetRectHelp()
{
	return CRect(m_ptHelp, CPoint(m_ptHelp.x + BUTTON_SIZE, m_ptHelp.y + BUTTON_SIZE)); 
}

//����ģʽ
CRect CGameSta::GetRectHell()
{
	return CRect(m_ptHell, CPoint(m_ptHell.x + BUTTON_SIZE, m_ptHell.y + BUTTON_SIZE)); 
}

//����ͼƬ
BOOL CGameSta::LoadImage()
{
	return CGameObject::LoadImage(m_Image[startback], IDB_STARTBACK, RGB(255, 255, 255), GAME_WIDTH - 20, GAME_HEIGHT, 0) &&
		   CGameObject::LoadImage(m_Image[startgame], IDB_STARTBUTTON, RGB(0, 0, 0), START_SIZE, START_SIZE, 0) &&
		   CGameObject::LoadImage(m_Image[help], IDB_HELP, RGB(0, 0, 0), BUTTON_SIZE, BUTTON_SIZE, 0) &&
		   CGameObject::LoadImage(m_Image[hell], IDB_HELL, RGB(0, 0, 0), BUTTON_SIZE, BUTTON_SIZE, 0) ;
}

BOOL CGameSta::Draw(CDC* pDC, BOOL bHelp)
{
	//����
	m_Image[startback].Draw(pDC, 0, CPoint(0, 0), ILD_TRANSPARENT);
	//��ʼ
	m_Image[startgame].Draw(pDC, 0, m_ptPos, ILD_TRANSPARENT);
	//����
	m_Image[help].Draw(pDC, 0, m_ptHelp, ILD_TRANSPARENT);
	//����ģʽ
	m_Image[hell].Draw(pDC, 0, m_ptHell, ILD_TRANSPARENT);

	if(bHelp)
	{
		AddText(pDC);
	}
	return TRUE;
}

//�����ĵ�
void CGameSta::AddText(CDC* pDC)
{
	int		nStaVer = 360;
	int		nDisVer  = 25;
	int		nTab = 30;
	int		nDisTab = 40;
	CFont font;
	font.CreateFont(20,
		8,
		0,
		0,
		400,
		FALSE,
		FALSE,
		0,
		ANSI_CHARSET,
		OUT_DEFAULT_PRECIS,
		CLIP_DEFAULT_PRECIS,
		DEFAULT_QUALITY,
		DEFAULT_PITCH | FF_SWISS,
		_T("΢���ź�"));  //����������
	pDC->SetBkMode(TRANSPARENT);
	pDC->SetTextColor(RGB(255, 255, 255));
	CFont* pOld = pDC->SelectObject(&font);

	pDC->TextOut(nTab, nStaVer, _T("1.ս�����ܣ�"));
	pDC->TextOut(nTab + nDisTab, nStaVer + nDisVer, _T("ս���������ȼ����������ҿ���ս���ƶ����ո����ӵ�"));
	pDC->TextOut(nTab, nStaVer + nDisVer * 2, _T("2.���߼��ܣ�"));
	pDC->TextOut(nTab + nDisTab, nStaVer + nDisVer * 3, _T("'B'�������޵�ģʽ"));
	pDC->TextOut(nTab + nDisTab, nStaVer + nDisVer * 4, _T("Ѫ����ÿ��һ��������Ѫ��������ӣ���������һ�룩��ֱ��ս��Ѫ����Ϊֹ"));
	pDC->TextOut(nTab + nDisTab, nStaVer + nDisVer * 5, _T("���ƣ������ٻ�һ���Ż�"));
	pDC->TextOut(nTab + nDisTab, nStaVer + nDisVer * 6, _T("����������ս��������"));
	pDC->TextOut(nTab, nStaVer + nDisVer * 7, _T("3.������ܣ�"));
	pDC->TextOut(nTab + nDisTab, nStaVer + nDisVer * 8, _T("Bossģʽ���޾�ģʽ����ÿ���Ѷȵ���"));
	pDC->TextOut(nTab + nDisTab, nStaVer + nDisVer * 9, _T("ÿ�ػ���ָ���ĵл��������Boss�����Boss���ɽ�����һ��"));
	pDC->TextOut(nTab + nDisTab, nStaVer + nDisVer * 10, _T("����ģʽ�ؿ�������Ѷȵ���"));
	pDC->TextOut(nTab + nDisTab, nStaVer + nDisVer * 11, _T("ս����������Ϸ����������������⴦������������"));
	pDC->SelectObject((pOld));

}
