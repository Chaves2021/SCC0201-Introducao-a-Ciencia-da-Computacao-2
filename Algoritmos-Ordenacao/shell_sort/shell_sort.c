/*
 SHELL-SORT

 INSERTION SORT IMPROVED
 INSERTION SORT MOVES ONLY ADJACENT ELEMENTS
 SHELL SORT MOVES DISTANT ELEMENTS YAY :P
 ELEMENTS SEPARATED BY H POSITIONS (MULTIPLES OF H), FOR EXAMPLE H = 2

 [H*0]   [1]	[H*1]	[3]
  10      3      5       2

 SORTING: STEP 1
 [H*0]   [1]	[H*1]	 [3]
   5      3      10       2

 SORTING: STEP 2
  [0]   [H*0]	[2]	 [H*1]
   5      2      10        3

 AFTER THAT, DECREASE H

 AFTER H == 1, DO INSERTION SORT :)

 -To choose a good H (increment) Knuth says:
 	H(1) = 1 && H(i+1) = 3*H(i) + 1

*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define SUCCESS		0
#define TRUE		1
#define FALSE		0

int main(void){
	int i, j;
	int key;
	int size = 10;
	int *array;
	array = (int *) calloc(size, sizeof(int));

	//Seed defined by time
	//OBS: NOT SECURE
	srand(time(NULL));

	printf("This is the array before sorting\n");
	for(i = 0; i < size; i++){
		array[i] = rand() % 100;
		printf("%d ", array[i]);
	}
	printf("\n");

	return SUCCESS;
}
