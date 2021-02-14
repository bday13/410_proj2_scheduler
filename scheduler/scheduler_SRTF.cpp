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

}

bool sort_remaining_cpu_time(const PCB &measurement1, const PCB &measurement2) {
	return measurement1.remaining_cpu_time < measurement2.remaining_cpu_time;
}

//SRTF-preemptive - sort ready_q by remaining_cpu_time whenever add(PCB p) or time_to_switch_processes is called
void Scheduler_SRTF::sort() {
	return;
}
