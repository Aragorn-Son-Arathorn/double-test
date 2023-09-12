/* 
Doesn't work yet, trying to make it so that it goes to that website when it's done it's countdown.

Ultimately i'm trying to make it a pop-out timer that you can open and close, then add inputs to how long you want it to go

Right now it's a static 20 min timer that'll run 

slowly working on it


no inline comments because im a bastard that just ripped it from the internet 
*/

#include <iomanip>
#include <iostream>
#include <chrono>
#include <thread>

using namespace std::chrono_literals;

int main()
{
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
    /*
    So trying to get it so when the timer finishes, it opens up this link. 
    ShellExecute(NULL, "open", "https://www.youtube.com/watch?v=v9XyIGXcRck&ab_channel=Lofiboostyourmood", NULL, NULL, SW_SHOWNORMAL);
    */
    
    std::cout << "Done\n";
}
