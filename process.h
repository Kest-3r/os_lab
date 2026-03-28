#ifndef PROCESS_H
#define PROCESS_H

struct Process{
    int id;
    int burst_time;
    int arrival_time;
    int waiting_time;
    int turnaround_time;
    bool is_complete = false;
};

#endif