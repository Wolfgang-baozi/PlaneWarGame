//CFactorBomb : 定义文件
//

#pragma once 

#include "stdafx.h"
#include "Factor.h"
#include "BombObject.h"
#include <cstring>
using namespace std;

class CFactorBomb : public CFactor
{
public:
	CBombObject* Creat(int ID, int x = -1, int y = -1);
public:
	enum BombType { BombBase, BombUpMain,  BombUpSub, 
					BombPurple, BombRedPoint, Missile, BossBombFast};
};