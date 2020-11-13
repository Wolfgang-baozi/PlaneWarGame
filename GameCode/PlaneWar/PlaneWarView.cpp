// PlaneWarView.cpp : CPlaneWarView 类的实现
//

#include "stdafx.h"
#include "PlaneWar.h"
#include "PlaneWarDoc.h"
#include "PlaneWarView.h"

#include <atlimage.h>
#include <mmsystem.h>
#include <Windows.h>
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPlaneWarView
//与 declare_dyn create一起使用 使object派生类
//在运行时能实时动态创建对象 （派生类， 基类）
IMPLEMENT_DYNCREATE(CPlaneWarView, CView)

//?? 消息映射宏
BEGIN_MESSAGE_MAP(CPlaneWarView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_TIMER()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CPlaneWarView 构造/析构

CPlaneWarView::CPlaneWarView()
{
	// TODO: 在此处添加构造代码
	m_pMe = NULL;
	m_pBack = NULL;
	m_pMemDC = NULL;
	m_pDC = NULL;
	m_pMemBitmap = NULL;
	m_pMe = NULL;
	m_pBack = NULL;
	m_pCounter = NULL;
	m_pPause = NULL;
	m_pNb = NULL;
	m_pSta = NULL;
	m_pCrash = NULL;
	m_pProp = NULL;
	m_pEnd = NULL;
}

CPlaneWarView::~CPlaneWarView()
{

}

BOOL CPlaneWarView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CPlaneWarView 绘制

void CPlaneWarView::OnDraw(CDC* /*pDC*/)
{
	CPlaneWarDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CPlaneWarView 打印

BOOL CPlaneWarView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CPlaneWarView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CPlaneWarView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CPlaneWarView 诊断

#ifdef _DEBUG
void CPlaneWarView::AssertValid() const
{
	CView::AssertValid();
}

void CPlaneWarView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPlaneWarDoc* CPlaneWarView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPlaneWarDoc)));
	return (CPlaneWarDoc*)m_pDocument;
}
#endif //_DEBUG


// CPlaneWarView 消息处理程序
void CPlaneWarView::OnInitialUpdate()
{
	CView::OnInitialUpdate();
	// TODO: 在此添加专用代码和/或调用基类
	
	
	
	//初始化游戏
	InitGame();
	//加载图片
	CPlaneWarView::LoadImage();
}


void CPlaneWarView::OnDestroy()
{
	CView::OnDestroy();
	StopOnGame();
	// TODO: 在此处添加消息处理程序代码
}

//结束
void CPlaneWarView::StopOnGame()
{
	delete m_pMe;
	delete m_pMemDC;
	delete m_pDC;
	delete m_pMemBitmap;
	delete m_pBack;
	delete m_pCounter;
	delete m_pPause;
	delete m_pNb;
	delete m_pSta;
	delete m_pCrash;
	delete m_pUpGame;
	delete m_pProp;
	delete m_pEnd;
}

//加载图片资源
void CPlaneWarView::LoadImage()
{
	//process
	CGameSta::LoadImage();
	CGameEnd::LoadImage();
	//counter
	CCounter::LoadImage();
	//explosion
	CExplosion::LoadImage();
	//prop
	CAddHP::LoadImage();
	CDefense::LoadImage(); 
	CUpGrade::LoadImage();
	//bomb
	CBombRedPoint::LoadImage();
	//CBombPurple::LoadImage();
	CMissile::LoadImage();
	CBossBombFast::LoadImage();
	CBombPurple::LoadImage();
	CBombBase::LoadImage();
	CBombUpMain::LoadImage();
	CBombUpSub::LoadImage();
	//plane
	CMyPlane::LoadImage();
	CFriendPlane::LoadImage();
	CBossBase::LoadImage();
	CBossMid::LoadImage();
	CBossKing::LoadImage();
	CEnemyYellow::LoadImage();
	CEnemyGreen::LoadImage();
	CEnemyGrey::LoadImage();
	CEnemyRed::LoadImage();
	//back
	CBack::LoadImage();
	//pause
	CPause::LoadImage();
	//pattern
	CNbPattern::LoadImage();
}
//初始化游戏数据
void CPlaneWarView::InitDate()
{
	m_nGameLevel = 1;
	m_nProcess = start; //设置游戏进程
	m_nGamePattern = bosspattern; //默认游戏模式
	m_pBack->SetGrade(rand()%3); //随机选择关卡背景
	m_nWait = 40; //产生敌机的时间间隔
	m_nEnemyNum = 0; //每关已经产生敌机数
	m_nMaxEnemyNum = 15; //每关最大敌机数
	m_bPause = FALSE; //暂停
	m_bNb = FALSE; //无敌模式
	m_bShe = FALSE; //僚机
	m_nBossStatus = unborn; //BOSS状态
	m_nWaitButton = 0; //按键缓冲
	m_nWaitProp = 0;
	m_bHelp = FALSE; //帮助
}

