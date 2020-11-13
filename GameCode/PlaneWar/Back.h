//CBack.h : �����ļ�

#include "stdafx.h"
#include "GameObject.h"
#include <mmsystem.h>
#include "resource.h"

class CBack : public CGameObject
{
public:
	enum GamePattern { bosspattern1, bosspattern2, bosspattern3 };

	//����
	CBack(int x, int y);
	
	//����
	~CBack();
	
	//��ñ����ȼ�
	int GetGrade() const;

	//��������
	void SetGrade(int Grade);

	//��þ�������
	CRect GetRect();

	//����ͼ��
	static BOOL LoadImage();

	//��ͼ
	BOOL Draw(CDC* pDC, BOOL bPause);

private:
	
	//ͼ������
	static CImageList m_Images[3];

	//�ؿ�
	int m_nGrade;

};
