#ifndef MONITOR_H
#define MONITOR_H

#include <vector>
#include <memory>
#include <algorithm>
#include <windows.h>
#include "Observer.h"

//This is a Subject class for maintaining a list of observers
//Methods to add, remove observers and to notify observers

class Monitor
{
	std::vector<std::shared_ptr<Observer>> observers; // List of observers

	bool cursorState = false; // Track cursor state (inside or outside the console)

	// Notify all observers of an event
	void Notify(const std::string& event)
	{
		for (auto& observer : observers)
		{
			observer->Handler(event); // Call the Handler method of each observer
		}
	}

public:
	// Add an observer to the list
	void AddObserver(std::shared_ptr<Observer> observer)
	{
		observers.push_back(observer);
	}
	
	// Remove an observer from the list
	void RemoverObserver(std::shared_ptr<Observer> observer)
	{
		observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
	}

	// Check the cursor position and notify observers if it changes
	void CheckPosition()
	{
		POINT p;
		if (GetCursorPos(&p))
		{
			HWND hwnd = WindowFromPoint(p);
			if (hwnd == GetConsoleWindow())
			{
				if (!cursorState)
				{
					cursorState = true;
					Notify("Enter"); // Notify observers that cursor entered the console window
				}
			}
			else
			{
				if (cursorState)
				{
					cursorState = false;
					Notify("Leave"); // Notify observers that cursor left the console window
				}
			}
		}
	}
};

#endif // !MONITOR_H

