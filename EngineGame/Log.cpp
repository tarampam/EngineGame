#include "Log.h"

using namespace std;
void Log::LogToConsole(string str)
{
	cout << "\nLOG : " << str << endl;
}

void Log::LogToFile(string str)
{
	str.insert(0, "\nLOG : ");
	log_queue.push_back(str);
}

string Log::GetFileName(string path)
{
	return "";
}

void Log::_InitLog(double ts, const char* file, int line_number)
{
	stringstream s;
	stringstream info;

	s << "\nTIME : [" << ts << "]\tTYPE : INIT_LOG   ";

	log_queue.insert(log_queue.begin(), log_header_text);
}

void Log::_LogInfo(char* vendor, char* version, char* renderer)
{
	stringstream info;

	info << "VENDOR : " << vendor << "\n" << "GL VERSION : " << version << "\n" << "RENDERER : " << renderer << "\n............................................\n";
	log_queue.insert(log_queue.begin() + 1, info.str());
}

void Log::_LogOpenGLInit(double ts, int version_minor, int version_major, const char* file, int line_number)
{
	stringstream s;

	s << "\nTIME : [" << ts << "]\tTYPE : INIT_GL " << version_minor << "." << version_major
		<< "\t| FILE : " << GetFileName(file) << "\tLINE : ["
		<< line_number << "]\n";

	log_queue.push_back(s.str());
}

void Log::_LogWindowCreation(double ts, const char* file, int line_number)
{
	stringstream s;

	s << "\nTIME : [" << ts << "]\tTYPE : INIT_WINDOW  " 
		<< "\t| FILE : " << GetFileName(file) << "\tLINE : ["
		<< line_number << "]  \n";

	log_queue.push_back(s.str());
}

void Log::_Log()
{
	static bool first_run = true;
	int logs_written = 0;
	ofstream log_file;

	if (first_run)
	{
		log_file.open(log_filepath, ios::out | ios::trunc);
	}

	else
	{
		log_file.open(log_filepath, ios::out | ios::app);
	}

	if (log_file.good() && log_file.is_open())
	{
		log_file.seekp(0, ios::end);

		for (int i = 0; i < log_queue.size(); i++)
		{
			log_file.write(log_queue[i].c_str(), log_queue[i].size());
			logs_written++;
		}

		log_queue.erase(log_queue.begin(), log_queue.begin() + logs_written);
	}
	else
	{
		LogToConsole((string)"Unable to open Log file to write the log...");
	}

	first_run = false;
	cout << "log";
	log_file.close();
}
