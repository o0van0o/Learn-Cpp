#include "stdafx.h"
#include "CLineMgr.h"

CLineMgr* CLineMgr::m_pInstance = new CLineMgr;

CLineMgr::CLineMgr()
{
}

CLineMgr::~CLineMgr()
{
	Release();
}

void CLineMgr::Initialize(int eStageID)
{
	if (eStageID == STAGE_A) {

		// TODO : �ʿ��� ������ ����Ʈ�� �����ϱ�
		LINEPOINT	tPoint[4]{
			{100.f, 450.f},
			{300.f, 450.f},
			{500.f, 250.f},
			{700.f, 250.f}
		};
		m_LineList.push_back(new CLine(tPoint[0], tPoint[1]));
		m_LineList.push_back(new CLine(tPoint[1], tPoint[2]));
		m_LineList.push_back(new CLine(tPoint[2], tPoint[3]));
	}
	else if (eStageID == STAGE_B) {
		
		// TODO : �ʿ��� ������ ����Ʈ�� �����ϱ�
		LINEPOINT	tPoint[4]{
			{100.f, 450.f},
			{300.f, 450.f},
			{500.f, 250.f},
			{700.f, 250.f}
		};
		m_LineList.push_back(new CLine(tPoint[0], tPoint[1]));
		m_LineList.push_back(new CLine(tPoint[1], tPoint[2]));
		
	}
	else if (eStageID == STAGE_C) {

		// TODO : �ʿ��� ������ ����Ʈ�� �����ϱ�
		LINEPOINT	tPoint[4]{
			{100.f, 450.f},
			{300.f, 450.f},
			{500.f, 250.f},
			{700.f, 250.f}
		};
		m_LineList.push_back(new CLine(tPoint[0], tPoint[1]));
		
	}
	else if (eStageID == STAGE_D) {

		// TODO : �ʿ��� ������ ����Ʈ�� �����ϱ�
		LINEPOINT	tPoint[4]{
			{100.f, 450.f},
			{300.f, 450.f},
			{500.f, 250.f},
			{700.f, 250.f}
		};

		m_LineList.push_back(new CLine(tPoint[2], tPoint[3]));
	}
	
}

/* FIX */
void CLineMgr::Render(HDC hDC)
{
	for (auto iter : m_LineList)
		iter->Render(hDC);
}

/* FIX */
void CLineMgr::Release()
{
	for_each(m_LineList.begin(), m_LineList.end(), Safe_Delete<CLine*>);
	m_LineList.clear();
}