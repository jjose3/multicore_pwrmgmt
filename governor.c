/*
 * model implementation for governor
 */

#include <stdio.h>

#include "governor.h"

void gov_init(struct gov_data *gov)
{
  if(gov==NULL){
    perror("gov: memory for gov_data is not allocated!!\n");
    return;
  }

  gov->cpu_util = 0;
  gov->targ_freq = 0;

  return;
}
