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
//������
#include"Utils.h"
namespace fs = std::filesystem;
#define PartOrder_H



class PartOrder {

public:

    PartOrder(std::string addr, std::string infos); // ���캯��

    ~PartOrder(); // ��������

    int insertBg(std::vector<std::string> stringArr); // ����
    int insetGreetingBord(std::vector<std::string> stringArr);//ӭ����
    int testOrder();//�������Զ���

    bool tidyUpiInfo();//��������
    bool saveDataToFile(std::string PARTY_HOME, std::string RELEASE_PATH, std::string MOUDLES_DIR, std::string ZSP_MOUDLES_DIR);//����ת��δ�ļ�
    bool createDetailText(std::string);
    bool copyImages(std::string PUBLIC_DIR, std::string BG_MOUDLES_DIR, std::string ZSP_MOUDLES_DIR);
    bool copyBGImages(std::string PUBLIC_DIR, std::string MOUDLES_DIR);
    bool copyZSPImages(std::string PUBLIC_DIR, std::string MOUDLES_DIR);
    bool copyImg(std::string src_image_path, std::string dest_directory_path);


// ˽�г�Ա����
    //�ջ���
    std::string recieveName;
    //���ʱ��
    std::string designTime;
    //����ʱ��
    std::string useTime;
    //������ʽ
    std::string postStyle;
    //�ջ���ַʡ
    std::string useProvince;
    //�ջ���ַ����
    std::string useCity;
    //�ջ���ַ��
    std::string useCounty;
    //�ջ���ַ����
    std::string useTown;
    //KT�������ַ
    std::string shippingAddress;
    //�ļ�Ŀ¼
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

