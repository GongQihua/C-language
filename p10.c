#include <stdio.h>
#include<ctype.h>
#include <stdlib.h>
#include<string.h>
int getString(char *);
int checkString(char *str, int n);
int main()
{
	char s[30];
	int n;
	char *str;
	n = getString(s);
	if (n < 0){
		printf("Not valid string\n");
	}
	else
	{
		str = malloc(sizeof(char) * 20);
		strcpy(str, s);
		printf("You entered %s with size %d\n", str, n);	}
}
int getString(char *s)
{
	int n;
	char str[30];
	int  i;
	printf("Enter the size of the string: ");
	do
	{
		scanf("%d", &n);
		if (n <= 0 || n > 20)
		{
			printf("Please enter again: ");
		}
	} while (n <= 0 || n > 20);
	printf("Please enter the string: ");
	do
	{
		scanf("%s", str);
		if (strlen(str) <= 0 || strlen(str) > n)
		{
			printf("String entered is longer than the allowed size\n");
			printf("Please enter a valid string: ");
		}
		else
		{
			for (i = 0; i < strlen(str); i++)
			{
				s[i] = toupper(str[i]);
			}
			s[i] = '\0';
			if (checkString(s, strlen(s)) == 1){
				break;
			}
			else
			{
				printf("Please enter a valid string: ");
				continue;
			}
		}
	} while (1);
	return strlen(s);
}
int checkString(char *s, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		if (s[i] >= 65 && s[i] <= 91)
		{
			continue;
		}
		else
			return 0;
	}
	return 1;
}
