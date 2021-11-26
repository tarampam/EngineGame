#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <filesystem>

class Log
{
public:
	std::string log_header_text = "Silnik Graficzny - Logowanie b³êdów \n\n";
	std::vector<std::string> log_queue;
	std::string log_filepath = (std::string)"log.txt";

	void LogToConsole(std::string str);
	void LogToFile(std::string str);

	//static string ExtendString(string str, int ex_amt, string ex_c);
	std::string GetFileName(std::string path);
	void _InitLog(double ts, const char* file, int line_number);
	void _LogInfo(char* vendor, char* version, char* renderer);
	void _LogOpenGLInit(double ts, int version_minor, int version_major, const char* file, int line_number);
	void _LogWindowCreation(double ts, const char* file, int line_number);
	void _Log();
};

