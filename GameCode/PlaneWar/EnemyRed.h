#pragma once
#include "EnemyObject.h"
#include "resource.h"

class CEnemyRed : public CEnemyObject
{
public:

	//����
	CEnemyRed();
	
	//����
	~CEnemyRed();

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
	static const int ENEMYRED_WIDTH = 75;
	static const int ENEMYRED_HEIGHT = 37;
	

	//���� 1->���� 0->ֹͣ 
	int    m_nHorMotion;

	//���� 1->���� 0->ֹͣ -1->����
	int		m_nVerMotion;

	//ͼ������
	int m_nImgIndex;
};

