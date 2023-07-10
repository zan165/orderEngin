
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

#include "PartOrder.h"

#define _CRT_SECURE_NO_WARNINGS
namespace fs = std::filesystem;

//====================================================����=============================================================

int copyImg(std::string src_image_path, std::string dest_directory_path) {
	try
	{
		if (!fs::exists(src_image_path)) {
			std::cout << "�ļ�������" << std::endl;
			return 0;
		}


		// ԴͼƬ·��

		//std::string src_image_path = "path/to/your/source/image.jpg";



		// Ŀ��Ŀ¼·��

		//std::string dest_directory_path = "path/to/your/destination/directory";



		// ȷ��Ŀ��Ŀ¼����

		if (!std::filesystem::exists(dest_directory_path)) {

			std::filesystem::create_directories(dest_directory_path);

		}



		// ����Ŀ���ļ�·��

		std::string dest_image_path = src_image_path.substr(src_image_path.find_last_of("/") + 1);



		//// ��Դ�ļ���Ŀ���ļ�

		//std::ifstream src_file(src_image_path, std::ios::binary);

		//std::ofstream dest_file(dest_image_path, std::ios::binary);



		//// �����ʧ�ܣ����������Ϣ���˳�����
		//if (!src_file || !dest_file) {

		//	std::cerr << "Error opening files for reading or writing." << std::endl;

		//	return 1;

		//}



		//// ��Դ�ļ����ݸ��Ƶ�Ŀ���ļ���

		//dest_file << src_file.rdbuf();



		//// �ر��ļ���

		//src_file.close();

		//dest_file.close();


		std::string command = "copy " + src_image_path + " " + dest_directory_path; // �滻Ϊ��Ҫ�򿪵��ļ���·��

		system(command.c_str());

		std::cout << "Image copied successfully." << std::endl;


		return 1;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return 0;
	}



	return 1;

}


int copyBackImg(std::string aimpath, std::string fromPath, std::vector<std::string> strCode_array) {

	if (!fs::exists(aimpath)) {
		//Ŀ¼������
		std::cerr << "Ŀ¼������  �������" << std::endl;

		return 0;
	}


	return 1;


}


int createText(std::string filePath, std::string fileName, std::string* infos) {
	;
	// ����һ���ı��ļ�������

	std::ofstream outfile(filePath + "\\" + fileName + ".txt");



	// ����ļ��򿪳ɹ�����д��һЩ����

	if (outfile.is_open()) {
		for (int i = 0; i < sizeof(infos); i++) {

			outfile << infos[i] << std::endl;

		}
	}
	else {

		std::cout << "Failed to open the file." << std::endl;
		return 0;
	}


	// �ر��ļ���

	outfile.close();



	return 1;
}

//releasePath���������ϼ�Ŀ¼
int createReleasePathDir(std::string path) {
	fs::path parent_dir = path; // ָ����Ŀ¼��·��

	if (!fs::exists(parent_dir)) {

		try {

			fs::create_directories(parent_dir); // ���Ŀ¼�����ڣ��򴴽���

		}
		catch (const fs::filesystem_error& e) {

			std::cerr << e.what() << std::endl;

			return 0;

		}

	}
	else {

		std::cout << "Parent directory already exists." << std::endl;

	}
	return 1;
}






int openDir(std::string path) {
	std::string command = "explorer " + path; // �滻Ϊ��Ҫ�򿪵��ļ���·��

	system(command.c_str());
	return 1;
}


std::vector<std::string> split(const std::string& str, const std::string& delimiters) {

	std::regex delimiter_regex(delimiters);

	std::sregex_token_iterator begin(str.begin(), str.end(), delimiter_regex, -1), end;

	std::vector<std::string> tokens(begin, end);

	return tokens;

}

tm* getCurrentTime(tm* newlocaltime) {
	time_t rawtime;




	// ��ȡ��ǰʱ���

	time(&rawtime);



	// ��ʱ���ת��Ϊ����ʱ��ṹ

	errno_t err = localtime_s(newlocaltime, &rawtime);

	if (err != 0) {

		std::cout << "Error: localtime_s failed with error code " << err << std::endl;



	}
	//memset(&newlocaltime, 0, sizeof(struct tm));
	return newlocaltime;

}

