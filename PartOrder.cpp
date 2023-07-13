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


bool copyImg(std::string src_image_path, std::string dest_directory_path) {
	try
	{
		if (!fs::exists(src_image_path)) {
			std::cout << "�ļ�������" << std::endl;
			return 0;
		}


		// ȷ��Ŀ��Ŀ¼����

		if (!std::filesystem::exists(dest_directory_path)) {

			std::filesystem::create_directories(dest_directory_path);

		}


		// ����Ŀ���ļ�·��

		std::string dest_image_path = src_image_path.substr(src_image_path.find_last_of("/") + 1);


		std::string command = "copy " + src_image_path + " " + dest_directory_path; // �滻Ϊ��Ҫ�򿪵��ļ���·��

		system(command.c_str());

		std::cout << "Image copied successfully." << std::endl;


		return true;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return false;
	}


	return 1;

}


bool createDetailText(std::string filePath, std::string* strArr) {

	return true;
}


std::vector<std::string> split(const std::string& str, const std::string& delimiters) {

	std::regex delimiter_regex(delimiters);

	std::sregex_token_iterator begin(str.begin(), str.end(), delimiter_regex, -1), end;

	std::vector<std::string> tokens(begin, end);

	return tokens;

}


//����ת��δ�ļ�
bool PartOrder::saveDataToFile() {
	tm nowTime;
	std::string PARTY_HOME = "\\\\Desktop - 127asaa\\�ɶ�����";
	std::string releasePath = "\\\\Fuwuqi\\������3-�Ѽ�ͼƬ����\\���ϰ�\\���ϰ��ز�\\ÿ����Ʋ��ϰ�\\��ǧ\\ȷ��\\���Բ��ù�";
	std::string MOUDLES_DIR = PARTY_HOME + "\\assets\\Moudles";

	std:tm* curentTime = Utils::getCurrentTime(&nowTime);

	std::string imgNamePath = "\\\\Desktop-127asaa\\�ɶ�����\\assets\\Moudles";
	//��������
	std::string currDate = std::to_string(curentTime->tm_mon + 1) + "." + std::to_string(curentTime->tm_mday);
	
	std::vector<std::string> addrInfos = split(addr," ");
	std::vector<std::string> psInfos = split(infos," ");
	std::string acceptName = "��ǧ";
	if (psInfos[0] == "q") {
		acceptName = "��ǧ";
	}
	else {
		acceptName = "����";
	}


	releasePath = releasePath + "\\" + acceptName;
	std::string excuteDate = psInfos[2];
	std::string courier = "";
	
	recieveName = addrInfos[0];

	std::string shippingAddressCity = "�Ĵ�ʡ�ɶ���";
	std::string pName = currDate + "_" + excuteDate + courier + "_�ջ��ˣ�" + recieveName;
	//ƴ���ļ���


	
	std::string PUBLIC_DIR = releasePath + "\\" + pName;
	std::filesystem::path folder_path(PUBLIC_DIR);
	try {
		std::filesystem::create_directories(folder_path);
		std::cout << "�ļ��д����ɹ�" << std::endl;
	}
	catch (const std::filesystem::filesystem_error& e) {
		std::cerr << "�����ļ���ʱ���� " << e.what() << std::endl;
	}

	std::cout << "�ļ���ַ�ǣ�" << PUBLIC_DIR << std::endl;
	std::string strArr[3];
	strArr[0] = "��ƣ�"+infos;
	strArr[1] = "������ȫ��";
	strArr[2] = "��ַ��"+addr;
	// ����һ���ı��ļ�������

	std::ofstream outfile(PUBLIC_DIR + "\\" + "˵��.txt");



	// ����ļ��򿪳ɹ�����д��һЩ����

	if (outfile.is_open()) {
		for (int i = 0; i < sizeof(strArr); i++) {

			outfile << strArr[i] << std::endl;

		}
	}
	else {

		std::cout << "Failed to open the file." << std::endl;
		return 0;
	}


	// �ر��ļ���

	outfile.close();


	std::string command = "explorer "+PUBLIC_DIR; // �滻Ϊ��Ҫ�򿪵��ļ���·��

	system(command.c_str());


	//std::vector<std::string> str_array = bgArr;
	//std::string toPath = "..\\public_dir";

	try
	{
		for (std::vector<std::string> ::iterator it = bgArr.begin(); it != bgArr.end(); it++) {

			std::string imgName = *it;
			if (copyImg(imgNamePath + "\\" + imgName + "\\" + imgName + ".jpg", PUBLIC_DIR)) {
				std::cout << "copy Image  " + imgNamePath + "\\" + imgName + "\\" + imgName + ".jpg  To" + PUBLIC_DIR << std::endl;
			}
		}

	}
	catch (const std::exception&)
	{
		std::cout << " ��������δͨ��" << std::endl;
		return 0;
	}


    return true;
}




//���Դ���
int PartOrder::testOrder() {


    return 0;
}
