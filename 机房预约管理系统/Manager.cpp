#include "Manager.h"


Manager::Manager()
{
}//默认构造


Manager::Manager(string name, string pwd)
{
	this->m_Name = name;
	this->m_Pwd = pwd;
}//有参构造


void Manager::Menu()
{
	cout << "欢迎管理员：" << this->m_Name << "登录！" << endl;
	cout << "\t\t ---------------------------------" << endl;
	cout << "\t\t|                                |" << endl;
	cout << "\t\t|          1.添加账号            |" << endl;
	cout << "\t\t|                                |" << endl;
	cout << "\t\t|          2.查看账号            |" << endl;
	cout << "\t\t|                                |" << endl;
	cout << "\t\t|          3.查看机房            |" << endl;
	cout << "\t\t|                                |" << endl;
	cout << "\t\t|          4.清空预约            |" << endl;
	cout << "\t\t|                                |" << endl;
	cout << "\t\t|          0.注销登录            |" << endl;
	cout << "\t\t|                                |" << endl;
	cout << "\t\t ---------------------------------" << endl;
	cout << "请选择您的操作： " << endl;
}//选择菜单


void Manager::addPerson()
{
}//添加账号  


void Manager::showPerson()
{
}//查看账号


void Manager::showComputer()
{
}//查看机房信息

void Manager::cleanFile()
{
}//清空预约记录