int isDircExist(std::string path) {

	if (std::filesystem::exists(path) && std::filesystem::is_directory(path)) {

		std::cout << "Ŀ¼���Է���" << std::endl;
		return 1;
	}

	std::cout << "Ŀ¼�޷�����" << std::endl;

	return 0;


}
std::string getCinStr(std::string psInfo) {

	std::cout << psInfo; // �����ʾ��Ϣ

	std::getline(std::cin, psInfo); // �ӱ�׼�����ȡһ�����ݲ��洢������str��

	//std::cout << "��������ַ����ǣ� " << str << std::endl; // ����û�������ַ���

	return psInfo;

}
int createOrder() {
	tm nowTime;
	std::string PARTY_HOME = "\\\\Desktop - 127asaa\\�ɶ�����";
	std::string releasePath = "\\\\Fuwuqi\\������3 - �Ѽ�ͼƬ����\\���ϰ�\\���ϰ��ز�\\ÿ����Ʋ��ϰ�";
	std::string MOUDLES_DIR = PARTY_HOME + "\\assets\\Moudles";

	std:tm* curentTime = getCurrentTime(&nowTime);

	std::string imgNamePath = "\\\\Desktop-127asaa\\�ɶ�����\\assets\\Moudles";
	//��������
	std::string currDate = std::to_string(curentTime->tm_mon + 1) + "." + std::to_string(curentTime->tm_mday);
	std::string excuteDate = "δ";
	std::string courier = "";
	std::string consignee = "����";
	std::string shippingAddressCity = "�Ĵ�ʡ�ɶ���";
	std::string pName = currDate + "," + excuteDate + courier + ",�ջ��ˣ�" + consignee + " " + shippingAddressCity;
	//ƴ���ļ���

	if (!fs::exists("\\\\Fuwuqi\\������3 - �Ѽ�ͼƬ����\\���ϰ�\\���ϰ��ز�\\ÿ����Ʋ��ϰ�")) {
		std::cout << "�ļ�Ŀ¼������ ��������ʧ�ܣ�����ϵ����Ա" << std::endl;

		//
		releasePath = "..\\public_dir";
		if (!createReleasePathDir(releasePath)) {
			std::cout << "�ļ�Ŀ¼������ ����ϵ����Ա" << std::endl;
			return 0;
		}
	}
	std::string PUBLIC_DIR = releasePath + "\\" + pName;

	//�����ַ
	char cinAddr[] = "�������ַ��Ϣ��";

	std::string addressStr = getCinStr(cinAddr);
	std::cout << "����ĵ�ַ�� " << addressStr << std::endl;


	//����˵��
	char cinDesignInfo[] = "�����뱸ע��Ϣ��";

	std::string psInfoStr = getCinStr(cinDesignInfo);
	std::cout << "���뱸ע��ϢΪ " << psInfoStr << std::endl;



	//���뱳�����
	char strBackGround[100];
	std::vector<std::string> str_array = {};

	while (true) {
		char cinBackGroundInfo[] = "��������Ҫѡ�ı�����ţ�";
		std::string backStr = getCinStr(cinBackGroundInfo);
		std::cout << backStr << std::endl;
		if (backStr == "0" || backStr == "1") {
			break;
		}
		str_array.push_back(backStr);
	}

	std::cout << "��Ҫ�������ļ�Ŀ¼Ϊ: " << PUBLIC_DIR << std::endl;

	std::cout << "�������ı��������¼���" << std::endl;
	for (const auto& str : str_array) {

		std::cout << str << std::endl;

	}

	//try
	//{
	//	for (std::vector<std::string> ::iterator it = str_array.begin(); it != str_array.end(); it++) {

	//		std::string imgName = *it;
	//		if (copyImg(imgNamePath + "\\" + imgName + "\\" + imgName + ".jpg", PUBLIC_DIR)) {
	//			std::cout << "copy Image  " + imgNamePath + "\\" + imgName + "\\" + imgName + ".jpg  To" + PUBLIC_DIR << std::endl;
	//		}
	//	}

	//}
	//catch (const std::exception&)
	//{
	//	std::cout << "createOrder ��������δͨ��" << std::endl;
	//	return 0;
	//}

	return 1;
}

