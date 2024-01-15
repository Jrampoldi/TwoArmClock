#include "coordinate_handler.h"


/* Defined value */ 
#define SIDE_SIZE			5

/* Global variable definitions */
volatile double arm_radians = 0;
volatile double base_radians = 0;
volatile double arm_degrees = 0;
volatile double base_degrees = 0;

/* function declarations */
void coordinate_to_rad(double x, double y);
double rad_to_degrees(double rad);

void move_arm(double x, double y){
	// functions needed for:
	// 	x-y to radians
	coordinate_to_rad(abs(x), y);

	//	radians to degree
	arm_degrees = rad_to_degrees(arm_radians);
	base_degrees = rad_to_degrees(base_radians);

	//	map_to_servo
	//	move_servo
	move_servo(map_to_servo(arm_degrees), map_to_servo(base_degrees), x);
}

void coordinate_to_rad(double x, double y){
	//write algo according to planning
	double sidei = sqrt(pow(x, 2) + pow(y, 2));	

	arm_radians = 2.0 * asin(sidei / (2.0 * SIDE_SIZE));
	base_radians = 180.0 - (atan(y / x) + acos( sidei / (2.0 * SIDE_SIZE)));
}

double rad_to_degrees(double rad){
	return (rad * (180.0 / M_PI));
}
