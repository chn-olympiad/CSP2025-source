#include <bits/stdc++.h>
using namespace std;

const int N = 1000010;

char s[N], ans[N];
int n, a[N], m;

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	scanf("%s", s);
	for (int i = 0; s[i] != '\0'; i++)
		if (s[i] >= '0' && s[i] <= '9')
			a[s[i] - '0']++;
	for (int i = 9; i >= 0; i--)
		for (int j = 1; j <= a[i]; ++j)
			ans[m++] = i + '0';
	printf("%s", ans);
	return 0;
}
