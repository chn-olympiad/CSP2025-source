#include <bits/stdc++.h>
using namespace std;

char s[1000005];
int num[1000005];

int main(){
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	int op = 0;
	while(n){
		if(s[n] >= '0' && s[n] <= '9'){
			op++;
			num[op] = s[n] - '0';
		}
		n--;
	}
	sort(num + 1, num + 1 + op);
	while(op){
		printf("%d", num[op]);
		op--;
	}
	return 0;
}
