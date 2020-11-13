//CFactorProp : 定义文件
//

#pragma once 

#include "stdafx.h"
#include "Factor.h"
#include "PropObject.h"
#include <cstring>
using namespace std;

class CFactorProp : public CFactor
{
public:
	CPropObject* Creat(int ID, int x = -1, int y = -1);
private:
	enum PropType { AddHP, UpGrade, Defense };
};