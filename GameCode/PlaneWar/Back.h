//CBack.h : 定义文件

#include "stdafx.h"
#include "GameObject.h"
#include <mmsystem.h>
#include "resource.h"

class CBack : public CGameObject
{
public:
	enum GamePattern { bosspattern1, bosspattern2, bosspattern3 };

	//构造
	CBack(int x, int y);
	
	//析构
	~CBack();
	
	//获得背景等级
	int GetGrade() const;

	//背景升级
	void SetGrade(int Grade);

	//获得矩形区域
	CRect GetRect();

	//加载图像
	static BOOL LoadImage();

	//绘图
	BOOL Draw(CDC* pDC, BOOL bPause);

private:
	
	//图像链表
	static CImageList m_Images[3];

	//关卡
	int m_nGrade;

};
