#pragma once
#include "Include.h"

class CKeyMgr
{
private:
public:
	static CKeyMgr*			m_pInstance;
	bool					m_bKeyState[VK_MAX];

public:
	CKeyMgr();
	~CKeyMgr();

public:	
	bool				Key_Pressing(int _iKey);
	bool				Key_Down(int _iKey);
	bool				Key_Up(int _iKey);

public:
	static CKeyMgr*		Get_Instance() { 
		if (!m_pInstance)
			m_pInstance = new CKeyMgr;

		return m_pInstance; 
	}

	static void			Destroy_Instance() {
		if (m_pInstance) {
			delete m_pInstance;
			m_pInstance = nullptr;
		}
	}
};

