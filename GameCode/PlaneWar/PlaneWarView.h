// PlaneWarView.h : CPlaneWarView ��Ľӿ�
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
	//�������л�����
	//����
	CPlaneWarView();
	//declare_dyn create -- ʵʱ��̬��������
	DECLARE_DYNCREATE(CPlaneWarView)

// ����
public:
	
	CPlaneWarDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~CPlaneWarView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

//����
protected:
	
	CDC*			m_pMemDC; //�ڴ�DC
	
	CClientDC*		m_pDC; //�豸DC
	
	CBitmap*		m_pMemBitmap; //�ڴ�λͼ
	
	CMyPlane*		m_pMe; //ս��

	CPropObject*	m_pProp; //����
	
	CBack*			m_pBack; //����

	CCounter*		m_pCounter; //�Ʒ�

	CCrash*			m_pCrash; //��ײ 
	
	CPause*			m_pPause; //��ͣ

	CNbPattern*		m_pNb; //�޵�ģʽ

	CGameSta*		m_pSta; //��Ϸ��ʼ����

	CGameEnd*		m_pEnd; //��Ϸ����

	CGameGrade*		m_pUpGame; //�ؿ�������
	
	CFactorBomb*	m_pFactorBomb;//����
	CFactorPlane*	m_pFactorPlane;
	CFactorProp*	m_pFactorProp;

	int				m_nProcess; //��Ϸ����
	int				m_nGamePattern; //��Ϸģʽ
	int				m_nGameLevel;//�ؿ�
	int				m_nEnemyNum; //ÿ���ѳ��ֵл�����
	int				m_nBossStatus; //BOSS״̬
	int				m_nWait; //�����л�ʱ����
	int				m_nMaxEnemyNum;//ÿ�����л���
	int				m_nWaitButton; //��������
	int				m_nWaitProp; //�������ߵ�ʱ����
	
	
//��Ϸ����
protected:

	//��ͣ
	bool		m_bPause;
	//�޵�ģʽ
	bool		m_bNb;
	//�Ż�ʱ��
	bool		m_bShe;
	//����
	bool		m_bHelp; 
	

	//��Ϸ����
	int		GetProcess() const;
	void	SetProcess(int nProcess);
	//�ؿ��ȼ�
	int		GetGameLevel() const;
	void	SetGameLevel(int nGameLevel);
	//��ͣ
	int		GetPause() const;
	//�޸İ�����ʶ
	void	SetHelp();
	//�޵�
	BOOL	GetNb() const;
	void	SetNb();
	//�����س�
	BOOL	IfButton();

	//����
	void	AI(); //BOSS�ؿ�
	void	PlaneMove();//�ɻ�״̬������ -> �ɻ��ƶ�, �����ӵ�, �޵�ģʽ
	BOOL	MonitorCrash(); //�����ײ,��ӱ�ը
	void	MakeProp(); //��������
	void	MakeEnemy(); //�����л�
	void	MakeEnemyBomb();//�����л��ӵ�
	void	MakeMyBomb(); //����ս���ӵ�
	void	MakeFriendBomb(); //�����Ż��ӵ�
	void	UpdateLevel();//�ؿ�����
	void	SetBossStatus(int nStatus); //�޸�BOSS��ʶ
	int		GetBossStatus(); //���BOSS��ʶ
	
	//��������
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);







protected:
	
protected:
	//��ʼ����Ϸ
	BOOL InitGame();
	
	//��ʼ����Ϸ����
	void InitDate();

	//����ͼƬ��Դ
	static void LoadImage();


	//������Ϸ
	void OnDestroy();
	void StopOnGame();

	//������Ϸ
	void ReStart();

	//ˢ����Ϸ���е�֡����
	void UpdateGaming(CDC* pMemDC);

	

	//��ü���״̬1->down
	int GetKey(int nVirtKey)
	{
		return (GetKeyState(nVirtKey) & 0x8000)? 1 : 0;
	}
	
	
	CObList    m_ObjList[9];



// ���ɵ���Ϣӳ�亯��
protected:

	DECLARE_MESSAGE_MAP()
public:
	virtual void OnInitialUpdate();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // PlaneWarView.cpp �еĵ��԰汾
inline CPlaneWarDoc* CPlaneWarView::GetDocument() const
   { return reinterpret_cast<CPlaneWarDoc*>(m_pDocument); }
#endif

