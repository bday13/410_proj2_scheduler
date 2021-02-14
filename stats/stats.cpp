/*
 * Stats.cpp
 *
 *  Created on: Sep 10, 2019
 *      Author: keith
 */

#include "../includes/stats.h"

using namespace std;

Stats::Stats(std::vector<PCB> &finished_vector) {
	av_response_time = 0.0;
	av_turnaround_time = 0.0;
	av_wait_time = 0.0;
	vec = &finished_vector;
}

//loops thru vec, prints 1 line for each process using the following format
//Process 1 Required CPU time:2  arrived:0 started:0 finished:2
//if there are 10 processes in vector, should print 10 lines
void Stats::showAllProcessInfo() {

}

//after a process is placed in the ready_q, how long does
//it take before its placed on the processor?
//response_time per process = start_time - arrival_time
//this funtion returns the average over all processes
float Stats::get_av_response_time() {

}

//after a process is placed in the ready_q, how long does
//it take to complete?
//turnaround time per process = finish_time - arrival_time
//this funtion returns the average over all processes
float Stats::get_av_turnaround_time() {

}

//after a process is placed in the ready_q, how much time does it
//spend waiting for processor time?
//wait time per process = finish_time - arrival_time-required_CPU_time
//this funtion returns the average over all processes
float Stats::get_av_wait_time() {

}

void Stats::calcStats() {
	av_turnaround_time = get_av_turnaround_time();
	av_response_time = get_av_response_time();
	av_wait_time = get_av_wait_time();
}
