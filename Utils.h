#pragma once
#ifndef Utils_H
#include<iostream>
#include <string>
#include<vector>

#define Utils_H
class Utils {

public:
	Utils(); // ���캯��

	~Utils(); // ��������

	static bool hasSpace(std::string str);
	static void log(std::string ingo);
	static void log(std::vector<std::string> str_array);
private:
   
};



#endif // Utils_H
