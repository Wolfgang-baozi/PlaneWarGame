#pragma once
#include "EnemyObject.h"
#include "resource.h"

class CEnemyYellow : public CEnemyObject
{
public:
	//����
	CEnemyYellow(void);
	CEnemyYellow(int x, int y);

	//����
	~CEnemyYellow();
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
	static const int ENEMYYELLOW_WIDTH = 50;
	static const int ENEMYYELLOW_HEIGHT = 35;
	

	//��ֱ���� 1->���� 0->ֹͣ 
	int    m_nHorMotion;

	//ˮƽ���� 1->���� 0->ֹͣ -1->����
	int		m_nVerMotion;
};