//初始化游戏
BOOL CPlaneWarView::InitGame()
{
	CRect rc;

	GetClientRect(rc);

	//产生随机数种子
	srand( (unsigned)time( NULL ) );

	//建立设备DC
	m_pDC = new CClientDC(this);

	//建立内存DC
	m_pMemDC = new CDC;
	m_pMemDC->CreateCompatibleDC(m_pDC);

	//建立内存位图
	m_pMemBitmap = new CBitmap;
	m_pMemBitmap -> CreateCompatibleBitmap(m_pDC, GAME_WIDTH, GAME_HEIGHT);

	//将位图选入内存DC
	m_pMemDC -> SelectObject( m_pMemBitmap );

	//工厂
	m_pFactorBomb = new CFactorBomb();
	m_pFactorPlane = new CFactorPlane();
	m_pFactorProp = new CFactorProp();

	//产生游戏对象
	m_pMe = new CMyPlane();
	m_pBack = new CBack(0, 0);
	m_pCounter = new CCounter();
	m_pPause = new CPause();
	m_pNb = new CNbPattern();
	m_pSta = new CGameSta();
	m_pCrash = new CCrash();
	m_pUpGame = new CGameGrade();
	m_pEnd = new CGameEnd();

	//初始化数据
	InitDate();

	//启动游戏
	SetTimer(1, 30, NULL);

	return TRUE;
}



//绘图
void CPlaneWarView::UpdateGaming(CDC* pMemDC)
{
	//绘制背景
	m_pBack->Draw(pMemDC, m_bPause);

	//绘制子弹  敌机 爆炸效果 道具
	for (int i = bombbase; i <= friendplane; ++i)
	{
		POSITION pos, pos1;
		for (pos = m_ObjList[i].GetHeadPosition(); (pos1 = pos) != NULL; )
		{
			CGameObject* pa = (CGameObject*)m_ObjList[i].GetNext(pos);
			if (!pa->Draw(m_pMemDC, m_bPause))
			{
				m_ObjList[i].RemoveAt(pos1);
				delete pa;
			}
		}
	}

	//绘制分数
	m_pCounter->Draw(m_pMemDC, m_bPause);

	//绘制button
	m_pPause->Draw(m_pMemDC, m_bPause); //暂停
	m_pNb->Draw(m_pMemDC, m_bNb); //无敌

	//画飞机 血条
	if(m_pMe != NULL)
		m_pMe->Draw(m_pMemDC, m_bPause);
}

//规则

//产生敌机子弹
void CPlaneWarView::MakeMyBomb()
{
	//飞机位置
	CPoint pPos = m_pMe->GetPoint();

	//获得发射位置
	CPoint pBombPos[4] = {(0, 0)};
	for(int i = 0; i < 4; ++i)
	{
		pBombPos[i] = m_pMe->GetBombPos(i+1);
	}

	//添加子弹
	switch(m_pMe->GetGrade())
		{
			case 1:
				for(int i=1; i<3; ++i)
				{
					m_ObjList[bombbase].AddTail(m_pFactorBomb->Creat(bombbase, pBombPos[i].x, pBombPos[i].y));
				}
				break;
			case 2:
				for(int i=0; i<4; ++i)
				{	
					m_ObjList[bombbase].AddTail(m_pFactorBomb->Creat(bombbase, pBombPos[i].x, pBombPos[i].y));
				}
				break;
			case 3:
				//副武器
				for(int i=0; i<4; i += 3)
				{
					m_ObjList[bombupsub].AddTail(m_pFactorBomb->Creat(bombupsub, pBombPos[i].x, pBombPos[i].y));
				}
				//主武器
				for(int i=1; i<3; ++i)
				{	
					m_ObjList[bombupmain].AddTail(m_pFactorBomb->Creat(bombupmain, pBombPos[i].x, pBombPos[i].y));
				}
				break;
		}
}

