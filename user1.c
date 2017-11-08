/*
 * model implementation for user1
 */

#include <stdio.h>

#include "user1.h"

void user1_init(struct user1_data *user)
{
  if(user==NULL){
    perror("user1: memory for user1_data is not allocated!!\n");
    return;
  }

  user->exec_time = 0;
  user->rem_time = USER1_EXECTIME;
  user->dis_energy = 0;
  user->est_energy = 0;
  user->targ_freq = 0;

  printf("user1: %s: user1 init done\n", __func__);

  return;
}

void user1_processfields(struct user1_data *user, unsigned long long curr_freq)
{
  float op_volt;

  user->exec_time += user->exec_time+((SAMPLING_PERIOD*1000)/2); //assumes equal priority arbiter
  user->rem_time = USER1_EXECTIME-user->exec_time;
  
  op_volt = get_volt_from_freq(curr_freq);
  //TODO: add leakage current term, adjust units
  user->dis_energy = (DESIGN_CAP*op_volt*op_volt*curr_freq) * user->exec_time;
  user->est_energy = (DESIGN_CAP*op_volt*op_volt*curr_freq) * user->rem_time;
  user->total_energy = user->dis_energy+user->est_energy;

  return;
}

unsigned long user1_recalc_totalenergy(struct user1_data *user, unsigned long long freq)
{
  float op_volt;
  unsigned long est_energy;
  unsigned long total_energy;
  
  op_volt = get_volt_from_freq(freq);
  //TODO: add leakage current term, adjust units
  est_energy = (DESIGN_CAP*op_volt*op_volt*freq) * user->rem_time;
  total_energy = user->dis_energy+est_energy;

  return total_energy;
}
