#pragma once

#include "stdAfx.h"
#include "EnemyObject.h"
#include "resource.h"

class CBossBase : public CEnemyObject
{
public:
	//����
	CBossBase();

	//����
	~CBossBase();

public:

	//��þ�������
	CRect GetRect();

	//�Ƿ񿪻�
	BOOL Fired();

	//����ͼƬ
	static BOOL LoadImage();

	//�ƶ�
	void Move();

	//���ض���
	BOOL Draw(CDC* pDC, BOOL bPause);

protected:
	//����
	static CImageList m_Images;

	//�ɻ���С
	static const int BOSSBASE_WIDTH = 150;
	static const int BOSSBASE_HEIGHT = 90;

};

