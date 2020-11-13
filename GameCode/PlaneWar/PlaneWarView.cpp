// PlaneWarView.cpp : CPlaneWarView ���ʵ��
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
//�� declare_dyn createһ��ʹ�� ʹobject������
//������ʱ��ʵʱ��̬�������� �������࣬ ���ࣩ
IMPLEMENT_DYNCREATE(CPlaneWarView, CView)

//?? ��Ϣӳ���
BEGIN_MESSAGE_MAP(CPlaneWarView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_TIMER()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CPlaneWarView ����/����

CPlaneWarView::CPlaneWarView()
{
	// TODO: �ڴ˴���ӹ������
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
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CPlaneWarView ����

void CPlaneWarView::OnDraw(CDC* /*pDC*/)
{
	CPlaneWarDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CPlaneWarView ��ӡ

BOOL CPlaneWarView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CPlaneWarView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CPlaneWarView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// CPlaneWarView ���

#ifdef _DEBUG
void CPlaneWarView::AssertValid() const
{
	CView::AssertValid();
}

void CPlaneWarView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPlaneWarDoc* CPlaneWarView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPlaneWarDoc)));
	return (CPlaneWarDoc*)m_pDocument;
}
#endif //_DEBUG


// CPlaneWarView ��Ϣ�������
void CPlaneWarView::OnInitialUpdate()
{
	CView::OnInitialUpdate();
	// TODO: �ڴ����ר�ô����/����û���
	
	
	
	//��ʼ����Ϸ
	InitGame();
	//����ͼƬ
	CPlaneWarView::LoadImage();
}


void CPlaneWarView::OnDestroy()
{
	CView::OnDestroy();
	StopOnGame();
	// TODO: �ڴ˴������Ϣ����������
}

//����
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

//����ͼƬ��Դ
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
//��ʼ����Ϸ����
void CPlaneWarView::InitDate()
{
	m_nGameLevel = 1;
	m_nProcess = start; //������Ϸ����
	m_nGamePattern = bosspattern; //Ĭ����Ϸģʽ
	m_pBack->SetGrade(rand()%3); //���ѡ��ؿ�����
	m_nWait = 40; //�����л���ʱ����
	m_nEnemyNum = 0; //ÿ���Ѿ������л���
	m_nMaxEnemyNum = 15; //ÿ�����л���
	m_bPause = FALSE; //��ͣ
	m_bNb = FALSE; //�޵�ģʽ
	m_bShe = FALSE; //�Ż�
	m_nBossStatus = unborn; //BOSS״̬
	m_nWaitButton = 0; //��������
	m_nWaitProp = 0;
	m_bHelp = FALSE; //����
}

//��ʼ����Ϸ
BOOL CPlaneWarView::InitGame()
{
	CRect rc;

	GetClientRect(rc);

	//�������������
	srand( (unsigned)time( NULL ) );

	//�����豸DC
	m_pDC = new CClientDC(this);

	//�����ڴ�DC
	m_pMemDC = new CDC;
	m_pMemDC->CreateCompatibleDC(m_pDC);

	//�����ڴ�λͼ
	m_pMemBitmap = new CBitmap;
	m_pMemBitmap -> CreateCompatibleBitmap(m_pDC, GAME_WIDTH, GAME_HEIGHT);

	//��λͼѡ���ڴ�DC
	m_pMemDC -> SelectObject( m_pMemBitmap );

	//����
	m_pFactorBomb = new CFactorBomb();
	m_pFactorPlane = new CFactorPlane();
	m_pFactorProp = new CFactorProp();

	//������Ϸ����
	m_pMe = new CMyPlane();
	m_pBack = new CBack(0, 0);
	m_pCounter = new CCounter();
	m_pPause = new CPause();
	m_pNb = new CNbPattern();
	m_pSta = new CGameSta();
	m_pCrash = new CCrash();
	m_pUpGame = new CGameGrade();
	m_pEnd = new CGameEnd();

	//��ʼ������
	InitDate();

	//������Ϸ
	SetTimer(1, 30, NULL);

	return TRUE;
}



