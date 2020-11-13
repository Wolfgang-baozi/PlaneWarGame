// CMoveLine.h : 定义文件
//

#pragma once
#include "stdafx.h"
#include "resource.h"

class CMoveLine : public CObject
{
public:

	//构造
	CMoveLine(void);

	//析构
	~CMoveLine(void);
public:

	//移动
	void Move(CPoint& ptPos, int nHor, int nVer, int nV);

private:

};

