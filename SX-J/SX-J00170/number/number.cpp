#include <bits/stdc++.h>
using namespace std;

void file() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
}

char s[1000005];
int a[1000005], m, n;

int main() {
	file();
	scanf("%s", s + 1);
	n = strlen(s + 1);
	for (int i = 1; i <= n; i++)
		if (isdigit(s[i]))
			a[++m] = s[i] - 48;
	sort(a + 1, a + m + 1);
	for (int i = m; i >= 1; i--)
		printf("%d", a[i]);
	return 0;
}