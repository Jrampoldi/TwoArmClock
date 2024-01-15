#ifndef TIME_HANDLER_H_
#define TIME_HANDLER_H_

#include "plot_values.h"


void update_clock();
// Description: will be called every
// 60 seconds and update min and 
// hour.
void update_time(int h, int m);
// Description: will call draw functions 
// for all four digits and pass the value
// of hour and min appropriatetly.

#endif
