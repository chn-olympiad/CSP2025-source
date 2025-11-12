//SN-J01212 Æë¾ýºÀ 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1000010;

char s[N];
int n, a[20];

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	scanf("%s", s + 1);
	n = strlen(s + 1);
	memset(a, 0, sizeof(a));
	for(int i = 1; i <= n; i++)
		if(s[i] >= '0' && s[i] <= '9')
			a[s[i] - '0']++;
	for(int i = 9; i >= 0; i--)
		for(int j = 1; j <= a[i]; j++)
			printf("%d", i);
	return 0;
}