//按键缓冲
BOOL CPlaneWarView::IfButton()
{
	if(m_nWaitButton == 0)
		return TRUE;
	else
		return FALSE;
}

//飞机状态检测键盘 -> 飞机移动, 发射子弹, 无敌模式
void CPlaneWarView::PlaneMove()
{
	// TODO: 在此处添加实现代码.
	
	//按键缓冲
	m_nWaitButton++;
	if(m_nWaitButton >= 3)
		m_nWaitButton = 0;

	//根据战机等级添加子弹
	if (GetKeyState(VK_SPACE) < 0 && m_pMe->IfFired())
	{
		MakeMyBomb();
	}
	//左
	if (GetKeyState(VK_LEFT) < 0) 
	{
		m_pMe->SetHorMotion(-1);
		if(GetProcess() == hell)
			m_pMe->SetHorMotion(1);
	}
	//右
	if (GetKeyState(VK_RIGHT) < 0) 
	{
		m_pMe->SetHorMotion(1);
		if(GetProcess() == hell)
			m_pMe->SetHorMotion(-1);
	}
	//上
	if (GetKeyState(VK_UP) < 0) 
	{
		m_pMe->SetVerMotion(-1);
	}
	//下
	if (GetKeyState(VK_DOWN) < 0) 
	{
		m_pMe->SetVerMotion(1);
	}
	if (GetKeyState('B') < 0 && IfButton()) 
	{
		SetNb();
	}
}

//获得游戏进程
int	CPlaneWarView::GetProcess() const
{
	return this->m_nProcess;
}

//更新游戏进程
void CPlaneWarView::SetProcess(int nProcess)
{
	this->m_nProcess = nProcess;
}

//获得选择关卡
int CPlaneWarView::GetGameLevel() const
{
	return this->m_nGameLevel;
}

//修改关卡
void CPlaneWarView::SetGameLevel(int nGameLevel)
{
	this->m_nGameLevel = nGameLevel;
}

//获得暂停标识
int	CPlaneWarView::GetPause() const
{
	return this->m_bPause;
}

//获得无敌模式标识
BOOL CPlaneWarView::GetNb() const
{
	return this->m_bNb;
}
//修改无敌模式标识
void CPlaneWarView::SetNb()
{
	this->m_bNb = !this->m_bNb;
}
//修改帮助标识
void CPlaneWarView::SetHelp()
{
	this->m_bHelp = !this->m_bHelp;
}

//检测碰撞
BOOL CPlaneWarView::MonitorCrash()
{
	//敌机和我方子弹
	for (int i = bombbase; i <= bombupsub; ++i)
	{
		//敌机
		m_pCrash->MyBomb_Enemy(m_ObjList[enemy], m_ObjList[i], m_ObjList[explosion], m_pCounter, m_nBossStatus, enemy);
		//BOSS
		m_pCrash->MyBomb_Enemy(m_ObjList[boss], m_ObjList[i], m_ObjList[explosion], m_pCounter, m_nBossStatus, boss);
	}

	//敌机和战机
	if( !m_pCrash->MyPlane_Enemy(m_ObjList[enemy], m_pMe, m_ObjList[explosion], m_pCounter, GetNb() ) )
		return FALSE;

	//战机和敌方子弹
	if( !m_pCrash->MyPlane_EnBomb(m_ObjList[enemybomb], m_pMe, m_ObjList[explosion], GetNb() ) )
		return FALSE;

	//道具和战机
	if(m_pCrash->MyPlane_Prop( m_ObjList[prop], m_pMe))
		m_ObjList[friendplane].AddTail(m_pFactorPlane->Creat(7, m_pMe->m_ptPos.x, m_pMe->m_ptPos.y) );

	return TRUE;
}

