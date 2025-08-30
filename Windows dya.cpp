#include<iostream>
#include<easyx.h>
#include<graphics.h>
#include<windows.h>
#include<mmsystem.h>
#include<shellapi.h>
#include<conio.h>
#include<vector>
#include<iostream>
#include<filesystem>
#include <glew.h>
#include <shlwapi.h>
#pragma comment(lib, "winmm.lib") 
#pragma comment(lib, "shlwapi.lib")

namespace fs = std::filesystem;

using namespace std;
// 正确定义消息结构体
MSG msg;

// 定义按钮点击状态变量
bool thiscomputerClicked = false;
bool InternetClicked = false;
bool trushbinClicked = false;
bool shezhiClicked = false;
bool down1Clicked = false;
bool shutClicked = false;
bool shutnext = false;
bool _shutdown = false;
bool newtextcheck = false;

int start;

#include <fstream>
#include <string>
#include <iostream>

bool createAndOpenFile(const std::string& filePath) {
	// 创建并写入文件
	std::ofstream file(filePath);
	if (!file.is_open()) {
		std::cerr << "无法创建文件: " << filePath << std::endl;
		return false;
	}
	file.close();

	
	return true;
}

bool checkthiscomputer() {
	// 需要获取最新鼠标坐标和事件 
	POINT chekdownofthiscomputer;
	GetCursorPos(&chekdownofthiscomputer);
	ScreenToClient(GetForegroundWindow(), &chekdownofthiscomputer);
	// 检测左键点击事件 
	if (GetAsyncKeyState(VK_LBUTTON) & 0x8000) {
		if (chekdownofthiscomputer.x >= 0 && chekdownofthiscomputer.x <= 75 && chekdownofthiscomputer.y >= 0 && chekdownofthiscomputer.y <= 75) {
			return true;
		}
	}
	return false;
}

bool checkshut() {
	// 需要获取最新鼠标坐标和事件 
	POINT checkdownofshut;
	GetCursorPos(&checkdownofshut);
	ScreenToClient(GetForegroundWindow(), &checkdownofshut);

	// 检测左键点击事件 
	if (GetAsyncKeyState(VK_LBUTTON) & 0x8000) {
		if (checkdownofshut.x >= 0 && checkdownofshut.x <= 50 && checkdownofshut.y >= 562 && checkdownofshut.y <= 600) {
			if (start == 0) start = 1;
			else if (start == 1) start = 0;
			return true;
		}
	}
	return false;
}

bool checkshut_next() {
	// 需要获取最新鼠标坐标和事件 
	POINT checkdownofshut_next;
	GetCursorPos(&checkdownofshut_next);
	ScreenToClient(GetForegroundWindow(), &checkdownofshut_next);

	// 检测左键点击事件 
	if (GetAsyncKeyState(VK_LBUTTON) & 0x8000) {
		if (checkdownofshut_next.x >= 600 && checkdownofshut_next.x <= 650 && checkdownofshut_next.y >= 562 && checkdownofshut_next.y <= 600) {
			if (start == 0) start = 1;
			else if (start == 1) start = 0;
			return true;
		}
	}
	return false;
}

bool checkInternet() {
	POINT checkdownofInternet;
	GetCursorPos(&checkdownofInternet);
	ScreenToClient(GetForegroundWindow(), &checkdownofInternet);

	// 检测左键点击事件 
	if (GetAsyncKeyState(VK_LBUTTON) & 0x8000) {
		if (checkdownofInternet.x >= 0 && checkdownofInternet.x <= 75 && checkdownofInternet.y >= 75 && checkdownofInternet.y <= 150) {
			return true;
		}
	}
	return false;
}

bool checktrushbin() {
	POINT checkdownoftrushbin;
	GetCursorPos(&checkdownoftrushbin);
	ScreenToClient(GetForegroundWindow(), &checkdownoftrushbin);

	// 检测左键点击事件 
	if (GetAsyncKeyState(VK_LBUTTON) & 0x8000) {
		if (checkdownoftrushbin.x >= 0 && checkdownoftrushbin.x <= 75 && checkdownoftrushbin.y >= 150 && checkdownoftrushbin.y <= 225 && start == 0) {
			return true;
		}
	}
	return false;
}

bool checkshezhi() {
	POINT checkdownofshezhi;
	GetCursorPos(&checkdownofshezhi);
	ScreenToClient(GetForegroundWindow(), &checkdownofshezhi);

	// 检测左键点击事件 
	if (GetAsyncKeyState(VK_LBUTTON) & 0x8000) {
		if (checkdownofshezhi.x >= 0 && checkdownofshezhi.x <= 75 && checkdownofshezhi.y >= 225 && checkdownofshezhi.y <= 300 && start ==0) {
			return true;
		}
	}
	return false;
}

bool checkbluescreen() {
	fs::path folderPath = ".\\硬盘\\C盘\\config";
	// 指定要检查的文件名
	fs::path fileName = "MBR.txt";

	// 构造完整的文件路径
	fs::path filePath = folderPath / fileName;

	// 检查文件是否存在且为常规文件
	if (fs::exists(filePath) && fs::is_regular_file(filePath)) {
		//return true;
	}
	else {
		return false;
	}

	folderPath = ".\\硬盘\\C盘\\system";
	fileName = "explorer01.exe";
	filePath = folderPath / fileName;
	if (fs::exists(filePath) && fs::is_regular_file(filePath)) {
		//return true;
	}
	else {
		return false;
	}

	folderPath = ".\\硬盘\\C盘\\system";
	fileName = "explorer10.exe";
	filePath = folderPath / fileName;
	if (fs::exists(filePath) && fs::is_regular_file(filePath)) {
		//return true;
	}
	else {
		return false;
	}

	folderPath = ".\\硬盘\\C盘\\system";
	fileName = "explorer11.exe";
	filePath = folderPath / fileName;
	if (fs::exists(filePath) && fs::is_regular_file(filePath)) {
		//return true;
	}
	else {
		return false;
	}

	folderPath = ".\\硬盘\\C盘\\system";
	fileName = "Internet1.exe";
	filePath = folderPath / fileName;
	if (fs::exists(filePath) && fs::is_regular_file(filePath)) {
		//return true;
	}
	else {
		return false;
	}

	folderPath = ".\\硬盘\\C盘\\system";
	fileName = "Windows dy1a.exe";
	filePath = folderPath / fileName;
	if (fs::exists(filePath) && fs::is_regular_file(filePath)) {
		//return true;
	}
	else {
		return false;
	}

	folderPath = ".\\硬盘\\C盘\\windows dya";
	fileName = "explorer1.exe";
	filePath = folderPath / fileName;
	if (fs::exists(filePath) && fs::is_regular_file(filePath)) {
		//return true;
	}
	else {
		return false;
	}

	folderPath = ".\\硬盘\\C盘\\windows dya";
	fileName = "Internet_nex1t.exe";
	filePath = folderPath / fileName;
	if (fs::exists(filePath) && fs::is_regular_file(filePath)) {
		//return true;
	}
	else {
		return false;
	}

	folderPath = ".\\硬盘\\C盘\\windows dya";
	fileName = "Internet.exe";
	filePath = folderPath / fileName;
	if (fs::exists(filePath) && fs::is_regular_file(filePath)) {
		//return true;
	}
	else {
		return false;
	}

	folderPath = ".\\硬盘\\C盘\\windows dya";
	fileName = "设备设置.exe";
	filePath = folderPath / fileName;
	if (fs::exists(filePath) && fs::is_regular_file(filePath)) {
		//return true;
	}
	else {
		return false;
	}
}

void RunHiddenProcess(const char* relativePath) {
	// 获取当前工作目录
	char currentDir[MAX_PATH];
	GetCurrentDirectoryA(MAX_PATH, currentDir);

	// 拼接完整路径
	char fullPath[MAX_PATH];
	PathCombineA(fullPath, currentDir, relativePath);

	STARTUPINFOA si = { sizeof(si) };
	PROCESS_INFORMATION pi;
	// 使用完整路径创建进程，保持隐藏窗口特性
	CreateProcessA(NULL, fullPath, NULL, NULL, FALSE,
		CREATE_NO_WINDOW, NULL, NULL, &si, &pi);
	CloseHandle(pi.hThread);
	CloseHandle(pi.hProcess);
}

bool checkdown1() {
	POINT checkdownof1;
	GetCursorPos(&checkdownof1);
	ScreenToClient(GetForegroundWindow(), &checkdownof1);

	// 检测左键点击事件 
	if (GetAsyncKeyState(VK_LBUTTON) & 0x8000) {
		if (checkdownof1.x >= 0 && checkdownof1.x <= 75 && checkdownof1.y >= 300 && checkdownof1.y <= 375 && start == 0 ) {
			return true;
		}
	}
	return false;
}

// 检查鼠标左键是否释放
bool isLeftButtonReleased() {
	return !(GetAsyncKeyState(VK_LBUTTON) & 0x8000);
}

#include <windows.h>
#include <mmsystem.h>

