// CMove.cpp : ʵ���ļ�
//

#pragma once
#include "stdafx.h"
#include "MoveLine.h"
#include "resource.h"

//����
CMoveLine::CMoveLine()
{

}

//����
CMoveLine::~CMoveLine()
{

}

//�ƶ�
void CMoveLine::Move(CPoint& ptPos, int nHor, int nVer, int nV)
{
	ptPos.x = ptPos.x + nHor * nV;
	ptPos.y = ptPos.y + nVer * nV;
}

