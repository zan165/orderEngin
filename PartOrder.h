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
//工具类
#include"Utils.h"
namespace fs = std::filesystem;
#define PartOrder_H



class PartOrder {

public:

    PartOrder(std::string addr, std::string infos); // 构造函数

    ~PartOrder(); // 析构函数

    int insertBg(std::vector<std::string> stringArr); // 背景
    int insetGreetingBord(std::vector<std::string> stringArr);//迎宾牌
    int testOrder();//创建测试订单

    bool tidyUpiInfo();//整理数据
    bool saveDataToFile(std::string PARTY_HOME, std::string RELEASE_PATH, std::string MOUDLES_DIR, std::string ZSP_MOUDLES_DIR);//数据转化未文件
    bool createDetailText(std::string);
    bool copyImages(std::string PUBLIC_DIR, std::string BG_MOUDLES_DIR, std::string ZSP_MOUDLES_DIR);
    bool copyBGImages(std::string PUBLIC_DIR, std::string MOUDLES_DIR);
    bool copyZSPImages(std::string PUBLIC_DIR, std::string MOUDLES_DIR);
    bool copyImg(std::string src_image_path, std::string dest_directory_path);


// 私有成员变量
    //收货人
    std::string recieveName;
    //设计时间
    std::string designTime;
    //布置时间
    std::string useTime;
    //发货方式
    std::string postStyle;
    //收货地址省
    std::string useProvince;
    //收货地址市区
    std::string useCity;
    //收货地址县
    std::string useCounty;
    //收货地址区镇
    std::string useTown;
    //KT板代发地址
    std::string shippingAddress;
    //文件目录
    std::string catalog;

    std::string addr;
    std::string infos;
    std::vector<std::string> bgArr;
    std::vector<std::string> greetBordArr;
    std::vector<std::string> splitAddr();
    std::vector<std::string> splitInfos();
private:
};



#endif // PartOrder_H

