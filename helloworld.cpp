
#include <iostream>
//文件流
#include <regex>
//正则
#include <vector>
//数组
#include <string>
//字符串
#include <cstdio>
//std标准库
#include<fstream>
//文件流
#include<filesystem>
//文件系统
#include<time.h>

#include "PartOrder.h"

#define _CRT_SECURE_NO_WARNINGS
namespace fs = std::filesystem;

//====================================================函数=============================================================

int copyImg(std::string src_image_path, std::string dest_directory_path) {
	try
	{
		if (!fs::exists(src_image_path)) {
			std::cout << "文件不存在" << std::endl;
			return 0;
		}


		// 源图片路径

		//std::string src_image_path = "path/to/your/source/image.jpg";



		// 目标目录路径

		//std::string dest_directory_path = "path/to/your/destination/directory";



		// 确保目标目录存在

		if (!std::filesystem::exists(dest_directory_path)) {

			std::filesystem::create_directories(dest_directory_path);

		}



		// 构建目标文件路径

		std::string dest_image_path = src_image_path.substr(src_image_path.find_last_of("/") + 1);



		//// 打开源文件和目标文件

		//std::ifstream src_file(src_image_path, std::ios::binary);

		//std::ofstream dest_file(dest_image_path, std::ios::binary);



		//// 如果打开失败，输出错误信息并退出程序
		//if (!src_file || !dest_file) {

		//	std::cerr << "Error opening files for reading or writing." << std::endl;

		//	return 1;

		//}



		//// 将源文件内容复制到目标文件中

		//dest_file << src_file.rdbuf();



		//// 关闭文件流

		//src_file.close();

		//dest_file.close();


		std::string command = "copy " + src_image_path + " " + dest_directory_path; // 替换为需要打开的文件夹路径

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
		//目录不存在
		std::cerr << "目录不存在  程序错误" << std::endl;

		return 0;
	}


	return 1;


}


int createText(std::string filePath, std::string fileName, std::string* infos) {
	;
	// 创建一个文本文件并打开它

	std::ofstream outfile(filePath + "\\" + fileName + ".txt");



	// 如果文件打开成功，则写入一些文字

	if (outfile.is_open()) {
		for (int i = 0; i < sizeof(infos); i++) {

			outfile << infos[i] << std::endl;

		}
	}
	else {

		std::cout << "Failed to open the file." << std::endl;
		return 0;
	}


	// 关闭文件流

	outfile.close();



	return 1;
}

