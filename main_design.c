/*
 * implementation of the main design
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "input_params.h"
#include "governor.h"
#include "user1.h"
#include "user2.h"


int main()
{

  struct gov_data *gov;
  struct user1_data *user1;
  struct user2_data *user2;
  unsigned long long curr_freq;

  gov = malloc(sizeof(struct gov_data));
  user1 = malloc(sizeof(struct user1_data));
  user2 = malloc(sizeof(struct user2_data));

  gov_init(gov);
  user1_init(user1);
  user2_init(user2);

  curr_freq = 800; //MHz
  sleep(SAMPLING_PERIOD);

  while(!user1->task_done || !user2->task_done){
   //find_targfreq(gov, curr_freq);
   user1_processfields(user1, curr_freq);
   user2_processfields(user2, curr_freq);

   //TODO: mathematical model and find the opt freq
   
    sleep(SAMPLING_PERIOD);
  }
  return 0;
}
