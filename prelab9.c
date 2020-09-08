#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 50
void get_size(int *size);
int check_size(int size);
void initialize_pointerArray(int *p, int size);
void print_pointerArray(int *p, int size);
int find_max(int *p, int size);
int main(){
	int array[MAX];
	int *pointer = array;
	int size,a;
	get_size(&size);
	a = check_size(size);
	while (a == 0)
	{
		printf("Invalid input enter the size of the array again: ");
		get_size(&size);
		a = check_size(size);
	}
	initialize_pointerArray(pointer, size);
	print_pointerArray(pointer, size);
	find_max(pointer, size);
	printf("\nThe largest value in the pointer is: %d\n", find_max(pointer, size));
}
void get_size(int *size){
	printf("Enter the size of array: ");
	scanf("%d", size);
}
int check_size(int size){
	if (size > 0 && size < 51){
		return 1;
	}
		return 0;
}
void initialize_pointerArray(int *p, int size){
	int i,r;
	srand(time(NULL));
	for (i = 0; i < size; i++){
		r = rand() % 10 + 1;
		*(p + i) = r;
	}
}
void print_pointerArray(int *p, int size){
	int i;
	printf("\nInput array\n");
	for (i = 0; i < size; i++){
		printf("%d ", *(p + i));
	}
	printf("\n");
}
int find_max(int *p, int size){
	int i;
	int max = *p;
	for (i = 1; i < size; i++){
		if (*(p + i) > max){
			max = *(p + i);
		}
	}
	return max;
}
