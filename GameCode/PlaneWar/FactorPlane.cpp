

#include "stdafx.h"
#include "FactorPlane.h"
#include "EnemyObject.h"
#include "BossBase.h"
#include "BossMid.h"
#include "BossKing.h"
#include "EnemyGreen.h"
#include "EnemyGrey.h"
#include "EnemyRed.h"
#include "EnemyYellow.h"
#include "FriendPlane.h"
#include <string>
using namespace std;


CPlaneObject* CFactorPlane::Creat(int ID, int x, int y)
{
	CPlaneObject* pPlane = NULL;
	//BossBase
	if(ID == BossBase)
		pPlane = new CBossBase();
	
	//BossMid
	else if(ID == BossMid)
		pPlane = new CBossMid();
	
	//BoseKing
	else if(ID == BossKing)
		pPlane = new CBossKing();
	
	//EnemyGreen
	else if(ID == EnemyGreen)
		pPlane = new CEnemyGreen();
	
	//EnemyGrey
	else if(ID == EnemyGrey)
		pPlane = new CEnemyGrey();
	
	//EnemyRed
	else if(ID == EnemyRed)
		pPlane = new CEnemyRed();
	
	//EnemyYellow
	else if(ID == EnemyYellow)
		pPlane = new CEnemyYellow();

	//friendplane
	else if(ID == friendplane)
		pPlane = new CFriendPlane();

	return pPlane;
}