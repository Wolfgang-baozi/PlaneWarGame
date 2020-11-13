 #pragma once
#include "EnemyObject.h"
#include "resource.h"

class CBossKing :public CEnemyObject
{
public:
	//����
	CBossKing();

	//����
	~CBossKing();

public:
	//���ض���
	BOOL Draw(CDC* pDC, BOOL bPause);

	//��þ�������
	CRect GetRect();

	//�Ƿ񿪻�
	BOOL Fired();

	//�ƶ�
	void Move();

	//����ͼƬ
	static BOOL LoadImage();

protected:
	//����
	static CImageList m_Images;

	//�ɻ���С
	static const int BOSSKING_WIDTH = 150;
	static const int BOSSKING_HEIGHT = 90;
};

