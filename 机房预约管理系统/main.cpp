#include <iostream>
#include <fstream>
#include <string>
#include "globalFile.h"
#include "Identity.h"
#include "Teacher.h"
#include "Auditor.h"
#include "Manager.h"
using namespace std;

void LoginIn(string fileName, int type);
void managerMenu(Identity*& manager);


int main() {
	int select = 0;

	while (true) {
		cout << "======================  欢迎来到传智播客机房预约系统  =====================" << endl;
		cout << endl << "请输入您的身份" << endl;
		cout << "\t\t -------------------------------\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          1.任课老师           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          2.审    核           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          3.管 理 员           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          0.退    出           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t -------------------------------\n";
		cout << "输入您的选择: ";

		cin >> select;

		switch (select)
		{
		case 1://老师接口 
			LoginIn(TEACHER_FILE, 1);
			break;
		case 2: //审核接口
			LoginIn(AUDITOR_FILE, 2);
			break;
		case 3: // 管理员接口
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0: // 退出
			cout << "欢迎下一次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "输入有误请重新输入" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}



void LoginIn(string fileName, int type)
{
	Identity * person = nullptr;

	ifstream ifs;
	ifs.open(fileName, ios::in);

	//假如fileNAme的文件不存在

	if (!ifs.is_open())
	{
		cout << "出错，文件夹不存在" << endl;
		ifs.close();
		return;
	}

	//初始化各个数据
	int id = 0;
	string name;
	string pwd;

	if (type == 1||type == 2)
	{
		cout << "输入你的id" << endl;
		cin >> id;
	}

	cout << "输入你的用户名" << endl;
	cin >> name;

	cout << "输入密码" << endl;
	cin >> pwd;

	if (type == 1)
	{
		//老师登录验证
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "老师验证登录成功!" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);

				return;//返回
			}
		}
	}
	else if (type == 2)
	{
		//审核登录验证
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "审核员验证登录成功!" << endl;
				system("pause");
				system("cls");
				person = new Auditor(id, name, pwd);

				return;//返回
			}
		}
	}
	else if (type == 3)
	{
		//管理员登录验证

		//初始管理员为bobo，密码为123
		string fName;
		string fPwd;
		while (ifs >> fName && ifs >> fPwd)
		{
			if (fName == name && fPwd == pwd)
			{
				cout << "管理员验证登录成功!" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);

				managerMenu(person);

				return;//返回
			}
		}
	}

	cout << "验证登录失败!" << endl;

	system("pause");
	system("cls");
	return;
}


//管理员菜单
void managerMenu(Identity*& manager)
{
	while (true)
	{
		//管理员菜单
		manager->Menu();

		Manager* man = (Manager*)manager;
		int select = 0;

		cin >> select;

		if (select == 1)  //添加账号
		{
			cout << "添加账号" << endl;
			man->addPerson();
		}
		else if (select == 2) //查看账号
		{
			cout << "查看账号" << endl;
			man->showPerson();
		}
		else if (select == 3) //查看机房
		{
			cout << "查看机房" << endl;
			man->showComputer();
		}
		else if (select == 4) //清空预约
		{
			cout << "清空预约" << endl;
			man->cleanFile();
		}
		else
		{
			delete manager;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}