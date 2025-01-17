#include "stdafx.h"
#include "FieldCreature.h"

CFieldCreature::CFieldCreature()
{
	memset(&m_stFcINFO, 0, sizeof(FCINFO));
}

CFieldCreature::~CFieldCreature()
{
}

bool CFieldCreature::IsDead()
{
	if (m_stFcINFO.iCurrHP <= 0) return true;
	else return false;
}

void CFieldCreature::Damaged(int _iAttack)
{
	m_stFcINFO.iCurrHP = m_stFcINFO.iCurrHP - _iAttack;
}

void CFieldCreature::SetCurrHP(int _iCurrHP)
{
	m_stFcINFO.iCurrHP = _iCurrHP;
}

void CFieldCreature::SetOffencePower(int _iOffencePower)
{
	m_stFcINFO.iOffencePower = _iOffencePower;
}

void CFieldCreature::SetGold(int _iGold)
{
	m_stFcINFO.iGold = _iGold;
}


int CFieldCreature::GetOffencePower() const
{
	return m_stFcINFO.iOffencePower;
}

int CFieldCreature::GetTotalHP() const
{
	return m_stFcINFO.iTotalHP;
}

int CFieldCreature::GetGold() const
{
	return m_stFcINFO.iGold;
}

