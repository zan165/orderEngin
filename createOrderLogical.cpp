#include "PartOrder.h"
#include"Utils.h"
#include"ConfigFile.h";



int main() {
	Utils::log("��ȡ����");
	ConfigFile config("config.conig");
	config.readFromFile("config.txt"); // ��config.txt�ļ��ж�ȡ������Ϣ���洢��configMap��

	/*config.setValue("PARTY_HOME", "G:\\PartEngin");
	config.setValue("RELEASE_PATH", "G:\\cproject\\day01\\public_dir");
	config.setValue("MOUDLES_DIR", "G:\\PartEngin\\assets\\Moudles");
	config.setValue("ZSP_MOUDLES_DIR", "G:\\PartEngin\\assets\\PhotoGuid");*/

	std::cout << "PARTY_HOME�� " << config.getValue("PARTY_HOME") << std::endl;
	std::cout << "RELEASE_PATH�� " << config.getValue("RELEASE_PATH") << std::endl;
	std::cout << "MOUDLES_DIR�� " << config.getValue("MOUDLES_DIR") << std::endl;
	std::cout << "ZSP_MOUDLES_DIR�� " << config.getValue("ZSP_MOUDLES_DIR") << std::endl;

	//config.writeToFile("config.txt"); // ��������Ϣд�뵽config.txt�ļ���

	//std::string command = "explorer G:\\cproject\\day01\\public_dir\\��ǧ\\7.15\\7.15_7.23����_�ջ��ˣ�Ƚ���,"; // �滻Ϊ��Ҫ�򿪵��ļ���·��
	//Utils::log(command.c_str());;
	//system(command.c_str());
	//return 0;

	Utils::log("��������");

	std::string psInfo;
	std::string addr;
	std::vector<std::string> strBG_array = {};
	std::vector<std::string> strYBP_array = {};
	//�Ƿ����ӭ���� �� ��ͷ����
	bool haveYBP = false;
	bool haveBG = true;
	std::string PARTY_HOME = config.getValue("PARTY_HOME");
	std::string RELEASE_PATH = config.getValue("RELEASE_PATH");
	std::string MOUDLES_DIR = PARTY_HOME + "\\assets\\Moudles";
	std::string ZSP_MOUDLES_DIR = config.getValue("ZSP_MOUDLES_DIR");
	

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
		else if (Utils::hasSpace( bgCode)) {
			Utils::log("�����������,����������");
		}
		else {
			strBG_array.push_back(bgCode);
		}
	}

	while (haveYBP) {
		std::string ybpCode;

		Utils::log("������ӭ���Ʊ��룬�˳�����0 ��");
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
	po->saveDataToFile(PARTY_HOME,RELEASE_PATH,MOUDLES_DIR,ZSP_MOUDLES_DIR);
	
	Utils::log("�����������");
	return 0;
}