#include "PartOrder.h"
#include"Utils.h"



int main() {
	Utils::log("��������");

	std::string psInfo;
	std::string addr;
	std::vector<std::string> strBG_array = {};
	std::vector<std::string> strYBP_array = {};
	//�Ƿ����ӭ���� �� ��ͷ����
	bool haveYBP = false;
	bool haveBG = true;

	if (Utils::exist("")) {

	}

	//��ַ
	Utils::log("�����붩����ַ��");
	std::getline(std::cin, addr); // �ӱ�׼�����ȡһ�����ݲ��洢������addr��

	std::cout << "������ĵ�ַ�ǣ� " << addr << std::endl; // ����û�������ַ���


	//��ע

	Utils::log("�����붩����ע��Ϣ��");
	std::getline(std::cin, psInfo); // �ӱ�׼�����ȡһ�����ݲ��洢������psInfo��

	std::cout << "������ı�ע�ǣ� " << psInfo << std::endl; // ����û�������ַ���


	while (haveBG) {
		std::string bgCode;

		Utils::log("�����뱳�����룬�˳�����0   ��Ƭ������1��");
		std::getline(std::cin, bgCode);

		if (bgCode == "0" || bgCode == "1") {
			if (bgCode == "1") { haveYBP = true; }
			break;
		}
		if (bgCode == "" || Utils::hasSpace(bgCode)) {
			Utils::log("�����������,����������");
		}
		else {
			strBG_array.push_back(bgCode);
		}
	}

	while (haveYBP) {
		std::string ybpCode;

		Utils::log("�����뱳�����룬�˳�����0 ��");
		std::getline(std::cin, ybpCode);

		if (ybpCode == "0") {
			
			break;
		}
		if (ybpCode == "" || Utils::hasSpace(ybpCode)) {
			Utils::log("ӭ���Ʊ������,����������");
		}
		else {
			strYBP_array.push_back(ybpCode);
		}
	}

	Utils::log("�������ı��������¼�����");
	Utils::log(strBG_array);
	Utils::log("��������ӭ���������¼�����");
	Utils::log(strYBP_array);

	PartOrder *po = new PartOrder(addr, psInfo);
	po->tidyUpiInfo();
	po->insertBg(strBG_array);
	po->insetGreetingBord(strYBP_array);
	po->saveDataToFile();
	
	Utils::log("�����������");
	return 0;
}