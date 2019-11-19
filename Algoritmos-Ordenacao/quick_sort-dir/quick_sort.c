/*
 QUICK-SORT

 Bubblesort upgrade \o/
 Best sorting distant elements of a array
 Divide array into 2 smaller arrays

 Choose a pivot, better pivot, best sorting
 elements at the left side of the pivot need to be lower than it
 elements at the right side of the pivot need to be higher than it
 After that, do it again with the smaller arrays

 Worst case complexity:	O(n²)
	 If the Pivot is the worst possible (at position 0 or n-1)
	 one of the subarray has only the pivot
	 and the other has n-1 elems
	 So the time is c(n)+c(n-1)+...+2c=c(n+(n-1)+...+2)=c((n-1)*(n-2)-1), so O(n²)

*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define SUCCESS		0
#define TRUE		1
#define FALSE		0

//Function to organize the array and the subarrays
void partition(int *array, int left, int right, int *i, int *j);
//Call quicksort to the right side and the left side of the array
void quick_sort(int *array, int left, int right);

int main(void){
	//Seed defined by time
	//OBS: NOT SECURE
	srand(time(NULL));
	int i;
	int size = 10;
	int *array;
	array = (int *) malloc(size * sizeof(int));
	printf("This is the array before sorting\n");
	for(i = 0; i < size; i++){ 
		array[i] = rand() % 100;
		printf("%d ", array[i]);
	}
	printf("\n");
	printf("This is the array after sorting\n");
	quick_sort(array, 0, size - 1);
	for(i = 0; i < size; i++) printf("%d ", array[i]);
	printf("\n");
	free(array);

	return SUCCESS;
}

void partition(int *array, int left, int right,
	       			int *left_curr, int *right_curr){
	int pivot;
	int aux;
	*left_curr = left;
	*right_curr = right;
	//Pivot receives the mid value of the array
	pivot = array[(*left_curr + *right_curr) / 2];
	do{ //while left and right didn't cross
		//Search until finds a value at the wrong side
		while(array[*left_curr] < pivot) (*left_curr)++;
		while(array[*right_curr] > pivot) (*right_curr)--;

		//if the positions didn't cross 
		//it means found 2 elems to swap positions
		if(*left_curr < *right_curr){
			aux = array[*right_curr];
			array[*right_curr] = array[*left_curr];
			array[*left_curr] = aux;
		}
	}while(*left_curr < *right_curr);
}

void quick_sort(int *array, int left, int right){
	int right_curr, left_curr;
	//Organize the actual array
	partition(array, left, right, &left_curr, &right_curr);
	//If left is smaller than (right_curr - 1), means there is a subarray at left side of pivot
	if(left < right_curr - 1) 
		quick_sort(array, left, right_curr - 1);
	//If left_curr + 1 is smaller than right, means there is a subarray at right side of pivot
	if(left_curr + 1 < right) 
		quick_sort(array, left_curr + 1, right);
}
