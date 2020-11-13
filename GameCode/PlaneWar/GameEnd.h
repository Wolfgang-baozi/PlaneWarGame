// CGameEnd.h : ʵ���ļ�
//

#pragma once
#include "stdafx.h"
#include "GameObject.h"
#include "resource.h"
#include <mmsystem.h>

class CGameEnd : public CGameObject
{
	enum Type { startback, startgame, help, rank, hell, smile};
public:
	
	//����
	CGameEnd(void);
	
	//����
	~CGameEnd(void);

public:

	//��ͼ
	BOOL Draw(CDC* pDC, BOOL bPause);

	//�������
	CRect GetRect();
	
	//����ͼƬ
	static BOOL LoadImage();

private:

	//ͼ������
	static CImageList m_Image;

	//λͼ��С
	static const int END_WIDTH = 300;
	static const int END_HEIGHT = 150;

};