//��ͼ
void CPlaneWarView::UpdateGaming(CDC* pMemDC)
{
	//���Ʊ���
	m_pBack->Draw(pMemDC, m_bPause);

	//�����ӵ�  �л� ��ըЧ�� ����
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

	//���Ʒ���
	m_pCounter->Draw(m_pMemDC, m_bPause);

	//����button
	m_pPause->Draw(m_pMemDC, m_bPause); //��ͣ
	m_pNb->Draw(m_pMemDC, m_bNb); //�޵�

	//���ɻ� Ѫ��
	if(m_pMe != NULL)
		m_pMe->Draw(m_pMemDC, m_bPause);
}

//����

//�����л��ӵ�
void CPlaneWarView::MakeMyBomb()
{
	//�ɻ�λ��
	CPoint pPos = m_pMe->GetPoint();

	//��÷���λ��
	CPoint pBombPos[4] = {(0, 0)};
	for(int i = 0; i < 4; ++i)
	{
		pBombPos[i] = m_pMe->GetBombPos(i+1);
	}

	//����ӵ�
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
				//������
				for(int i=0; i<4; i += 3)
				{
					m_ObjList[bombupsub].AddTail(m_pFactorBomb->Creat(bombupsub, pBombPos[i].x, pBombPos[i].y));
				}
				//������
				for(int i=1; i<3; ++i)
				{	
					m_ObjList[bombupmain].AddTail(m_pFactorBomb->Creat(bombupmain, pBombPos[i].x, pBombPos[i].y));
				}
				break;
		}
}

//��������
BOOL CPlaneWarView::IfButton()
{
	if(m_nWaitButton == 0)
		return TRUE;
	else
		return FALSE;
}

//�ɻ�״̬������ -> �ɻ��ƶ�, �����ӵ�, �޵�ģʽ
void CPlaneWarView::PlaneMove()
{
	// TODO: �ڴ˴����ʵ�ִ���.
	
	//��������
	m_nWaitButton++;
	if(m_nWaitButton >= 3)
		m_nWaitButton = 0;

	//����ս���ȼ�����ӵ�
	if (GetKeyState(VK_SPACE) < 0 && m_pMe->IfFired())
	{
		MakeMyBomb();
	}
	//��
	if (GetKeyState(VK_LEFT) < 0) 
	{
		m_pMe->SetHorMotion(-1);
		if(GetProcess() == hell)
			m_pMe->SetHorMotion(1);
	}
	//��
	if (GetKeyState(VK_RIGHT) < 0) 
	{
		m_pMe->SetHorMotion(1);
		if(GetProcess() == hell)
			m_pMe->SetHorMotion(-1);
	}
	//��
	if (GetKeyState(VK_UP) < 0) 
	{
		m_pMe->SetVerMotion(-1);
	}
	//��
	if (GetKeyState(VK_DOWN) < 0) 
	{
		m_pMe->SetVerMotion(1);
	}
	if (GetKeyState('B') < 0 && IfButton()) 
	{
		SetNb();
	}
}

//�����Ϸ����
int	CPlaneWarView::GetProcess() const
{
	return this->m_nProcess;
}

//������Ϸ����
void CPlaneWarView::SetProcess(int nProcess)
{
	this->m_nProcess = nProcess;
}

//���ѡ��ؿ�
int CPlaneWarView::GetGameLevel() const
{
	return this->m_nGameLevel;
}

//�޸Ĺؿ�
void CPlaneWarView::SetGameLevel(int nGameLevel)
{
	this->m_nGameLevel = nGameLevel;
}

//�����ͣ��ʶ
int	CPlaneWarView::GetPause() const
{
	return this->m_bPause;
}

//����޵�ģʽ��ʶ
BOOL CPlaneWarView::GetNb() const
{
	return this->m_bNb;
}
//�޸��޵�ģʽ��ʶ
void CPlaneWarView::SetNb()
{
	this->m_bNb = !this->m_bNb;
}
//�޸İ�����ʶ
void CPlaneWarView::SetHelp()
{
	this->m_bHelp = !this->m_bHelp;
}

