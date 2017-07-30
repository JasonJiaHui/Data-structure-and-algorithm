#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int bruteForce(char *str, char *pattern)
{
	int strLen = strlen(str);
	int patternLen = strlen(pattern);

	int j,k;

	for(j = 0; j < strLen - patternLen; j++){
		k = 0;
		while(k < patternLen && str[j+k] == pattern[k]){
			k++;
		}
		if(k == patternLen){
			return j;
		}
	}
	return -1;
}


int main(void)
{
	char str[100];
	char pattern[100];

	printf("please input string and pattern\n");
	scanf("%s%s", str, pattern);

	int index = bruteForce(str, pattern);

	printf("index: %d\n", index);

	return 0;
}
