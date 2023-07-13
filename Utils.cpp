#include "Utils.h"






//���캯��
Utils::Utils() {
}


//��������
Utils::~Utils() {

}

bool Utils::hasSpace(std::string str) {
	//string str = "Hello World!"; // ���жϵ��ַ���

	int n = str.size(); // ��ȡ�ַ�������

	bool hasSpace = false; // ���ڱ���ַ������Ƿ��пո�

	for (int i = 0; i < n; i++) { // �����ַ����е�ÿ���ַ�

		if (str[i] == ' ') { // �����ǰ�ַ��ǿո���hasSpace���Ϊtrue

			hasSpace = true;

		}
		else if (str[i] != ' ' && str[i] != '\0') { // �����ǰ�ַ����ǿո��Ҳ����ַ�����β�����������

			continue;

		}
		else { // �����ǰ�ַ����ַ�����β��������ѭ��

			break;

		}

	}
	if (hasSpace) { // ����ַ����к��пո��������ʾ��Ϣ

		//std::cout << "�ַ����к��пո�" << std::endl;
		return true;
	}
	else { // ����ַ����в����пո��������ʾ��Ϣ

		//std::cout << "�ַ����в����пո�" << std::endl;
		return false;
	}
}


void Utils::log(std::vector<std::string> array) {
	for (const auto& str : array) {

		std::cout << str << std::endl;

	}
}


void Utils::log(std::string str) {
		std::cout << str << std::endl;
}


bool Utils::exist(std::string dir) {
	return std::filesystem::exists(dir);
}



tm* Utils::getCurrentTime(tm* newlocaltime) {
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