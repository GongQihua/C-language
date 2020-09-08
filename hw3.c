#include <stdio.h>
#include <stdlib.h>
int load_data(char*, int *, float *);
void print_data(int *, float *, int);
int update_data(char*, int *, float *, int);
int highest_amount( float *, int );
int lowest_amount( float *, int);
float average_amount( float *, int );
void write_data(char* , int *, float *, int , int, int, float);

int main(int argc, char *argv[]){
  int *accno;
  float *amount;
  int size;
  int highestIdx, lowestIdx;
  float avg;
  if(argc != 5){
    printf("Insufficient arguments\n");
    exit(1);
  }
  size = atoi(argv[2]);
  accno = (int *) malloc(sizeof(int) * size);
  amount = (float *) malloc(sizeof(float) * size);
  if(load_data(argv[1], accno, amount) != 1){
    printf("Unable to open input file\n");
    exit(1);
  }
  print_data(accno, amount, size);
  update_data(argv[3], accno, amount, size);
  highestIdx = highest_amount(amount, size);
  lowestIdx = lowest_amount(amount, size);
  avg = average_amount(amount, size);
  print_data(accno, amount, size);
  printf("The highest amount is $%.2f in the account number %d\n", *(amount+highestIdx), *(accno+highestIdx));
  printf("The lowest amount is $%.2f in the account number %d\n", *(amount+lowestIdx), *(accno+lowestIdx));
  printf("The average amount is $%.2f\n", avg);
  write_data(argv[4], accno, amount, size, highestIdx, lowestIdx, avg);
  free(accno);
  free(amount);
  return 0;
}

int load_data(char* fname, int *accno, float *amount){
  FILE *fp = fopen(fname, "r");
  int n, i;
  if(fp == NULL){
    return 0;
  }
  else{
    fscanf(fp, "%d", &n);
    for(i = 0 ; i < n; i ++)
    fscanf(fp, "%d %f", accno+i, amount+i);
    fclose(fp);
    return 1;
  }
}

void print_data(int *accno, float *amount, int size){
  int i;
  printf("Account No. \t Amount\n");
  for(i = 0; i < size; i++){
    printf("%10d %10.2f\n", *(accno+i) , *(amount+i));
  }
}

int index_of_account(int *accno, int size, int search){
  int i ;
  for(i = 0; i < size; i++){
    if(*(accno + i) == search)
    return i;
  }
  return -1;
  }

int update_data(char* fname, int *accno, float *amount, int size){
  FILE *fp = fopen(fname, "r");
  int n, i, idx;
  int acc;
  float amt;
  if(fp == NULL){
    printf("Unable to open file %s", fname);
    return 0;
  }
  else{
  fscanf(fp, "%d", &n);
  for(i = 0 ; i < n; i ++){
    fscanf(fp, "%d %f", &acc, &amt);
    idx = index_of_account(accno, size, acc);
    if(idx != -1){
      amount[idx] += amt;
    }
  }
  fclose(fp);
  return 1;
  }
}

int highest_amount( float *amount, int size ){
  int i;
  int highestIdx = 0;
  for(i = 1; i < size; i++){
    if(*(amount+i) > *(amount + highestIdx))
    highestIdx = i;
  }
  return highestIdx;
}

int lowest_amount( float *amount, int size){
  int i;
  int lowestIdx = 0;
  for(i = 1; i < size; i++){
    if(*(amount+i) < *(amount + lowestIdx))
    lowestIdx = i;
  }
  return lowestIdx;
}

float average_amount( float *amount, int size ){
  int i;
  double avg = 0;
  for(i = 0; i < size; i++){
    avg += *(amount + i);
  }
  avg /= size;
  return avg;
}

void write_data(char* fname , int *accno, float *amount, int size , int highestIdx, int lowestIdx, float avg){
  FILE *fp = fopen(fname, "w");
  int i;
  if(fp == NULL){
    printf("Could not write to file %s", fname);
    return;
  }
  else{
    for(i = 0; i < size; i++)
    fprintf(fp, "%d %.2f\n", *(accno + i), *(amount + i));
    fprintf(fp, "\nThe highest amount is $%.2f in the account number %d\n", *(amount+highestIdx), *(accno+highestIdx));
    fprintf(fp, "The lowest amount is $%.2f in the account number %d\n", *(amount+lowestIdx), *(accno+lowestIdx));
    fprintf(fp, "The average amount is $%.2f\n", avg);
    fclose(fp);
  }
}
