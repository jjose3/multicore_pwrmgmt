/*
 * model implementation for governor
 */

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>


#include "governor.h"


unsigned int get_cpuutil(struct gov_data* gov_data)
{
//set cpuutil to be a rand value between 0 and 10
int seed = time(NULL);
srand(seed);   
int r = rand()%2;

   if (r)
	{
	cur_cpuutil = cur_cpuutil + 5;
		if (cur_cpuutil > 90)
		cur_cpuutil = 90;
	}
   else
	{
	cur_cpuutil = cur_cpuutil - 5;
		if (cur_cpuutil < 10)
		cur_cpuutil = 10;
	} 

gov_data->cpu_util = cur_cpuutil;
printf("CPU utilization set to: %d\n", gov_data->cpu_util);
return cur_cpuutil;
}

unsigned long long find_targfreq(struct gov_data* gov_data, unsigned long long curr_freq)
{
	
	target_freq = curr_freq;
	//get current cpuutil
	cur_cpuutil = get_cpuutil(gov_data);

	//check if current load is below or above threshold
	if (cur_cpuutil >= DEF_FREQUENCY_UP_THRESHOLD)
		{
		printf("CPU utilization crossed upper threshold\n");
		if (target_freq == SCALING_MAX_FREQ) //already at maximum scaling freq
		{	
			gov_data->targ_freq = target_freq;
			return target_freq;
		}
		else
		   {
		    target_freq = (1 + DEF_FREQUENCY_STEP/100) * target_freq;
		    if (target_freq >= SCALING_MAX_FREQ)
		    target_freq = SCALING_MAX_FREQ;
		    gov_data->targ_freq = target_freq;
		    return target_freq;
		    }
	
		} 
	else if (cur_cpuutil <= DEF_FREQUENCY_DOWN_THRESHOLD)
	{
	printf("CPU utilization below lower threshold\n");
		if (target_freq == SCALING_MIN_FREQ) //already at minimum scaling freq
		{	
			gov_data->targ_freq = target_freq;
			return target_freq;
		}
		else
		   {
		    target_freq = (1 - DEF_FREQUENCY_STEP/100) * target_freq;
		    if (target_freq <= SCALING_MIN_FREQ)
		    target_freq = SCALING_MIN_FREQ;
		    gov_data->targ_freq = target_freq;
		    return target_freq;
		    }
	}
	return target_freq;
}
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