void open() {
	for (int ans = 0; ans < 5; ans++) {
		IMAGE frame_00_delay;
		loadimage(&frame_00_delay, ".\\硬盘\\C盘\\windows dya\\open\\frame_00_delay-0.05s.gif", 1280, 600);
		putimage(0, 0, &frame_00_delay);
		Sleep(4);
		IMAGE frame_01_delay;
		loadimage(&frame_01_delay, ".\\硬盘\\C盘\\windows dya\\open\\frame_01_delay-0.05s.gif", 1280, 600);
		putimage(0, 0, &frame_01_delay);
		Sleep(4);
		IMAGE frame_02_delay;
		loadimage(&frame_02_delay, ".\\硬盘\\C盘\\windows dya\\open\\frame_02_delay-0.05s.gif", 1280, 600);
		putimage(0, 0, &frame_02_delay);
		Sleep(4);
		IMAGE frame_03_delay;
		loadimage(&frame_03_delay, ".\\硬盘\\C盘\\windows dya\\open\\frame_03_delay-0.05s.gif", 1280, 600);
		putimage(0, 0, &frame_03_delay);
		Sleep(4);
		IMAGE frame_04_delay;
		loadimage(&frame_04_delay, ".\\硬盘\\C盘\\windows dya\\open\\frame_04_delay-0.05s.gif", 1280, 600);
		putimage(0, 0, &frame_04_delay);
		Sleep(4);
		IMAGE frame_05_delay;
		loadimage(&frame_05_delay, ".\\硬盘\\C盘\\windows dya\\open\\frame_05_delay-0.05s.gif", 1280, 600);
		putimage(0, 0, &frame_05_delay);
		Sleep(4);
		IMAGE frame_06_delay;
		loadimage(&frame_06_delay, ".\\硬盘\\C盘\\windows dya\\open\\frame_06_delay-0.05s.gif", 1280, 600);
		putimage(0, 0, &frame_06_delay);
		Sleep(4);
		IMAGE frame_07_delay;
		loadimage(&frame_07_delay, ".\\硬盘\\C盘\\windows dya\\open\\frame_07_delay-0.05s.gif", 1280, 600);
		putimage(0, 0, &frame_07_delay);
		Sleep(4);
		IMAGE frame_08_delay;
		loadimage(&frame_08_delay, ".\\硬盘\\C盘\\windows dya\\open\\frame_08_delay-0.05s.gif", 1280, 600);
		putimage(0, 0, &frame_08_delay);
		Sleep(4);
		IMAGE frame_09_delay;
		loadimage(&frame_09_delay, ".\\硬盘\\C盘\\windows dya\\open\\frame_09_delay-0.05s.gif", 1280, 600);
		putimage(0, 0, &frame_09_delay);
		Sleep(4);
		IMAGE frame_10_delay;
		loadimage(&frame_10_delay, ".\\硬盘\\C盘\\windows dya\\open\\frame_10_delay-0.05s.gif", 1280, 600);
		putimage(0, 0, &frame_10_delay);
		Sleep(4);
		IMAGE frame_11_delay;
		loadimage(&frame_11_delay, ".\\硬盘\\C盘\\windows dya\\open\\frame_11_delay-0.05s.gif", 1280, 600);
		putimage(0, 0, &frame_11_delay);
		Sleep(4);
		IMAGE frame_12_delay;
		loadimage(&frame_12_delay, ".\\硬盘\\C盘\\windows dya\\open\\frame_12_delay-0.05s.gif", 1280, 600);
		putimage(0, 0, &frame_12_delay);
		Sleep(4);
		IMAGE frame_13_delay;
		loadimage(&frame_13_delay, ".\\硬盘\\C盘\\windows dya\\open\\frame_13_delay-0.05s.gif", 1280, 600);
		putimage(0, 0, &frame_13_delay);
		Sleep(4);
		IMAGE frame_14_delay;
		loadimage(&frame_14_delay, ".\\硬盘\\C盘\\windows dya\\open\\frame_14_delay-0.05s.gif", 1280, 600);
		putimage(0, 0, &frame_14_delay);
		Sleep(4);
		IMAGE frame_15_delay;
		loadimage(&frame_15_delay, ".\\硬盘\\C盘\\windows dya\\open\\frame_15_delay-0.05s.gif", 1280, 600);
		putimage(0, 0, &frame_15_delay);
		Sleep(4);
		IMAGE frame_16_delay;
		loadimage(&frame_16_delay, ".\\硬盘\\C盘\\windows dya\\open\\frame_16_delay-0.05s.gif", 1280, 600);
		putimage(0, 0, &frame_16_delay);
		Sleep(4);
		IMAGE frame_17_delay;
		loadimage(&frame_17_delay, ".\\硬盘\\C盘\\windows dya\\open\\frame_17_delay-0.05s.gif", 1280, 600);
		putimage(0, 0, &frame_17_delay);
		Sleep(4);
		IMAGE frame_18_delay;
		loadimage(&frame_18_delay, ".\\硬盘\\C盘\\windows dya\\open\\frame_18_delay-0.05s.gif", 1280, 600);
		putimage(0, 0, &frame_18_delay);
		Sleep(4);
		IMAGE frame_19_delay;
		loadimage(&frame_19_delay, ".\\硬盘\\C盘\\windows dya\\open\\frame_19_delay-0.05s.gif", 1280, 600);
		putimage(0, 0, &frame_19_delay);
		Sleep(4);
		IMAGE frame_20_delay;
		loadimage(&frame_20_delay, ".\\硬盘\\C盘\\windows dya\\open\\frame_20_delay-0.05s.gif", 1280, 600);
		putimage(0, 0, &frame_20_delay);
		Sleep(4);
		IMAGE frame_21_delay;
		loadimage(&frame_21_delay, ".\\硬盘\\C盘\\windows dya\\open\\frame_21_delay-0.05s.gif", 1280, 600);
		putimage(0, 0, &frame_21_delay);
		Sleep(4);
		IMAGE frame_22_delay;
		loadimage(&frame_22_delay, ".\\硬盘\\C盘\\windows dya\\open\\frame_22_delay-0.05s.gif", 1280, 600);
		putimage(0, 0, &frame_22_delay);
		Sleep(4);
		IMAGE frame_23_delay;
		loadimage(&frame_23_delay, ".\\硬盘\\C盘\\windows dya\\open\\frame_23_delay-0.05s.gif", 1280, 600);
		putimage(0, 0, &frame_23_delay);
		Sleep(4);
		IMAGE frame_24_delay;
		loadimage(&frame_24_delay, ".\\硬盘\\C盘\\windows dya\\open\\frame_24_delay-0.05s.gif", 1280, 600);
		putimage(0, 0, &frame_24_delay);
		Sleep(4);
		IMAGE frame_25_delay;
		loadimage(&frame_25_delay, ".\\硬盘\\C盘\\windows dya\\open\\frame_25_delay-0.05s.gif", 1280, 600);
		putimage(0, 0, &frame_25_delay);
		Sleep(4);
		IMAGE frame_26_delay;
		loadimage(&frame_26_delay, ".\\硬盘\\C盘\\windows dya\\open\\frame_26_delay-0.05s.gif", 1280, 600);
		putimage(0, 0, &frame_26_delay);
		Sleep(4);
	}
}

