#include<stdio.h>
#include<stdlib.h>

int get_record_count(char *filename){
  FILE *fp;
  fp = fopen(filename, "r");
  if(fp==NULL){
    return 0;
  }
  int size = 0;
  int account;
  float amount;
  while(!feof(fp)){
    fscanf(fp, "%d %f", &account, &amount);
    size++;
  }
  fclose(fp);
  return size;
}

int load_data(char*filename, int *account, float *amount, int size){
  FILE *fp;
  fp = fopen(filename, "r");
  if(fp==NULL){
    return 0;
  }
  int i=0;
  while(!feof(fp)){
    fscanf(fp, "%d %f", &account[i], &amount[i]);
    i++;
  }
  return i;
}

void print_data(int *account, float *amount, int size){
  printf("Accout No. Amount\n");
  int i;
  for(i=0; i<size-1; i++){
    printf("%d %.2f\n", account[i], amount[i]);
  }
}

int highest_amount( float *amount, int size){
  int max = 0;
  int i;
  for(i=0;i<size-1; i++){
    if(amount[i]>amount[max])
    max = i;
  }
return max;
}

int lowest_amount( float *amount, int size){
  int min = 0;
  int i;
  for(i=0;i<size-1; i++){
    if(amount[i]<amount[min])
    min = i;
  }
  return min;
}

float average_amount( float *amount, int size){
  float avg = 0.0;
  int i;
  for(i=0; i<size-1; i++){
    avg=avg+amount[i];
  }
  avg=avg/size;
  return avg;
}

int write_data(char *filename , int *account, float *amount, int size, int highest, int lowest, float avg){
  FILE *fx;
  fx = fopen(filename, "w");
  fprintf(fx, "Accout No. Amount\n");
  int i;
  for(i=0; i<size; i++)
  fprintf(fx, "%d %.2f\n", account[i], amount[i]);
  fprintf(fx, "The highest amount is $%.2f in the account number %d\n", amount[highest], account[highest]);
  fprintf(fx, "The lowest amount is $%.2f in the account number %d\n", amount[lowest], account[lowest]);
  fprintf(fx, "The average amount is $%.2f\n", avg);
  fclose(fx);
  return 0;
}

int main(int argc, char *argv[]){
  int size,highest,lowest;
  float avg;
  if(argc!=3){
    printf("Usage: ./a.out input-file output-file\n");
    return -1;
  }
  size = get_record_count(argv[1]);
  int*account = (int *)malloc(sizeof(int)*size);
  float*amount = (float *)malloc(sizeof(float)*size);
  load_data(argv[1], account, amount, size);
  print_data(account, amount, size);
  highest = highest_amount(amount, size);
  lowest = lowest_amount(amount, size);
  avg = average_amount(amount, size);
  printf("The highest amount is $%.2f in the account number %d\n", *(amount+highest), *(account+highest));
  printf("The lowest amount is $%.2f in the account number %d\n", *(amount+lowest), *(account+lowest));
  printf("The average amount is $%.2f\n", avg);
  write_data(argv[2], account, amount, size, highest, lowest, avg);
}
