#pragma once
#include "Identity.h"
#include <iostream>
using namespace std;
/*
- ��ʾ�����Ĳ˵�����
- ����ԤԼ
- �鿴����ԤԼ
- �鿴����ԤԼ
- ȡ��ԤԼ
*/
class Teacher : public Identity
{
public:
	Teacher();//Ĭ�Ϲ���

	Teacher(int id, string name, string pwd);//���ι���

	virtual void Menu();

	
	void applyOrder();//����ԤԼ

	
	void showMyOrder();//�鿴�ҵ�ԤԼ

	
	void showAllOrder();//�鿴����ԤԼ

	
	void cancelOrder();//ȡ��ԤԼ

	int m_Id;//��ʦid
};
