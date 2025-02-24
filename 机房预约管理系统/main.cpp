#include <iostream>
#include <fstream>
#include "globalFile.h"
#include "Identity.h"
#include <string>
#include "Teacher.h"
using namespace std;

void LoginIn(string fileName, int type);


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
	}
	else if (type == 3)
	{
		//����Ա��¼��֤
	}

	cout << "��֤��¼ʧ��!" << endl;

	system("pause");
	system("cls");
	return;
}
