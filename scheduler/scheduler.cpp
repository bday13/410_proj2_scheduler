/*
 * scheduler.cpp
 *
 *  Created on: Sep 8, 2019
 *      Author: keith
 */
#include "..includes/scheduler.h"

using namespace std;

//add a process, either a new one or one that
//had been running on the CPU and has been preempted
void Scheduler::add(PCB p) {

}

//get next process
PCB Scheduler::getNext() {

}

//returns true if there are no  jobs in the readyQ
//false otherwise
bool Scheduler::isEmpty() {

}

//if process has completed (used all its remaining_cpu_time) or
//if we are using a preemptive scheduling algorithm and the
//timeslice is over then its time to switch processes
//returns:
//true - switch processes
//false - do not switch
bool Scheduler::time_to_switch_processes(int tick_count, PCB &p) {

}

