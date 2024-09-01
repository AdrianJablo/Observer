/*
Observer.
Implement a console application that:
- Prints “hello world” (or any other text) in the console.
- watches the mouse moving: 
When the cursor moves to the console window area, the text color in the console changes and the current time is written into the log file with the tag “Enter”.
When the cursor leaves the console window area, the text color changes to the original and the current time is written into the log file with the tag “Leave”.
You may hardcode the path to the log file or put it in the same folder as exe file.
Use observer.
*/

#include <iostream>
#include "Monitor.h"
#include "ObserverLog.h"
#include "ObserverColor.h"
#include <memory>
#include <windows.h>

using namespace std;

int main()
{
    // Create instances of Monitor, ObserverLog, and ObserverColor
    try
    {
        auto monitor = make_shared<Monitor>();
        auto observerlog = make_shared<ObserverLog>("logobserved.txt");
        auto observercolor = make_shared<ObserverColor>();

        // Add observers to the monitor
        monitor->AddObserver(observerlog);
        monitor->AddObserver(observercolor);

        while (true)
        {
            monitor->CheckPosition(); // Check cursor position
            // To clear the screen and print every time new Hello world
            //Had problems with changing color on the console found this solution     
            system("cls"); 
            cout << "Hello World!\n";
            Sleep(100); // Check every 100ms
        }
    }
    catch(const exception& ex)
    {
        cerr << ex.what() << endl; 
        return 1;
    }
    return 0;
}
