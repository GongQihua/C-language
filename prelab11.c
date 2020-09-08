#include<stdio.h>
#define MAX 22
struct Student{
  char name[20];
  int id;
  int grade;
};
struct Student info[MAX];

void get_size(int *size){
  scanf("%d", size);
}

int check_size(int n){
  return n <= MAX ? 1 : 0;
}

void load_structdata(char *filename, int n){
  int i;
  FILE *fp;
  fp = fopen(filename, "r");
  for( i = 0 ; i < n ; i++){
    fscanf(fp, "%s %d %d\n", info[i].name, &info[i].id, &info[i].grade);
  }
}

void print_data(int size){
  int i;
  printf("\nStudent-Record: \n\n");
  printf("s/no\tName\t\tid\tGrade\n\n");
  for(i = 0 ; i < size ; i++){
    printf("%d.\t%-15s%d\t%d\n", i+1, info[i].name, info[i].id, info[i].grade);
  }
}

int main(){
  int size;
  printf("Enter the size of the Input: ");
  get_size(&size);
  printf("\n=================================================================\n");
  while(!check_size(size)){
    printf("Invalid Size Entered! Minimum is 1 and Maximum is 22!\n");
    printf("=================================================================");
    printf("\nPlease enter again: ");
    get_size(&size);
    printf("\n=================================================================\n");
  }
  char filename[20] = "prelab_data.txt";
  load_structdata(filename, size);
  print_data(size);
}
