#include "CLogger.h"
#include <iostream>

CLogger::CLogger()
{
	string sTimeStamp = getCurrentDate();
	string sPath = ".\\logs\\"+sTimeStamp;
	
	try
	{
		_mkdir(sPath.c_str());

		m_sFileName = sPath + "\\unnamedLog.log";
		
		if (!exists(m_sFileName.c_str()))
			m_oFileHandler.open(m_sFileName, std::ios::out);
		else
			m_oFileHandler.open(m_sFileName, std::ios::app);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

CLogger::CLogger(string sFileName)
{
	string sTimeStamp = getCurrentDate();
	string sPath = ".\\logs\\" + sTimeStamp;
	
	try
	{
		_mkdir(sPath.c_str());

		m_sFileName = sPath + "\\" + sFileName + ".log";
		
		if(!exists(m_sFileName.c_str()))
			m_oFileHandler.open(m_sFileName, std::ios::out);
		else
			m_oFileHandler.open(m_sFileName, std::ios::app);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

CLogger::~CLogger()
{
	try
	{
		m_oFileHandler.close();
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

int CLogger::log(string stringToLog)
{
	int iRetVal;

	try
	{
		stringToLog = "["+getCurrentTimeStamp() + "] - " + stringToLog + "\r\n";
		m_oFileHandler << stringToLog;
		iRetVal = stringToLog.length();
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
		iRetVal = -1;
	}

	return iRetVal;
}

bool CLogger::exists(string sFileName)
{
	std::ifstream file(sFileName.c_str());

	if (!file)
		return false;
	else
	{
		file.close();
		return true;
	}
}

string CLogger::getCurrentDate()
{
	time_t currTime;
	tm* pCurrTime;
	char sBuffer[11];
	string* p_sMyDate = nullptr;

	time(&currTime);
	pCurrTime = localtime(&currTime);

	strftime(sBuffer, 11, "%d-%m-%Y", pCurrTime);
	p_sMyDate = new string(sBuffer);

	return string(sBuffer);
}

string CLogger::getCurrentTimeStamp()
{
	time_t currTime;
	tm* pCurrTime;
	char sBuffer[20];
	string* p_sMyDate = nullptr;

	time(&currTime);
	pCurrTime = localtime(&currTime);

	strftime(sBuffer, 20, "%d-%m-%Y %H:%M:%S", pCurrTime);
	p_sMyDate = new string(sBuffer);

	return string(sBuffer);
}
