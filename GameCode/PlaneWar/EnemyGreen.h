#pragma once
#include "EnemyObject.h"
#include "resource.h"

class CEnemyGreen : public CEnemyObject
{
public:

	//����
	CEnemyGreen();

	//����
	~CEnemyGreen();

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
	static const int ENEMYGREEN_WIDTH = 75;
	static const int ENEMYGREEN_HEIGHT = 37;
	

	//���� 1->���� 0->ֹͣ 
	int    m_nHorMotion;

	//���� 1->���� 0->ֹͣ -1->����
	int		m_nVerMotion;
};


