#pragma once
#include "Identity.h"
#include <vector>
#include <iostream>
#include "Auditor.h"
#include "Teacher.h"
using namespace std;


//- ��ʾ����Ա�����Ĳ˵�����
//
//- ����˺�
//
//- �鿴�˺�
//
//- �鿴������Ϣ
//
//- ���ԤԼ��¼

class Manager :public Identity
{	
public:
	Manager();//Ĭ�Ϲ���
	
	Manager(string name, string pwd);//�вι���  ����Ա����������
	
	virtual void Menu();//ѡ��˵�
	
	void addPerson();//����˺�  
	
	void showPerson();//�鿴�˺�
	
	void showComputer();//�鿴������Ϣ

	void cleanFile();//���ԤԼ��¼

	void initVector();//��ʼ�����ж��Ƿ��ظ�

	vector<Auditor> vAud;//�������

	vector<Teacher> vTea;//��ʦ����
};