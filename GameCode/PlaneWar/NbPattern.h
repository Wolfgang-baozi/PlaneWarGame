//CNbPattern.h : �����ļ�
//

#pragma once
#include "stdafx.h"
#include "GameObject.h"
#include <mmsystem.h>

class CNbPattern : public CGameObject
{
	enum Pattern { on, off };
public:
	//����
	CNbPattern(void);
	
	//����
	~CNbPattern(void);

	//����ͼ��
	static BOOL LoadImage();

	//��þ���
	CRect GetRect();

	//��ͼ
	BOOL Draw(CDC* pDC,BOOL bPause);

public:

	//ͼ������
	static CImageList m_Image[3];

	//λͼ
	static const int NB_WIDTH = 35;
	static const int NB_HEIGHT = 25;
};