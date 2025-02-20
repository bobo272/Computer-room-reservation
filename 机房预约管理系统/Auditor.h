#pragma once
#include "Identity.h"
#include <iostream>
using namespace std;

/*
- 显示操作的菜单界面
- 查看所有预约
- 审核预约
*/


class Auditor :public Identity
{
public:
	Auditor();//默认构造

	Auditor(int id, string name, string pwd);//含参构造

	virtual void Menu();//菜单

	void showAllOrder();//查看所有预约

	void validOrder();//审核预约

	int m_id;
};