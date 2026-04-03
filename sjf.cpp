#include <iostream>
#include <vector>
#include "process.h"

int main(){
    int process_num;

    std::cout<<"Number of process:";
    std::cin>>process_num;

    std::vector<Process> process(process_num);

    //input
    std::cout<<"Input burst time\n";
    for(int i = 0; i< process_num; i++){
        std::cout<<"Process "<<i<<": ";
        std::cin>>process[i].burst_time;
        process[i].id = i;
        //default arrival time to 0;
        process[i].arrival_time=0;
    }

    // //list process details
    // for(int i = 0; i< process_num; i++){
    //     std::cout<<"Process "<<i<<": ";
    //     std::cout<<process[i].id<<"\t"<<process[i].burst_time<<"\t"<<process[i].waiting_time<<"\t"<<process[i].turnaround_time<<"\n";
    // }

    //didn't consider cases of jobs with differing arrival time
    //bubble
    for(int i = 0; i< process_num-1; i++){
        for (int j = 0; j < process_num-i-1; j++){
            bool swap = false;
            //smallest burst first (SJF)
            if(process[j].burst_time>process[j+1].burst_time){
                swap = true;
            //earliest arrival time first (FCFS)
            }else if(process[j].burst_time==process[j+1].burst_time){
                if(process[j].arrival_time>process[j+1].arrival_time){
                    swap = true;
                }
            }
            //swap
            if(swap){
                std::swap(process[j],process[j+1]);
            }
        }
    }


    //execution
    int global_time = 0;
    for(int i = 0; i< process_num; i++){
            //initialize process
            process[i].waiting_time = global_time - process[i].arrival_time;
            global_time += process[i].burst_time;
            process[i].turnaround_time = process[i].waiting_time + process[i].burst_time;
    }

    //list process details in table
    std::cout<<"\tID  Burst Time \t Waiting Time \t Turnaround Time \n";
    for(int i = 0; i< process_num; i++){
        std::cout<<"Process\t"<<process[i].id<<"\t"<<process[i].burst_time<<"\t\t"<<process[i].waiting_time<<"\t\t"<<process[i].turnaround_time<<"\n";
    }
}