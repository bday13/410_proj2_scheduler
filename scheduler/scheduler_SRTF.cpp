/*
 * SchedulerSRTF.cpp
 *
 *  Created on: Sep 10, 2019
 *      Author: keith
 *
 *      implements shortest remaining time first scheduling algorithm
 *     pre-emptive
 */

#include <algorithm>
#include "../includes/scheduler_SRTF.h"

using namespace std;

//override base class behaviour if necessary, otherwise call it
bool Scheduler_SRTF::time_to_switch_processes(int tick_count, PCB &p) {
	sort();
	return Scheduler::time_to_switch_processes(tick_count, p);}

bool sort_remaining(PCB &i, PCB &j) {
	return i.remaining_cpu_time < j.remaining_cpu_time;
}

//SRTF-preemptive - sort ready_q by remaining_cpu_time whenever add(PCB p) or time_to_switch_processes is called
void Scheduler_SRTF::sort() {
	preemptive = true;
	vector<PCB> tempVec;
	while (!ready_q->empty()) {
		tempVec.push_back(ready_q->front());
		ready_q->pop();
	}
	std::sort(tempVec.begin(), tempVec.end(), sort_remaining);

	for (int i = 0; i < tempVec.size(); i++) {
		ready_q->push(tempVec.at(i));
	}
}
