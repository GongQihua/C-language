#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 50
void get_size(int *size);
int check_size(int size);
void initialize_pointerArray(int *p, int size);
void print_pointerArray(int *p, int size);
int find_max(int *p, int size);
int find_min(int *p, int size);
void bubble_sort(int *p, int size);
float find_median(int *p, int size);
void bouns(int *p, int size);
int main(){
	int array[MAX];
	int *pointer = array;
	int size,a;
	get_size(&size);
	a = check_size(size);
	while (a == 0)
	{
		printf("\nPlease enter again:");
		get_size(&size);
		a = check_size(size);
	}
	initialize_pointerArray(pointer, size);
	print_pointerArray(pointer, size);
	find_min(pointer, size);
	printf("\nThe minimum of all the numbers= %d", find_min(pointer, size));
	find_max(pointer, size);
	printf("\nThe maximum of all the numbers= %d\n", find_max(pointer, size));
	bubble_sort(pointer, size);
	find_median(pointer, size);
	printf("\nThe median of the pointer=%.2f\n", find_median(pointer, size));
	bouns(pointer, size);
}
void get_size(int *size){
	printf("Enter the size of pointer:");
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
	printf("Input array\n");
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
int find_min(int *p, int size){
  int i;
	int min = *p;
	for (i = 1; i < size; i++) {
		if (*(p + i) < min) {
			min = *(p + i);
		}
	}
	return min;
}
void bubble_sort(int *p, int size) {
	int i,j,t;
	printf("\nThe sort pointer is:\n");
	for (i = 0; i < size - 1; i++) {
		for (j = 0; j < size - i - 1; j++) {
			if (*(p+j) > *(p+j +1))
			{
				t= *(p+j+1);
				*(p+j+1) = *(p+j);
				*(p+j) = t;
			}
		}
	}
	for (i = 0; i < size; i++) {
		printf("%d ", *(p + i));
	}
}
float find_median(int *p, int size) {
	float med;
	int x;
	x = size % 2;
		if(x == 1){
			med = *(p + size / 2);
	}
		if (x == 0) {
			med = (*(p + size / 2-1) + *(p + size / 2)) / 2.00;
		}
		return med;
}
void bouns(int *p, int size) {
	int i, j, t;
	printf("\n******** BONUS ********:\n");
	for (i = 0; i < size - 1; i++) {
		for (j = 0; j < size - i - 1; j++) {
			if (*(p + j) < *(p + j + 1))
			{
				t = *(p + j + 1);
				*(p + j + 1) = *(p + j);
				*(p + j) = t;
			}
		}
	}
	printf("\nThe pointer reversed and with every other number is:\n");
	for (i = 0; i < size; i++) {
			if (*(p + i) != *(p + i - 1)) {
				printf("%d ", *(p + i));
			}
		}
}
