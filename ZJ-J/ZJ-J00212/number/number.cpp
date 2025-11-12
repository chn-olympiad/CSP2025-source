#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1000010;

char st[MAXN];
int len, s[110];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	scanf("%s", st);
	len = strlen(st);
	for (int i=0; i<=9; i++) s[i] = 0;
	for (int i=0; i<len; i++) {
		if (st[i]>='0' && st[i]<='9') s[st[i]-'0'] ++;
	}
	for (int i=9; i>=0; i--) {
		while (s[i]--) {
			printf("%d", i);
		}
	}
	return 0;
} 