void shut() {
	for (int ans = 0; ans < 5; ans++) {
		IMAGE frame_00_delay;
		loadimage(&frame_00_delay, ".\\硬盘\\C盘\\windows dya\\shutdown\\frame_00_delay-0.04s.gif", 1280, 600);
		putimage(0, 0, &frame_00_delay);
		Sleep(2);
		IMAGE frame_01_delay;
		loadimage(&frame_01_delay, ".\\硬盘\\C盘\\windows dya\\shutdown\\frame_01_delay-0.04s.gif", 1280, 600);
		putimage(0, 0, &frame_01_delay);
		Sleep(2);
		IMAGE frame_02_delay;
		loadimage(&frame_02_delay, ".\\硬盘\\C盘\\windows dya\\shutdown\\frame_02_delay-0.04s.gif", 1280, 600);
		putimage(0, 0, &frame_02_delay);
		Sleep(2);
		IMAGE frame_03_delay;
		loadimage(&frame_03_delay, ".\\硬盘\\C盘\\windows dya\\shutdown\\frame_03_delay-0.04s.gif", 1280, 600);
		putimage(0, 0, &frame_03_delay);
		Sleep(2);
		IMAGE frame_04_delay;
		loadimage(&frame_04_delay, ".\\硬盘\\C盘\\windows dya\\shutdown\\frame_04_delay-0.04s.gif", 1280, 600);
		putimage(0, 0, &frame_04_delay);
		Sleep(2);
		IMAGE frame_05_delay;
		loadimage(&frame_05_delay, ".\\硬盘\\C盘\\windows dya\\shutdown\\frame_05_delay-0.04s.gif", 1280, 600);
		putimage(0, 0, &frame_05_delay);
		Sleep(2);
		IMAGE frame_06_delay;
		loadimage(&frame_06_delay, ".\\硬盘\\C盘\\windows dya\\shutdown\\frame_06_delay-0.04s.gif", 1280, 600);
		putimage(0, 0, &frame_06_delay);
		Sleep(2);
		IMAGE frame_07_delay;
		loadimage(&frame_07_delay, ".\\硬盘\\C盘\\windows dya\\shutdown\\frame_07_delay-0.04s.gif", 1280, 600);
		putimage(0, 0, &frame_07_delay);
		Sleep(2);
		IMAGE frame_08_delay;
		loadimage(&frame_08_delay, ".\\硬盘\\C盘\\windows dya\\shutdown\\frame_08_delay-0.04s.gif", 1280, 600);
		putimage(0, 0, &frame_08_delay);
		Sleep(2);
		IMAGE frame_09_delay;
		loadimage(&frame_09_delay, ".\\硬盘\\C盘\\windows dya\\shutdown\\frame_09_delay-0.04s.gif", 1280, 600);
		putimage(0, 0, &frame_09_delay);
		Sleep(2);
		IMAGE frame_10_delay;
		loadimage(&frame_10_delay, ".\\硬盘\\C盘\\windows dya\\shutdown\\frame_10_delay-0.04s.gif", 1280, 600);
		putimage(0, 0, &frame_10_delay);
		Sleep(2);
		IMAGE frame_11_delay;
		loadimage(&frame_11_delay, ".\\硬盘\\C盘\\windows dya\\shutdown\\frame_11_delay-0.04s.gif", 1280, 600);
		putimage(0, 0, &frame_11_delay);
		Sleep(2);
		IMAGE frame_12_delay;
		loadimage(&frame_12_delay, ".\\硬盘\\C盘\\windows dya\\shutdown\\frame_12_delay-0.04s.gif", 1280, 600);
		putimage(0, 0, &frame_12_delay);
		Sleep(2);
		IMAGE frame_13_delay;
		loadimage(&frame_13_delay, ".\\硬盘\\C盘\\windows dya\\shutdown\\frame_13_delay-0.04s.gif", 1280, 600);
		putimage(0, 0, &frame_13_delay);
		Sleep(2);
		IMAGE frame_14_delay;
		loadimage(&frame_14_delay, ".\\硬盘\\C盘\\windows dya\\shutdown\\frame_14_delay-0.04s.gif", 1280, 600);
		putimage(0, 0, &frame_14_delay);
		Sleep(2);
		IMAGE frame_15_delay;
		loadimage(&frame_15_delay, ".\\硬盘\\C盘\\windows dya\\shutdown\\frame_15_delay-0.04s.gif", 1280, 600);
		putimage(0, 0, &frame_15_delay);
		Sleep(2);
		IMAGE frame_16_delay;
		loadimage(&frame_16_delay, ".\\硬盘\\C盘\\windows dya\\shutdown\\frame_16_delay-0.04s.gif", 1280, 600);
		putimage(0, 0, &frame_16_delay);
		Sleep(2);
		IMAGE frame_17_delay;
		loadimage(&frame_17_delay, ".\\硬盘\\C盘\\windows dya\\shutdown\\frame_17_delay-0.04s.gif", 1280, 600);
		putimage(0, 0, &frame_17_delay);
		Sleep(2);
		IMAGE frame_18_delay;
		loadimage(&frame_18_delay, ".\\硬盘\\C盘\\windows dya\\shutdown\\frame_18_delay-0.04s.gif", 1280, 600);
		putimage(0, 0, &frame_18_delay);
		Sleep(2);
		IMAGE frame_19_delay;
		loadimage(&frame_19_delay, ".\\硬盘\\C盘\\windows dya\\shutdown\\frame_19_delay-0.04s.gif", 1280, 600);
		putimage(0, 0, &frame_19_delay);
		Sleep(2);
		IMAGE frame_20_delay;
		loadimage(&frame_20_delay, ".\\硬盘\\C盘\\windows dya\\shutdown\\frame_20_delay-0.04s.gif", 1280, 600);
		putimage(0, 0, &frame_20_delay);
		Sleep(2);
		IMAGE frame_21_delay;
		loadimage(&frame_21_delay, ".\\硬盘\\C盘\\windows dya\\shutdown\\frame_21_delay-0.04s.gif", 1280, 600);
		putimage(0, 0, &frame_21_delay);
		Sleep(2);
		IMAGE frame_22_delay;
		loadimage(&frame_22_delay, ".\\硬盘\\C盘\\windows dya\\shutdown\\frame_22_delay-0.04s.gif", 1280, 600);
		putimage(0, 0, &frame_22_delay);
		Sleep(2);
		IMAGE frame_23_delay;
		loadimage(&frame_23_delay, ".\\硬盘\\C盘\\windows dya\\shutdown\\frame_23_delay-0.04s.gif", 1280, 600);
		putimage(0, 0, &frame_23_delay);
		Sleep(2);
		IMAGE frame_24_delay;
		loadimage(&frame_24_delay, ".\\硬盘\\C盘\\windows dya\\shutdown\\frame_24_delay-0.04s.gif", 1280, 600);
		putimage(0, 0, &frame_24_delay);
		Sleep(2);
		IMAGE frame_25_delay;
		loadimage(&frame_25_delay, ".\\硬盘\\C盘\\windows dya\\shutdown\\frame_25_delay-0.04s.gif", 1280, 600);
		putimage(0, 0, &frame_25_delay);
		Sleep(2);
		IMAGE frame_26_delay;
		loadimage(&frame_26_delay, ".\\硬盘\\C盘\\windows dya\\shutdown\\frame_26_delay-0.04s.gif", 1280, 600);
		putimage(0, 0, &frame_26_delay);
		Sleep(2);
		IMAGE frame_27_delay;
		loadimage(&frame_27_delay, ".\\硬盘\\C盘\\windows dya\\shutdown\\frame_27_delay-0.04s.gif", 1280, 600);
		putimage(0, 0, &frame_27_delay);
		Sleep(2);
		IMAGE frame_28_delay;
		loadimage(&frame_28_delay, ".\\硬盘\\C盘\\windows dya\\shutdown\\frame_28_delay-0.04s.gif", 1280, 600);
		putimage(0, 0, &frame_28_delay);
		Sleep(2);
		IMAGE frame_29_delay;
		loadimage(&frame_29_delay, ".\\硬盘\\C盘\\windows dya\\shutdown\\frame_29_delay-0.04s.gif", 1280, 600);
		putimage(0, 0, &frame_29_delay);
		Sleep(2);
		IMAGE frame_30_delay;
		loadimage(&frame_30_delay, ".\\硬盘\\C盘\\windows dya\\shutdown\\frame_30_delay-0.04s.gif", 1280, 600);
		putimage(0, 0, &frame_30_delay);
		Sleep(2);
		IMAGE frame_31_delay;
		loadimage(&frame_31_delay, ".\\硬盘\\C盘\\windows dya\\shutdown\\frame_31_delay-0.04s.gif", 1280, 600);
		putimage(0, 0, &frame_31_delay);
		Sleep(2);
		IMAGE frame_32_delay;
		loadimage(&frame_32_delay, ".\\硬盘\\C盘\\windows dya\\shutdown\\frame_32_delay-0.04s.gif", 1280, 600);
		putimage(0, 0, &frame_32_delay);
		Sleep(2);
		IMAGE frame_33_delay;
		loadimage(&frame_33_delay, ".\\硬盘\\C盘\\windows dya\\shutdown\\frame_33_delay-0.04s.gif", 1280, 600);
		putimage(0, 0, &frame_33_delay);
		Sleep(2);
		IMAGE frame_34_delay;
		loadimage(&frame_34_delay, ".\\硬盘\\C盘\\windows dya\\shutdown\\frame_34_delay-0.04s.gif", 1280, 600);
		putimage(0, 0, &frame_34_delay);
		Sleep(2);
		IMAGE frame_35_delay;
		loadimage(&frame_35_delay, ".\\硬盘\\C盘\\windows dya\\shutdown\\frame_35_delay-0.04s.gif", 1280, 600);
		putimage(0, 0, &frame_35_delay);
		Sleep(2);
		IMAGE frame_36_delay;
		loadimage(&frame_36_delay, ".\\硬盘\\C盘\\windows dya\\shutdown\\frame_36_delay-0.04s.gif", 1280, 600);
		putimage(0, 0, &frame_36_delay);
		Sleep(2);
		IMAGE frame_37_delay;
		loadimage(&frame_37_delay, ".\\硬盘\\C盘\\windows dya\\shutdown\\frame_37_delay-0.04s.gif", 1280, 600);
		putimage(0, 0, &frame_37_delay);
		Sleep(2);
		IMAGE frame_38_delay;
		loadimage(&frame_38_delay, ".\\硬盘\\C盘\\windows dya\\shutdown\\frame_38_delay-0.04s.gif", 1280, 600);
		putimage(0, 0, &frame_38_delay);
		Sleep(2);
		IMAGE frame_39_delay;
		loadimage(&frame_39_delay, ".\\硬盘\\C盘\\windows dya\\shutdown\\frame_39_delay-0.04s.gif", 1280, 600);
		putimage(0, 0, &frame_39_delay);
		Sleep(2);
		IMAGE frame_40_delay;
		loadimage(&frame_40_delay, ".\\硬盘\\C盘\\windows dya\\shutdown\\frame_40_delay-0.04s.gif", 1280, 600);
		putimage(0, 0, &frame_40_delay);
		Sleep(2);
		IMAGE frame_41_delay;
		loadimage(&frame_41_delay, ".\\硬盘\\C盘\\windows dya\\shutdown\\frame_41_delay-0.04s.gif", 1280, 600);
		putimage(0, 0, &frame_41_delay);
		Sleep(2);
		IMAGE frame_42_delay;
		loadimage(&frame_42_delay, ".\\硬盘\\C盘\\windows dya\\shutdown\\frame_42_delay-0.04s.gif", 1280, 600);
		putimage(0, 0, &frame_42_delay);
		Sleep(2);
		IMAGE frame_43_delay;
		loadimage(&frame_43_delay, ".\\硬盘\\C盘\\windows dya\\shutdown\\frame_43_delay-0.04s.gif", 1280, 600);
		putimage(0, 0, &frame_43_delay);
		Sleep(2);
		IMAGE frame_44_delay;
		loadimage(&frame_44_delay, ".\\硬盘\\C盘\\windows dya\\shutdown\\frame_44_delay-0.04s.gif", 1280, 600);
		putimage(0, 0, &frame_44_delay);
		Sleep(2);
		IMAGE frame_45_delay;
		loadimage(&frame_45_delay, ".\\硬盘\\C盘\\windows dya\\shutdown\\frame_45_delay-0.04s.gif", 1280, 600);
		putimage(0, 0, &frame_45_delay);
		Sleep(2);
		IMAGE frame_46_delay;
		loadimage(&frame_46_delay, ".\\硬盘\\C盘\\windows dya\\shutdown\\frame_46_delay-0.04s.gif", 1280, 600);
		putimage(0, 0, &frame_46_delay);
		Sleep(2);
		IMAGE frame_47_delay;
		loadimage(&frame_47_delay, ".\\硬盘\\C盘\\windows dya\\shutdown\\frame_47_delay-0.04s.gif", 1280, 600);
		putimage(0, 0, &frame_47_delay);
		Sleep(2);
		IMAGE frame_48_delay;
		loadimage(&frame_48_delay, ".\\硬盘\\C盘\\windows dya\\shutdown\\frame_48_delay-0.04s.gif", 1280, 600);
		putimage(0, 0, &frame_48_delay);
		Sleep(2);
		IMAGE frame_49_delay;
		loadimage(&frame_49_delay, ".\\硬盘\\C盘\\windows dya\\shutdown\\frame_49_delay-0.04s.gif", 1280, 600);
		putimage(0, 0, &frame_49_delay);
		Sleep(2);
		IMAGE frame_50_delay;
		loadimage(&frame_50_delay, ".\\硬盘\\C盘\\windows dya\\shutdown\\frame_50_delay-0.04s.gif", 1280, 600);
		putimage(0, 0, &frame_50_delay);
		Sleep(2);
		IMAGE frame_51_delay;
		loadimage(&frame_51_delay, ".\\硬盘\\C盘\\windows dya\\shutdown\\frame_51_delay-0.04s.gif", 1280, 600);
		putimage(0, 0, &frame_51_delay);
		Sleep(2);
		IMAGE frame_52_delay;
		loadimage(&frame_52_delay, ".\\硬盘\\C盘\\windows dya\\shutdown\\frame_52_delay-0.04s.gif", 1280, 600);
		putimage(0, 0, &frame_52_delay);
		Sleep(2);
		IMAGE frame_53_delay;
		loadimage(&frame_53_delay, ".\\硬盘\\C盘\\windows dya\\shutdown\\frame_53_delay-0.04s.gif", 1280, 600);
		putimage(0, 0, &frame_53_delay);
		Sleep(2);
		IMAGE frame_54_delay;
		loadimage(&frame_54_delay, ".\\硬盘\\C盘\\windows dya\\shutdown\\frame_54_delay-0.04s.gif", 1280, 600);
		putimage(0, 0, &frame_54_delay);
		Sleep(2);
		IMAGE frame_55_delay;
		loadimage(&frame_55_delay, ".\\硬盘\\C盘\\windows dya\\shutdown\\frame_55_delay-0.04s.gif", 1280, 600);
		putimage(0, 0, &frame_55_delay);
		Sleep(2);
		IMAGE frame_56_delay;
		loadimage(&frame_56_delay, ".\\硬盘\\C盘\\windows dya\\shutdown\\frame_56_delay-0.04s.gif", 1280, 600);
		putimage(0, 0, &frame_56_delay);
		Sleep(2);
		IMAGE frame_57_delay;
		loadimage(&frame_57_delay, ".\\硬盘\\C盘\\windows dya\\shutdown\\frame_57_delay-0.04s.gif", 1280, 600);
		putimage(0, 0, &frame_57_delay);
		Sleep(2);
		IMAGE frame_58_delay;
		loadimage(&frame_58_delay, ".\\硬盘\\C盘\\windows dya\\shutdown\\frame_58_delay-0.04s.gif", 1280, 600);
		putimage(0, 0, &frame_58_delay);
		Sleep(2);
		IMAGE frame_59_delay;
		loadimage(&frame_59_delay, ".\\硬盘\\C盘\\windows dya\\shutdown\\frame_59_delay-0.04s.gif", 1280, 600);
		putimage(0, 0, &frame_59_delay);
		Sleep(2);
		IMAGE frame_60_delay;
		loadimage(&frame_60_delay, ".\\硬盘\\C盘\\windows dya\\shutdown\\frame_60_delay-0.04s.gif", 1280, 600);
		putimage(0, 0, &frame_60_delay);
		Sleep(2);
		IMAGE frame_61_delay;
		loadimage(&frame_61_delay, ".\\硬盘\\C盘\\windows dya\\shutdown\\frame_61_delay-0.04s.gif", 1280, 600);
		putimage(0, 0, &frame_61_delay);
		Sleep(2);
		IMAGE frame_62_delay;
		loadimage(&frame_62_delay, ".\\硬盘\\C盘\\windows dya\\shutdown\\frame_62_delay-0.04s.gif", 1280, 600);
		putimage(0, 0, &frame_62_delay);
		Sleep(2);
		IMAGE frame_63_delay;
		loadimage(&frame_63_delay, ".\\硬盘\\C盘\\windows dya\\shutdown\\frame_63_delay-0.04s.gif", 1280, 600);
		putimage(0, 0, &frame_63_delay);
		Sleep(2);
		IMAGE frame_64_delay;
		loadimage(&frame_64_delay, ".\\硬盘\\C盘\\windows dya\\shutdown\\frame_64_delay-0.04s.gif", 1280, 600);
		putimage(0, 0, &frame_64_delay);
		Sleep(2);
		IMAGE frame_65_delay;
		loadimage(&frame_65_delay, ".\\硬盘\\C盘\\windows dya\\shutdown\\frame_65_delay-0.04s.gif", 1280, 600);
		putimage(0, 0, &frame_65_delay);
		Sleep(2);
		IMAGE frame_66_delay;
		loadimage(&frame_66_delay, ".\\硬盘\\C盘\\windows dya\\shutdown\\frame_66_delay-0.04s.gif", 1280, 600);
		putimage(0, 0, &frame_66_delay);
		Sleep(2);
		IMAGE frame_67_delay;
		loadimage(&frame_67_delay, ".\\硬盘\\C盘\\windows dya\\shutdown\\frame_67_delay-0.04s.gif", 1280, 600);
		putimage(0, 0, &frame_67_delay);
		Sleep(2);
		IMAGE frame_68_delay;
		loadimage(&frame_68_delay, ".\\硬盘\\C盘\\windows dya\\shutdown\\frame_68_delay-0.04s.gif", 1280, 600);
		putimage(0, 0, &frame_68_delay);
		Sleep(2);
		IMAGE frame_69_delay;
		loadimage(&frame_69_delay, ".\\硬盘\\C盘\\windows dya\\shutdown\\frame_69_delay-0.04s.gif", 1280, 600);
		putimage(0, 0, &frame_69_delay);
		Sleep(2);
		IMAGE frame_70_delay;
		loadimage(&frame_70_delay, ".\\硬盘\\C盘\\windows dya\\shutdown\\frame_70_delay-0.04s.gif", 1280, 600);
		putimage(0, 0, &frame_70_delay);
		Sleep(2);
		IMAGE frame_71_delay;
		loadimage(&frame_71_delay, ".\\硬盘\\C盘\\windows dya\\shutdown\\frame_71_delay-0.04s.gif", 1280, 600);
		putimage(0, 0, &frame_71_delay);
		Sleep(2);
		IMAGE frame_72_delay;
		loadimage(&frame_72_delay, ".\\硬盘\\C盘\\windows dya\\shutdown\\frame_72_delay-0.04s.gif", 1280, 600);
		putimage(0, 0, &frame_72_delay);
		Sleep(2);
		IMAGE frame_73_delay;
		loadimage(&frame_73_delay, ".\\硬盘\\C盘\\windows dya\\shutdown\\frame_73_delay-0.04s.gif", 1280, 600);
		putimage(0, 0, &frame_73_delay);
		Sleep(2);
		IMAGE frame_74_delay;
		loadimage(&frame_74_delay, ".\\硬盘\\C盘\\windows dya\\shutdown\\frame_74_delay-0.04s.gif", 1280, 600);
		putimage(0, 0, &frame_74_delay);
		Sleep(2);
	}
	closegraph();
	return;
}

