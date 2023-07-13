#pragma once
#ifndef Utils_H
#include<iostream>
#include <string>
#include<vector>
#include<filesystem>

#define Utils_H
class Utils {

public:
	Utils(); // 构造函数

	~Utils(); // 析构函数

	static bool hasSpace(std::string str);
	static void log(std::string ingo);
	static void log(std::vector<std::string> str_array);
	static bool exist(std::string dir);
	static tm* getCurrentTime(tm* newlocaltime);
private:
   
};



#endif // Utils_H