//产生敌机
void CPlaneWarView::MakeEnemy()
{
	if ( m_nWait < 0 && m_nEnemyNum <= m_nMaxEnemyNum ) 
	{
		m_nWait = rand() % 40 + 8;
		m_ObjList[enemy].AddTail(m_pFactorPlane->Creat(rand() % 4 + 3) );
		m_nEnemyNum++;
	}
	//产生BOSS
	if(m_nEnemyNum > m_nMaxEnemyNum)
	{
		m_nEnemyNum = 0;
		if(GetBossStatus() == unborn)
		{
			m_ObjList[boss].AddTail(m_pFactorPlane->Creat(rand() % 3) );
			SetBossStatus(born);
		}
	}
	m_nWait--;
}

//产生敌机子弹
void CPlaneWarView::MakeEnemyBomb()
{
	//声明子弹种类
	int nBombKind;
	
	//获得战机区域
	CPoint ptMe = m_pMe->GetPoint();

	//遍历所有敌机,再其位置添加子弹
	POSITION pos;
	for (int i = enemy; i <= boss; ++i)
	{
		for (pos = m_ObjList[i].GetHeadPosition(); pos != NULL; )
		{
			//获得敌机对象
			CEnemyObject* pe = (CEnemyObject*)m_ObjList[i].GetNext(pos);

			//敌机可以开火时,添加子弹
			if (pe->Fired())
			{
				//boss比敌机多两种子弹
				if(i == enemy)
				{
					nBombKind = rand() % 3 + 3;
					m_ObjList[enemybomb].AddTail(m_pFactorBomb->Creat(nBombKind, (pe->GetRect().left + pe->GetRect().right) / 2 - 10, pe->GetRect().bottom + 5));
				}
				if(i == boss)
				{
					nBombKind = rand() % 4 + 3;
					//特殊子弹, 降低概率,每次4发
					if(nBombKind == 6 && rand() % 2 == 0)
					{
						int nXDis = (pe->GetRect().left + pe->GetRect().right) / 10;
						CPoint ptBoss( pe->GetRect().left, pe->GetRect().bottom + 5);
						for(int i = 0; i < 4; ++i)
						{
							m_ObjList[enemybomb].AddTail(m_pFactorBomb->Creat(nBombKind, ptBoss.x, ptBoss.y) );
							ptBoss.x = ptBoss.x + nXDis;
						}
					}
					//普通子弹,一次一发
					else if( nBombKind <= 5 )
						m_ObjList[enemybomb].AddTail(m_pFactorBomb->Creat(nBombKind, (pe->GetRect().left + pe->GetRect().right) / 2 - 10, pe->GetRect().bottom + 5));
				}
				
				
			}
		}
	}
}

//产生僚机子弹
void CPlaneWarView::MakeFriendBomb()
{
	
	POSITION pos;
	for (pos = m_ObjList[friendplane].GetHeadPosition(); pos != NULL; )
	{
		//获得僚机对象
		CFriendPlane* pe = (CFriendPlane*)m_ObjList[friendplane].GetNext(pos);
		
		//飞机位置
		CPoint pPos = pe->GetPoint();
		
		//获得发射位置
		CPoint pBombPos[4] = {(0, 0)};
		for(int i = 0; i < 4; ++i)
		{
			pBombPos[i] = pe->GetBombPos(i+1);
		}

		//僚机可以开火时,添加子弹
		if (pe->IfFired())
		{
			for(int i=0; i<4; ++i)
			{	
				m_ObjList[bombbase].AddTail(m_pFactorBomb->Creat(bombbase, pBombPos[i].x, pBombPos[i].y));
			}
		}
	}
}

//获得BOSS标识
int CPlaneWarView::GetBossStatus()
{
	return this->m_nBossStatus;
}

//修改BOSS标识
void CPlaneWarView::SetBossStatus(int nStatus)
{
	m_nBossStatus = nStatus;
}

//升级关卡
void CPlaneWarView::UpdateLevel()
{
	//游戏关卡
	SetGameLevel(GetGameLevel() + 1);

	//升级背景
	int ans = m_pBack->GetGrade();
	while (m_pBack->GetGrade() == ans) 
	{
		//保证背景不重复
		m_pBack->SetGrade(rand() % 3);
	}

	//BOSS标识
	SetBossStatus(unborn);

	//关卡升级
	int nGameLevel =  GetGameLevel();

	//升级敌机数
	m_pUpGame->UpDate(m_nMaxEnemyNum, nGameLevel);

}

