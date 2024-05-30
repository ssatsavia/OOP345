//
//  TimedTask.hpp
//  w2p2
//
//  Created by Sage Satsavia on 2024-05-24.
//


#ifndef SENECA_TIMEDTASK_H
#define SENECA_TIMEDTASK_H

#include <iostream>
#include <chrono>
#include <string>
#include <iomanip>

namespace seneca {
using namespace std;


    class TimedTask {
    public:
        struct Task {
            string name;
            string unitTime;
            chrono::steady_clock::duration duration;
        };

    private:
        Task tasks[10];
        size_t numTasks;
        chrono::steady_clock::time_point startTime;
        chrono::steady_clock::time_point endTime;

    public:
        TimedTask();
        void startClock();
        void stopClock();
        void addTask(const char* taskName);

        friend ostream& operator<<(ostream& os, const TimedTask& timedTask);
    };
}

#endif // SENECA_TIMEDTASK_H

