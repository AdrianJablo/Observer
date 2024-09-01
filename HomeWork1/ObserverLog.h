#ifndef OBSERVERLOG_H
#define OBSERVERLOG_H

#include <fstream>
#include <ctime>
#include <iostream>
#include <stdexcept>
#include "Observer.h"

//The ObserverLog hadles logging the events

class ObserverLog :public Observer
{
	std::ofstream logfile; // Log file stream

public:
	// Constructor opens the log file
	ObserverLog(const std::string& filename)
	{
		logfile.open(filename, std::ios_base::app);
		if (!logfile)
		{
			throw std::runtime_error("I can not open the file/do not exist"); // Throw if the file can't be opened
		}
	}

	// Handle event by writing to the log file
	void Handler(const std::string& event) override
	{
		if (logfile)
		{
			std::time_t now = std::time(nullptr);
			char buffer[26];
			ctime_s(buffer, sizeof(buffer), &now); // Using safer ctime_s
			logfile << event << " " << buffer; // Write event and time to log file
		}
	}

	// Destructor closes the log file
	~ObserverLog()
	{
		if (logfile)
		{
			logfile.close();
		}
	}
};

#endif // !OBSERVERLOG_H
