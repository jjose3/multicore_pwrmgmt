/*
 * model implementation for user2
 */

#include <stdio.h>

#include "user2.h"

void user2_init(struct user2_data *user)
{
  if(user==NULL){
    perror("user2: memory for user2_data is not allocated!!\n");
    return;
  }

  user->exec_time = 0;
  user->rem_time = USER2_EXECTIME;
  user->dis_energy = 0;
  user->est_energy = 0;
  user->targ_freq = 0;
  user->task_done = false;

  printf("user2: %s: user2 init done\n", __func__);

  return;
}

void user2_done(struct user2_data *user)
{
  if(user->exec_time != USER2_EXECTIME){
    return;
  }

  user->exec_time = USER2_EXECTIME;
  user->rem_time = 0;
  user->dis_energy = 0;
  user->est_energy = 0;
  user->targ_freq = 0;
  user->task_done = true;

  printf("user2: %s: user2 task done\n", __func__);

  return;
}

void user2_processfields(struct user2_data *user, unsigned long long curr_freq)
{
  float op_volt;

  user->exec_time += user->exec_time+((SAMPLING_PERIOD*1000)/2); //assumes equal priority arbiter
  user->rem_time = USER2_EXECTIME-user->exec_time;
  
  if(user->exec_time==USER2_EXECTIME){
    user2_done(user);
    return;
  }
  
  op_volt = get_volt_from_freq(curr_freq);
  //TODO: add leakage current term, adjust units
  user->dis_energy = (DESIGN_CAP*op_volt*op_volt*curr_freq) * user->exec_time;
  user->est_energy = (DESIGN_CAP*op_volt*op_volt*curr_freq) * user->rem_time;
  user->total_energy = user->dis_energy+user->est_energy;

  return;
}

unsigned long user2_recalc_totalenergy(struct user2_data *user, unsigned long long freq)
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
