#pragma once


#ifndef PartOrder_H
#include <iostream>
//文件流
#include <regex>
//正则
#include <vector>
//数组
#include <string>
//字符串
#include <cstdio>
//std标准库
#include<fstream>
//文件流
#include<filesystem>
//文件系统
#include<time.h>
#define PartOrder_H



class PartOrder {

public:

    PartOrder(std::string addr, std::string infos); // 构造函数

    ~PartOrder(); // 析构函数

    int insertBg(std::vector<std::string> stringArr); // 背景
    int insetGreetingBord(std::vector<std::string> stringArr);//迎宾牌
    int testOrder();//创建测试订单

    bool tidyUpiInfo();//整理数据
    bool saveDataToFile();//数据转化未文件
private:
// 私有成员变量
    std::string recieveName;
    std::string addr;
    std::string infos;
    std::vector<std::string> bgArr;
    std::vector<std::string> greetBordArr;
    std::vector<std::string> splitAddr();
    std::vector<std::string> splitInfos();
};



#endif // PartOrder_H

