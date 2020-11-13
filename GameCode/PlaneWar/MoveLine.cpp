// CMove.cpp : 实现文件
//

#pragma once
#include "stdafx.h"
#include "MoveLine.h"
#include "resource.h"

//构造
CMoveLine::CMoveLine()
{

}

//析构
CMoveLine::~CMoveLine()
{

}

//移动
void CMoveLine::Move(CPoint& ptPos, int nHor, int nVer, int nV)
{
	ptPos.x = ptPos.x + nHor * nV;
	ptPos.y = ptPos.y + nVer * nV;
}

