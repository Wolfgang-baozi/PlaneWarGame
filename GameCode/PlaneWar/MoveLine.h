// CMoveLine.h : �����ļ�
//

#pragma once
#include "stdafx.h"
#include "resource.h"

class CMoveLine : public CObject
{
public:

	//����
	CMoveLine(void);

	//����
	~CMoveLine(void);
public:

	//�ƶ�
	void Move(CPoint& ptPos, int nHor, int nVer, int nV);

private:

};

