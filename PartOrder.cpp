#include "PartOrder.h"

PartOrder::PartOrder( std::string ar, std::string ins) {
    addr = ar;
    infos = ins;
}


PartOrder::~PartOrder() {} // ��������ʵ��Ϊ��



int PartOrder::insertBg(std::vector<std::string> stringArr) {
    bgArr = stringArr;
    return 0;
} // ����


int PartOrder::insetGreetingBord(std::vector<std::string> stringArr) {
    greetBordArr = stringArr;
    return 0;
}//ӭ����


bool PartOrder::tidyUpiInfo() {
    std::cout << "addr ::" << addr << std::endl;
    std::cout << "infos ::" << infos << std::endl;

    return true;
}

std::vector<std::string> PartOrder::splitAddr() {
    std::vector<std::string> arry;
    return arry;
}
std::vector<std::string> PartOrder::splitInfos() {
    std::vector<std::string> arry;
    return arry;
}

//����ת��δ�ļ�
bool PartOrder::saveDataToFile() {

    return true;
}

//���Դ���
int PartOrder::testOrder() {


    return 0;
}
