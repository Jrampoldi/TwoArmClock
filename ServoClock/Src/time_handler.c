#include "time_handler.h"

/* Function Declarations */
void update_time(int h, int m);
// Description: will call draw functions
// for all four digits and pass the value
// of hour and min appropriatetly.

/* Global Variables */
volatile int min = 0;
volatile int hr = 0;

void update_clock(){
    //60 seconds passed
    min++;
    if (min >= 60){
        min = 0;
        hr++;
    }
    if (hr >= 24){
        hr = 0;
    }
    update_time(hr, min);
}

void update_time(int h, int m){
    //call appropriate functions to 
    //draw time
    if (h >= 10){
        draw_D1((int)h / 10);
        draw_D2((int)h % 10);
    }
    else{
        draw_D1(0);
        draw_D2(h);
    }
    if (m >= 10){
        draw_D3((int)m / 10);
        draw_D4((int)m % 10);
    }
    else{
        draw_D3(0);
        draw_D4(m);
    }
}
