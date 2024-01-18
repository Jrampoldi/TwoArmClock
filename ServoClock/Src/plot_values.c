#include "plot_values.h"

/*Definitions*/
#define Y_OFFSET            2

/*Global Variables*/
int zero_array_size = 10;
int one_array_size = 10;
int two_array_size = 12;
int three_array_size = 13;
int four_array_size = 10;
int five_array_size = 12;
int six_array_size = 14;
int seven_array_size = 6;
int eight_array_size = 17;
int nine_array_size = 14;

int zero_array[][2] = {{3, 1}, {3, 5}, {0, 5}, {0, 0},
						{1, 1}, {2, 1}, {2, 4}, {1, 4},
						{1, 1}, {0, 0}};

int one_array[][2] = {{3, 0}, {3, 1}, {2, 1}, {2, 4},
						{3, 4}, {3, 5}, {1, 5}, {1, 1},
						{0, 1}, {0, 0}};

int two_array[][2] = {{3, 0}, {3, 3}, {1, 3}, {1, 4},
						{3, 4},{3, 5}, {0, 5}, {0, 2},
						{2, 2}, {2, 1},{0, 1}, {0, 0}};


int three_array[][2] = {{3, 0}, {3, 1}, {1, 1}, {1, 2},
						{2, 2}, {3, 2}, {2, 3}, {1, 3},
						{1, 4}, {3, 4}, {3, 5}, {0, 5},
						{0, 0}};

int four_array[][2] = {{1, 1}, {2, 1}, {3, 2}, {3, 5},
						{2, 5}, {2, 3}, {1, 3}, {1, 5},
						{0, 5}, {0, 0}};

int five_array[][2] = {{0, 3}, {1, 3}, {1, 1}, {1, 2},
						{3, 2}, {3, 5}, {0, 5}, {0, 4},
						{2, 4}, {2, 3}, {0, 3}, {0, 0}};

int six_array[][2] = {{3, 0}, {3, 5}, {0, 5}, {0, 4},
						{2, 4}, {2, 3}, {0, 3}, {0, 0},
						{1, 1}, {2, 1}, {2, 2}, {1, 2},
						{1, 1}, {0, 0}};

int seven_array[][2] = {{1, 0}, {1, 4}, {3, 4}, {3, 5},
						{5, 0}, {0, 0}};

int eight_array[][2] = {{3, 1}, {3, 5}, {0, 5}, {0, 0},
						{1, 1}, {2, 1}, {2, 2}, {1, 2},
						{1, 1}, {1, 3}, {2, 3}, {2, 4},
						{1, 4}, {1, 3}, {1, 4}, {0, 5},
						{0, 0}};

int nine_array[][2] = {{1, 0}, {1, 2}, {3, 2}, {3, 5},
						{0, 5}, {0, 0}, {1, 0}, {1, 3},
						{2, 3}, {2, 4}, {1, 4}, {1, 3},
						{1, 0}, {0, 0}};

void draw_colon(){
    //colon to be centered on line
}


void draw_D1(int digit){
    int x_offset = -4;
	switch(digit){
		case 0: draw_zero(x_offset); break;
		case 1: draw_one(x_offset); break;
		case 2: draw_two(x_offset); break;
		case 3: draw_three(x_offset); break;
		case 4: draw_four(x_offset); break;
		case 5: draw_five(x_offset); break;
		case 6: draw_six(x_offset); break;
		case 7: draw_seven(x_offset); break;
		case 8: draw_eight(x_offset); break;
		case 9: draw_nine(x_offset); break;
	}
}
void draw_D2(int digit){
    int x_offset = -1;
	switch(digit){
		case 0: draw_zero(x_offset); break;
		case 1: draw_one(x_offset); break;
		case 2: draw_two(x_offset); break;
		case 3: draw_three(x_offset); break;
		case 4: draw_four(x_offset); break;
		case 5: draw_five(x_offset); break;
		case 6: draw_six(x_offset); break;
		case 7: draw_seven(x_offset); break;
		case 8: draw_eight(x_offset); break;
		case 9: draw_nine(x_offset); break;
	}
}
void draw_D3(int digit){
    int x_offset = 4;
	switch(digit){
		case 0: draw_zero(x_offset); break;
		case 1: draw_one(x_offset); break;
		case 2: draw_two(x_offset); break;
		case 3: draw_three(x_offset); break;
		case 4: draw_four(x_offset); break;
		case 5: draw_five(x_offset); break;
		case 6: draw_six(x_offset); break;
		case 7: draw_seven(x_offset); break;
		case 8: draw_eight(x_offset); break;
		case 9: draw_nine(x_offset); break;
	}
}
void draw_D4(int digit){
    int x_offset = 7;
	switch(digit){
		case 0: draw_zero(x_offset); break;
		case 1: draw_one(x_offset); break;
		case 2: draw_two(x_offset); break;
		case 3: draw_three(x_offset); break;
		case 4: draw_four(x_offset); break;
		case 5: draw_five(x_offset); break;
		case 6: draw_six(x_offset); break;
		case 7: draw_seven(x_offset); break;
		case 8: draw_eight(x_offset); break;
		case 9: draw_nine(x_offset); break;
	}
}
void draw_zero(int offset_x){
	printf("Drawing Zero:\n");
	for (int i = 0; i < one_array_size; i++){
		move_arm(zero_array[i][0] + offset_x, zero_array[i][1] + Y_OFFSET);
	}
}

void draw_one(int offset_x){
    //one with offsetx and offsety
	printf("Drawing One: \n");
	for (int i = 0; i < one_array_size; i++){
		move_arm(one_array[i][0] + offset_x, one_array[i][1] + Y_OFFSET);
	}
}
void draw_two(int offset_x){
    //two with offsetx and offsety
	for (int i = 0; i < two_array_size; i++){
		move_arm(two_array[i][0] + offset_x, two_array[i][1] + Y_OFFSET);
	}
}
void draw_three(int offset_x){
    //three with offsetx and offsety
	for (int i = 0; i < three_array_size; i++){
		move_arm(three_array[i][0] + offset_x, three_array[i][1] + Y_OFFSET);
	}
}
void draw_four(int offset_x){
    //four with offsetx and offsety
	for (int i = 0; i < four_array_size; i++){
		move_arm(four_array[i][0] + offset_x, four_array[i][1] + Y_OFFSET);
	}
}
void draw_five(int offset_x){
    //five with offsetx and offsety
	for (int i = 0; i < five_array_size; i++){
		move_arm(five_array[i][0] + offset_x, five_array[i][1] + Y_OFFSET);
	}
}
void draw_six(int offset_x){
    //six with offsetx and offsety
	for (int i = 0; i < six_array_size; i++){
		move_arm(six_array[i][0] + offset_x, six_array[i][1] + Y_OFFSET);
	}
}
void draw_seven(int offset_x){
    //seven with offsetx and offsety
	for (int i = 0; i < seven_array_size; i++){
		move_arm(seven_array[i][0] + offset_x, seven_array[i][1] + Y_OFFSET);
	}
}
void draw_eight(int offset_x){
    //eight with offsetx and offsety
	for (int i = 0; i < eight_array_size; i++){
		move_arm(eight_array[i][0] + offset_x, eight_array[i][1] + Y_OFFSET);
	}
}
void draw_nine(int offset_x){
    //nine with offsetx and offsety
	for (int i = 0; i < nine_array_size; i++){
		move_arm(nine_array[i][0] + offset_x, nine_array[i][1] + Y_OFFSET);
	}
}

