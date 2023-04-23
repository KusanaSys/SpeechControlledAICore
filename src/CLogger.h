#ifndef CLOGGER_LOADED
#define CLOGGER_LOADED 50
#define _CRT_SECURE_NO_WARNINGS 4996

#include <string>
#include <fstream>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <direct.h>

using std::string;
using std::fstream;

class CLogger
{
	public:
		CLogger();
		CLogger(string sFileName);
		~CLogger();

		int log(string stringToLog);
	private:
		string m_sFileName;
		fstream m_oFileHandler;
		bool exists(string sFileName);
		

		string getCurrentDate();
		string getCurrentTimeStamp();
	protected:
};
#endif

