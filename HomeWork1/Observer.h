#ifndef OBSERVER_H
#define OBSERVER_H

#include <string>

//The observer interface, it will handle events 

class Observer
{
public:
	virtual void Handler(const std::string& event) = 0; // Pure virtual method to handle events
	
	virtual ~Observer() = default; // Virtual destructor
};

#endif // !OBSERVER_H

