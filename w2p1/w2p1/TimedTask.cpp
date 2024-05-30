//
//  TimedTask.cpp
//  w2p1
//
//  Created by Sage Satsavia on 2024-05-24.
//

#include "TimedTask.h"

namespace seneca {

using namespace std;

    TimedTask::TimedTask() : numTasks(0) {}

void TimedTask::addTask(const char* taskName) {
    if (numTasks < 10) {
        tasks[numTasks].name = taskName;
        tasks[numTasks].unitTime = "nanoseconds";
        tasks[numTasks].duration = chrono::duration_cast<chrono::nanoseconds>(endTime - startTime);
        numTasks++;
    }
}

    void TimedTask::startClock() {
        startTime = chrono::steady_clock::now();
    }

    void TimedTask::stopClock() {
        endTime = chrono::steady_clock::now();
    }

  

ostream& operator<<(ostream& os, const TimedTask& timedTask) {
    
    os << "--------------------------\n";
    os << "Execution Times:\n";
    os << "--------------------------\n";
    for (size_t i = 0; i < timedTask.numTasks; ++i) {
        os << setw(21) << left << timedTask.tasks[i].name;
        os << setw(13) << right << chrono::duration_cast<chrono::nanoseconds>(timedTask.tasks[i].duration).count() << " ";
        os << timedTask.tasks[i].unitTime << "\n";
    }
    os << "--------------------------\n";
    return os;
  }

}


