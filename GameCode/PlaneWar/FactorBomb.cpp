//FactorBomb.cpp : 实现文件
//

#include "stdafx.h"
#include "FactorBomb.h"
#include "BombObject.h"

#include "BombBase.h"
#include "BombUpMain.h"
#include "BombUpSub.h"

#include "BombPurple.h"
#include "BombRedPoint.h"
#include "BossBombFast.h"
#include "Missile.h"

#include <string>
using namespace std;


CBombObject* CFactorBomb::Creat(int ID, int x, int y)
{
	CBombObject* pBomb = NULL;
	//BombBase
	if(ID == BombBase)
		pBomb = new CBombBase(x, y);
	
	//BombUpMain
	else if(ID == BombUpMain)
		pBomb = new CBombUpMain(x, y);
	
	//BombUpSub
	else if(ID == BombUpSub)
		pBomb = new CBombUpSub(x, y);
	
	//BombPurple
	else if(ID == BombPurple)
		pBomb = new CBombPurple(x, y);
	
	//BombRedPoint
	else if(ID == BombRedPoint)
		pBomb = new CBombRedPoint(x, y);
	
	//Missile
	else if (ID == Missile)
		pBomb = new CMissile(x, y);

	//BossBombFast
	else if(ID == BossBombFast)
		pBomb = new CBossBombFast(x, y);
	

	return pBomb;
}