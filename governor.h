/*
 * model header for governor, contains struct and functions
 */
#ifndef GOVERNOR_H
#define GOVERNOR_H

#include "input_params.h"

struct gov_data{
  unsigned int cpu_util;
  unsigned long long targ_freq;
};

void gov_init(struct gov_data*);
void find_targfreq(struct gov_data*, unsigned long long curr_freq);
void get_cpuutil(struct gov_data*);

#endif /* GOVERNOR_H */
