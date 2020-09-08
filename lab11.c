#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 40
struct City {
   char country[100] ;
   int zipcode ;
   char city[100] ;
   int group ;
 };
 struct City myCities[MAX] ;
 struct income{
   int Zip;
   int Inc;
 };
 struct income info[MAX];

void get_size(int *size){
   scanf("%d", size);
}

int check_size(int n){
   if(n>=4 && n<=40) {
     return 1 ;
   }
   return 0 ;
}

int check_group(int group){
   if(group>=1 && group<=3){
     return 1 ;
   }
   return 0 ;
}

void load_data(const char *filename, int n){
   int i = 0, zipcode ;
   char country[100], city[100] ;
   FILE *fp;
   fp = fopen(filename, "r");
   printf("S/No\t%-15s\tZipcode\tCity\n\n", "Country");
   while(i<n && !feof(fp)){
       fscanf(fp, "%s %d %s", country, &zipcode, city);
       printf("%d\t%-15s\t%d\t%s\n", i+1, country, zipcode, city );
       i++ ;
   }
printf("=================================================================\n");
}

void classify(const char *filename, int n){
   int  i = 0,a=0,b=0,c=0 ;
   FILE *fp;
   fp = fopen(filename, "r");
   printf("S/No\t%-15s\tZipcode\t%-15s\tGroup\n\n", "Country", "City");
   while(i<n && !feof(fp)){
       fscanf(fp, "%s %d %s", myCities[i].country, &myCities[i].zipcode, myCities[i].city);
       if(myCities[i].zipcode >=63000 && myCities[i].zipcode <=63999){
         myCities[i].group = 1 ;
         a++;
       }
       else if(myCities[i].zipcode >=64000 && myCities[i].zipcode <=64999){
         myCities[i].group = 2 ;
         b++;
       }
       else if(myCities[i].zipcode >=65000 && myCities[i].zipcode <=65999){
         myCities[i].group = 3 ;
         c++;
       }
       printf("%d\t%-15s\t%d\t%-15s\t%d\n", i+1, myCities[i].country, myCities[i].zipcode, myCities[i].city, myCities[i].group );
       i++ ;
   }
printf("=================================================================\n");
printf("Number of Information in Group 1:%d\n",a);
printf("Number of Information in Group 2:%d\n",b);
printf("Number of Information in Group 3:%d\n",c);
printf("=================================================================\n");
}

void frequency(const char *filename, int n, int group){
   int groupc = 0, low, high, j = 1, i=0 ;
   char citytop3[3][100];
   int freqtop3[3] = {0};
   if(group==1){
       low = 63000 ;
       high = 63999 ;
   }
   else if(group==2){
       low = 64000 ;
       high = 64999 ;
   }
   else{
       low = 65000 ;
       high = 65999 ;
   }
   FILE *fp = fopen(filename, "r");
   printf("=================================================================\n");
   printf("Cities in group %d .... \n", group);
   while(i<n && !feof(fp)){
       fscanf(fp, "%s %d %s", myCities[i].country, &myCities[i].zipcode, myCities[i].city);
       if(myCities[i].zipcode>=low && myCities[i].zipcode<=high){
           myCities[i].group = group ;
           groupc++ ;
           printf("[%d]\t%s\n", j, myCities[i].city);
           if(j<=3){
               strcpy(citytop3[j-1], myCities[i].city);
               freqtop3[j-1]++ ;
           }
           else{
               if(strcmp(myCities[i].city, citytop3[0])==0){
                  freqtop3[0]++ ;
                }
               if(strcmp(myCities[i].city, citytop3[1])==0){
                  freqtop3[1]++ ;
                }
               if(strcmp(myCities[i].city, citytop3[2])==0){
                 freqtop3[2]++ ;
               }
           }
           j++ ;
       }
       i++ ;
   }
   printf("=================================================================\n");
   printf("FREQUENCY TABLE..........\n");
   printf("S/N0\t %-15s\tFrequency\n", "City");
   if(j>1){
     printf("1\t %-15s\t%d\n", citytop3[0], freqtop3[0]);
   }
   if(j>2){
     printf("2\t %-15s\t%d\n", citytop3[1], freqtop3[1]);
   }
   if(j>3){
     printf("3\t %-15s\t%d\n", citytop3[2], freqtop3[2]);
   }
}

void load_structdata(char *filename, int n){
  int i;
  FILE *fp;
  fp = fopen(filename, "r");
  for( i = 0 ; i < n ; i++){
    fscanf(fp,"%d %d\n", &info[i].Zip, &info[i].Inc);
  }
}

void print_data(int size){
  int i;
  printf("\nIncome-Record\n\n");
  printf("s/no\tZipcode\tincome\n\n");
  for(i = 0 ; i < size ; i++){
    printf("%d.\t%d\t%d\n", i+1, info[i].Zip, info[i].Inc);
  }
}

int main( int n,char const *string[]){
   printf("Enter the size of input : ");
   get_size(&n);
   printf("=================================================================\n");
   while(check_size(n)==0){
       printf("Invalid Size Entered! Minimum is 4 and Maximum is 40!\n");
       printf("=================================================================\n");
       printf("Please enter again ");
       get_size(&n);
       printf("=================================================================\n");
   }
   load_data(string[1], n);
   classify(string[1], n);
   int group ;
   printf("Enter the group number : ");
   scanf("%d", &group) ;
   while(check_group(group)==0){
       printf("Wrong input ! Group must be from 1 tp 3\n");
       printf("=================================================================\n");
       printf("Enter the group number : ");
       scanf("%d", &group) ;
   }
   frequency(string[1], n, group);
   printf("*******************BONUS**********************");
   char filename[MAX] = "bonus_data.txt";
   load_structdata(filename, n);
   print_data(n);
}
