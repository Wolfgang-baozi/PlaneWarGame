// CGameSta.h : ʵ���ļ�
//

#pragma once
#include "stdafx.h"
#include "GameObject.h"
#include "resource.h"
#include <mmsystem.h>

class CGameSta : public CGameObject
{
	enum Type { startback, startgame, help, rank, hell};
public:
	
	//����
	CGameSta(void);
	
	//����
	~CGameSta(void);

public:

	//��ͼ
	BOOL Draw(CDC* pDC, BOOL bPause);

	//��ñ�������
	CRect GetRect();

	//��ÿ�ʼ����
	CRect GetRectStart();

	//��������
	CRect GetRectHelp();

	//����ģʽ
	CRect GetRectHell();
	
	//����ͼƬ
	static BOOL LoadImage();

	//����
	void AddText(CDC* pDC);

private:

	//ͼ������
	static CImageList m_Image[4];

	//λͼ��С
	//start button
	static const int START_SIZE = 120;
	//help button
	static const int BUTTON_SIZE  = 30;

	//λ��
	CPoint		m_ptHelp; //help
	CPoint		m_ptHell; //hell
};

