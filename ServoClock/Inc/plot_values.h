#ifndef PLOT_VALUES_H_
#define PLOT_VALUES_H_

#include "coordinate_handler.h"
#include "stm32f411xe.h"

// Note: all values are based on
// the equation
//          y = sqrt(100 - pow(x, 2));
// where, the circle has a radius of 
// 10 inches (each arm is 5 inches)


void draw_colon();
// Description: responsible for drawing 
// the colon in the middle of map

void draw_one(int offset_x, int offset_y);
void draw_two(int offset_x, int offset_y);
void draw_three(int offset_x, int offset_y);
void draw_four(int offset_x, int offset_y);
void draw_five(int offset_x, int offset_y);
void draw_six(int offset_x, int offset_y);
void draw_seven(int offset_x, int offset_y);
void draw_eight(int offset_x, int offset_y);
void draw_nine(int offset_x, int offset_y);
// Description: Will draw a digit with
// offsets provided for x & y.

#endif
