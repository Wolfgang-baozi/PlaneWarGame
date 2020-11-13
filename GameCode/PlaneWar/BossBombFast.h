//ͣ��һ��
//ֱ�� �����ƶ�

#pragma once
#include "BombObject.h"
#include "Stdafx.h"
#include "resource.h"

class CBossBombFast : public CBombObject
{
public:
	//����
	CBossBombFast(int x, int y);

	//����
	~CBossBombFast(void);

	//��ͼ
	BOOL Draw(CDC* pDC,BOOL bPause);

	//����Ѿ�ͣ��ʱ��
	int GetWait() const;

	//����ͣ��ʱ��
	void AddWait();

	//�Ƿ��ƶ�
	BOOL IfMove();

	//��ȡ�ӵ�����
	int GetKingBomb() const;

	//�޸��ӵ�����
	void SetKindBomb(int nLevel);

	
	//�ƶ�
	BOOL Move();


	//��þ�������
	CRect GetRect()
	{
		return CRect(m_ptPos, CPoint(m_ptPos.x + BOSSBOMBFAST_WIDTH, m_ptPos.y + BOSSBOMBFAST_HEIGHT));
	}

	//����ͼ��
	static BOOL LoadImage();

private:

	//�ӵ�λͼ��С 20*35 
	//�����ӵ�һ����
	static const int BOSSBOMBFAST_WIDTH = 20;
	static const int BOSSBOMBFAST_HEIGHT = 25;

	//ͼ������
	static			 CImageList m_Images[3];

	//�ӵ��Ѿ�ͣ��ʱ��
	int				 m_nWait;

	//�ӵ���Ҫͣ��ʱ��
	static const int m_nNeedWait = 90;

	//�����ӵ����� 1 -> ��ɫ, 2 -> ��ɫ
	int				 m_nKindBomb;
};