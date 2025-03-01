#include "Manager.h"
#include <fstream>
#include "globalFile.h"

Manager::Manager()
{
}//默认构造


Manager::Manager(string name, string pwd)
{
	this->m_Name = name;
	this->m_Pwd = pwd;

	this->initVector();
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
	cout << "请输入添加账号的类型" << endl;
	cout << "1、添加老师" << endl;
	cout << "2、添加审核" << endl;


	string fileName;
	string tip;
	ofstream ofs;

	int select = 0;
	cin >> select;
	string errorTip; //重复错误提示
	if (select == 2)
	{
		fileName = AUDITOR_FILE;
		tip = "请输入id： ";
		errorTip = "id重复，请重新输入";
	}
	else
	{
		fileName = TEACHER_FILE;
		tip = "请输入id：";
		errorTip = "id重复，请重新输入";
	}

	ofs.open(fileName, ios::out | ios::app);
	int id;
	string name;
	string pwd;
	cout << tip << endl;

	while (true)
	{
		cin >> id;

		bool ret = this->checkRepeat(id, select);

		if (ret) //有重复
		{
			cout << errorTip << endl;
		}
		else
		{
			break;
		}
	}

	cout << "请输入姓名： " << endl;
	cin >> name;

	cout << "请输入密码： " << endl;
	cin >> pwd;

	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "添加成功" << endl;

	system("pause");
	system("cls");

	ofs.close();

	//重新初始化容器
	this->initVector();
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


void Manager::initVector()
{
	ifstream ifs;
	ifs.open(AUDITOR_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		return;
	}

	vAud.clear();
	vTea.clear();

	Auditor a;
	while (ifs >> a.m_id && ifs >> a.m_Name && ifs >> a.m_Pwd)
	{
		vAud.push_back(a);
	}

	cout << "审核的人数是" << vAud.size() << endl;

	ifs.close();//审核人数统计结束

	ifs.open(TEACHER_FILE, ios::in);

	Teacher t;
	while (ifs >> t.m_Id && ifs >> t.m_Name && ifs >> t.m_Pwd)
	{
		vTea.push_back(t);
	}
	cout << "当前教师数量为： " << vTea.size() << endl;

	ifs.close();
}

bool Manager::checkRepeat(int id, int type)
{
	if (type == 1)
	{
		for (auto intr = vTea.begin(); intr != vTea.end(); intr++)
		{
			if (id == intr->m_Id)
			{
				return true;
			}
		}
	}
	else
	{
		for (auto intr = vAud.begin(); intr != vAud.end(); intr++)
		{
			if (id == intr->m_id)
			{
				return true;
			}
		}
	}
	return false;
}