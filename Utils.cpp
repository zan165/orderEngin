#include "Utils.h"






//构造函数
Utils::Utils() {
}


//析构函数
Utils::~Utils() {

}

bool Utils::hasSpace(std::string str) {
	//string str = "Hello World!"; // 待判断的字符串

	int n = str.size(); // 获取字符串长度

	bool hasSpace = false; // 用于标记字符串中是否含有空格

	for (int i = 0; i < n; i++) { // 遍历字符串中的每个字符

		if (str[i] == ' ') { // 如果当前字符是空格，则将hasSpace标记为true

			hasSpace = true;

		}
		else if (str[i] != ' ' && str[i] != '\0') { // 如果当前字符不是空格且不是字符串结尾，则继续遍历

			continue;

		}
		else { // 如果当前字符是字符串结尾，则跳出循环

			break;

		}

	}
	if (hasSpace) { // 如果字符串中含有空格，则输出提示信息

		//std::cout << "字符串中含有空格" << std::endl;
		return true;
	}
	else { // 如果字符串中不含有空格，则输出提示信息

		//std::cout << "字符串中不含有空格" << std::endl;
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




	// 获取当前时间戳

	time(&rawtime);



	// 将时间戳转换为本地时间结构

	errno_t err = localtime_s(newlocaltime, &rawtime);

	if (err != 0) {

		std::cout << "Error: localtime_s failed with error code " << err << std::endl;



	}
	//memset(&newlocaltime, 0, sizeof(struct tm));
	return newlocaltime;

}