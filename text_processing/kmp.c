#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int *fail;

void computeFail(char *p, int n, int *fail)
{
	int j = 1;
	int k = 0;
	while(j < n){
		if(p[j] == p[k]){
			fail[j] = k + 1;
			j++;
			k++;
		}else if(k > 0){
			k = fail[k - 1];
		}else{
			j++;
		}
	}

}

int kmp(char *str, char *pattern)
{
	int stringLen = strlen(str);
	int patternLen = strlen(pattern);
	
	fail = (int *)malloc(sizeof(int) * patternLen);
	computeFail(pattern, patternLen, fail);	

	int i;
	for(i = 0; i < patternLen; i++){
		printf("%d\t", fail[i]);
	}


	int j = 0;
	int k = 0;
	while(j < stringLen){
		if(str[j] == pattern[k]){
			if(k == patternLen - 1){
				return j - patternLen + 1;
			}
			j++;
			k++;
		}else if(k > 0){
			k = fail[k - 1];
		}else{
			j++;
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

	
	int index = kmp(str, pattern);

	printf("index: %d\n", index);
	free(fail);
	printf("free success...");

	return 0;	
}

