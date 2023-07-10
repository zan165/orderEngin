#include "PartOrder.h"
#include"Utils.h"



int main() {
	Utils::log("创建订单");

	std::string psInfo;
	std::string addr;
	std::vector<std::string> strBG_array = {};
	std::vector<std::string> strYBP_array = {};
	//是否包含迎宾牌 或 大头娃娃
	bool haveYBP = false;
	bool haveBG = true;

	if (Utils::exist("")) {

	}

	//地址
	Utils::log("请输入订单地址：");
	std::getline(std::cin, addr); // 从标准输入读取一行数据并存储到变量addr中

	std::cout << "您输入的地址是： " << addr << std::endl; // 输出用户输入的字符串


	//备注

	Utils::log("请输入订单备注信息：");
	std::getline(std::cin, psInfo); // 从标准输入读取一行数据并存储到变量psInfo中

	std::cout << "您输入的备注是： " << psInfo << std::endl; // 输出用户输入的字符串


	while (haveBG) {
		std::string bgCode;

		Utils::log("请输入背景编码，退出输入0   照片牌输入1：");
		std::getline(std::cin, bgCode);

		if (bgCode == "0" || bgCode == "1") {
			if (bgCode == "1") { haveYBP = true; }
			break;
		}
		if (bgCode == "" || Utils::hasSpace(bgCode)) {
			Utils::log("背景编码错误,请重新输入");
		}
		else {
			strBG_array.push_back(bgCode);
		}
	}

	while (haveYBP) {
		std::string ybpCode;

		Utils::log("请输入背景编码，退出输入0 ：");
		std::getline(std::cin, ybpCode);

		if (ybpCode == "0") {
			
			break;
		}
		if (ybpCode == "" || Utils::hasSpace(ybpCode)) {
			Utils::log("迎宾牌编码错误,请重新输入");
		}
		else {
			strYBP_array.push_back(ybpCode);
		}
	}

	Utils::log("您创建的背景有以下几个：");
	Utils::log(strBG_array);
	Utils::log("您创建的迎宾牌有以下几个：");
	Utils::log(strYBP_array);

	PartOrder *po = new PartOrder(addr, psInfo);
	po->tidyUpiInfo();
	po->insertBg(strBG_array);
	po->insetGreetingBord(strYBP_array);
	po->saveDataToFile();
	
	Utils::log("订单创建完成");
	return 0;
}