//====================================================��������=====================================================


int tesCreateText() {
	std::string path = "\\\\Fuwuqi\\������3-�Ѽ�ͼƬ����\\���ϰ�\\���ϰ��ز�\\ÿ����Ʋ��ϰ�\\��ǧ\\ȷ��\\���Բ��ù�";

	//std::string path = "..\\public_dir";
	std::string name = "˵��";
	std::string strArr[3];
	strArr[0] = "��ƣ�";
	strArr[1] = "������";
	strArr[2] = "��ַ��";


	createText(path, name, strArr);

	std::ifstream infile(path + "\\" + name + ".txt");
	if (infile.is_open()) {

		std::string line;

		while (std::getline(infile, line)) {

			std::cout << line << std::endl;

		}

		std::cout << "createText ��������ͨ��" << std::endl;

	}
	else {

		std::cout << "Failed to open the file.  createText  ������������δͨ��" << std::endl;
		return 0;

	}

	return 1;
}

int test0penDir() {
	//openDir("\\\\Fuwuqi\\������3-�Ѽ�ͼƬ����\\���ϰ�\\���ϰ��ز�\\ÿ����Ʋ��ϰ�\\��ǧ\\ȷ��\\���Բ��ù�");
	//openDir("..\\public_dir");
	printf("���ļ��в�������ͨ��\n");
	return 1;
}

int testInput() {

	return 1;
}

int testSplit() {
	std::string strForSplit = "hello,world this,is,a test";

	std::string delimiters = " |,";

	std::vector<std::string> result = split(strForSplit, delimiters);



	for (const auto& token : result) {

		std::cout << token << std::endl;

	}

	if (result.size() == 6) {
		printf("split���� ����ͨ����������\n");
		return 1;
	}
	printf("split���� ����δͨ����������\n");
	return 0;

}

int testCopyImg() {
	std::string imgNamePath = "\\\\Desktop-127asaa\\�ɶ�����\\assets\\Moudles";
	std::vector<std::string> str_array = {};
	str_array.push_back("80SLRSR03");

	str_array.push_back("80SLRSR04");

	str_array.push_back("80SLRSR05");

	str_array.push_back("80SLRSR06");
	std::string toPath = "..\\public_dir";

	try
	{
		for (std::vector<std::string> ::iterator it = str_array.begin(); it != str_array.end(); it++) {

			std::string imgName = *it;
			if (copyImg(imgNamePath + "\\" + imgName + "\\" + imgName + ".jpg", toPath)) {
				std::cout << "copy Image  " + imgNamePath + "\\" + imgName + "\\" + imgName + ".jpg  To" + toPath << std::endl;
			}
		}
		
	}
	catch (const std::exception&)
	{
		std::cout << "testCopyImg ��������δͨ��" << std::endl;
		return 0;
	}

	return 1;
}

int testExistDir() {

	if (fs::exists("\\\\Fuwuqi\\������3-�Ѽ�ͼƬ����\\���ϰ�\\���ϰ��ز�\\ÿ����Ʋ��ϰ�\\��ǧ\\ȷ��\\���Բ��ù�")) {
		printf("testExistDir��������ͨ��\n");
		return 1;
	}
	printf("testExistDir��������δͨ��\n");
	return 0;
}

int testUnit() {

	if (!testExistDir() ||!tesCreateText() || !testSplit() || !testInput() || !testCopyImg() || !test0penDir()) {
		printf("��������δͨ��\n");
		return 0;
	}

	return 1;
}


int helloMain() {

	//�Ƿ�����Ը����
	bool shouldTest = true;
	if (shouldTest) {
		if (!testUnit()) {
			std::cout << "���Ե�Ԫ��δͨ���Բ������� ���Ⱥ˶Լ��" << std::endl;
			return 0;
		}
		std::cout << "��������ͨ��" << std::endl;

	}

	//createOrder();


	return 0;

}

