/*
 * contains user and governor input parameters like exec time, target energy, power scheme
 */
#ifndef INPUT_PARAMS_H
#define INPUT_PARAMS_H

#define USER1_EXECTIME 500 //ms
#define USER1_TARGENERGY 100 //nJ

#define USER2_EXECTIME 200 //ms
#define USER2_TARGENERGY 10 //nJ

#define GOV_SCHEME "ondemand"

#define DESIGN_CAP 100 //pF

#define SAMPLING_PERIOD 5 //us

float get_volt_from_freq(unsigned long long);

#endif /* INPUT_PARAMS_H */
