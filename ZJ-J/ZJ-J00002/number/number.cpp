/* Æ´Êý */
                              
#include <bits/stdc++.h>
#define regint register int
using namespace std;

int ton[256];
char c;
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	c = getchar();
	do{
		ton[c]++;
		c = getchar();
	}while(c != '\377');
	
	for(regint i = '9'; i >= '0'; i--)
		while(ton[i]--)
			printf("%c", i);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
