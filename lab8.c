#include <stdio.h>
#include<stdlib.h>
#include<math.h>
int errorCheck(int n);
int factorial(int n);
void maclaurinSeries(float* arr, int size, int x);
void printArray(float* arr, int size);
void reverseArray(float* arr, int size);
int main(){
	int n, x,a,b;
	float arr[10];
	printf("Enter a value to compute the Maclaurin series expansion (x): ");
	scanf("%d", &x);
	a = errorCheck(x);
	while (a == 0){
		printf("x must be larger than 0 and less than 10. Please enter again:");
		scanf("%d", &x);
		a = errorCheck(x);
	}
	printf("\n Enter a value for the Maclaurin series to run (n): ");
	scanf("%d", &n);
	b = errorCheck(n);
	while (b== 0){
		printf("n must be larger than 0 and less than 10. Please enter again:");
		scanf("%d", &n);
		b = errorCheck(n);
	}
	maclaurinSeries(arr, n + 1, x);
	printArray(arr, n + 1);
	reverseArray(arr, n + 1);
}
int errorCheck(int n){
	if (n > 0 && n < 10) {
		return 1;
	}
		return 0;
}
int factorial(int n){
	int fact = 1;
	int i;
	for (i = 1; i <= n; i++)
	{
		fact = fact * i;
	}
	return fact;
}
void maclaurinSeries(float* arr, int size, int x){
	float sum = 0;
	int i, j = 0, t = 1;
	for (i = 0; i < size; i++)
	{
		sum = sum +pow(x, j) / factorial(j)*t;
		*arr = sum;
		arr++;
		j = j + 2;
		t = t * (-1);
	}
}
void printArray(float* arr, int size){
	int i;
	printf("\n The array for the Maclaurin series is: \n");
	for (i = 0; i < size; i++)
	{
		printf("%.4f ", *arr);
		arr++;
	}
}
void reverseArray(float* arr, int size){
	int i;
	printf("\n----------BONUS-------------\n");
	printf("The reverse array is: \n");
	for (i = size - 1; i >= 0; i--)
	{
		printf("%.4f ", *(arr+i));
	}
}
