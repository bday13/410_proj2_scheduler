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
	std::vector<PCB> stats;
	stats = *vec;

	for (PCB process: stats) {
		printf("Process %d Required CPU time:%d  arrived:%d started:%d finished:%d \n",
				process.process_number, process.required_cpu_time, process.arrival_time, process.start_time, process.finish_time);
	}
}

//after a process is placed in the ready_q, how long does
//it take before its placed on the processor?
//response_time per process = start_time - arrival_time
//this funtion returns the average over all processes
float Stats::get_av_response_time() {
	if (av_response_time == 0.0) {
		calcStats();
	}
	return av_response_time;
}

//after a process is placed in the ready_q, how long does
//it take to complete?
//turnaround time per process = finish_time - arrival_time
//this funtion returns the average over all processes
float Stats::get_av_turnaround_time() {
	if (av_turnaround_time == 0.0) {
		calcStats();
	}
	return av_turnaround_time;
}

//after a process is placed in the ready_q, how much time does it
//spend waiting for processor time?
//wait time per process = finish_time - arrival_time-required_CPU_time
//this funtion returns the average over all processes
float Stats::get_av_wait_time() {
	if (av_wait_time == 0.0) {
		calcStats();
	}
	return av_wait_time;
}

//does all the work
void Stats::calcStats() {
	float tempR = 0.0;
	float tempT = 0.0;
	float tempW = 0.0;

	for (PCB p : *vec) {
		tempR += p.start_time - p.arrival_time;
		tempT += p.finish_time - p.arrival_time;
		tempW += p.finish_time - p.arrival_time - p.required_cpu_time;
	}

	av_response_time = tempR/vec->size();
	av_turnaround_time = tempT/vec->size();
	av_wait_time = tempW/vec->size();
}