#include<ctime>

bool checkshutdown_next() {
	POINT _checkshutdown;
	GetCursorPos(&_checkshutdown);
	ScreenToClient(GetForegroundWindow(), &_checkshutdown);

	// 检测左键点击事件 
	if (GetAsyncKeyState(VK_LBUTTON) & 0x8000) {
		if (_checkshutdown.x >= 742 && _checkshutdown.x <= 771 && _checkshutdown.y >= 515 && _checkshutdown.y <= 541 && start == 1) {
			return true;
		}
	}
	return false;
}

bool checkshutdown() {
	POINT __checkshutdown;
	GetCursorPos(&__checkshutdown);
	ScreenToClient(GetForegroundWindow(), &__checkshutdown);

	// 检测左键点击事件 
	if (GetAsyncKeyState(VK_LBUTTON) & 0x8000) {
		if (__checkshutdown.x >= 341 && __checkshutdown.x <= 369 && __checkshutdown.y >= 515 && __checkshutdown.y <= 541 && start == 1) {
			return true;
		}
	}
	return false;
}

void checkdowns() {
	if (checkInternet() && !InternetClicked) {
		RunHiddenProcess(".\\硬盘\\C盘\\windows dya\\Internet1.exe");
		InternetClicked = true;
	}

	if (checkthiscomputer() && !thiscomputerClicked) {
		RunHiddenProcess(".\\硬盘\\C盘\\windows dya\\explorer1.exe");
		thiscomputerClicked = true;
	}

	if (checktrushbin() && !trushbinClicked) {
		system("explorer.exe shell:RecycleBinFolder");
		trushbinClicked = true;
	}

	if (checkshezhi() && !shezhiClicked) {
		ShellExecute(NULL, "open", "control.exe", NULL, NULL, SW_SHOWNORMAL);
		shezhiClicked = true;
	}



	if (checkdown1() && !down1Clicked) {
		RunHiddenProcess(".\\硬盘\\C盘\\windows dya\\设备设置.exe");
		down1Clicked = true;
	}

}
/*当LOGO在任务栏中间时，对开始菜单的应用的操作*/
bool explorer_at_startmenu() {
	POINT explorer_at_menu_down;
	GetCursorPos(&explorer_at_menu_down);
	ScreenToClient(GetForegroundWindow(), &explorer_at_menu_down);

	// 检测左键点击事件 
	if (GetAsyncKeyState(VK_LBUTTON) & 0x8000) {
		if (explorer_at_menu_down.x >= 417 && explorer_at_menu_down.x <= 561 && explorer_at_menu_down.y >= 221 && explorer_at_menu_down.y <= 323) {
			return true;
		}
	}
	return false;
}
// 417 221
bool notepad_at_startmenu() {
	POINT notepad_at_startmenu_down;
	GetCursorPos(&notepad_at_startmenu_down);
	ScreenToClient(GetForegroundWindow(), &notepad_at_startmenu_down);

	// 检测左键点击事件 
	if (GetAsyncKeyState(VK_LBUTTON) & 0x8000) {
		if (notepad_at_startmenu_down.x >= 562 && notepad_at_startmenu_down.x <= 675 && notepad_at_startmenu_down.y >= 221 && notepad_at_startmenu_down.y <= 323) {
			return true;
		}
	}
	return false;
}
bool paint_at_startmenu() {
	POINT paint_at_startmenu_down;
	GetCursorPos(&paint_at_startmenu_down);
	ScreenToClient(GetForegroundWindow(), &paint_at_startmenu_down);

	// 检测左键点击事件 
	if (GetAsyncKeyState(VK_LBUTTON) & 0x8000) {
		if (paint_at_startmenu_down.x >= 676 && paint_at_startmenu_down.x <= 776 && paint_at_startmenu_down.y >= 221 && paint_at_startmenu_down.y <= 323) {
			return true;
		}
	}
	return false;
}

