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
