/*
 * header for input parameters, contains get voltage function
 */

#include <stdio.h>

#include "input_params.h"

float get_volt_from_freq(unsigned long long freq)
{
  float volt;
//freq-volt pairs
  switch(freq){
    case 500 : 
      volt = 1.5;
      break;
    case 1000 :
      volt = 2.0;
      break;
    case 1500 :
      volt = 2.5;
      break;
    default :
      perror("input_params: wrong freq value!!\n");
      return -1;
  }

  return volt;
}

