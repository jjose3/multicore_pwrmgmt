/*
 * model header for user1, contains struct and functions
 */
#ifndef USER1_H
#define USER1_H

#include "input_params.h"

struct user1_data{
  unsigned long long exec_time; //ns
  unsigned long long rem_time;  //ns
  unsigned long dis_energy; //nJ
  unsigned long est_energy; //nJ
  unsigned long total_energy; //nJ
  unsigned long long targ_freq; //MHz
};

void user1_init(struct user1_data*);
void user1_processfields(struct user1_data*, unsigned long long);
unsigned long user1_recalc_totalenergy(struct user1_data*, unsigned long long);



#endif /* USER1_H */
