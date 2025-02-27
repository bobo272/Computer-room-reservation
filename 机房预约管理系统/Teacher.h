#pragma once
#include "Identity.h"
#include <iostream>
using namespace std;
/*
- 显示操作的菜单界面
- 申请预约
- 查看自身预约
- 查看所有预约
- 取消预约
*/
class Teacher : public Identity
{
public:
	Teacher();//默认构造

	Teacher(int id, string name, string pwd);//含参构造

	virtual void Menu();

	
	void applyOrder();//申请预约

	
	void showMyOrder();//查看我的预约

	
	void showAllOrder();//查看所有预约

	
	void cancelOrder();//取消预约

	int m_Id;//教师id
};
