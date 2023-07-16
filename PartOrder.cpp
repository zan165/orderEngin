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

bool  PartOrder::copyImages(std::string PUBLIC_DIR, std::string BG_MOUDLES_DIR, std::string ZSP_MOUDLES_DIR) {
	copyBGImages(PUBLIC_DIR, BG_MOUDLES_DIR);
	copyZSPImages(PUBLIC_DIR, ZSP_MOUDLES_DIR);
	return true;
}



bool  PartOrder::copyBGImages(std::string PUBLIC_DIR, std::string MOUDLES_DIR) {

	try
	{
		for (std::vector<std::string> ::iterator it = bgArr.begin(); it != bgArr.end(); it++) {

			std::string imgName = *it;
			if (copyImg(MOUDLES_DIR + "\\" + imgName + "\\" + imgName + ".jpg", PUBLIC_DIR)) {
				std::cout << "copy Image  " + MOUDLES_DIR + "\\" + imgName + "\\" + imgName + ".jpg  To" + PUBLIC_DIR << std::endl;
			}
		}

	}
	catch (const std::exception&)
	{
		std::cout << " ����ͼƬδ�����ɹ�" << std::endl;
		return false;;
	}

	return true;

}


bool  PartOrder::copyZSPImages(std::string PUBLIC_DIR, std::string MOUDLES_DIR) {

	try
	{
		for (std::vector<std::string> ::iterator it = greetBordArr.begin(); it != greetBordArr.end(); it++) {

			std::string imgName = *it;
			if (copyImg(MOUDLES_DIR +  "\\" + imgName + ".jpg", PUBLIC_DIR)) {
				std::cout << "copy Image  " + MOUDLES_DIR  + "\\" + imgName + ".jpg  To" + PUBLIC_DIR << std::endl;
			}
		}

	}
	catch (const std::exception&)
	{
		std::cout << " ����ͼƬδ�����ɹ�" << std::endl;
		return false;;
	}

	return true;

}





bool PartOrder::createDetailText(std::string PUBLIC_DIR) {

	std::string strArr[3];
	strArr[0] = "��ƣ�" + infos;
	strArr[1] = "������";
	strArr[2] = "��ַ��" + addr;
	// ����һ���ı��ļ�������

	//����˵���ļ�
	try
	{
		std::ofstream outfile(PUBLIC_DIR + "\\" + "˵��.txt");

		// ����ļ��򿪳ɹ�����д��һЩ����

		if (outfile.is_open()) {
			outfile << strArr[0] << std::endl << std::endl << std::endl << strArr[1] << std::endl << std::endl << std::endl << strArr[2] << std::endl;
		}

		// �ر��ļ���

		outfile.close();

	}
	catch (const std::exception&)
	{

		std::cout << "Failed to create DetailText file." << std::endl;
		return 0;
	}

	return true;
}


std::vector<std::string> split(const std::string& str, const std::string& delimiters) {

	std::regex delimiter_regex(delimiters);

	std::sregex_token_iterator begin(str.begin(), str.end(), delimiter_regex, -1), end;

	std::vector<std::string> tokens(begin, end);

	return tokens;

}


//����ת��δ�ļ�
bool PartOrder::saveDataToFile(std::string PARTY_HOME, std::string releasePath, std::string MOUDLES_DIR,std::string ZSP_MOUDLES_DIR) {
	tm nowTime;

	std:tm* curentTime = Utils::getCurrentTime(&nowTime);

	//��������
	std::string currDate = std::to_string(curentTime->tm_mon + 1) + "." + std::to_string(curentTime->tm_mday);
	
	std::vector<std::string> addrInfos = split(addr," |,");
	std::vector<std::string> psInfos = split(infos," |,");
	std::string acceptName = "��ǧ";
	if (psInfos[0] == "q") {
		acceptName = "��ǧ";
	}
	else if (psInfos[0] == "m") {
		acceptName = "��־��";
	}else if (psInfos[0] == "zlh") {
		acceptName = "��";
	}
	else {
		acceptName = psInfos[0];
	}


	releasePath = releasePath + "\\" + acceptName+"\\"+currDate;
	std::string excuteDate = psInfos[2];
	std::string courier = "";
	
	recieveName = addrInfos[0];
	std::string usrAddrCity = "";
	useProvince = addrInfos[2];
	useCity = addrInfos[3];
	if (useProvince.find("ʡ") != std::string::npos) {
		// str����substr
		usrAddrCity = useProvince;
		if (useCity.find("��") != std::string::npos) {
			usrAddrCity = usrAddrCity + "_" + useCity;
		}
	}

	std::string shippingAddressCity = "�Ĵ�ʡ�ɶ���";
	std::string pName = currDate + "_" + excuteDate + courier + "_�ջ��ˣ�" + recieveName;
	//ƴ���ļ���
	if (usrAddrCity != "") {
		pName = pName + "_" + usrAddrCity;
	}


	
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


	createDetailText(PUBLIC_DIR);

	//���Ʊ���ͼƬ ��ָʾ��

	copyImages(PUBLIC_DIR, MOUDLES_DIR, ZSP_MOUDLES_DIR);



	std::string command = "explorer " + PUBLIC_DIR; // �滻Ϊ��Ҫ�򿪵��ļ���·��
	Utils::log(command.c_str());;
	system(command.c_str());

    return true;
}


bool PartOrder::copyImg(std::string src_image_path, std::string dest_directory_path) {
	try
	{
		if (!fs::exists(src_image_path)) {
			std::cout << src_image_path+ " �ļ�������" << std::endl;
			return 0;
		}


		// ȷ��Ŀ��Ŀ¼����

		if (!std::filesystem::exists(dest_directory_path)) {

			std::filesystem::create_directories(dest_directory_path);

		}


		// ����Ŀ���ļ�·��

		std::string dest_image_path = src_image_path.substr(src_image_path.find_last_of("/") + 1);

		Utils::log("xcopy  " + src_image_path + " " + dest_directory_path);

		std::string command = "xcopy " + src_image_path + " " + dest_directory_path; // �滻Ϊ��Ҫ�򿪵��ļ���·��

		system(command.c_str());

		std::cout << "Image copied successfully." << std::endl;


		return true;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return false;
	}


	return true;;

}



//���Դ���
