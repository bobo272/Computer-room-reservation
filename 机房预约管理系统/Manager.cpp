#include "Manager.h"
#include <fstream>
#include "globalFile.h"
Manager::Manager()
{
}//Ĭ�Ϲ���


Manager::Manager(string name, string pwd)
{
	this->m_Name = name;
	this->m_Pwd = pwd;

	this->initVector();
}//�вι���


void Manager::Menu()
{
	cout << "��ӭ����Ա��" << this->m_Name << "��¼��" << endl;
	cout << "\t\t ---------------------------------" << endl;
	cout << "\t\t|                                |" << endl;
	cout << "\t\t|          1.����˺�            |" << endl;
	cout << "\t\t|                                |" << endl;
	cout << "\t\t|          2.�鿴�˺�            |" << endl;
	cout << "\t\t|                                |" << endl;
	cout << "\t\t|          3.�鿴����            |" << endl;
	cout << "\t\t|                                |" << endl;
	cout << "\t\t|          4.���ԤԼ            |" << endl;
	cout << "\t\t|                                |" << endl;
	cout << "\t\t|          0.ע����¼            |" << endl;
	cout << "\t\t|                                |" << endl;
	cout << "\t\t ---------------------------------" << endl;
	cout << "��ѡ�����Ĳ����� " << endl;
}//ѡ��˵�


void Manager::addPerson()
{
	cout << "����������˺ŵ�����" << endl;
	cout << "1�������ʦ" << endl;
	cout << "2��������" << endl;


	string fileName;
	string tip;
	ofstream ofs;

	int select = 0;
	cin >> select;

	if (select == 2)
	{
		fileName = AUDITOR_FILE;
		tip = "������id�� ";
	}
	else
	{
		fileName = TEACHER_FILE;
		tip = "������id��";
	}

	ofs.open(fileName, ios::out | ios::app);
	int id;
	string name;
	string pwd;
	cout << tip << endl;
	cin >> id;

	cout << "������������ " << endl;
	cin >> name;

	cout << "���������룺 " << endl;
	cin >> pwd;

	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "��ӳɹ�" << endl;

	system("pause");
	system("cls");

	ofs.close();
}//����˺�  


void Manager::showPerson()
{
}//�鿴�˺�


void Manager::showComputer()
{
}//�鿴������Ϣ

void Manager::cleanFile()
{
}//���ԤԼ��¼


void Manager::initVector()
{
	ifstream ifs;
	ifs.open(AUDITOR_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		return;
	}

	vAud.clear();
	vTea.clear();

	Auditor a;
	while (ifs >> a.m_id && ifs >> a.m_Name && ifs >> a.m_Pwd)
	{
		vAud.push_back(a);
	}

	cout << "��˵�������" << vAud.size() << endl;

	ifs.close();//�������ͳ�ƽ���

	ifs.open(TEACHER_FILE, ios::in);

	Teacher t;
	while (ifs >> t.m_Id && ifs >> t.m_Name && ifs >> t.m_Pwd)
	{
		vTea.push_back(t);
	}
	cout << "��ǰ��ʦ����Ϊ�� " << vTea.size() << endl;

	ifs.close();
}