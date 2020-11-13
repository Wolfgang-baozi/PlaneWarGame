// CPause.h : �����ļ�
//

#pragma once
#include "stdafx.h"
#include "GameObject.h"
#include "resource.h"
#include <mmsystem.h>

class CPause : public CGameObject
{
	enum Button { pause, back, continuebutton };
public:
	//����
	CPause(void);

	//����
	~CPause(void);

	//����ͼ��
	static BOOL LoadImage();

	//��ͼ
	BOOL Draw(CDC *pDC, BOOL bPause);

	//��þ��� -> ֹͣ
	CRect GetRectStop();

	//��þ��� -> ����
	CRect GetRectGo();

	//��þ��� -> ����
	CRect GetRect();

	//�Ƿ���ͣ
	void PauseButton(bool & bPause);

private:

	//ͼ������
	static CImageList m_Image[3];

	//λͼ
	//puase continue
	static const int BUTTON_WIDTH = 20;
	static const int BUTTON_HEIGHT = 20;
	//go back
	static const int BACK_WIDTH = 20;
	static const int BACK_HEIGHT = 20;

	//���ؼ�λ��
	CPoint			 m_ptBack;
};