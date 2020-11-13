//CFactorPlane : 定义文件
//

#pragma once 

#include "stdafx.h"
#include "Factor.h"
#include "EnemyObject.h"
#include "PlaneObject.h"
#include "FriendPlane.h"
#include <cstring>
using namespace std;

class CFactorPlane : public CFactor
{
public:
	CPlaneObject* Creat(int ID, int x = -1, int y = -1);
public:
	enum PlaneType {BossBase, BossMid, BossKing, 
					EnemyGreen, EnemyGrey, EnemyRed, EnemyYellow, friendplane };
};