#pragma once
#include "Identity.h"
#include <iostream>
using namespace std;

/*
- ��ʾ�����Ĳ˵�����
- �鿴����ԤԼ
- ���ԤԼ
*/


class Auditor :public Identity
{
public:
	Auditor();//Ĭ�Ϲ���

	Auditor(int id, string name, string pwd);//���ι���

	virtual void Menu();//�˵�

	void showAllOrder();//�鿴����ԤԼ

	void validOrder();//���ԤԼ

	int m_id;
};