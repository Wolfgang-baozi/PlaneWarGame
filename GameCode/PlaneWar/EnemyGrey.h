#pragma once
#include "EnemyObject.h"
#include "resource.h"

class CEnemyGrey : public CEnemyObject
{
public:

	//����
	CEnemyGrey();

	//����
	~CEnemyGrey();
public:

	//���ض���
	BOOL Draw(CDC* pDC, BOOL bPause);

	//��þ�������
	CRect GetRect();

	//�Ƿ����ӵ�
	BOOL Fired();
	
	//�ƶ�
	BOOL Move();

	//����ͼƬ
	static BOOL LoadImage();

protected:

	//����
	static CImageList m_Images;

	//�ɻ���С
	static const int ENEMYGREY_WIDTH = 70;
	static const int ENEMYGREY_HEIGHT = 35;

	//���� 1->���� 0->ֹͣ 
	int    m_nHorMotion;

	//���� 1->���� 0->ֹͣ -1->����
	int		m_nVerMotion;

	//ͼ������
	int m_nImgIndex;
};