//产生道具
void CPlaneWarView::MakeProp()
{
	//冷却时间
	m_nWaitProp++;
	if(m_nWaitProp >= rand() % 300 + 500)
		m_nWaitProp = 0;

	//随机生成道具
	if(m_nWaitProp == 0)
		m_ObjList[prop].AddTail( m_pFactorProp->Creat(rand() % 3) );

}

//BOSS关卡
void CPlaneWarView::AI()
{

	//是否暂停
	if (m_bPause) return;

	//添加子弹
	MakeEnemyBomb();
	MakeFriendBomb();

	//产生道具
	MakeProp();

	//战机存活时的操作
	if (m_pMe->GetNowHP() > 0)
	{
		//产生敌机
		MakeEnemy();

		//监测按键
		PlaneMove();

		//碰撞检测,战机死亡 游戏结束
		if(!MonitorCrash())
			SetProcess(end);

		//关卡升级 添加boss判断
		if( GetBossStatus() == death )
			UpdateLevel();		
	}
	else 
		SetProcess(end);
}

//重启游戏
void CPlaneWarView::ReStart()
{
	for (int i = 0; i < 9; i++)
				{
					POSITION pos, pos1;
					for (pos = m_ObjList[i].GetHeadPosition(); (pos1 = pos) != NULL; ) {
						CGameObject * pa = (CGameObject *)m_ObjList[i].GetNext(pos);
						m_ObjList[i].RemoveAt(pos1);
						delete pa;
					}
				}
	StopOnGame();
	InitGame();
}

//游戏进程
void CPlaneWarView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	int nProcess = GetProcess();
	if(nProcess == start || nProcess == help)
	{
		//BOSS模式
		CRect rect = m_pSta->GetRectStart();
		if(point.x > rect.left && point.x < rect.right && point.y > rect.top  && point.y < rect.bottom)
		{
			SetProcess(bosspattern);
		}
		//困难模式
		rect = m_pSta->GetRectHell();
		if(point.x > rect.left && point.x < rect.right && point.y > rect.top  && point.y < rect.bottom)
		{
			SetProcess(hell);
		}
		//帮助
		rect = m_pSta->GetRectHelp();
		if(point.x > rect.left && point.x < rect.right && point.y > rect.top  && point.y < rect.bottom)
		{
			SetHelp();
			SetProcess(help);
		}
	}
	if(nProcess == bosspattern || nProcess == hell || nProcess == end)
	{
		//点击暂停按钮
		CRect rect = m_pPause->GetRectStop();
		if(point.x > rect.left && point.x < rect.right && point.y > rect.top  && point.y < rect.bottom)
		{
			m_pPause->PauseButton(m_bPause);
			m_pMe->SetHorMotion(0);
			m_pMe->SetVerMotion(0);
		}
		//返回主界面
		rect = m_pPause->GetRect();
		if(point.x > rect.left && point.x < rect.right && point.y > rect.top  && point.y < rect.bottom)
		{
			ReStart();
			SetProcess(start);
		}
		//无敌模式
		rect = m_pNb->GetRect();
		if(point.x > rect.left && point.x < rect.right && point.y > rect.top  && point.y < rect.bottom)
		{
			if(!m_pPause)
			{
				SetNb();
			}
		}
		//END 鼠标点击任意地方返回
		rect = m_pBack->GetRect();
		if(point.x > rect.left && point.x < rect.right && point.y > rect.top  && point.y < rect.bottom)
		{
			if(nProcess == end)
			{
				ReStart();
				SetProcess(start);
			}
		}
	}

	CView::OnLButtonUp(nFlags, point);
}

void CPlaneWarView::OnTimer(UINT_PTR nIDEvent)
{
	//开始界面
	if(GetProcess() == start || GetProcess() == help)
	{
		m_pSta->Draw(m_pMemDC, m_bHelp);
	}
	//游戏中
	if(GetProcess() == bosspattern || GetProcess() == end || GetProcess() == hell)
	{
		AI();
		UpdateGaming(m_pMemDC);
		//游戏结束
		if(GetProcess() == end)
		{
			m_pEnd->Draw(m_pMemDC, FALSE);
		}
	}
	m_pDC->BitBlt(0, 0, GAME_WIDTH, GAME_HEIGHT, m_pMemDC, 0, 0, SRCCOPY);
	CView::OnTimer(nIDEvent);
}