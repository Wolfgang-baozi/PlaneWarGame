#pragma once
#include "EnemyObject.h"
#include "resource.h"

class CBossMid : public CEnemyObject
{
public:
	//����
	CBossMid(void);

	//����
	~CBossMid(void);

public:

	//��þ�������
	CRect GetRect();

	//�Ƿ񿪻�
	BOOL Fired();

	//�ƶ�
	void Move();

	//����ͼƬ
	static BOOL LoadImage();

	//���ض���
	BOOL Draw(CDC* pDC, BOOL bPause);

protected:
	//����
	static CImageList m_Images;

	//�ɻ���С
	static const int BOSSMID_WIDTH = 150;
	static const int BOSSMID_HEIGHT = 90;


};