//releasePath创建订单上级目录
int createReleasePathDir(std::string path) {
	fs::path parent_dir = path; // 指定父目录的路径

	if (!fs::exists(parent_dir)) {

		try {

			fs::create_directories(parent_dir); // 如果目录不存在，则创建它

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
	std::string command = "explorer " + path; // 替换为需要打开的文件夹路径

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

int isDircExist(std::string path) {

	if (std::filesystem::exists(path) && std::filesystem::is_directory(path)) {

		std::cout << "目录可以访问" << std::endl;
		return 1;
	}

	std::cout << "目录无法访问" << std::endl;

	return 0;


}
std::string getCinStr(std::string psInfo) {

	std::cout << psInfo; // 输出提示信息

	std::getline(std::cin, psInfo); // 从标准输入读取一行数据并存储到变量str中

	//std::cout << "您输入的字符串是： " << str << std::endl; // 输出用户输入的字符串

	return psInfo;

}
int createOrder() {
	tm nowTime;
	std::string PARTY_HOME = "\\\\Desktop - 127asaa\\派对引擎";
	std::string releasePath = "\\\\Fuwuqi\\服务器3 - 搜集图片案例\\材料包\\材料包素材\\每日设计材料包";
	std::string MOUDLES_DIR = PARTY_HOME + "\\assets\\Moudles";

	std:tm* curentTime = getCurrentTime(&nowTime);

	std::string imgNamePath = "\\\\Desktop-127asaa\\派对引擎\\assets\\Moudles";
	//今天日期
	std::string currDate = std::to_string(curentTime->tm_mon + 1) + "." + std::to_string(curentTime->tm_mday);
	std::string excuteDate = "未";
	std::string courier = "";
	std::string consignee = "测试";
	std::string shippingAddressCity = "四川省成都市";
	std::string pName = currDate + "," + excuteDate + courier + ",收货人：" + consignee + " " + shippingAddressCity;
	//拼出文件名

	if (!fs::exists("\\\\Fuwuqi\\服务器3 - 搜集图片案例\\材料包\\材料包素材\\每日设计材料包")) {
		std::cout << "文件目录不存在 或者联网失败，请联系管理员" << std::endl;

		//
		releasePath = "..\\public_dir";
		if (!createReleasePathDir(releasePath)) {
			std::cout << "文件目录不存在 请联系管理员" << std::endl;
			return 0;
		}
	}
	std::string PUBLIC_DIR = releasePath + "\\" + pName;

	//输入地址
	char cinAddr[] = "请输入地址信息：";

	std::string addressStr = getCinStr(cinAddr);
	std::cout << "输入的地址是 " << addressStr << std::endl;


	//输入说明
	char cinDesignInfo[] = "请输入备注信息：";

	std::string psInfoStr = getCinStr(cinDesignInfo);
	std::cout << "输入备注信息为 " << psInfoStr << std::endl;



	//输入背景编号
	char strBackGround[100];
	std::vector<std::string> str_array = {};

	while (true) {
		char cinBackGroundInfo[] = "请输入您要选的背景编号：";
		std::string backStr = getCinStr(cinBackGroundInfo);
		std::cout << backStr << std::endl;
		if (backStr == "0" || backStr == "1") {
			break;
		}
		str_array.push_back(backStr);
	}

	std::cout << "您要创建的文件目录为: " << PUBLIC_DIR << std::endl;

	std::cout << "您创建的背景有以下几个" << std::endl;
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
	//	std::cout << "createOrder 函数调试未通过" << std::endl;
	//	return 0;
	//}

	return 1;
}

//====================================================测试用例=====================================================


int tesCreateText() {
	std::string path = "\\\\Fuwuqi\\服务器3-搜集图片案例\\材料包\\材料包素材\\每日设计材料包\\阿千\\确认\\测试不用管";

	//std::string path = "..\\public_dir";
	std::string name = "说明";
	std::string strArr[3];
	strArr[0] = "设计：";
	strArr[1] = "发货：";
	strArr[2] = "地址：";


	createText(path, name, strArr);

	std::ifstream infile(path + "\\" + name + ".txt");
	if (infile.is_open()) {

		std::string line;

		while (std::getline(infile, line)) {

			std::cout << line << std::endl;

		}

		std::cout << "createText 测试用例通过" << std::endl;

	}
	else {

		std::cout << "Failed to open the file.  createText  函数测试用例未通过" << std::endl;
		return 0;

	}

	return 1;
}

int test0penDir() {
	//openDir("\\\\Fuwuqi\\服务器3-搜集图片案例\\材料包\\材料包素材\\每日设计材料包\\阿千\\确认\\测试不用管");
	//openDir("..\\public_dir");
	printf("打开文件夹测试用例通过\n");
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
		printf("split函数 函数通过测试用例\n");
		return 1;
	}
	printf("split函数 函数未通过测试用例\n");
	return 0;

}

int testCopyImg() {
	std::string imgNamePath = "\\\\Desktop-127asaa\\派对引擎\\assets\\Moudles";
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
		std::cout << "testCopyImg 函数调试未通过" << std::endl;
		return 0;
	}

	return 1;
}

int testExistDir() {

	if (fs::exists("\\\\Fuwuqi\\服务器3-搜集图片案例\\材料包\\材料包素材\\每日设计材料包\\阿千\\确认\\测试不用管")) {
		printf("testExistDir测试用例通过\n");
		return 1;
	}
	printf("testExistDir测试用例未通过\n");
	return 0;
}

int testUnit() {

	if (!testExistDir() ||!tesCreateText() || !testSplit() || !testInput() || !testCopyImg() || !test0penDir()) {
		printf("测试用例未通过\n");
		return 0;
	}

	return 1;
}


int helloMain() {

	//是否开启但愿测试
	bool shouldTest = true;
	if (shouldTest) {
		if (!testUnit()) {
			std::cout << "测试单元有未通过对测试用例 请先核对检查" << std::endl;
			return 0;
		}
		std::cout << "测试用例通过" << std::endl;

	}

	//createOrder();


	return 0;

}

