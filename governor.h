/*
 * model header for governor, contains struct and functions
 */
#ifndef GOVERNOR_H
#define GOVERNOR_H

#include "input_params.h"

/* governor macros */
#define DEF_FREQUENCY_UP_THRESHOLD		(80)
#define DEF_FREQUENCY_DOWN_THRESHOLD		(20)
#define DEF_FREQUENCY_STEP			(5)
#define DEF_SAMPLING_DOWN_FACTOR		(1)
#define MAX_SAMPLING_DOWN_FACTOR		(10)
#define SCALING_MAX_FREQ			(2100000)
#define SCALING_MIN_FREQ			(800000)

unsigned int cur_cpuutil = 10;

struct gov_data{
  unsigned int cpu_util;
  unsigned long long targ_freq;
};

void gov_init(struct gov_data*);
unsigned long long find_targfreq(struct gov_data*, unsigned long long curr_freq);
unsigned int get_cpuutil(struct gov_data*);

#endif /* GOVERNOR_H */
