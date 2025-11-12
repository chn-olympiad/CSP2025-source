#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+10;

char s[N];
int n;

int a[N], m;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	scanf("%s", s+1);
	n = strlen(s+1);
	
	for(int i=1; i<=n; i++)
		if(s[i]>='0' and s[i]<='9')
			a[++m] = s[i] - '0';
	
	sort(a+1, a+1+m, greater<int>());
	
	for(int i=1; i<=m; i++)
		putchar(a[i]+'0');
	
	return 0;
}
