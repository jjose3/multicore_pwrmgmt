/*
 * model header for user2, contains struct and functions
 */
#ifndef USER2_H
#define USER2_H

#include "input_params.h"

struct user2_data{
  unsigned long long exec_time; //ns
  unsigned long long rem_time;  //ns
  unsigned long dis_energy; //nJ
  unsigned long est_energy; //nJ
  unsigned long total_energy; //nJ
  unsigned long long targ_freq; //MHz
};

void user2_init(struct user2_data*);
void user2_processfields(struct user2_data*, unsigned long long);
unsigned long user2_recalc_totalenergy(struct user2_data*, unsigned long long);


#endif /* USER2_H */
