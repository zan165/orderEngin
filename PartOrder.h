#pragma once


#ifndef PartOrder_H
#include <iostream>
//�ļ���
#include <regex>
//����
#include <vector>
//����
#include <string>
//�ַ���
#include <cstdio>
//std��׼��
#include<fstream>
//�ļ���
#include<filesystem>
//�ļ�ϵͳ
#include<time.h>
#define PartOrder_H



class PartOrder {

public:

    PartOrder(std::string addr, std::string infos); // ���캯��

    ~PartOrder(); // ��������

    int insertBg(std::vector<std::string> stringArr); // ����
    int insetGreetingBord(std::vector<std::string> stringArr);//ӭ����
    int testOrder();//�������Զ���

    bool tidyUpiInfo();//��������
    bool saveDataToFile();//����ת��δ�ļ�
private:
// ˽�г�Ա����
    std::string recieveName;
    std::string addr;
    std::string infos;
    std::vector<std::string> bgArr;
    std::vector<std::string> greetBordArr;
    std::vector<std::string> splitAddr();
    std::vector<std::string> splitInfos();
};



#endif // PartOrder_H

