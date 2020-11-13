// PlaneWarView.h : CPlaneWarView 类的接口
//

#pragma once
#include "GameObject.h"

//plane
#include "PlaneObject.h"
#include "FriendPlane.h"
#include "MyPlane.h"
//enemy
#include "EnemyObject.h"
#include "BossBase.h"
#include "BossMid.h"
#include "BossKing.h"
#include "EnemyGreen.h"
#include "EnemyGrey.h"
#include "EnemyRed.h"
#include "EnemyYellow.h"
//bomb
#include "BombObject.h"
#include "BombBase.h"
#include "BombUpMain.h"
#include "BombUpSub.h"
#include "BombPurple.h"
#include "BombRedPoint.h"
#include "Missile.h"
#include "BossBombFast.h"
//counter
#include "Counter.h"
//explosion
#include "Explosion.h"
//prop
#include "PropObject.h"
#include "AddHP.h"
#include "UpGrade.h"
#include "Defense.h"
//back
#include "Back.h"
//factor
#include "Factor.h"
#include "FactorBomb.h"
#include "FactorPlane.h"
#include "FactorProp.h"
//pause
#include "Pause.h"
//pattern
#include "NbPattern.h"
//process
#include "GameSta.h"
#include "GameEnd.h"
//GameGrade
#include "GameGrade.h"
//crash
#include "Crash.h"

class CPlaneWarView : public CView
{
	enum PlaneType { bombbase, bombupmain,  bombupsub, enemy, boss, enemybomb, explosion,  prop, friendplane  }; //8
	enum GameProcess { start, bosspattern, hell, help, end};
	enum BossStatus { unborn, born, death };
protected: 
	//仅从序列化创建
	//构造
	CPlaneWarView();
	//declare_dyn create -- 实时动态创建对象
	DECLARE_DYNCREATE(CPlaneWarView)

// 属性
public:
	
	CPlaneWarDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CPlaneWarView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

//对象
protected:
	
	CDC*			m_pMemDC; //内存DC
	
	CClientDC*		m_pDC; //设备DC
	
	CBitmap*		m_pMemBitmap; //内存位图
	
	CMyPlane*		m_pMe; //战机

	CPropObject*	m_pProp; //道具
	
	CBack*			m_pBack; //背景

	CCounter*		m_pCounter; //计分

	CCrash*			m_pCrash; //碰撞 
	
	CPause*			m_pPause; //暂停

	CNbPattern*		m_pNb; //无敌模式

	CGameSta*		m_pSta; //游戏开始界面

	CGameEnd*		m_pEnd; //游戏结束

	CGameGrade*		m_pUpGame; //关卡生成器
	
	CFactorBomb*	m_pFactorBomb;//工厂
	CFactorPlane*	m_pFactorPlane;
	CFactorProp*	m_pFactorProp;

	int				m_nProcess; //游戏进程
	int				m_nGamePattern; //游戏模式
	int				m_nGameLevel;//关卡
	int				m_nEnemyNum; //每关已出现敌机数量
	int				m_nBossStatus; //BOSS状态
	int				m_nWait; //产生敌机时间间隔
	int				m_nMaxEnemyNum;//每关最大敌机数
	int				m_nWaitButton; //按键缓冲
	int				m_nWaitProp; //产生道具的时间间隔
	
	
//游戏规则
protected:

	//暂停
	bool		m_bPause;
	//无敌模式
	bool		m_bNb;
	//僚机时间
	bool		m_bShe;
	//帮助
	bool		m_bHelp; 
	

	//游戏进程
	int		GetProcess() const;
	void	SetProcess(int nProcess);
	//关卡等级
	int		GetGameLevel() const;
	void	SetGameLevel(int nGameLevel);
	//暂停
	int		GetPause() const;
	//修改帮助标识
	void	SetHelp();
	//无敌
	BOOL	GetNb() const;
	void	SetNb();
	//按键关冲
	BOOL	IfButton();

	//规则
	void	AI(); //BOSS关卡
	void	PlaneMove();//飞机状态检测键盘 -> 飞机移动, 发射子弹, 无敌模式
	BOOL	MonitorCrash(); //检测碰撞,添加爆炸
	void	MakeProp(); //产生道具
	void	MakeEnemy(); //产生敌机
	void	MakeEnemyBomb();//产生敌机子弹
	void	MakeMyBomb(); //产生战机子弹
	void	MakeFriendBomb(); //产生僚机子弹
	void	UpdateLevel();//关卡升级
	void	SetBossStatus(int nStatus); //修改BOSS标识
	int		GetBossStatus(); //获得BOSS标识
	
	//检测鼠标点击
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);







protected:
	
protected:
	//初始化游戏
	BOOL InitGame();
	
	//初始化游戏数据
	void InitDate();

	//加载图片资源
	static void LoadImage();


	//结束游戏
	void OnDestroy();
	void StopOnGame();

	//重启游戏
	void ReStart();

	//刷新游戏进行的帧画面
	void UpdateGaming(CDC* pMemDC);

	

	//获得键的状态1->down
	int GetKey(int nVirtKey)
	{
		return (GetKeyState(nVirtKey) & 0x8000)? 1 : 0;
	}
	
	
	CObList    m_ObjList[9];



// 生成的消息映射函数
protected:

	DECLARE_MESSAGE_MAP()
public:
	virtual void OnInitialUpdate();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // PlaneWarView.cpp 中的调试版本
inline CPlaneWarDoc* CPlaneWarView::GetDocument() const
   { return reinterpret_cast<CPlaneWarDoc*>(m_pDocument); }
#endif