/*当LOGO在任务栏左边时，对开始菜单的应用的操作*/
bool explorer_atleft_startmenu() {
	POINT explorer_atleft_menu_down;
	GetCursorPos(&explorer_atleft_menu_down);
	ScreenToClient(GetForegroundWindow(), &explorer_atleft_menu_down);

	// 检测左键点击事件 
	if (GetAsyncKeyState(VK_LBUTTON) & 0x8000) {
		if (explorer_atleft_menu_down.x >= 16 && explorer_atleft_menu_down.x <= 160 && explorer_atleft_menu_down.y >= 225 && explorer_atleft_menu_down.y <= 323) {
			return true;
		}
	}
	return false;
}
// 417 221
bool notepad_atleft_startmenu() {
	POINT notepad_atleft_startmenu_down;
	GetCursorPos(&notepad_atleft_startmenu_down);
	ScreenToClient(GetForegroundWindow(), &notepad_atleft_startmenu_down);

	// 检测左键点击事件 
	if (GetAsyncKeyState(VK_LBUTTON) & 0x8000) {
		if (notepad_atleft_startmenu_down.x >= 160 && notepad_atleft_startmenu_down.x <= 273 && notepad_atleft_startmenu_down.y >= 225 && notepad_atleft_startmenu_down.y <= 323) {
			return true;
		}
	}
	return false;
}
bool paint_atleft_startmenu() {
	POINT paint_atleft_startmenu_down;
	GetCursorPos(&paint_atleft_startmenu_down);
	ScreenToClient(GetForegroundWindow(), &paint_atleft_startmenu_down);

	// 检测左键点击事件 
	if (GetAsyncKeyState(VK_LBUTTON) & 0x8000) {
		if (paint_atleft_startmenu_down.x >= 273 && paint_atleft_startmenu_down.x <= 373 && paint_atleft_startmenu_down.y >= 225 && paint_atleft_startmenu_down.y <= 323) {
			return true;
		}
	}
	return false;
}

#include<iostream>
#include<easyx.h>
#include<Windows.h>
#include <graphics.h>
#include <conio.h>
#include <string>
#include <vector>
#include <fstream>


bool startlogo_at() {
	string startallback;
	// 从 First_station.txt 文件中读取内容到 selected1Content
	ifstream startallback_at("startallback_at.txt");
	if (startallback_at.is_open()) {
		// 使用 getline 函数读取文件内容到字符串
		getline(startallback_at, startallback);
		startallback_at.close();
	}
	if (startallback == "left") return true;
	else if (startallback == "middle") return false;

}
IMAGE textima;

POINT newtext_;
void newtext() {
	GetCursorPos(&newtext_);
	ScreenToClient(GetForegroundWindow(), &newtext_);
	// 检测右键点击事件 
	if (GetAsyncKeyState(VK_LBUTTON) & 0x8000) {
		if (newtext_.x>0&&newtext_.x<75&&newtext_.y>300&&newtext_.y<=375&&start==0) {
			
		}
	}
}
std::vector<std::string> txtFiles;
#include <iostream>
#include <filesystem>
#include <string>
#include <vector>

