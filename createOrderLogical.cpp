#include "PartOrder.h"
#include"Utils.h"



int main() {
	Utils::log("��������");

	std::string psInfo;
	std::string addr;
	std::vector<std::string> str_array = {};
	//�Ƿ����ӭ���� �� ��ͷ����
	bool haveYBP = false;
	

	//��ַ
	Utils::log("�����붩����ַ��");
	std::getline(std::cin, addr); // �ӱ�׼�����ȡһ�����ݲ��洢������addr��

	std::cout << "������ĵ�ַ�ǣ� " << addr << std::endl; // ����û�������ַ���


	//��ע

	Utils::log("�����붩����ע��Ϣ��");
	std::getline(std::cin, psInfo); // �ӱ�׼�����ȡһ�����ݲ��洢������psInfo��

	std::cout << "������ı�ע�ǣ� " << psInfo << std::endl; // ����û�������ַ���


	while (true) {
		std::string bgCode;

		Utils::log("�����뱳�����룬�˳�����0   ��Ƭ������1��");
		std::getline(std::cin, bgCode);

		if (bgCode == "0" || bgCode == "1") {
			break;
		}
		if (bgCode == "" || Utils::hasSpace(bgCode)) {
			Utils::log("�����������,����������");
		}
		else {
			str_array.push_back(bgCode);
		}
	}


	Utils::log("�������ı��������¼�����");
	Utils::log(str_array);

	PartOrder *po = new PartOrder(addr, psInfo);
	po->tidyUpiInfo();
	po->insertBg(str_array);
	po->saveDataToFile();
	
	Utils::log("�����������");
	return 0;
}