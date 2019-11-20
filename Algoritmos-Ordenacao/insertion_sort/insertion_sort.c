/*
 INSERTION SORT
 
 INSERTION WORKS IN AN ALREADY SORTED ARRAY, SO YOU STARTS SORTING THE FIRST POSITION OF THE ARRAY

 Worts case complexity: O(n²)
 	-If the array sort is inverted, you always need to go to the beginning of the array
 Best case complexity:  O(n)
 	-If the array is already sorted, just scroll the array one time

 Conclusion:
 	-Only good for arrays already sorted

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

	//INSERTION SORT AHHHHHHHHHHHH :)
	for(i = 1; i < size; i++){
		key = array[i];
		j = i - 1;
		//While j represents a valid indice
		//and the array in that indice is bigger than the key
		//move this element to the right
		while(j >= 0 && array[j] > key){
			array[j+1] = array[j];
			j--;
		}
		//When one of the conditions is not satisfied, the key is inserted already in the right position
		array[j+1] = key;
	}

	printf("This is the array after sorting\n");
	for(i = 0; i < size; i++) printf("%d ", array[i]);
	printf("\n");

	return SUCCESS;
}
