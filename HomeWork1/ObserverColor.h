#ifndef OBSERVERCOLOR_H
#define OBSERVERCOLOR_H

#include <windows.h>
#include "Observer.h"

//The ObserverColor changes the color text in the console

class ObserverColor :public Observer
{
public:
	// Handle event by changing the console text color
	void Handler(const std::string& event) override
	{
		if (event == "Enter")
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN); // Change color to green
		}
		else if (event == "Leave")
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN); // Change color to white
		}
	}
};

#endif // !OBSERVERCOLOR_H