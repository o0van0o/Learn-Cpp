#pragma once

#include "CObj.h"

template < typename T>
class CAbstractFactory {
public:
	CAbstractFactory() {}
	~CAbstractFactory() {}

public:
	static CObj*	Create() {
		CObj* pObj = new T;
		pObj->Initialize();
		return pObj;
	}

	static CObj* Create(float _fX, float _fY) {
		CObj* pObj = new T;
		pObj->Initialize();
		pObj->Set_Info_CenterPos(_fX, _fY);
		return pObj;
	}

	// TODO 추가할 사항 
};