namespace fs = std::filesystem;
std::vector<std::string> getTxtFiles(const std::string& directory) {
	std::vector<std::string> txtFiles;

	for (const auto& entry : fs::directory_iterator(directory)) {
		if (entry.is_regular_file() && entry.path().extension() == ".txt") {
			txtFiles.push_back(entry.path().filename().string());
		}
	}

	return txtFiles;
}
int x=0, y=300;
int main() {
	initgraph(1280, 600);
	setbkmode(TRANSPARENT);
	cleardevice();
	setbkcolor(BLACK);
	open();

	if (checkbluescreen() == false) {
		IMAGE bluescreen_ima;
		loadimage(&bluescreen_ima, ".\\硬盘\\C盘\\windows dya\\Web\\bluescreen\\bluescreen.jpg",1280,600);
		cleardevice();
		putimage(0, 0, &bluescreen_ima);
	}

	/*加载桌面文件*/
	/*std::string folderPath = ".\\硬盘\\C盘\\user\\桌面"; // 替换为实际路径

	try {
		// 获取所有txt文件的文件名
		 txtFiles = getTxtFiles(folderPath);

		// 输出找到的文件数量
		std::cout << "找到 " << txtFiles.size() << " 个TXT文件" << std::endl;

		// 遍历vector并打印每个文件名
		for (const auto& fileName : txtFiles) {
			std::cout << fileName << std::endl;
		}

		// 现在你可以使用txtFiles vector进行后续操作
		// 例如，访问第一个文件名: txtFiles[0]
		// 或者遍历所有文件: for (const auto& file : txtFiles) {...}

	}
	catch (const fs::filesystem_error& e) {
		std::cerr << "文件系统错误: " << e.what() << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "错误: " << e.what() << std::endl;
	}

	*/

	bool startallbackcheck = startlogo_at();

	// 修正图片路径（建议使用相对路径）
	IMAGE wallpaper;
	loadimage(&wallpaper, ".\\硬盘\\C盘\\Windows dya\\Web\\Wallpaper\\img0.jpg", 1280, 600);
	putimage(0, 0, &wallpaper);

	IMAGE thiscom;
	loadimage(&thiscom, ".\\硬盘\\C盘\\Windows dya\\Web\\computer pictures\\thiscom.png", 75, 75);
	putimage(0, 0, &thiscom);

	IMAGE taskbar;
	loadimage(&taskbar, ".\\硬盘\\C盘\\Windows dya\\Web\\taskbar\\taskbar.png", 1280, 38);
	putimage(0, 562, &taskbar);

	IMAGE windowsdyapictures;
	loadimage(&windowsdyapictures, ".\\硬盘\\C盘\\Windows dya\\Web\\Windows dya pictures\\Windows dya pictures.png", 50, 38);
	if (startallbackcheck == true)
		putimage(0, 562, &windowsdyapictures);
	else if (startallbackcheck == false)
		putimage(600, 562, &windowsdyapictures);

	IMAGE Internet;
	loadimage(&Internet, ".\\硬盘\\C盘\\Windows dya\\Web\\Internet\\Internet.png", 75, 75);
	putimage(0, 75, &Internet);

	IMAGE trushbin;
	loadimage(&trushbin, ".\\硬盘\\C盘\\Windows dya\\Web\\trush bin\\trushbin.png", 75, 75);
	putimage(0, 150, &trushbin);

	IMAGE shezhi;
	loadimage(&shezhi, ".\\硬盘\\C盘\\Windows dya\\Web\\sh\\she zhi.png", 75, 75);
	putimage(0, 225, &shezhi);

	IMAGE shezhi1;
	loadimage(&shezhi1, ".\\硬盘\\C盘\\Windows dya\\Web\\设置\\设置.png", 75, 75);
	putimage(0, 300, &shezhi1);
	for (int numberstotal_of_txtFiles = 0; numberstotal_of_txtFiles < txtFiles.size(); numberstotal_of_txtFiles) {

	}
	// 正确的消息循环处理 
	while (true) {
		IMAGE frame_00_delay;
		loadimage(&frame_00_delay, ".\\硬盘\\C盘\\windows dya\\helppeople\\1.png");
		putimage(1229, 485, &frame_00_delay);
		Sleep(2);
		checkdowns();
		IMAGE frame_01_delay;
		loadimage(&frame_01_delay, ".\\硬盘\\C盘\\windows dya\\helppeople\\2.png");
		putimage(1229, 485, &frame_01_delay);
		Sleep(2);
		checkdowns();
		IMAGE frame_02_delay;
		loadimage(&frame_02_delay, ".\\硬盘\\C盘\\windows dya\\helppeople\\3.png");
		putimage(1229, 485, &frame_02_delay);
		Sleep(2);
		checkdowns();
		IMAGE frame_03_delay;
		loadimage(&frame_03_delay, ".\\硬盘\\C盘\\windows dya\\helppeople\\4.png");
		putimage(1229, 485, &frame_03_delay);
		Sleep(2);
		checkdowns();
		IMAGE frame_04_delay;
		loadimage(&frame_04_delay, ".\\硬盘\\C盘\\windows dya\\helppeople\\5.png");
		putimage(1229, 485, &frame_04_delay);
		Sleep(2);
		checkdowns();
		IMAGE frame_05_delay;
		loadimage(&frame_05_delay, ".\\硬盘\\C盘\\windows dya\\helppeople\\6.png");
		putimage(1229, 485, &frame_05_delay);
		Sleep(2);
		checkdowns();
		IMAGE frame_06_delay;
		loadimage(&frame_06_delay, ".\\硬盘\\C盘\\windows dya\\helppeople\\7.png");
		putimage(1229, 485, &frame_06_delay);
		Sleep(2);
		checkdowns();
		IMAGE frame_07_delay;
		loadimage(&frame_07_delay, ".\\硬盘\\C盘\\windows dya\\helppeople\\8.png");
		putimage(1229, 485, &frame_07_delay);
		Sleep(2);
		checkdowns();
		IMAGE frame_08_delay;
		loadimage(&frame_08_delay, ".\\硬盘\\C盘\\windows dya\\helppeople\\9.png");
		putimage(1229, 485, &frame_08_delay);
		Sleep(2);
		checkdowns();
		IMAGE frame_09_delay;
		loadimage(&frame_09_delay, ".\\硬盘\\C盘\\windows dya\\helppeople\\10.png");
		putimage(1229, 485, &frame_09_delay);
		Sleep(2);
		checkdowns();
		IMAGE frame_10_delay;
		loadimage(&frame_10_delay, ".\\硬盘\\C盘\\windows dya\\helppeople\\11.png");
		putimage(1229, 485, &frame_10_delay);
		Sleep(2);
		checkdowns();
		IMAGE frame_11_delay;
		loadimage(&frame_11_delay, ".\\硬盘\\C盘\\windows dya\\helppeople\\12.png");
		putimage(1229, 485, &frame_11_delay);
		Sleep(2);
		checkdowns();
		IMAGE frame_12_delay;
		loadimage(&frame_12_delay, ".\\硬盘\\C盘\\windows dya\\helppeople\\13.png");
		putimage(1229, 485, &frame_12_delay);
		Sleep(2);
		checkdowns();
		IMAGE frame_13_delay;
		loadimage(&frame_13_delay, ".\\硬盘\\C盘\\windows dya\\helppeople\\14.png");
		putimage(1229, 485, &frame_13_delay);
		Sleep(2);
		checkdowns();
		IMAGE frame_14_delay;
		loadimage(&frame_14_delay, ".\\硬盘\\C盘\\windows dya\\helppeople\\15.png");
		putimage(1229, 485, &frame_14_delay);
		Sleep(2);
		checkdowns();
		IMAGE frame_15_delay;
		loadimage(&frame_15_delay, ".\\硬盘\\C盘\\windows dya\\helppeople\\16.png");
		putimage(1229, 485, &frame_15_delay);
		Sleep(2);
		checkdowns();
		IMAGE frame_16_delay;
		loadimage(&frame_16_delay, ".\\硬盘\\C盘\\windows dya\\helppeople\\17.png");
		putimage(1229, 485, &frame_16_delay);
		Sleep(2);
		checkdowns();
		IMAGE frame_17_delay;
		loadimage(&frame_17_delay, ".\\硬盘\\C盘\\windows dya\\helppeople\\18.png");
		putimage(1229, 485, &frame_17_delay);
		Sleep(2);
		checkdowns();
		IMAGE frame_18_delay;
		loadimage(&frame_18_delay, ".\\硬盘\\C盘\\windows dya\\helppeople\\19.png");
		putimage(1229, 485, &frame_18_delay);
		Sleep(2);
		checkdowns();
		IMAGE frame_19_delay;
		loadimage(&frame_19_delay, ".\\硬盘\\C盘\\windows dya\\helppeople\\20.png");
		putimage(1229, 485, &frame_19_delay);
		Sleep(2);
		checkdowns();
		IMAGE frame_20_delay;
		loadimage(&frame_20_delay, ".\\硬盘\\C盘\\windows dya\\helppeople\\21.png");
		putimage(1229, 485, &frame_20_delay);
		Sleep(2);
		checkdowns();
		IMAGE frame_21_delay;
		loadimage(&frame_21_delay, ".\\硬盘\\C盘\\windows dya\\helppeople\\22.png");
		putimage(1229, 485, &frame_21_delay);
		Sleep(2);
		checkdowns();
		IMAGE frame_22_delay;
		loadimage(&frame_22_delay, ".\\硬盘\\C盘\\windows dya\\helppeople\\23.png");
		putimage(1229, 485, &frame_22_delay);
		Sleep(2);
		checkdowns();
		IMAGE frame_23_delay;
		loadimage(&frame_23_delay, ".\\硬盘\\C盘\\windows dya\\helppeople\\24.png");
		putimage(1229, 485, &frame_23_delay);
		Sleep(2);
		checkdowns();
		IMAGE frame_24_delay;
		loadimage(&frame_24_delay, ".\\硬盘\\C盘\\windows dya\\helppeople\\25.png");
		putimage(1229, 485, &frame_24_delay);
		Sleep(2);
		checkdowns();
		IMAGE frame_25_delay;
		loadimage(&frame_25_delay, ".\\硬盘\\C盘\\windows dya\\helppeople\\26.png");
		putimage(1229, 485, &frame_25_delay);
		Sleep(2);
		checkdowns();
		IMAGE frame_26_delay;
		loadimage(&frame_26_delay, ".\\硬盘\\C盘\\windows dya\\helppeople\\27.png");
		putimage(1229, 485, &frame_26_delay);
		Sleep(2);
		checkdowns();
		IMAGE frame_27_delay;
		loadimage(&frame_27_delay, ".\\硬盘\\C盘\\windows dya\\helppeople\\28.png");
		putimage(1229, 485, &frame_27_delay);
		Sleep(2);
		checkdowns();
		IMAGE frame_28_delay;
		loadimage(&frame_28_delay, ".\\硬盘\\C盘\\windows dya\\helppeople\\29.png");
		putimage(1229, 485, &frame_28_delay);
		Sleep(2);
		checkdowns();
		IMAGE frame_29_delay;
		loadimage(&frame_29_delay, ".\\硬盘\\C盘\\windows dya\\helppeople\\30.png");
		putimage(1229, 485, &frame_29_delay);
		Sleep(2);
		checkdowns();
		IMAGE frame_30_delay;
		loadimage(&frame_30_delay, ".\\硬盘\\C盘\\windows dya\\helppeople\\31.png");
		putimage(1229, 485, &frame_30_delay);
		Sleep(2);
		checkdowns();
		IMAGE frame_31_delay;
		loadimage(&frame_31_delay, ".\\硬盘\\C盘\\windows dya\\helppeople\\32.png");
		putimage(1229, 485, &frame_31_delay);
		Sleep(2);
		checkdowns();
		IMAGE frame_32_delay;
		loadimage(&frame_32_delay, ".\\硬盘\\C盘\\windows dya\\helppeople\\33.png");
		putimage(1229, 485, &frame_32_delay);
		Sleep(2);
		checkdowns();
		IMAGE frame_33_delay;
		loadimage(&frame_33_delay, ".\\硬盘\\C盘\\windows dya\\helppeople\\34.png");
		putimage(1229, 485, &frame_33_delay);
		Sleep(2);
		checkdowns();
		IMAGE frame_34_delay;
		loadimage(&frame_34_delay, ".\\硬盘\\C盘\\windows dya\\helppeople\\35.png");
		putimage(1229, 485, &frame_34_delay);
		Sleep(2);
		checkdowns();
		IMAGE frame_35_delay;
		loadimage(&frame_35_delay, ".\\硬盘\\C盘\\windows dya\\helppeople\\36.png");
		putimage(1229, 485, &frame_35_delay);
		Sleep(2);
		checkdowns();
		IMAGE frame_36_delay;
		loadimage(&frame_36_delay, ".\\硬盘\\C盘\\windows dya\\helppeople\\37.png");
		putimage(1229, 485, &frame_36_delay);
		Sleep(2);
		checkdowns();
		IMAGE frame_37_delay;
		loadimage(&frame_37_delay, ".\\硬盘\\C盘\\windows dya\\helppeople\\38.png");
		putimage(1229, 485, &frame_37_delay);
		Sleep(2);
		checkdowns();
		IMAGE frame_38_delay;
		loadimage(&frame_38_delay, ".\\硬盘\\C盘\\windows dya\\helppeople\\39.png");
		putimage(1229, 485, &frame_38_delay);
		Sleep(2);
		checkdowns();
		IMAGE frame_39_delay;
		loadimage(&frame_39_delay, ".\\硬盘\\C盘\\windows dya\\helppeople\\40.png");
		putimage(1229, 485, &frame_39_delay);
		Sleep(2);
		checkdowns();
		IMAGE frame_40_delay;
		loadimage(&frame_40_delay, ".\\硬盘\\C盘\\windows dya\\helppeople\\41.png");
		putimage(1229, 485, &frame_40_delay);
		Sleep(2);
		checkdowns();
		IMAGE frame_41_delay;
		loadimage(&frame_41_delay, ".\\硬盘\\C盘\\windows dya\\helppeople\\42.png");
		putimage(1229, 485, &frame_41_delay);
		Sleep(2);
		checkdowns();
		IMAGE frame_42_delay;
		loadimage(&frame_42_delay, ".\\硬盘\\C盘\\windows dya\\helppeople\\43.png");
		putimage(1229, 485, &frame_42_delay);
		Sleep(2);
		checkdowns();
		IMAGE frame_43_delay;
		loadimage(&frame_43_delay, ".\\硬盘\\C盘\\windows dya\\helppeople\\44.png");
		putimage(1229, 485, &frame_43_delay);
		Sleep(2);
		checkdowns();
		IMAGE frame_44_delay;
		loadimage(&frame_44_delay, ".\\硬盘\\C盘\\windows dya\\helppeople\\45.png");
		putimage(1229, 485, &frame_44_delay);
		Sleep(2);
		checkdowns();
		IMAGE frame_45_delay;
		loadimage(&frame_45_delay, ".\\硬盘\\C盘\\windows dya\\helppeople\\46.png");
		putimage(1229, 485, &frame_45_delay);
		Sleep(2);
		checkdowns();
		IMAGE frame_46_delay;
		loadimage(&frame_46_delay, ".\\硬盘\\C盘\\windows dya\\helppeople\\47.png");
		putimage(1229, 485, &frame_46_delay);
		Sleep(2);
		checkdowns();
		IMAGE frame_47_delay;
		loadimage(&frame_47_delay, ".\\硬盘\\C盘\\windows dya\\helppeople\\48.png");
		putimage(1229, 485, &frame_47_delay);
		Sleep(2);
		checkdowns();
		IMAGE frame_48_delay;
		loadimage(&frame_48_delay, ".\\硬盘\\C盘\\windows dya\\helppeople\\49.png");
		putimage(1229, 485, &frame_48_delay);
		Sleep(2);
		checkdowns();
		IMAGE frame_49_delay;
		loadimage(&frame_49_delay, ".\\硬盘\\C盘\\windows dya\\helppeople\\50.png");
		putimage(1229, 485, &frame_49_delay);
		Sleep(2);
		checkdowns();
		IMAGE frame_50_delay;
		loadimage(&frame_50_delay, ".\\硬盘\\C盘\\windows dya\\helppeople\\51.png");
		putimage(1229, 485, &frame_50_delay);
		Sleep(2);
		checkdowns();
		IMAGE frame_51_delay;
		loadimage(&frame_51_delay, ".\\硬盘\\C盘\\windows dya\\helppeople\\52.png");
		putimage(1229, 485, &frame_51_delay);
		Sleep(2);
		checkdowns();
		IMAGE frame_52_delay;
		loadimage(&frame_52_delay, ".\\硬盘\\C盘\\windows dya\\helppeople\\53.png");
		putimage(1229, 485, &frame_52_delay);
		Sleep(2);
		checkdowns();
		IMAGE frame_53_delay;
		loadimage(&frame_53_delay, ".\\硬盘\\C盘\\windows dya\\helppeople\\54.png");
		putimage(1229, 485, &frame_53_delay);
		Sleep(2);
		checkdowns();
		IMAGE frame_54_delay;
		loadimage(&frame_54_delay, ".\\硬盘\\C盘\\windows dya\\helppeople\\55.png");
		putimage(1229, 485, &frame_54_delay);
		Sleep(2);
		checkdowns();
		IMAGE frame_55_delay;
		loadimage(&frame_55_delay, ".\\硬盘\\C盘\\windows dya\\helppeople\\56.png");
		putimage(1229, 485, &frame_55_delay);
		Sleep(2);
		checkdowns();
		IMAGE frame_56_delay;
		loadimage(&frame_56_delay, ".\\硬盘\\C盘\\windows dya\\helppeople\\57.png");
		putimage(1229, 485, &frame_56_delay);
		Sleep(2);
		checkdowns();
		IMAGE frame_57_delay;
		loadimage(&frame_57_delay, ".\\硬盘\\C盘\\windows dya\\helppeople\\58.png");
		putimage(1229, 485, &frame_57_delay);
		Sleep(2);
		checkdowns();
		IMAGE frame_58_delay;
		loadimage(&frame_58_delay, ".\\硬盘\\C盘\\windows dya\\helppeople\\59.png");
		putimage(1229, 485, &frame_58_delay);
		Sleep(2);
		checkdowns();
		IMAGE frame_59_delay;
		loadimage(&frame_59_delay, ".\\硬盘\\C盘\\windows dya\\helppeople\\60.png");
		putimage(1229, 485, &frame_59_delay);
		Sleep(2);
		checkdowns();
		IMAGE frame_60_delay;
		loadimage(&frame_60_delay, ".\\硬盘\\C盘\\windows dya\\helppeople\\61.png");
		putimage(1229, 485, &frame_60_delay);
		Sleep(2);
		checkdowns();
		IMAGE frame_61_delay;
		loadimage(&frame_61_delay, ".\\硬盘\\C盘\\windows dya\\helppeople\\62.png");
		putimage(1229, 485, &frame_61_delay);
		Sleep(2);
		if (IsWindowVisible(GetForegroundWindow())) { // 判断窗口是否可见
		checkdowns();
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		if (checkbluescreen() == false) {
			IMAGE bluescreens;
			loadimage(&bluescreens, ".\\硬盘\\C盘\\Windows dya\\Web\\bluescreen\\bluescreen.jpg", 1280, 600);
			putimage(0, 0, &bluescreens);
			Sleep(30000);
			return 0;
		}

		if (isLeftButtonReleased()) {
			// 鼠标左键释放，重置所有按钮点击状态
			thiscomputerClicked = false;
			InternetClicked = false;
			trushbinClicked = false;
			shezhiClicked = false;
			down1Clicked = false;
			shutClicked = false;
			shutnext = false;
			_shutdown = false;
			newtextcheck = false;
		}

		// 获取当前时间戳（从1970年1月1日至今的秒数）
		time_t now = time(nullptr);

		// 使用 localtime_s 替代 localtime
		tm localTime;
		errno_t err = localtime_s(&localTime, &now);
		if (err != 0) {
			std::cerr << "Failed to get local time." << std::endl;
			return 1;
		}

		// 输出年月日时分秒
		int tmyear = localTime.tm_year + 1900;  // 年份需加1900
		int tmmon = localTime.tm_mon + 1;    // 月份从0开始
		int tmday = localTime.tm_mday;
		int tmhour = localTime.tm_hour;
		int tmmin = localTime.tm_min;
		int tmsec = localTime.tm_sec;
		char text[100] = {};
		settextcolor(BLACK);
		settextstyle(20, 0, "宋体");
		sprintf_s(text, "%d年%d月%d日%d时%d分%d秒", tmyear, tmmon, tmday, tmhour, tmmin, tmsec);
		IMAGE taskbar;
		loadimage(&taskbar, ".\\硬盘\\C盘\\Windows dya\\Web\\taskbar\\taskbar.png", 1280, 38);
		putimage(50, 562, &taskbar);
		outtextxy(1000, 562, text);
		if (startallbackcheck == true)
			putimage(0, 562, &windowsdyapictures);
		else if (startallbackcheck == false)
			putimage(600, 562, &windowsdyapictures);



			if (checkInternet() && !InternetClicked) {
				RunHiddenProcess(".\\硬盘\\C盘\\windows dya\\Internet1.exe");
				InternetClicked = true;
			}

			if (checkthiscomputer() && !thiscomputerClicked) {
				RunHiddenProcess(".\\硬盘\\C盘\\windows dya\\explorer1.exe");
				thiscomputerClicked = true;
			}

			if (checktrushbin() && !trushbinClicked) {
				system("explorer.exe shell:RecycleBinFolder");
				trushbinClicked = true;
			}

			if (checkshezhi() && !shezhiClicked) {
				ShellExecute(NULL, "open", "control.exe", NULL, NULL, SW_SHOWNORMAL);
				shezhiClicked = true;
			}

			if (checkdown1() && !down1Clicked) {
				RunHiddenProcess(".\\硬盘\\C盘\\windows dya\\设备设置.exe");
				down1Clicked = true;
			}
			/*当LOGO在任务栏左部时，对开始菜单的操作*/
			if (checkshut() && !shutClicked && startallbackcheck == true) {
				if (start == 1) {
					IMAGE startmenu;
					loadimage(&startmenu, ".\\硬盘\\C盘\\windows dya\\Web\\startmenu\\startmenu.png");
					putimage(0, 162, &startmenu);

				}
				else if (start == 0) {
					cleardevice();
					IMAGE wallpaper;
					loadimage(&wallpaper, ".\\硬盘\\C盘\\Windows dya\\Web\\Wallpaper\\img0.jpg", 1280, 600);
					putimage(0, 0, &wallpaper);

					IMAGE thiscom;
					loadimage(&thiscom, ".\\硬盘\\C盘\\Windows dya\\Web\\computer pictures\\thiscom.png", 75, 75);
					putimage(0, 0, &thiscom);

					IMAGE taskbar;
					loadimage(&taskbar, ".\\硬盘\\C盘\\Windows dya\\Web\\taskbar\\taskbar.png", 1280, 38);
					putimage(0, 562, &taskbar);

					IMAGE windowsdyapictures;
					loadimage(&windowsdyapictures, ".\\硬盘\\C盘\\Windows dya\\Web\\Windows dya pictures\\Windows dya pictures.png", 50, 38);
					if (startallbackcheck == true)
						putimage(0, 562, &windowsdyapictures);
					else if (startallbackcheck == false)
						putimage(600, 562, &windowsdyapictures);

					IMAGE Internet;
					loadimage(&Internet, ".\\硬盘\\C盘\\Windows dya\\Web\\Internet\\Internet.png", 75, 75);
					putimage(0, 75, &Internet);

					IMAGE trushbin;
					loadimage(&trushbin, ".\\硬盘\\C盘\\Windows dya\\Web\\trush bin\\trushbin.png", 75, 75);
					putimage(0, 150, &trushbin);

					IMAGE shezhi;
					loadimage(&shezhi, ".\\硬盘\\C盘\\Windows dya\\Web\\sh\\she zhi.png", 75, 75);
					putimage(0, 225, &shezhi);

					IMAGE shezhi1;
					loadimage(&shezhi1, ".\\硬盘\\C盘\\Windows dya\\Web\\设置\\设置.png", 75, 75);
					putimage(0, 300, &shezhi1);
				}

			}
			if (checkshutdown() && start == 1) {
				shut();
			}
			/*当LOGO在任务栏中间时，对开始菜单的操作*/
			if (checkshut_next() && startallbackcheck == false && !shutnext) {
				if (start == 1) {
					IMAGE startmenu;
					loadimage(&startmenu, ".\\硬盘\\C盘\\windows dya\\Web\\startmenu\\startmenu.png");
					putimage(400, 162, &startmenu);

				}
				else if (start == 0) {
					cleardevice();
					IMAGE wallpaper;
					loadimage(&wallpaper, ".\\硬盘\\C盘\\Windows dya\\Web\\Wallpaper\\img0.jpg", 1280, 600);
					putimage(0, 0, &wallpaper);

					IMAGE thiscom;
					loadimage(&thiscom, ".\\硬盘\\C盘\\Windows dya\\Web\\computer pictures\\thiscom.png", 75, 75);
					putimage(0, 0, &thiscom);

					IMAGE taskbar;
					loadimage(&taskbar, ".\\硬盘\\C盘\\Windows dya\\Web\\taskbar\\taskbar.png", 1280, 38);
					putimage(0, 562, &taskbar);

					IMAGE windowsdyapictures;
					loadimage(&windowsdyapictures, ".\\硬盘\\C盘\\Windows dya\\Web\\Windows dya pictures\\Windows dya pictures.png", 50, 38);
					if (startallbackcheck == true)
						putimage(0, 562, &windowsdyapictures);
					else if (startallbackcheck == false)
						putimage(600, 562, &windowsdyapictures);

					IMAGE Internet;
					loadimage(&Internet, ".\\硬盘\\C盘\\Windows dya\\Web\\Internet\\Internet.png", 75, 75);
					putimage(0, 75, &Internet);

					IMAGE trushbin;
					loadimage(&trushbin, ".\\硬盘\\C盘\\Windows dya\\Web\\trush bin\\trushbin.png", 75, 75);
					putimage(0, 150, &trushbin);

					IMAGE shezhi;
					loadimage(&shezhi, ".\\硬盘\\C盘\\Windows dya\\Web\\sh\\she zhi.png", 75, 75);
					putimage(0, 225, &shezhi);

					IMAGE shezhi1;
					loadimage(&shezhi1, ".\\硬盘\\C盘\\Windows dya\\Web\\设置\\设置.png", 75, 75);
					putimage(0, 300, &shezhi1);
				}

			}
			if (checkshutdown_next() && !_shutdown) {
				shut();
			}
			if (start == 1 && startallbackcheck == false) {
				if (explorer_at_startmenu()) {
					RunHiddenProcess("explorer1.exe");
				}
				else if (notepad_at_startmenu()) {
					RunHiddenProcess("notepad.exe");
				}
				else if (paint_at_startmenu()) {
					RunHiddenProcess("mspaint.exe");
				}
			}
			if (start == 1 && startallbackcheck == true) {
				if (explorer_atleft_startmenu()) {
					RunHiddenProcess("explorer1.exe");
				}
				else if (notepad_atleft_startmenu()) {
					RunHiddenProcess("notepad.exe");
				}
				else if (paint_atleft_startmenu()) {
					RunHiddenProcess("mspaint.exe");
				}
			}
			/*
			if (!newtextcheck) {
				loadimage(&textima, ".\\硬盘\\C盘\\windows dya\\Web\\text\\text.png");
				putimage(0,300,&textima);
				newtext();

				std::string filePath = ".\\硬盘\\C盘\\user\\桌面\\newtext.txt"; // 替换为实际路径
				if (createAndOpenFile(filePath)) {
					// 可选：使用系统默认程序打开文件
					system(("start " + filePath).c_str());
				}
				RunHiddenProcess("rename.exe");
			}*/

		}
		Sleep(10); // 避免CPU占用过高 
		msg.message = 0;
	}
	return 0;
}




