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
		cout << "======================  ��ӭ�������ǲ��ͻ���ԤԼϵͳ  =====================" << endl;
		cout << endl << "�������������" << endl;
		cout << "\t\t -------------------------------\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          1.�ο���ʦ           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          2.��    ��           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          3.�� �� Ա           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          0.��    ��           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t -------------------------------\n";
		cout << "��������ѡ��: ";

		cin >> select;

		switch (select)
		{
		case 1://��ʦ�ӿ� 
			LoginIn(TEACHER_FILE, 1);
			break;
		case 2: //��˽ӿ�
			LoginIn(AUDITOR_FILE, 2);
			break;
		case 3: // ����Ա�ӿ�
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0: // �˳�
			cout << "��ӭ��һ��ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "������������������" << endl;
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

	//����fileNAme���ļ�������

	if (!ifs.is_open())
	{
		cout << "�����ļ��в�����" << endl;
		ifs.close();
		return;
	}

	//��ʼ����������
	int id = 0;
	string name;
	string pwd;

	if (type == 1||type == 2)
	{
		cout << "�������id" << endl;
		cin >> id;
	}

	cout << "��������û���" << endl;
	cin >> name;

	cout << "��������" << endl;
	cin >> pwd;

	if (type == 1)
	{
		//��ʦ��¼��֤
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "��ʦ��֤��¼�ɹ�!" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);

				return;//����
			}
		}
	}
	else if (type == 2)
	{
		//��˵�¼��֤
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "���Ա��֤��¼�ɹ�!" << endl;
				system("pause");
				system("cls");
				person = new Auditor(id, name, pwd);

				return;//����
			}
		}
	}
	else if (type == 3)
	{
		//����Ա��¼��֤

		//��ʼ����ԱΪbobo������Ϊ123
		string fName;
		string fPwd;
		while (ifs >> fName && ifs >> fPwd)
		{
			if (fName == name && fPwd == pwd)
			{
				cout << "����Ա��֤��¼�ɹ�!" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);

				managerMenu(person);

				return;//����
			}
		}
	}

	cout << "��֤��¼ʧ��!" << endl;

	system("pause");
	system("cls");
	return;
}


//����Ա�˵�
void managerMenu(Identity*& manager)
{
	while (true)
	{
		//����Ա�˵�
		manager->Menu();

		Manager* man = (Manager*)manager;
		int select = 0;

		cin >> select;

		if (select == 1)  //����˺�
		{
			cout << "����˺�" << endl;
			man->addPerson();
		}
		else if (select == 2) //�鿴�˺�
		{
			cout << "�鿴�˺�" << endl;
			man->showPerson();
		}
		else if (select == 3) //�鿴����
		{
			cout << "�鿴����" << endl;
			man->showComputer();
		}
		else if (select == 4) //���ԤԼ
		{
			cout << "���ԤԼ" << endl;
			man->cleanFile();
		}
		else
		{
			delete manager;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}