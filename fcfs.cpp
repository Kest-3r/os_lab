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

    int global_time = 0;
    for(int i = 0; i< process_num; i++){
        if(process[i].is_complete==false){
            //initialize process
            process[i].waiting_time = global_time - process[i].arrival_time;
            global_time += process[i].burst_time;
            //process completed
            process[i].is_complete = true;
            process[i].turnaround_time = process[i].waiting_time + process[i].burst_time;
        }
    }

    //list process details in table
    std::cout<<"\tID  Burst Time \t Waiting Time \t Turnaround Time \n";
    for(int i = 0; i< process_num; i++){
        std::cout<<"Process\t"<<process[i].id<<"\t"<<process[i].burst_time<<"\t\t"<<process[i].waiting_time<<"\t\t"<<process[i].turnaround_time<<"\n";
    }
}