#pragma once

#include "MyPlane.h"

class CFriendPlane :public CPlaneObject
{
public:
	//����
	CFriendPlane();

	//����
	~CFriendPlane(void);

	//��÷���λ��
	CPoint GetBombPos(int nPos) const;

	//��ͼ
	BOOL Draw(CDC* pDC,BOOL bPause);

	//����ͼƬ
	static BOOL LoadImage();

	//�ƶ�
	void Move();


	//��þ���
	CRect GetRect()
	{
		return CRect(m_ptPos,CPoint(m_ptPos.x+PLANE_WIDTH,m_ptPos.y+PLANE_HEIGHT));
	}

	//�Ƿ����ӵ�
	BOOL IfFired();

	//�������ʱ��
	int GetLifeTime() const;

	//�޸�����ʱ��
	int SetLifeTime(int LifeTime);
	
public:
	//λͼ 119*170
	static const int PLANE_WIDTH = 59;
	static const int PLANE_HEIGHT = 80;
private:

	//����λͼ����
	static CImageList m_Images;

	//�ɻ��ȼ�
	int m_nLevel;

	//�Ż�����ʱ��
	int m_nLifeTime;
};
