#pragma once
#include <iostream>
#include <string>
class Identity
{
public:
	virtual void Menu() = 0;

	std::string m_Name; //ÕË»§Ãû
	std::string m_Pwd;  //ÃÜÂë
};