//�����ײ
BOOL CPlaneWarView::MonitorCrash()
{
	//�л����ҷ��ӵ�
	for (int i = bombbase; i <= bombupsub; ++i)
	{
		//�л�
		m_pCrash->MyBomb_Enemy(m_ObjList[enemy], m_ObjList[i], m_ObjList[explosion], m_pCounter, m_nBossStatus, enemy);
		//BOSS
		m_pCrash->MyBomb_Enemy(m_ObjList[boss], m_ObjList[i], m_ObjList[explosion], m_pCounter, m_nBossStatus, boss);
	}

	//�л���ս��
	if( !m_pCrash->MyPlane_Enemy(m_ObjList[enemy], m_pMe, m_ObjList[explosion], m_pCounter, GetNb() ) )
		return FALSE;

	//ս���͵з��ӵ�
	if( !m_pCrash->MyPlane_EnBomb(m_ObjList[enemybomb], m_pMe, m_ObjList[explosion], GetNb() ) )
		return FALSE;

	//���ߺ�ս��
	if(m_pCrash->MyPlane_Prop( m_ObjList[prop], m_pMe))
		m_ObjList[friendplane].AddTail(m_pFactorPlane->Creat(7, m_pMe->m_ptPos.x, m_pMe->m_ptPos.y) );

	return TRUE;
}

