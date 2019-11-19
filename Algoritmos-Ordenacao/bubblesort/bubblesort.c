/*
 BUBBLESORT

 j comparison quantity is n-j comparisons
 so it's (n-1)+(n-2)+...+(n-i)=(2*i*n-i²-i)/2 and this is...1/2(n²-n)=O(n²)

 Worst case complexity: 	O(n²)
 Best case complexity: 		O(n)

 PROS
     -It's simple
     -Good for arrays almost sorted and small
 CONS
     -Memory cost too high especially with big arrays
     -Not good for arrays elems too distants

 CONCLUSION: 
    -One of the worst sort methods, too costly :(
    -Probably using it when i'm lazy :p
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define SUCCESS		0
#define TRUE		1
#define FALSE		0

int main(void){
	//Seed defined by time
	//OBS: NOT SECURE
	srand(time(NULL));
	int i, j;
	int size = 10;
	int *array;
	//Boolean to know if array stills need sorting
	int do_sort = TRUE;
	//Variable to store a value when it's changing place
	int aux;
	array = (int *) malloc(size * sizeof(int));
	printf("This is the array before sorting\n");
	for(i = 0; i < size; i++){
		array[i] = rand() % 100;
		printf("%d ", array[i]);
	}
	printf("\n");
	printf("This is the array after sorting :)\n");
	for(i = 0; i < size - 1 && do_sort; i++){
		do_sort = FALSE;
		for(j = i + 1; j < size; j++){
			if(array[i] > array[j]){
				aux = array[i];
				array[i] = array[j];
				array[j] = aux;
				do_sort = TRUE;
			}
		}
	}
	for(i = 0; i < size; i++) printf("%d ", array[i]);
	printf("\n");

	return SUCCESS;
}
