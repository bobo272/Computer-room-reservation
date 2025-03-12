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

	ifstream ifs;

	ifs.open(COMPUTER_FILE, ios::in);

	ComputerRoom c;
	while (ifs >> c.m_ComId && ifs >> c.m_MaxNum)
	{
		vCom.push_back(c);
	}
	cout << "当前机房数量为： " << vCom.size() << endl;

	ifs.close();
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
	cout << "\t\t|          5.添加机房            |" << endl;
	cout << "\t\t|                                |" << endl;
	cout << "\t\t|          6.修改机房            |" << endl;
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

void printTeacher(Teacher& t)
{
	cout << "id： " << t.m_Id << " 姓名： " << t.m_Name << " 密码：" << t.m_Pwd << endl;
}

void printAuditor(Auditor& a)
{
	cout << "id: " << a.m_id << " 姓名:" << a.m_Name << " 密码:" << a.m_Pwd << endl;
}

void Manager::showPerson()
{
	cout << "请选择查看内容：" << endl;
	cout << "1、查看所有老师" << endl;
	cout << "2、查看所有审核" << endl;

	int select = 0;

	cin >> select;

	if (select == 1)
	{
		cout << "所有老师信息如下： " << endl;
		for_each(vTea.begin(), vTea.end(), printTeacher);
	}
	else if (select == 2)
	{
		cout << "所有审核信息如下： " << endl;
		for_each(vAud.begin(), vAud.end(), printAuditor);
	}
	else
	{
		cout << "输入有误" << endl;
	}
	system("pause");
	system("cls");
}//查看账号


void Manager::showComputer()
{
	cout << "机房信息如下： " << endl;
	for (vector<ComputerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++)
	{
		cout << "机房编号： " << it->m_ComId << " 机房最大容量： " << it->m_MaxNum << endl;
	}
	system("pause");
	system("cls");
}//查看机房信息

void Manager::cleanFile()
{
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();

	cout << "清空成功！" << endl;
	system("pause");
	system("cls");
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

void Manager::addComputerRoom() {
	ComputerRoom newRoom;
	cout << "请输入机房编号：";
	cin >> newRoom.m_ComId;
	cout << "请输入机房最大容量：";
	cin >> newRoom.m_MaxNum;

	// 检查编号是否重复（类似账号查重逻辑）
	if (checkRepeat(newRoom.m_ComId, 3)) {
		cout << "机房编号重复！" << endl;
		return;
	}

	vCom.push_back(newRoom);
	cout << "添加成功！" << endl;

	saveComputerRoomsToFile();
}

void Manager::modifyComputerRoom() {
	showComputer(); // 调用现有方法显示机房列表 

	int roomId;
	cout << "请输入要修改的机房编号：";
	cin >> roomId;

	for (auto& room : vCom) {
		if (room.m_ComId == roomId) {
			cout << "请输入新容量：";
			cin >> room.m_MaxNum;
			cout << "修改成功！" << endl;

			saveComputerRoomsToFile();
			return;
		}
	}
	cout << "未找到该机房！" << endl;
}

void Manager::saveComputerRoomsToFile() {
	ofstream ofs(COMPUTER_FILE, ios::out | ios::trunc); // 清空模式打开文件 [^6][^4]

	for (auto& room : vCom) {
		ofs << room.m_ComId << " "  // 机房编号 [^3]
			<< room.m_MaxNum << endl;// 最大容量 [^3]
	}
	ofs.close();
}
