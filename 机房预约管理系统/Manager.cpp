#include "Manager.h"


Manager::Manager()
{
}//Ĭ�Ϲ���


Manager::Manager(string name, string pwd)
{
	this->m_Name = name;
	this->m_Pwd = pwd;
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