//�����л�
void CPlaneWarView::MakeEnemy()
{
	if ( m_nWait < 0 && m_nEnemyNum <= m_nMaxEnemyNum ) 
	{
		m_nWait = rand() % 40 + 8;
		m_ObjList[enemy].AddTail(m_pFactorPlane->Creat(rand() % 4 + 3) );
		m_nEnemyNum++;
	}
	//����BOSS
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

//�����л��ӵ�
void CPlaneWarView::MakeEnemyBomb()
{
	//�����ӵ�����
	int nBombKind;
	
	//���ս������
	CPoint ptMe = m_pMe->GetPoint();

	//�������ел�,����λ������ӵ�
	POSITION pos;
	for (int i = enemy; i <= boss; ++i)
	{
		for (pos = m_ObjList[i].GetHeadPosition(); pos != NULL; )
		{
			//��õл�����
			CEnemyObject* pe = (CEnemyObject*)m_ObjList[i].GetNext(pos);

			//�л����Կ���ʱ,����ӵ�
			if (pe->Fired())
			{
				//boss�ȵл��������ӵ�
				if(i == enemy)
				{
					nBombKind = rand() % 3 + 3;
					m_ObjList[enemybomb].AddTail(m_pFactorBomb->Creat(nBombKind, (pe->GetRect().left + pe->GetRect().right) / 2 - 10, pe->GetRect().bottom + 5));
				}
				if(i == boss)
				{
					nBombKind = rand() % 4 + 3;
					//�����ӵ�, ���͸���,ÿ��4��
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
					//��ͨ�ӵ�,һ��һ��
					else if( nBombKind <= 5 )
						m_ObjList[enemybomb].AddTail(m_pFactorBomb->Creat(nBombKind, (pe->GetRect().left + pe->GetRect().right) / 2 - 10, pe->GetRect().bottom + 5));
				}
				
				
			}
		}
	}
}

//�����Ż��ӵ�
void CPlaneWarView::MakeFriendBomb()
{
	
	POSITION pos;
	for (pos = m_ObjList[friendplane].GetHeadPosition(); pos != NULL; )
	{
		//����Ż�����
		CFriendPlane* pe = (CFriendPlane*)m_ObjList[friendplane].GetNext(pos);
		
		//�ɻ�λ��
		CPoint pPos = pe->GetPoint();
		
		//��÷���λ��
		CPoint pBombPos[4] = {(0, 0)};
		for(int i = 0; i < 4; ++i)
		{
			pBombPos[i] = pe->GetBombPos(i+1);
		}

		//�Ż����Կ���ʱ,����ӵ�
		if (pe->IfFired())
		{
			for(int i=0; i<4; ++i)
			{	
				m_ObjList[bombbase].AddTail(m_pFactorBomb->Creat(bombbase, pBombPos[i].x, pBombPos[i].y));
			}
		}
	}
}

//���BOSS��ʶ
int CPlaneWarView::GetBossStatus()
{
	return this->m_nBossStatus;
}

//�޸�BOSS��ʶ
void CPlaneWarView::SetBossStatus(int nStatus)
{
	m_nBossStatus = nStatus;
}

//�����ؿ�
void CPlaneWarView::UpdateLevel()
{
	//��Ϸ�ؿ�
	SetGameLevel(GetGameLevel() + 1);

	//��������
	int ans = m_pBack->GetGrade();
	while (m_pBack->GetGrade() == ans) 
	{
		//��֤�������ظ�
		m_pBack->SetGrade(rand() % 3);
	}

	//BOSS��ʶ
	SetBossStatus(unborn);

	//�ؿ�����
	int nGameLevel =  GetGameLevel();

	//�����л���
	m_pUpGame->UpDate(m_nMaxEnemyNum, nGameLevel);

}

//��������
void CPlaneWarView::MakeProp()
{
	//��ȴʱ��
	m_nWaitProp++;
	if(m_nWaitProp >= rand() % 300 + 500)
		m_nWaitProp = 0;

	//������ɵ���
	if(m_nWaitProp == 0)
		m_ObjList[prop].AddTail( m_pFactorProp->Creat(rand() % 3) );

}

//BOSS�ؿ�
void CPlaneWarView::AI()
{

	//�Ƿ���ͣ
	if (m_bPause) return;

	//����ӵ�
	MakeEnemyBomb();
	MakeFriendBomb();

	//��������
	MakeProp();

	//ս�����ʱ�Ĳ���
	if (m_pMe->GetNowHP() > 0)
	{
		//�����л�
		MakeEnemy();

		//��ⰴ��
		PlaneMove();

		//��ײ���,ս������ ��Ϸ����
		if(!MonitorCrash())
			SetProcess(end);

		//�ؿ����� ���boss�ж�
		if( GetBossStatus() == death )
			UpdateLevel();		
	}
	else 
		SetProcess(end);
}

//������Ϸ
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

//��Ϸ����
void CPlaneWarView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	int nProcess = GetProcess();
	if(nProcess == start || nProcess == help)
	{
		//BOSSģʽ
		CRect rect = m_pSta->GetRectStart();
		if(point.x > rect.left && point.x < rect.right && point.y > rect.top  && point.y < rect.bottom)
		{
			SetProcess(bosspattern);
		}
		//����ģʽ
		rect = m_pSta->GetRectHell();
		if(point.x > rect.left && point.x < rect.right && point.y > rect.top  && point.y < rect.bottom)
		{
			SetProcess(hell);
		}
		//����
		rect = m_pSta->GetRectHelp();
		if(point.x > rect.left && point.x < rect.right && point.y > rect.top  && point.y < rect.bottom)
		{
			SetHelp();
			SetProcess(help);
		}
	}
	if(nProcess == bosspattern || nProcess == hell || nProcess == end)
	{
		//�����ͣ��ť
		CRect rect = m_pPause->GetRectStop();
		if(point.x > rect.left && point.x < rect.right && point.y > rect.top  && point.y < rect.bottom)
		{
			m_pPause->PauseButton(m_bPause);
			m_pMe->SetHorMotion(0);
			m_pMe->SetVerMotion(0);
		}
		//����������
		rect = m_pPause->GetRect();
		if(point.x > rect.left && point.x < rect.right && point.y > rect.top  && point.y < rect.bottom)
		{
			ReStart();
			SetProcess(start);
		}
		//�޵�ģʽ
		rect = m_pNb->GetRect();
		if(point.x > rect.left && point.x < rect.right && point.y > rect.top  && point.y < rect.bottom)
		{
			if(!m_pPause)
			{
				SetNb();
			}
		}
		//END ���������ط�����
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
	//��ʼ����
	if(GetProcess() == start || GetProcess() == help)
	{
		m_pSta->Draw(m_pMemDC, m_bHelp);
	}
	//��Ϸ��
	if(GetProcess() == bosspattern || GetProcess() == end || GetProcess() == hell)
	{
		AI();
		UpdateGaming(m_pMemDC);
		//��Ϸ����
		if(GetProcess() == end)
		{
			m_pEnd->Draw(m_pMemDC, FALSE);
		}
	}
	m_pDC->BitBlt(0, 0, GAME_WIDTH, GAME_HEIGHT, m_pMemDC, 0, 0, SRCCOPY);
	CView::OnTimer(nIDEvent);
}