#include "coordinate_handler.h"


/* Defined value */ 
#define SIDE_SIZE			5

/* Global variable definitions */
volatile float arm_radians = 0;
volatile float base_radians = 0;
volatile float arm_degrees = 0;
volatile float base_degrees = 0;

/* function declarations */
void coordinate_to_rad(float x, float y);
float rad_to_degrees(float rad);

void move_arm(float x, float y){
	// functions needed for:
	// 	x-y to radians
	coordinate_to_rad(abs(x), y);

	//	radians to degree
	arm_degrees = rad_to_degrees(arm_radians);
	base_degrees = 180.0 - rad_to_degrees(base_radians);

	//	map_to_servo
	//	move_servo
	move_servo(map_to_servo(base_degrees), map_to_servo(arm_degrees), x);
}

void coordinate_to_rad(float x, float y){
	//write algo according to planning
	double sidei = sqrt(pow(x, 2) + pow(y, 2));	

	arm_radians = 2.0 * asin(sidei / (2.0 * SIDE_SIZE));
	base_radians = (atan(y / x) + acos( sidei / (2.0 * SIDE_SIZE)));
}

float rad_to_degrees(float rad){
	return (rad * (180.0 / M_PI));
}
