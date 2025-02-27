#pragma once
#include "Identity.h"
#include <vector>
#include <iostream>
#include "Auditor.h"
#include "Teacher.h"
using namespace std;


//- 显示管理员操作的菜单界面
//
//- 添加账号
//
//- 查看账号
//
//- 查看机房信息
//
//- 清空预约记录

class Manager :public Identity
{	
public:
	Manager();//默认构造
	
	Manager(string name, string pwd);//有参构造  管理员姓名，密码
	
	virtual void Menu();//选择菜单
	
	void addPerson();//添加账号  
	
	void showPerson();//查看账号
	
	void showComputer();//查看机房信息

	void cleanFile();//清空预约记录

	void initVector();//初始化并判断是否重复

	vector<Auditor> vAud;//审查容器

	vector<Teacher> vTea;//教师容器
};