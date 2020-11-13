
#pragma once

#include "stdafx.h"
#include "PropObject.h"
#include "AddHP.h"
#include "UpGrade.h"
#include "Defense.h"
#include "FactorProp.h"
#include <string>
using namespace std;

CPropObject* CFactorProp::Creat(int ID, int x, int y)
{
	CPropObject* pProp = NULL;
	
	//AddHP
	if(ID == AddHP)
		pProp = new CAddHP();

	//UpGrade
	else if(ID == UpGrade)
		pProp = new CUpGrade();

	//Defense
	else if(ID == Defense)
		pProp = new CDefense();

	return pProp;
}