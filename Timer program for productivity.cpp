/* 
Using just the windows API. no fancy shmancy frameworks...that'll come later once I know how to code
-----Ultimately i'm trying to make it a pop-out timer that you can open and close, then add inputs to how long you want it to go

Right now it's a static  min timer that'll run

slowly working on it

no inline comments because im a bastard that just ripped it from the internet 
*/

#include <Windows.h>
#include <iomanip>
#include <iostream>
#include <chrono>
#include <thread>
#include <string>
#include <ShellAPI.h>

using namespace std::chrono_literals;

/*

// Function to open a web page
void OpenWebPage(const std::string& url) {
    ShellExecuteA(nullptr, "open", url.c_str(), nullptr, nullptr, SW_SHOWNORMAL);
*/

int main()
{
    
    /*   
    std::string webpageURL = "https://www.youtube.com/watch?v=6H-PLF2CR18&ab_channel=LOFIKEEPYOUSAFE"; // Replace with your desired URL
    */
    
    const auto timer_duration = 20min;
    const auto start = std::chrono::steady_clock::now();

    std::chrono::duration<double> time_left = timer_duration - (std::chrono::steady_clock::now() - start);
    while (time_left > 0s)
    {
        const auto hrs = std::chrono::duration_cast<std::chrono::hours>(time_left);
        const auto mins = std::chrono::duration_cast<std::chrono::minutes>(time_left - hrs);
        const auto secs = std::chrono::duration_cast<std::chrono::seconds>(time_left - hrs - mins);
        std::cout << std::setfill('0') << std::setw(2) << hrs.count() << ":"
                  << std::setfill('0') << std::setw(2) << mins.count() << ":"
                  << std::setfill('0') << std::setw(2) << secs.count() << "\n";

        std::this_thread::sleep_for(1s);

        time_left = timer_duration - (std::chrono::steady_clock::now() - start);
    }
    std::cout << "Done\n";
}
