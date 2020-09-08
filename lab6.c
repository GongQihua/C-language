#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 20
#define MAX1 400
int check_error(int size);
void initialize_2Darray(int array[][MAX] , int size);
void print_2Darray(int array[][MAX], int size);
int findZeros(int array[][MAX], int size);
int findEvenOdd(int array[][MAX], int size);
void printTranspose(int array[][MAX], int size);
void flattenArray(int array[][MAX], int size);
void Bonus(int array[][MAX], int size);
int main(){
        int size ,check, array1[MAX][MAX] = {};
        printf( "Enter the size of the 2-D array:\n");
        scanf("%d",&size);
        check = check_error(size);
        while(check == 0) {
                printf("Please enter a value between 1-20 only:\n");
                scanf("%d",&size);
                check = check_error(size);;
        }
        initialize_2Darray(array1, size);
        print_2Darray(array1, size);
        findZeros(array1, size);
        printf( "The number of zeros in 2-D Array:%d\n", findZeros(array1, size));
        findEvenOdd(array1, size);
        printf("The number of Even numbers:%d\n", findEvenOdd(array1, size));
        printf("The number of Odd numbers:%d\n", size*size-findEvenOdd(array1, size));
        printTranspose(array1, size);
        flattenArray(array1, size);
        Bonus(array1, size);
}
int check_error(int size)
{
        if (size >0 && size <= 20) {
                return 1;
        }
        else {
                return 0;
        }
}
void initialize_2Darray(int array[][MAX], int size)
{
        int i, j;
        srand(time(NULL));
        for (i = 0; i < size; i++){for (j = 0; j < size; j++){
                        array[i][j] = rand() %10 ;
                }
        }
}
void print_2Darray(int array[][MAX], int size){
        int i, j;
        printf( "THE FIRST 2-D ARRAY is:\n");
        for (i = 0; i < size; i++)
        {
                for (j = 0; j < size; j++)
                {
                        printf("%3d",array[i][j]);
                }
                printf("\n");
        }
        printf("\n");
}
int findZeros(int array[][MAX], int size)
{
        int count = 0, i, j;
        for (i = 0; i < size; i++)
        {
                for (j = 0; j < size; j++)
                {
                        if (array[i][j] == 0) {
                                count++;
                        }
                }
        }
        return count;
}
int findEvenOdd(int array[][MAX], int size){
        int even = 0, i, j;
        for (i = 0; i < size; i++)
        {
                for (j = 0; j < size; j++)
                {
                        if (array[i][j] % 2 == 0) {
                                even++;
                        }
                }
        }
        return even;
}
void printTranspose(int array[][MAX], int size) {
        int i, j;
        printf("The transpose of the 2-D Array is:\n");
        for (j = 0; j< size; j++)
        {
                for (i = 0; i < size; i++)
                {
                        printf("%3d", array[i][j]);
                }
                printf("\n");
        }
        printf("\n");
}
void flattenArray(int array[][MAX], int size) {
        int i, j,n=0, a[MAX1] = {};
        printf("The flattened array is:\n");
        for (i = 0; i < size; i++)
        {
                for (j = 0; j < size; j++)
                {
                        a[n] = array[i][j];
                        n = n + 1;
                }
        }
        for (n = 0; n < size*size; n++) {
                printf("%d", a[n]);
        }
        printf("\n");
}
void Bonus(int array[][MAX], int size) {
        int i, j,t, n = 0, a[MAX1] = {};
        printf("The bonus part is:\n");
        for (i = 0; i < size; i++)
        {
                for (j = 0; j < size; j++)
                {
                        a[n] = array[i][j];
                        n = n + 1;
                }
        }
        for (i = 0; i < size*size; i++)
        {
                for (j = 0; j < size*size; j++)
                {
                        if (a[j] > a[j + 1])
                        {
                                t = a[j + 1];
                                a[j + 1] = a[j];
                                a[j] = t;
                        }
                }
        }
        for (i = 0; i < size*size; i++)
        {
                printf("%d ", a[i]);
        }
}
