#include <stdio.h>
#include<ctype.h>
#include <stdlib.h>
#include<string.h>
#include<time.h>
int getString(char *s);
int checkString(char *str, int n);
int stringSum(char *str, int n);
void cipherString(char *str, int n,int r);
int main(){
	char s[30];
	int n;
	char *str;
	int r;
	srand(time(NULL));
	r = rand() % 25 + 1;
	n = getString(s);
	if (n < 0){
		printf("Not valid string\n");
	}
		str = malloc(sizeof(char) * 20);
		strcpy(str, s);
		printf("You entered %s with size %d\n", str, n);
		cipherString(str,n,r);
		stringSum(str, n);
		printf("The sum of the ascii in %s is %d\n",str,stringSum(str, n));
		free(str);
	}
int getString(char *s)
{
	int n,a;
	char str[30];
	int  i;
	printf("Enter the size of the string: ");
	scanf("%d", &n);
	while (n <= 0 || n > 20){
		printf("Please enter again: ");
		scanf("%d", &n);
	}
	printf("Please enter the string: ");
	do
	{
		scanf("%s",str);
		a=strlen(str);
		if (a <= 0 || a > n)
		{
			printf("String entered is longer than the allowed size\n");
			printf("Please enter a valid string: ");
		}
		else
		{
			for (i = 0; i < a; i++)
			{
				s[i] = toupper(str[i]);
			}
			s[i] = '\0';
			if (checkString(s, a) == 1){
				break;
			}
			else
			{
				printf("Please enter a valid string: ");
				continue;
			}
		}
	} while (1);
	return a;
}
int checkString(char *s, int n){
	int i;
	for (i = 0; i < n; i++){
		if (s[i] < 65 || (s[i] > 90 && s[i] < 97) || s[i] > 122){
			return 0;
		}
	}
	return 1;
}
void cipherString(char *str, int n,int r){
	int i,j,a;
	char s[30];
	for (i = 0; i < n; i++){
		s[i]=str[i]+ r;
	}
	printf("The cipher string is %s, waht is the cipher key:",s);
	scanf("%d",&a);
	while(a!=r){
		while(a<=0||a>=26){
			printf("The cipher key is between 1 and 25, try again:");
			scanf("%d",&a);
		}
	for (i = 0; i < n; i++){
	for (j = 0; j < a; j++) {
		s[i]--;
		if (s[i] < 65) {
			s[i] = 90;
		}
	}
}
		printf("The cipher string shifted back %d is %s,incorrect",a,s);
		for (i = 0; i < n; i++){
			s[i]=str[i]+ r;
		}
		printf("The ciphered string is %s, what is the cipher key:",s);
		scanf("%d",&a);
	}
	if(a==r){
		for (i = 0; i < n; i++){
			s[i]=str[i]-a;
		}
		printf("The cipher string shifted back %d is %s,that's correct",a,s);
	}
}
int stringSum(char *str, int n){
	int i,sum=0;
	for(i = 0; i <= n; i++){
		sum=sum+str[i];
	}
	return sum;
}
