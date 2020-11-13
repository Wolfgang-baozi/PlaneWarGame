//CFactor : 定义文件
//

#pragma once 

#include "GameObject.h"
#include "stdafx.h"

#include <string>
using namespace std;

class CFactor
{
public:
	virtual CGameObject* Creat(int name, int x = -1, int y = -1) = 0;
};